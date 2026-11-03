#!/bin/sh
{
echo "# UIN-Campus"
echo "Systeme de gestion academique de l'UIN (projet fil rouge C++23)."
echo
echo "## Versions des outils"
echo "- g++ $(g++ --version | head -1 | awk '{print $NF}')"
echo "- clang++ $(clang++ --version | head -1 | awk '{print $4}')"
echo "- cmake $(cmake --version | head -1 | awk '{print $3}')"
echo "- ninja $(ninja --version)"
echo "- gdb $(gdb --version | head -1 | awk '{print $NF}')"
echo "- git $(git --version | awk '{print $3}')"
echo
echo "## Construire"
echo '```'
echo "cmake --preset debug"
echo "cmake --build --preset debug"
echo "./build/debug/uin-campus"
echo '```'
echo
echo "## Historique"
git log --oneline | sed 's/^/- /'
} > README.md
