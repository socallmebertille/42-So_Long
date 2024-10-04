#!/bin/bash

# Couleurs pour un affichage visuel amélioré
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
NC='\033[0m' # Pas de couleur

# Liste des commandes à tester
commands=(
    "./so_long maps/invalid/not_good_char.ber"
    "./so_long maps/invalid/empty_col_1.ber"
    "./so_long maps/invalid/empty_line_1.ber"
    "./so_long maps/invalid/empty_line_2.ber"
    "./so_long maps/invalid/empty_line_3.ber"
    "./so_long maps/invalid/mult_exit.ber"
    "./so_long maps/invalid/mult_play.ber"
    "./so_long maps/invalid/no_coin.ber"
    "./so_long maps/invalid/no_exit.ber"
    "./so_long maps/invalid/no_play.ber"
    "./so_long maps/invalid/no_wall.ber"
    "./so_long maps/invalid/no_access_exit.ber"
    "./so_long maps/invalid/not_access_coin.ber"
    "./so_long maps/invalid/not_rect_map.ber"
    "./so_long maps/invalid/coin_after_exit.ber"
    "./so_long maps/invalid/folder.ber"
)

# Liste des outputs a avoir
right_out=(
    "Error\nThe map contain at least 1 wrong character."
    "Error\nThe map contain at least 1 wrong character."
    "Error\nThe map contain too much '\\n'."
    "Error\nThe map contain too much '\\n'."
    "Error\nThe map contain too much '\\n'."
    "Error\nToo much exit detected."
    "Error\nToo much player detected."
    "Error\nNo collectible detected."
    "Error\nNo exit detected."
    "Error\nNo player detected."
    "Error\nThe map isn't surounded by walls or column empty."
    "Error\nWe can't access exit."
    "Error\nWe can't access all collectibles."
    "Error\nThe map isn't rectangular or line empty."
    "Error\nWe can't access all collectibles."
    "Error\nThere is an issue while reading the map."
)

# Comparaison des sorties pour une map invalide
echo -e "${BLUE}-------------- Comparaison des sorties pour une map invalide ----------------------${NC}"
echo -e
for i in "${!commands[@]}"; do
    cmd="${commands[$i]}"
    expected_output="${right_out[$i]}"

    echo -e "${BLUE}($i)${NC}${YELLOW} Output of :${NC} $cmd ${YELLOW}\n>>>>>>>>>>> should be :${NC} $expected_output"

    # Exécuter la commande et capturer sa sortie dans une variable et un fichier
    output=$(eval "$cmd")
    echo "$output" > out.txt

    # Remplacer les retours à la ligne réels par une représentation explicite '\n'
    clean_output=$(echo "$output" | sed ':a;N;$!ba;s/\n/\\n/g')
    clean_expected=$(echo "$expected_output" | sed ':a;N;$!ba;s/\n/\\n/g')

    # Comparer les sorties nettoyées
    if [[ "$clean_output" == "$clean_expected" ]]; then
        echo -e "${GREEN}======================> OK${NC}"
    else
        echo -e "${RED}======================> KO${NC}"
        echo -e "${RED}Sortie obtenue :${NC} $output"
        echo -e "${RED}Différences après normalisation :${NC}"
        echo -e "$clean_output" | cat -e # Afficher avec des symboles pour les caractères invisibles
        echo -e "$clean_expected" | cat -e # Afficher avec des symboles pour les caractères invisibles
    fi
    echo -e
done

# Tests avec valgrind uniquement pour ton programme
echo -e "${BLUE}-------------- valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes ----------------------${NC}"
echo -e

# Fichier temporaire pour stocker la sortie de Valgrind
temp_file=$(mktemp)

for i in "${!commands[@]}"; do
    cmd="${commands[$i]}"
    valgrind_cmd="valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes $cmd"
    echo -e "${BLUE}($i)${NC}${YELLOW} Valgrind :${NC} $cmd"

    # Exécuter Valgrind et rediriger la sortie vers un fichier temporaire
    eval "$valgrind_cmd" &> "$temp_file"

    # Afficher la sortie complète de Valgrind
    # echo -e "${BLUE}------------ Sortie complète de Valgrind ------------${NC}"
    # cat "$temp_file"

    # Chercher la ligne "total heap usage"
    heap_usage=$(grep "total heap usage:" "$temp_file")

    echo -e "${GREEN}Total heap usage :${NC} $heap_usage"

    # Si aucune ligne n'est trouvée, afficher un message clair
    if [[ -z "$heap_usage" ]]; then
        echo -e "${RED}Erreur : Impossible de trouver 'total heap usage' dans la sortie de Valgrind.${NC}"
    fi
    echo -e
done

# Supprimer le fichier temporaire
rm -f "$temp_file" out.txt