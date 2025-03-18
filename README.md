# So_Long
And thanks for all the fish!

## Check my demo

[![Watch me on YouTube](https://img.shields.io/badge/Watch_me_on_YouTube-ff0000?style=for-the-badge&logo=youtube&logoColor=white)](https://youtu.be/XLiG6d9VJvI?si=CMYbCpsLkb29LYys)

<p align="center">
  <img src="so_long_bonus.gif" alt="my demo" width="1000">
</p>

## Step 1 : how to start the project

### Step 1.1 : understand the subject

Ici, on parle de modeliser une map 2D dans une fentetre oou les murs sont representes par des "1", le sol par des "0", les collectibles par des "c", la sortie par un "E" et le joueur par un "P".
Sachant cela, on peut tout de suite commencer a creer une serie de map invalides qui permettront de coder un pasring assez solide, afin d'eviter tout probleme d'affichage ou encore pire... des "segmentations fault" (le programme lit dela de ce qu'il doit lire, cad, des valeurs aleatoires ou inexistantes).

### Step 1.2 : parsing

On peut commecer par verifier que le fichier dans lequel on va lire notre map est valide :
- extension du fichier correcte (termine par ".ber", comme le sujet l'indique)
- permission du fichier (= on a l'autorisation de l'ouvrir)
On peut ensuite lire le fichier afin de recuperer les donnees de la map avec ```readline()```:
- 1 joueur unique
- map uniquement entouree de mur "1"
- map rectangulaire
- aucun caractere autre que "1", "0", "C", "E" ou "P" dans la map
- 1 unique saut a la ligne par ligne "\n"
- 1 collectible minimum "C"
- 1 unique sortie "E"

## Step 2 : learn how to use the minilibx

En l'occurence ici, on utilise la minilix en tant que librairie pour afficher une fenetre en C.

### Step 2.1 : initialtion

```
mlx = mlx_init();
window = mlx_new_window(mlx, window_width * 48, window_height * 48, "So_Long");
```

### Step 2.2 : what we will need

A cote de cela, on a acces a une serie d'autres fonctionnalites liees a cette fentre. 
Par exemple : 
| Option  | Function  |
| --- | --- |
| pouvoir fermer cette fenetre via la croix | ```mlx_hook(game->win, 33, 0, function_who_kills_prog, game);```|
| inserer des images grace a la conversion des formats .xpm | ```mlx_xpm_file_to_image(mlx, "path_of_img", &img_width, &img_height);``` |
| placer l'image dans la fenetre | ```mlx_put_image_to_window(mlx, window, img, x_pixel_in_window, y_pixel_in_window);``` |

## Step 3 : put the map on the window

Ici, c'est assez simple, on parcours la map que l'on vient de recuperer et on affiche une certaine image pour chaque caractere de la map (```si map[i][j] == "1" {on affiche la texture correspondant au mur;}```, etc).

## Step 4 : we need to make this window a game

On a plus qu'a creer les fonctions permettant de deplacer le joueur. Le plus simple est de renvoyer le programme vers une fonction qui fait avancer le joueur a chaque fois que certaines touches du clavier sont pressees. Puis, selon la touche pressee, on modifie l'emplacement du "P" dans la map afin que la fonction qui affiche l'image (appele en continue via la mlx ```mlx_key_hook(window, function_who_put_imgs_in_window, struct_of_the_game);```, affiche cette fois le nouveau rendu. L'idee est la meme pour la recuperation des collectibles. Ainsi, lorsque le joueur "P" atteint la sortie "E", la partie se termine.

## Step 5 : why should we stop there ? let's do bonuses

### Step 5.1 : counter of movement on the window

Il suffit de creer une nouvelle image a affiche (en haut a gauche de la fenetre, par exemple) dans laquelle on va implement du texte grace a la fonction de la mlx ```mlx_string_put(mlx, window, x_pixel_in_windox, y_pixel_in_window, color_txt, "txt");```.

### Step 5.2 : enemy patrol

Au meme titre que lorsque le joueur atteint la sortie, le jeu se termine, s'il atteint un ennemi, le jeu s'arrete MAIS par une defaite.
Auquel cas, le parsing doit etre modifie pour ajouter l'option "N" (ou ce que tu prefere) pour lire un ennemi dans la map.

### Step 5.2 : sprite animation

On peut aisement imaginer que les ennemis vadrouillent en boucle dans la map grace a une fonction random (initialement non-autorise dans la partie mandatory du sujet MAIS ne vous faites pas avoir comme moi puisque le sujet precise : "You are allowed to use other functions to complete the bonus part as long as their use is justified during your evaluation. Be smart!").
