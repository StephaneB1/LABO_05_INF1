#ifndef JEUX_DE_LA_VIE_H
#define JEUX_DE_LA_VIE_H

#include <vector>

const std::vector<unsigned> REGLE_NAISSANCE = {3};
const std::vector<unsigned> REGLE_SURVIS = {2, 3};

/**
 * @brief Gère la simulation
 */
void simulation(unsigned nombreSimulations);

#endif /* JEUX_DE_LA_VIE_H */

