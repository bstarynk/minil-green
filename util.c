/// fichier minil-green/util.c
/// SPDX-License-Identifier: GPL-3.0-or-later
/// (C) copyright © Basile Starynkevitch <basile@starynkevitch.net> 2026
/// par Basile STARYNKEVITCH, sous licence libre logicielle GPLv3+ ou CeCILL
/// pour la licence GPLv3+ voir https://www.gnu.org/licenses/gpl-3.0.fr.html
/// pour la licence CeCILL voir https://cecill.info/index.fr.html



#include "minil.h"

/// renvoie la position d'un caractère UTF8 bizarre non impriable;
/// bien noter que sous l'encodage UTF8 un caractère (dont µ ou É)
/// peut occuper plusieur octets.

/// à lire: Wikipedia: https://fr.wikipedia.org/wiki/UTF-8
/// à lire: https://www.gnu.org/software/libunistring/
int
mi_position_caractere_bizarre (const char *ch)
{
  int l= 0;
  if (!ch)
    return -1;
  const char*p = (ch);
  const char*s = NULL;          /* le suivant en UTF8 */
  // Un caractère UTF8 s'encode en au plus 4 octets, et l'octet nul
  // indique la fin de la chaine...
  for (const char*p = ch; *p; p=s)
    {
      ucs4_t u=0;
      l=0;
      for (const char*q = p; q<p+4 && q; q++)
        {
          l++;
        };
      // l contient maintenant la longueur en octets du caractère UTF8 courant en p
      if (l==0)
        s = NULL;
      else
        s = p+l;
      l = u8_mbtouc(&u, (const uint8_t*)p, (size_t)l);
      if (uc_is_general_category_withtable(u,
                                           UC_CATEGORY_MASK_Cs
                                           | UC_CATEGORY_MASK_Co
                                           | UC_CATEGORY_MASK_Cn
                                           | UC_CATEGORY_MASK_M
                                           | UC_CATEGORY_MASK_Mn
                                           | UC_CATEGORY_MASK_Mc
                                           | UC_CATEGORY_MASK_Cc
                                           | UC_CATEGORY_MASK_Cf
                                           | UC_CATEGORY_MASK_Cs
                                           | UC_CATEGORY_MASK_Co
                                           | UC_CATEGORY_MASK_Cn))
        return (int)(p - ch);
    }
  return -1;
}                               /* fin mi_position_caractere_bizarre */


/**** fin du fichier mini-green/util.c ********/
