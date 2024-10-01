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
    "./so_long maps/invalid/coin_after_exit.ber"
    "./so_long maps/invalid/no_access_exit.ber"
    "./so_long maps/invalid/not_access_coin.ber"
    "./so_long maps/invalid/not_rect_map.ber"
)

# Liste des outputs a avoir
right_out=(
    "The map contain at least 1 wrong character."
    "The map contain at least 1 wrong character."
    "The map contain too much '\\n'."
    "The map contain too much '\\n'."
    "The map contain too much '\\n'."
    "Too much exit detected."
    "Too much player detected."
    "No collectible detected."
    "No exit detected."
    "No player detected."
    "The map isn't surounded by walls or column empty."
    ""
    ""
    ""
    "The map isn't rectangular or line empty."
)

# Comparaison des sorties pour une map invalide
echo -e "${BLUE}-------------- Comparaison des sorties pour une map invalide ----------------------${NC}"
for i in "${!commands[@]}"; do
    cmd="${commands[$i]}"
    expected_output="${right_out[$i]}"

    echo -e "${YELLOW}Sortie de la commande :${NC} $cmd ${YELLOW}\n>>>>>>>>>>> doit être :${NC} $expected_output"

    # Exécuter la commande et capturer sa sortie
    output=$(eval "$cmd")

    # Comparer la sortie avec la valeur attendue
    if [[ "$output" == "$expected_output" ]]; then
        echo -e "${GREEN}======================> OK${NC}"
    else
        echo -e "${RED}======================> KO${NC}"
        echo -e "${RED}Sortie obtenue :\n${NC}$output"
    fi
done