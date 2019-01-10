/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05
 Fichier     : jeux_de_la_vie.cpp
 Auteur(s)   : BOUSBAA Eric, BOTTIN Stéphane, FERRARI Teo
 Date        : 10.01.2019

 But         : 

 Remarque(s) : - Les valeurs définissant si une cellule doit naître ou survivre sont 
                 défini dans des listes constantes. Chaque valeur de la liste représente
                 une condition à laquelle la règle associé est valide.
               - Afin de modifier la configuration initiale du tableau de base, 
                 il suffit de placer un 1 dans toute cellule voulant être initialement
                 habitée.
               - La taille du tableau initial peut être changé en ajoutant/supprimant
                 les lignes/colonnes dans son initialisation.
               - Toutes les altération d'une génération de cellules à une autre 
                 s'effectuent simultanément. Càd qu'il n'y a pas d'ordre de priorité entre
                 vivre et mourir.

 Compilateur : - Apple LLVM version 9.0.0 (clang-900.0.39.2)
               - MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "jeux_de_la_vie.h"

using namespace std;

const char CARACTERE_VIE = 'X';
const char CARACTERE_MORT = '.';

/**
 * @brief Affiche le tableau représentant le jeu de la vie en utilisant des 
 * charactères pour représenter les états de vie et de mort des cellules
 * @param tableau : tableau booleen a afficher
 * @param caractereVie : caraectere representant un cellule
 * @param caractereMort : caraectere representant un abscence de cellule
 */
void afficherTableau(const vector<vector<bool>>&tableau, char caractereVie, char caractereMort);

/**
 * @brief fonction qui retourne l'état futur d'une case specifique du tableau 
 * representant le jeu de la vie
 * @param tableau : tableau booleen representant le jeu de la vie
 * @param i : position verticale de la case a tester
 * @param j : position horizontale de la case a tester
 * @return : l'etat dans lequel devrait etre la case par rapport au cases l'entourant
 */
bool etatFutur(const vector<vector<bool>>&tableau, unsigned i, unsigned j);

/**
 * @brief fonction verifiant les occurences de cellules autour d'une cellule donnee
 * @param tableau : tableau booleen representant le jeu de la vie
 * @param x : position horizontale de la case a tester
 * @param y : position verticale de la case a tester
 * @return le nombre d'occurences de cellules autour de la cellule donnee
 */
unsigned occ(const vector < vector<bool>>&tableau, unsigned x, unsigned y);

/**
 * @brief verifies qu'une valeur est dans un interval donne
 * @param V : interval dans lequel on teste 
 * @param val : valeur a trouver dans l'interval
 * @return si la valeur se trouve dans l'interval ou non
 */
bool estDansIntervalle(const vector<unsigned> &V, const unsigned val);

const unsigned NOMBRE_CASES_VOISINES = 8;

void simulation(unsigned nombreSimulations) {

   vector < vector<bool>> tableauPresent = {
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
   };

   vector < vector<bool>> tableauFutur(tableauPresent.size(),
           vector<bool>(tableauPresent[0].size()));

   for (unsigned n = 1; n <= nombreSimulations; ++n) {

      cout << "Generation : " << n << endl;
      afficherTableau(tableauPresent, CARACTERE_VIE, CARACTERE_MORT);
      cout << endl;

      for (unsigned i = 0; i < tableauPresent.size(); ++i) {
         for (unsigned j = 0; j < tableauPresent[0].size(); ++j) {
            tableauFutur[i][j] = etatFutur(tableauPresent, i, j);
         }
      }
      tableauPresent = tableauFutur;
   }
}

unsigned occ(const vector < vector<bool>>&tableau, unsigned x, unsigned y) {
   unsigned nb_cases_voisines = 0;
   int positionAbsolueX, postitionAbsolueY;
   int positionRelativeX[NOMBRE_CASES_VOISINES] = {1, -1, 0, 0, 1, 1, -1, -1};
   int positionRelativeY[NOMBRE_CASES_VOISINES] = {0, 0, 1, -1, 1, -1, 1, -1};

   for (int i = 0; i < (int) NOMBRE_CASES_VOISINES; ++i) {
      positionAbsolueX = (int) x + positionRelativeX[i];
      postitionAbsolueY = (int) y + positionRelativeY[i];
      if (positionAbsolueX < (int) tableau[0].size() && positionAbsolueX >= 0 &&
              postitionAbsolueY >= 0 && postitionAbsolueY < (int) tableau.size()) {
         if (tableau[(size_t) postitionAbsolueY][(size_t) positionAbsolueX] == 1) {
            nb_cases_voisines++;
         }
      }
   }
   return nb_cases_voisines;
}

void afficherTableau(const vector < vector<bool>>&tableau, char caractereVie,
        char caractereMort) {
   for (size_t i = 0; i < tableau.size(); ++i) {
      for (size_t j = 0; j < tableau[0].size(); ++j) {
         cout << " " << (tableau[i][j] ? caractereVie : caractereMort) << " ";
      }
      cout << endl;
   }
}

bool estDansIntervalle(const vector<unsigned> &V, const unsigned val) {
   for (auto i = V.begin(); i != V.end(); ++i) {
      if (val == *i) {
         return true;
      }
   }
   return false;
}

bool etatFutur(const vector < vector<bool>>&tableau, unsigned i, unsigned j) {
   unsigned occurences = occ(tableau, j, i);
   if (tableau[i][j]) {
      return estDansIntervalle(REGLE_NAISSANCE, occurences) ||
              estDansIntervalle(REGLE_SURVIS, occurences) ? 1 : 0;
   } else {
      return estDansIntervalle(REGLE_NAISSANCE, occurences) ? 1 : 0;
   }
}
