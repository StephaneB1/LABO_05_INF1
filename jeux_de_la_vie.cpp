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

unsigned occ(const bool tab[][LARGEUR_TABLEAU], size_t x, size_t y);

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
            tableauFutur[i][j] = 0; //TODO la fonction qui me dit quoi mettre dans le tableauFutur
         }
      }
      //Ici utiliser la classe Vector nous simplifierait la tâche
      copieTableau(tableauPresent, tableauFutur, HAUTEUR_TABLEAU, LARGEUR_TABLEAU);
   }
}

const unsigned VIE = 3; //TODO intervalle

unsigned occ(const bool tab[][LARGEUR_TABLEAU], size_t x, size_t y) {

   int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
   int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

   unsigned nb_cases_voisines = 0;
   int nx, ny;
   for (int i = 0; i < 8; ++i) {
      nx = x + dx[i];
      ny = y + dy[i];
      if (nx < LARGEUR_TABLEAU && nx >= 0 && ny >= 0 && ny < HAUTEUR_TABLEAU) {
         if (tab[ny][nx] == 1) {
            nb_cases_voisines++;
         }
      }
   }
   return nb_cases_voisines;
}

void afficherTableau(const bool tableau[][LARGEUR_TABLEAU]) {
   for (size_t i = 0; i < HAUTEUR_TABLEAU; i++) {
      for (size_t j = 0; j < LARGEUR_TABLEAU; j++) {
         cout << (tableau[i][j] ? " X " : " . ");
      }
      cout << endl;
   }
}

void copieTableau(bool tableau1[][LARGEUR_TABLEAU], bool tableau2[][LARGEUR_TABLEAU], unsigned hauteur, unsigned largeur) {

   for (unsigned i = 0; i < hauteur; i++) {
      for (unsigned j = 0; j < largeur; j++) {
         tableau1[i][j] = tableau2[i][j];
      }
   }
}
