#ifndef JEUX_DE_LA_VIE_H
#define JEUX_DE_LA_VIE_H

#include <vector>

// Nombres de cellule voisines menant à la naissance d'une cellulle jusque là inhabitée
const std::vector<unsigned> REGLE_NAISSANCE = {3};
// Nombres de cellules voisine qu'une cellule habitée doit avoir pour survivre
const std::vector<unsigned> REGLE_SURVIS = {2, 3};

/**
 * @brief Lance les simulation du jeux de la vie.
 * @param nombreSimulations : nombre de générations à afficher
 */
void simulation(unsigned nombreSimulations);

#endif /* JEUX_DE_LA_VIE_H */

