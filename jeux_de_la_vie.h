#ifndef JEUX_DE_LA_VIE_H
#define JEUX_DE_LA_VIE_H

const unsigned HAUTEUR_TABLEAU = 11;
const unsigned LARGEUR_TABLEAU = 10;

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
void copieTableau(bool tableau1[][LARGEUR_TABLEAU],bool tableau2[][LARGEUR_TABLEAU], unsigned hauteur, unsigned largeur);

void afficherTableau(const bool tableau[][LARGEUR_TABLEAU]);

#endif /* JEUX_DE_LA_VIE_H */

