#ifndef JEUX_DE_LA_VIE_H
#define JEUX_DE_LA_VIE_H

#include <vector>

/**
 * @brief Gère la simulation
 */
void simulation();

void afficherTableau(const std::vector<std::vector<bool>>& tableau);

bool etatFutur(const std::vector<std::vector<bool>>& tableau, unsigned i, unsigned j);

unsigned occ(const std::vector<std::vector<bool>>& tableau, size_t x, size_t y);

#endif /* JEUX_DE_LA_VIE_H */

