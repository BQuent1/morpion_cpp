# PROJET MORPION

Lorsque vous lancez le programme, il vous demande de choisir entre le mode 2 joueurs ou le mode solo. Vous entrez ensuite les noms et les symboles des participants.
Si vous avez choisi le mode solo (contre l'IA), vous devez également choisir le niveau de l'IA (simple ou un peu plus compliqué).
Le programme décide aléatoirement qui commence à jouer.

Les colonnes sont nommées de A à C et les lignes de 1 à 3. Pour jouer, il suffit de choisir la lettre de la colonne en majuscule, suivie du numéro de la ligne.
Les joueurs jouent chacun leur tour jusqu'à ce qu'il y ait un gagnant ou que le tableau soit plein. Dans ce dernier cas, la partie se termine par un match nul.


## Améliorations proposées

J'ai proposé une amélioration du mode de jeu en solo. Le programme examine chaque case vide pour déterminer si elle peut conduire à une victoire ou empêcher une défaite de l'IA.
Par exemple, si la case B1 est vide, le programme vérifie si les cases A1 et A3 ou B2 et B3 contiennent des symboles identiques.
Cela signifie soit que le joueur est sur le point de gagner, auquel cas l'IA doit jouer en B1, soit que l'IA a déjà placé des symboles dans ces cases et qu'elle doit jouer en B1 pour gagner.

Pour l'instant, le programme parcourt la grille dans l'ordre et coche les cases, ce qui peut entraîner des erreurs, comme dans cet exemple :

```
    A   B   C
1 | X |   | X
2 | o | o | X
3 |   | o | o
```

Ici, l'IA (symbole X) devrait jouer en B1, mais elle joue ainsi :

```
    A   B   C
1 | X |   | X
2 | o | o | X
3 | X | o | o
```

Elle a détecté qu'en A3, les cases B3 et C3 étaient pleines de symboles identiques. Elle a donc placé son symbole en A3, alors qu'elle aurait dû le mettre en B1 pour gagner immédiatement.
Ce problème de cohérence est encore en cours d'amélioration, avec des probabilités plus élevées d'être choisies si les symboles adjacents sont ceux de l'IA.

Si l'IA ne trouve aucune case cohérente avec les symboles adjacents, elle place simplement un symbole au hasard dans la grille, ce qui lui permet au moins de commencer la partie.

Le programme a été conçu et testé sur Windows.
Quentin BAUD
