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

void afficherTableau(const std::vector<std::vector<bool>>& tableau);

bool etatFutur(const std::vector<std::vector<bool>>& tableau, unsigned i, unsigned j);

unsigned occ(const std::vector < std::vector<bool>>&tableau, unsigned x, unsigned y);

#endif /* JEUX_DE_LA_VIE_H */

