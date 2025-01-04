
### README - Program "Obracający się ostrosłup 3D"

#### Wymagania:
1. **Środowisko uruchomieniowe:**
   - Program działa w środowisku **Turbo C++** uruchomionym w **DOSBox**.
   - Upewnij się, że masz zainstalowany DOSBox i Turbo C++.
2. **Pliki dodatkowe:**
   - Plik sterownika grafiki **BGI** (np. `EGAVGA.BGI`) musi znajdować się w katalogu `C:\TC\BGI`.

#### Instrukcja obsługi:
1. **Uruchomienie programu:**
   - Otwórz **DOSBox**.
   - Zamontuj folder z programem jako dysk w DOSBox:
     ```
     mount c [ścieżka_do_folderu_z_programem]
     c:
     ```
   - Uruchom plik wykonywalny:
     ```
     3D.exe
     ```
2. **Sterowanie w programie:**
   - **`+`**: Zwiększa prędkość obrotu.
   - **`-`**: Zmniejsza prędkość obrotu.
   - **Strzałka w górę**: Zwiększa ogniskową (FOV).
   - **Strzałka w dół**: Zmniejsza ogniskową (FOV).
   - **Strzałka w lewo**: Zwiększa czas opóźnienia (delay).
   - **Strzałka w prawo**: Zmniejsza czas opóźnienia (delay).
   - **ESC**: Kończy program.

#### Funkcjonalność:
Program wizualizuje obracający się ostrosłup 3D, którego podstawą jest kwadrat, a wierzchołkiem jest punkt w przestrzeni. 
- Projektowanie w 3D odbywa się przy użyciu rzutowania perspektywicznego.
- Obiekt można obracać w czasie rzeczywistym, dostosowując parametry takie jak prędkość obrotu, FOV (ogniskowa), oraz opóźnienie animacji.

#### Struktura kodu:
1. **Struktura `Point3D`**: Reprezentuje punkt w przestrzeni 3D (x, y, z).
2. **Funkcja `project`**: Realizuje rzutowanie perspektywiczne.
3. **Funkcja `rotateY`**: Obraca punkt 3D względem osi Y.
4. **Pętla główna programu**:
   - Aktualizuje pozycje punktów ostrosłupa.
   - Rysuje linie reprezentujące krawędzie ostrosłupa.
   - Obsługuje wejście użytkownika do sterowania parametrami.

#### Autor:
Program został stworzony przez **marotox123**.

#### Uwagi:
- Jeśli program nie działa, upewnij się że masz Turbo C++ 3.0 i że plik `EGAVGA.BGI` znajduje się w katalogu `C:\TC\BGI`.
- Aby uzyskać płynne działanie, dostosuj opóźnienie (delay) w zależności od wydajności emulatora DOSBox.
