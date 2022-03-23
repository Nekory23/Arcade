# B-OOP-400-PAR-4-1-arcade-chloe.chauvin

[trello](https://trello.com/b/I5uZiBk4/arcade)

## DIMANCHE
Faire toutes les intefaces

Classe encapsulation libdl

## MERCREDI
début lib graphique

capable d'afficher des trucs en respectanr les intefaces et gérer les inputs 

core entièrement focntionelle

## VENDREDI
début 1er jeu et capable de load et de renvoyer la map fin de la 1ère lib graphique, début de la seconde

Core qui handle les jeux et qui est capable de switch de lib graphique

## DIMANCHE
valgrind nickel un peu de refactoring de code

## MERCREDI
fin du premier jeu (gerer les inputs + jouer)

find de la seconde lib graphique

## APRES
Faire et finir le deuxième jeux et la dernière lib graphique

# Structure

## LIBs graphiques supportées
    - ncurse
    - sfml
    - ld12

## jeux supportés
    - snake
    - pacman

## Lib graphiques :
-> Classe pour gerer tout ce qui est inputs et display avec
données :
    - sprite
    - textures
    - pixels
    - animations (clock...)
    - inputs
fonctions :
    - initTextures (ou équivalent) pour tout creer (map + sprites)
    - fonction pour tout display

## Core :
Core :
-> c'est vraiment ce qui va nous permettre de tout relier entre tout
-> travail de traductions des inputs pour gerer apres dans le jeu
-> vraiment un pont entre les autres parties...
-> au début il faut qu'on puisse envoyer les premieres infos (map) aux 2 autres parties pour gerer le début du display mais aussi la gestion des sprites (ou pas) 

Core class :
    - map
    - vector de map ou vector de class game (pour contenir les parties si on change de jeux)
    - fonction read config
    - call game et LibGraph
    - function pour gérer les input de l'utilisateur et l'envoyé ce qu'il faut a la class LibGraph et Game

SI INTERRACTION :
-> appeler l'update du jeu
-> appeler la lib graphique pour tous les display

-> au début on lit un fichier de config pour avoir la map et pouvoir la stocker (dans quoi a determiner (vector ?)) sinon on stocke toute la classe du jeu dedans pour pouvoir récup les états si on a besoin de le relancer ?
-> gestion des scores (pas encore tres claire donc a voir ensemble)

## Jeux :
-> Une classe qui va nous permettre de manage les états du jeu avec
  données :
    - la map
    - le joueur
    - les ennemis (si il y en a)
    - si on a gagné / perdu
  fonctions :
    - setGame / initGame : initialise un peut tout (display, sprite...) -> envoie tout au core pour pouvoir demander a la lib graph de gerer
    - startGame : pour lancer la boucle de jeu
    - draw : permet de faire le lien avec le core en lui envoyant quoi display pour qu'il l'envoie a la lib graph (draw -> Core -> Lib_graphique)
    - updateGame : prends en compte les nouveaux états...