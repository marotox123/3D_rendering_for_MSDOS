#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <dos.h>

typedef struct {
    float x, y, z;
} Point3D;

void project(Point3D point, int *px, int *py, int f, int d) {
    *px = (int)((point.x * f) / (point.z + d)) + 320;
    *py = (int)((point.y * f) / (point.z + d)) + 240;
}

void rotateY(Point3D *point, float angle) {
    float x = point->x;
    float z = point->z;
    point->x = x * cos(angle) + z * sin(angle);
    point->z = -x * sin(angle) + z * cos(angle);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    if (graphresult() != 0) {
        exit(1);
    }

    int f = 200;
    int d = 500;
    float rotationSpeed = 0.05;
    int delayTime = 30;

    Point3D base[4] = {
        {-100, -100, 0},
        {100, -100, 0},
        {100, 100, 0},
        {-100, 100, 0}
    };
    Point3D apex = {0, 0, 150};

    int i;

    while (1) {
        cleardevice();

        setcolor(RED);
        char infoText[100];
        sprintf(infoText, "Predkosc obrotu: %.2f | Delay: %d | Ogniskowa: %d", rotationSpeed, delayTime, f);
        outtextxy(10, 10, "Sterowanie:");
        outtextxy(10, 30, "'+' - zwieksz predkosc, '-' - zmniejsz predkosc");
        outtextxy(10, 50, "Strzalki gora/dol - zmieniaj FOV");
        outtextxy(10, 70, "Strzalki lewo/prawo - zmieniaj opoznienie (delay)");
        outtextxy(10, 90, infoText);

        setcolor(WHITE);
        outtextxy(370, 460, "Zrobione poprzez marotox123");

        for (i = 0; i < 4; i++) {
            rotateY(&base[i], rotationSpeed);
        }
        rotateY(&apex, rotationSpeed);

        for (i = 0; i < 4; i++) {
            int x1, y1, x2, y2;
            project(base[i], &x1, &y1, f, d);
            project(base[(i + 1) % 4], &x2, &y2, f, d);
            line(x1, y1, x2, y2);
        }

        for (i = 0; i < 4; i++) {
            int x1, y1, x2, y2;
            project(base[i], &x1, &y1, f, d);
            project(apex, &x2, &y2, f, d);
            line(x1, y1, x2, y2);
        }

        if (kbhit()) {
            char key = getch();
            if (key == '=') {
                rotationSpeed += 0.01;
                if (rotationSpeed > 1.0) {
                    rotationSpeed = 1.0;
                }
            } else if (key == '-') {
                rotationSpeed -= 0.01;
                if (rotationSpeed < 0.01) {
                    rotationSpeed = 0.01;
                }
            } else if (key == 27) {
                break;
            } else if (key == 0) {
                key = getch();
                if (key == 72) { // Strzalka w gore
                    f += 10;
                } else if (key == 80) { // Strzalka w dol
                    f -= 10;
                    if (f < 10) f = 10;
                } else if (key == 75) { // Strzalka w lewo
                    delayTime += 5;
                    if (delayTime > 100) delayTime = 100;
                } else if (key == 77) { // Strzalka w prawo
                    delayTime -= 5;
                    if (delayTime < 5) delayTime = 5;
                }
            }
        }

        delay(delayTime);
    }

    closegraph();
    return 0;
}
