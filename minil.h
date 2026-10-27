#ifndef MINIL_INCLUS
/// fichier minil-green/minil.h (licence GPLv3+)
/// par Basile STARYNKEVITCH, 92340 Bourg-la-Reine, France
#define MINIL_INCLUS
#define _GNU_SOURCE 1

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

extern const unsigned mi_tableau_premiers[];

/// renvoie un nombre premier supérieur à l'argument (ou 0 en échec):
extern unsigned mi_premier_apres(unsigned);
#endif /*MINIL_INCLUS */
