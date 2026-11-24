/// fichier minil-green/util.c
/// SPDX-License-Identifier: GPL-3.0-or-later
/// (C) copyright © Basile Starynkevitch <basile@starynkevitch.net> 2026
/// par Basile STARYNKEVITCH, sous licence libre logicielle GPLv3+ ou CeCILL
/// pour la licence GPLv3+ voir https://www.gnu.org/licenses/gpl-3.0.fr.html
/// pour la licence CeCILL voir https://cecill.info/index.fr.html



#include "minil.h"

/// renvoie la position d'un caractère UTF8 bizarre
int
mi_position_caractere_bizarre (const char *ch)
{
  if (!ch)
    return -1;
#warning mi_position_caractere_bizarre incomplet
  /* comme la fonction n'est pas codée on arrête le traitement brutalement: */
  abort ();
}				/* fin mi_position_caractere_bizarre */


/**** fin du fichier mini-green/util.c ********/
