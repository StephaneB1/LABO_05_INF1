/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05
 Fichier     : main.cpp
 Auteur(s)   : <prÈnom> <nom>
 Date        : <jj.mm.aaaa>

 But         : <à competer>

 Remarque(s) : <à completer>

 Compilateur : MinGW-g++ <x.y.z>
 -----------------------------------------------------------------------------------
 */

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "jeux_de_la_vie.h"

using namespace std;

void simulation() {

   bool tableauPresent[][10] = {
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
      {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
   };

   bool tableauFutur[HAUTEUR_TABLEAU][LARGEUR_TABLEAU];

   while (true) {
      //TODO fonction pour afficher tableauPresent
      afficherTableau(tableauPresent);
      cout << endl;

      for (unsigned i = 0; i < HAUTEUR_TABLEAU; i++) {
         for (unsigned j = 0; j < LARGEUR_TABLEAU; j++) {
            tableauFutur[i][j] = etatFutur(tableauPresent, i, j); //TODO la fonction qui me dit quoi mettre dans le tableauFutur
         }
      }
      //Ici utiliser la classe Vector nous simplifierait la tâche
      copieTableau(tableauPresent, tableauFutur);
   }
}

unsigned occ(bool tableau[][LARGEUR_TABLEAU], unsigned x, unsigned y) {

   unsigned colonnesVoisines = (y == 0 || y == LARGEUR_TABLEAU - 1) ? 2 : 3;
   unsigned lignesVoisines = (x == 0 || x == HAUTEUR_TABLEAU - 1) ? 2 : 3;
   unsigned occurences = 0;

   unsigned startX = x - 1;
   if (x <= 0) {
      startX = 0;
   } else if (x >= LARGEUR_TABLEAU) {
      startX = LARGEUR_TABLEAU - 2;
   }

   unsigned startY = y - 1;
   if (y <= 0) {
      startY = 0;
   } else if (y >= HAUTEUR_TABLEAU) {
      startY = HAUTEUR_TABLEAU - 1;
   }

   for (unsigned col = startY; col < startY + colonnesVoisines; col++) {
      for (unsigned lig = startX; lig < startX + lignesVoisines; lig++) {
         if (tableau[col][lig] && !(lig == x && col == y)) {
            occurences++;
         }
      }
   }
   cout << occurences<< " ";
   return occurences;
}

void afficherTableau(const bool tableau[][LARGEUR_TABLEAU]) {
   for (size_t i = 0; i < HAUTEUR_TABLEAU; i++) {
      for (size_t j = 0; j < LARGEUR_TABLEAU; j++) {
         cout << (tableau[i][j] ? " X " : " . ");
      }
      cout << endl;
   }
}

bool etatFutur(bool tableau[][LARGEUR_TABLEAU], unsigned i, unsigned j) {
   unsigned occurences = occ(tableau, j,i);

   if (tableau[i][j]==1) {
      return (occurences == 2 || occurences == 3) ? 1 : 0;
   } else {
      return (occurences == 3) ? 1 : 0;
   }
}

void copieTableau(bool tableau1[][LARGEUR_TABLEAU], bool tableau2[][LARGEUR_TABLEAU]) {

   for (unsigned i = 0; i < HAUTEUR_TABLEAU; i++) {
      for (unsigned j = 0; j < LARGEUR_TABLEAU; j++) {
         tableau1[i][j] = tableau2[i][j];
      }
   }
}
