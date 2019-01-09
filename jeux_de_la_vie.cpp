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

void simulation() {

   vector < vector<bool>> tableauPresent = {
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
   };

   vector < vector<bool>> tableauFutur = tableauPresent;

   while (true) {
      //TODO fonction pour afficher tableauPresent
      afficherTableau(tableauPresent);
      cout << endl;

      for (unsigned i = 0; i < tableauPresent.size(); i++) {
         for (unsigned j = 0; j < tableauPresent[0].size(); j++) {
            tableauFutur[i][j] = etatFutur(tableauPresent, i, j); 
         }
      }
      //Ici utiliser la classe Vector nous simplifierait la tâche
      tableauPresent = tableauFutur;
      
      Sleep(1000);
   }
}

unsigned occ(const vector < vector<bool>>&tableau, size_t x, size_t y) {

   int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
   int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

   unsigned nb_cases_voisines = 0;
   int nx, ny;
   for (int i = 0; i < 8; ++i) {
      nx = x + dx[i];
      ny = y + dy[i];
      if (nx < tableau[0].size() && nx >= 0 && ny >= 0 && ny < tableau.size()) {
         if (tableau[ny][nx] == 1) {
            nb_cases_voisines++;
         }
      }
   }
   return nb_cases_voisines;
}

void afficherTableau(const vector < vector<bool>>&tableau) {
   for (size_t i = 0; i < tableau.size(); i++) {
      for (size_t j = 0; j < tableau[0].size(); j++) {
         cout << (tableau[i][j] ? " X " : " . ");
      }
      cout << endl;
   }
}

bool etatFutur(const vector < vector<bool>>&tableau, unsigned i, unsigned j) {
   unsigned occurences = occ(tableau, j, i);

   if (tableau[i][j] == 1) {
      return (occurences == 2 || occurences == 3) ? 1 : 0;
   } else {
      return (occurences == 3) ? 1 : 0;
   }
}
