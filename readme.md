# UIN-Campus
Systeme de gestion academique de l'UIN (projet fil rouge C++23).
## Versions des outils
 g++ 15.2.0- clang++ 21.1.8- cmake 4.2.3- ninja 1.13.2- gdb 17.1- git 2.53.0
## Construire et executer
    cmake --preset debug
    cmake --build --preset debug
    ./build/debug/uin-campus
Le preset debug active AddressSanitizer et UBSan.
## Options de la ligne de commande
    ./build/debug/uin-campus --version
    ./build/debug/uin-campus --aide
Une option inconnue affiche l'aide sur la sortie d'erreur et renvoie le code 1.
## Resultat attendu
 Le programme demande le nom d'un etudiant, ses notes et leurs coefficients, puis affiche son releve. 
 Exemple avec trois UE (notes 12, 14.5 et 16, coefficients 2, 3 et 1) :
    Etudiant                      Aminata Moussa
    Moyenne ponderee                       13.92
    Moyenne simple                         14.17
    Note min / max                 12.00 / 16.00
    Ecart-type                              1.65
    UE validees                            3 / 3
    Mention                           Assez bien

## Choix de conception
 Les fonctions de calcul recoivent des std::span : elles acceptent un vector, un array ou une partie de tableau, sans copie.- Les seuils des mentions sont un std::array constexpr verifie par static_assert.- Les arguments de la ligne de commande sont lus a travers un std::span.
## Qualite du code- Avertissements stricts :
 -Wall -Wextra -Wpedantic -Wshadow -Wconversion- Style : clang-format (fichier .clang-format)- Analyse : clang-tidy (fichier .clang-tidy)