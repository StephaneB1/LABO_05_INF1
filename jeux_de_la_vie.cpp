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
#include <vector>
#include <windows.h>
#include "jeux_de_la_vie.h"

using namespace std;

unsigned occ(const bool tab[][LARGEUR_TABLEAU], size_t x, size_t y);
bool etatFutur(const bool tab[][LARGEUR_TABLEAU], size_t x, size_t y);
bool contains(vector<int> const &V, const int &x);

void simulation() {

   bool tableauPresent[][LARGEUR_TABLEAU] = {
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
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
      Sleep(1000);
   }
}
const vector<int> NAISSANCE = {3};
const vector<int> SURVIS = {2};


bool estDansIntervalle(const vector<int> &V, const int val){
   return (val >= vector.begin() and val <= vector.end());
}

unsigned occ(const bool tab[][LARGEUR_TABLEAU], size_t x, size_t y){
   unsigned nb_cases_voisines = 0;
   int nx, ny;
   int dx[8] = {1, -1, 0,  0, 1,  1, -1, -1};
   int dy[8] = {0,  0, 1, -1, 1, -1,  1, -1};
   
   for(int i = 0; i < 8; ++i){
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
