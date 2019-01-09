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
#include "jeux_de_la_vie.h"

using namespace std;

void afficherTableau(const vector<vector<bool>>& tableau);

bool etatFutur(const std::vector<vector<bool>>& tableau, unsigned i, unsigned j);

unsigned occ(const vector < std::vector<bool>>&tableau, unsigned x, unsigned y);

bool contains(vector<int> const &V, const int &x);

const unsigned NOMBRE_CASES_VOISINES = 8;

void simulation(unsigned nombreSimulations) {
   
   vector <vector<bool>> tableauPresent = {
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

   vector <vector<bool>> tableauFutur(tableauPresent.size(), vector<bool>(tableauPresent[0].size()));

   for (unsigned n = 1; n <= nombreSimulations; n++) {
      //TODO fonction pour afficher tableauPresent
      cout << "Génération : " << n << endl;
      afficherTableau(tableauPresent);
      cout << endl;

      for (unsigned i = 0; i < tableauPresent.size(); i++) {
         for (unsigned j = 0; j < tableauPresent[0].size(); j++) {
            tableauFutur[i][j] = etatFutur(tableauPresent, i, j);
         }
      }
      //Ici utiliser la classe Vector nous simplifierait la tâche
      tableauPresent = tableauFutur;
   }
}

unsigned occ(const vector < vector<bool>>&tableau, unsigned x, unsigned y){
   unsigned nb_cases_voisines = 0;
   int nx, ny;
   int dx[8] = {1, -1, 0,  0, 1,  1, -1, -1};
   int dy[8] = {0,  0, 1, -1, 1, -1,  1, -1};
   
   for(int i = 0; i < (int) NOMBRE_CASES_VOISINES; ++i){
      nx = (int) x + dx[i];
      ny = (int) y + dy[i];
      if (nx < (int) tableau[0].size() && nx >= 0 && ny >= 0 && ny < (int) tableau.size()) {
         if (tableau[(size_t)ny][(size_t)nx] == 1) {
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

bool estDansIntervalle(const vector<unsigned> &V, const unsigned val){
   for(auto i = V.begin(); i != V.end(); ++i){
      if(val == *i){
         return true;
      }
   }
   return false;
}

bool etatFutur(const vector < vector<bool>>&tableau, unsigned i, unsigned j) {
   unsigned occurences = occ(tableau, j,i);
   if (tableau[i][j]) {
      return estDansIntervalle(REGLE_NAISSANCE, occurences) || 
             estDansIntervalle(REGLE_SURVIS, occurences) ? 1 : 0 ;
      
   } else {
      return estDansIntervalle(REGLE_NAISSANCE, occurences) ? 1 : 0;
 
   }
}
