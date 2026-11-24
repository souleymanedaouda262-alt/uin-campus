# UIN-Campus
Systeme de gestion academique de l'UIN (projet fil rouge C++23).
## Versions des outils
 g++ 15.2.0- clang++ 21.1.8- cmake 4.2.3- ninja 1.13.2- gdb 17.1- git 2.53.0
## Construire, tester, installer, versionner
    rm-rf build
    cmake--preset debug
    cmake--build--preset debug
    ./build/debug/app/uin-campus--version

## Fil rouge — Restructuration de UIN-Campus
 uin-campus/
├── CMakeLists.txt              ← modifié
├── CMakePresets.json
├── include/uincampus/
│   ├── uincampus.hpp           ← nouveau (en-tête parapluie)
│   ├── version.hpp             ← modifié
│   ├── regles.hpp
│   ├── saisie.hpp
│   └── calculs.hpp
├── src/
│   ├── CMakeLists.txt          ← nouveau
│   ├── config.hpp.in           ← nouveau (gabarit)
│   ├── version.cpp             ← modifié
│   ├── regles.cpp
│   ├── saisie.cpp
│   └── calculs.cpp
├── app/
│   ├── CMakeLists.txt          ← nouveau
│   └── main.cpp                ← modifié
└── tests/

## Installation de la version Release :
    cmake --preset release
    cmake --build --preset release
    cmake --install build/release --prefix ~/.local
    ~/.local/bin/uin-campus --version 