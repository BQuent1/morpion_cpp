# PROJET MORPION

Lorsque vous lancer le programme, il vous demande de choisir entre le mode 2 joueurs ou solo. Vous entrez ensuite les noms et symboles des ou du participants.
Si vous avez choisi le mode solo (contre l'IA), vous devez également choisir le niveau de l'IA (simple ou un peu plus compliqué).
Le programme décide aléatoirement de la personne qui commence à jouer.

J'ai nommer les colonnes de A à C et les lignes de 1 à 3. Pour jouer il suffit de choisir la lettre de la colonne en majuscule puis le numéro de la ligne.
Vous jouez chacun votre tour jusqu'à ce qu'il y ait un gagnant ou que le tableau soit plein, dans ce cas il y a match nul.


## Améliorations proposées

J'ai proposé une amélioration du mode de jeu en solo. Le programme regarde en fait pour chaque case vide, quelle sont les cases dépendantes qui permettrait d'arriver à la victoire ou alors à la défaite de l'IA.
Je m'explique, si par exemple la case B1 est vide, alors le programme pourrait définir de mettre son symbole ici. 
Pour décider, je vais regarder si les cases A1 et A3 ou B2 et B3 sont pleines de symboles identiques. 
Cela voudrait dire soit que le joueur est en train de gagner et donc qu'il faut mettre un symbole à cet endroit, soit que l'IA a déjà placer des symboles dans ces cases et que donc il faut placer un symbole dans la case actuelle pour gagner.

Pour l'instant le programme parcoure la grille dans l'ordre et regarde les cases à cocher, ce qui peut mener à quelques 'erreurs' comme dans ce cas :

    A   B   C\
1 | X |   | X\
2 | o | o | X\
3 |   | o | o\

Ici l'IA (symbole X) doit jouer en B1 mais voilà ce qu'elle fait :

    A   B   C\
1 | X |   | X\
2 | o | o | X\
3 | X | o | o\

Elle a détecté en A3 que les cases B3 et C3 était pleine de symbole identique donc elle a placer son symbole en A3 mais elle aurait du le mettre en B1 afin de gagner directemenent.
Ce petit problème de cohérence est encore en cours d'amélioration avec des probabilités plus grande d'être choisi si les symboles adjacents sont ceux de l'IA.

Si l'IA ne trouve pas de cohérence avec les cases adjacente, elle place simplement un symbole au hasard dans la grille, ce qui lui permet quand même de commencer la partie.



Le programme a été conçu et testé sur Windows.
