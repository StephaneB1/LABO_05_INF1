#ifndef JEUX_DE_LA_VIE_H
#define JEUX_DE_LA_VIE_H

#include <vector>

const size_t HAUTEUR_TABLEAU = 10;
const size_t LARGEUR_TABLEAU = 11;

const std::vector<int> NAISSANCE = {3};
const std::vector<int> SURVIS = {2, 3};

/**
 * @brief Gère la simulation
 */
void simulation();

/**
 * @brief Permet de copier un tableau dans un autre
 * @param tableau1 : tableau cible
 * @param tableau2 : tableau copié
 * @param hauteur
 * @param largeur
 */
void copieTableau(bool tableau1[][LARGEUR_TABLEAU],bool tableau2[][LARGEUR_TABLEAU]);

void afficherTableau(const bool tableau[][LARGEUR_TABLEAU]);

bool etatFutur(bool tableau[][LARGEUR_TABLEAU],unsigned i,unsigned j);

unsigned occ(const bool tab[][LARGEUR_TABLEAU], size_t x, size_t y);

#endif /* JEUX_DE_LA_VIE_H */

