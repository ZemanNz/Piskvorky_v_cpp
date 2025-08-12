# SFML Test (C++)

Jednoduchý projekt v C++ s **SFML** (2D okno, mřížka, kreslení tvarů a textu). Vhodné jako základ pro piškvorky / tic‑tac‑toe a další malé hry.

## 🚀 Funkce
- Vytvoření okna (`sf::RenderWindow`)
- Vykreslení mřížky a herních prvků (kolečko/křížek)
- Základ klikací logiky
- Ukázky práce s barvami a tloušťkou čar

## 🧰 Požadavky
- Ubuntu / Linux (funguje i jinde)
- `g++`, `make`
- Knihovna **SFML** (grafika, okno, systém)

Instalace na Ubuntu:
```bash
sudo apt update
sudo apt install g++ build-essential libsfml-dev
```

## 📦 Stažení projektu
Pokud chceš projekt stáhnout/clonovat:
```bash
git clone https://github.com/<tvuj-username>/<nazev-repozitare>.git
cd <nazev-repozitare>
```

> Alternativně stáhni ZIP z GitHubu (Code → Download ZIP) a rozbal.

## 🛠️ Kompilace a spuštění (jednoduchá varianta)
Z kořene projektu spusť **dva příkazy**:

```bash
g++ main.cpp -o hra -lsfml-graphics -lsfml-window -lsfml-system
./hra
```

> Tvoje konzole mohla vypadat i takto (jiný prompt/cesta je v pořádku):
```
nik@nik-Modern-14-C13M:~/Plocha/Programing/C++/Vyzualizace/sfml_test$ g++ main.cpp -o hra -lsfml-graphics -lsfml-window -lsfml-system
nik@nik-Modern-14-C13M:~/Plocha/Programing/C++/Vyzualizace/sfml_test$ ./hra
```

## 🗂️ Struktura projektu (doporučení)
```
.
├── assets/
│   └── fonts/
│       └── DejaVuSans.ttf     # doporučený font (zkopíruj sem)
├── main.cpp
└── README.md
```

## 🔤 Fonty (častý problém)
Pokud používáš text (`sf::Text`), ujisti se, že máš v projektu font a správnou relativní cestu, např.:
```cpp
sf::Font font;
font.loadFromFile("assets/fonts/DejaVuSans.ttf");
```
Na Ubuntu můžeš zkopírovat systémový font:
```bash
mkdir -p assets/fonts
cp /usr/share/fonts/truetype/dejavu/DejaVuSans.ttf assets/fonts/
```

## ▶️ Spuštění
Po úspěšné kompilaci stačí:
```bash
./hra
```

## 🧩 CMake (volitelné)
Chceš-li stavět přes CMake, přidej `CMakeLists.txt`:
```cmake
cmake_minimum_required(VERSION 3.10)
project(sfml_test)
set(CMAKE_CXX_STANDARD 17)
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
add_executable(sfml_test main.cpp)
target_link_libraries(sfml_test sfml-graphics sfml-window sfml-system)
```
Build:
```bash
mkdir build && cd build
cmake ..
make
./sfml_test
```

## ❓ Troubleshooting
- **Failed to load font**: zkontroluj, že soubor fontu existuje a cesta sedí vzhledem k místu, odkud program spouštíš.
- **Nic se nevykreslí**: kresli vždy mezi `window.clear()` a `window.display()` v hlavní smyčce. Nekresli a zároveň nevolej `display()` v pomocných funkcích.
- **Kliky nesedí**: pokud používáš `View`, převáděj pixely na světové souřadnice `window.mapPixelToCoords(...)`.

---

Hezké hraní a klidně otevři issue/PR s nápady ✌️
