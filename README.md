# AntSurvival
LP73 Project of Rousseaux Thibaut and Razafindratsima Gabriel
Fourmilière:
-Créée au centre (1 case?)
-Consommation de nourriture pour création de fourmis, survie des fourmis

Reine:
-Pont des oeufs
-Proba que la reine ponde une reine, + de chance si fourmilière est full
-Maturité de guerrière -> se barre avec quelques guerriers

Ouvrière:
-amenager fourmilière et s'ocupper des oeufs

Guerrière:
-Défendre la fourmilière
-Chercher nouriture
-Attaquer ennemi
-Attaquer fourmilière

Déplacement:
-Se déplacent en voyant les cellules adjacentes/aléatoirement, s'oriente vers nourriture et phéromones alliées. Evite les obstacles.*
-Dépose des phéromones. Phéromone déposée s'ajoute à phéromone existante(?)
-Visualiser les déplacements en mode texte

Phéromone:
-Temps d'expiration
-Est écrasée si une autre fourmis d'une autre fourmilière passe
-Ajoute temps d'expiration si fourmis de la meme fourmilière passe

Cycle de fourmis: Ouvrière en premier

Evolution du terrain:
-Création d'obstacles, nourriture

Map:
-Constitution aléatoire, taille (100x50), nouriture(500)/obstacle(1000)/vide avec fourmilière au centre, taux d'évap des phéromones (0.95).

