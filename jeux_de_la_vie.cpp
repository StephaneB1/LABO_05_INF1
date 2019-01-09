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
      for (unsigned i = 0; i < HAUTEUR_TABLEAU; i++) { //petit affichage de tableau utilisé pour tests
         for (unsigned j = 0; j < LARGEUR_TABLEAU; j++) {
            cout << tableauPresent[i][j];
         }
         cout << endl;
      }

      for (unsigned i = 0; i < HAUTEUR_TABLEAU; i++) {
         for (unsigned j = 0; j < LARGEUR_TABLEAU; j++) {
            tableauFutur[i][j] = 0; //TODO la fonction qui me dit quoi mettre dans le tableauFutur
         }
      }
      //Ici utiliser la classe Vector nous simplifierait la tâche
      copieTableau(tableauPresent, tableauFutur, HAUTEUR_TABLEAU, LARGEUR_TABLEAU);
   }
}

void copieTableau(bool tableau1[][LARGEUR_TABLEAU], bool tableau2[][LARGEUR_TABLEAU], unsigned hauteur, unsigned largeur) {

   for (unsigned i = 0; i < hauteur; i++) {
      for (unsigned j = 0; j < largeur; j++) {
         tableau1[i][j] = tableau2[i][j];
      }
   }
}
