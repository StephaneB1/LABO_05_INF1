/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05
 Fichier     : main.cpp
 Auteur(s)   : BOUSBAA Eric, BOTTIN Stéphane, FERRARI Teo
 Date        : 10.01.2019

 But         : Ce programme a pour but de modéliser une grille régulières de cellules
               contenant un état si cette dernière est habitée ou non. Chaque cellule
               survis à une génération si celle-ci est entourée de X cellules voisines
               habitées. Dans le cas contraire, la cellule disparait à la génération 
               suivante. Une cellule peut "naître" si celle-ci est la voisine de Y
               cellules habitées à la génération suivante.
               Pour un nombre N de générations donnés, les cellules de la grille vont
               évoluer (c-à-d être habitées, disparaitre ou naître) N fois.
               Le programme est insipiré du jeux de la vie, inventé par J.H. Conway.        
      
 Remarque(s) : - Les cellules considérés comme voisines sont celles situés en haut/bas,
                 à gauche/droite ainsi que celles situés dans les diagonales,
                 à l'exception des cellules situés aux extrêmirés de la grille.
               - Dans la représentation de la grille, 2 caractères sont représentés, 
                 l'un étant un cellule habitée et l'autre une cellule vide.      

 Compilateur : - Apple LLVM version 9.0.0 (clang-900.0.39.2)
               - MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/


#include <cstdlib>
#include <iostream>
#include "jeux_de_la_vie.h"

using namespace std;

int main() {
   const unsigned NOMBRE_GENERATIONS = 12;
   
   simulation(NOMBRE_GENERATIONS);
   cout << "Appuyez sur une touche pour continuer... ";
   cin.get();

   return EXIT_SUCCESS;
}

