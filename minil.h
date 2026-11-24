#ifndef MINIL_INCLUS
/// fichier minil-green/minil.h (licence GPLv3+ ou CeCILL)
/// SPDX-License-Identifier: GPL-3.0-or-later
/// (C) copyright © Basile Starynkevitch 2026
/// par Basile STARYNKEVITCH, 92340 Bourg-la-Reine, France
/// courriel basile@starynkevitch.net
/// En France, aussi sous licence CeCILL https://cecill.info/
/// Voir aussi https://cppreference.com/c
/// par Basile STARYNKEVITCH, sous licence libre logicielle GPLv3+ ou CeCILL
/// pour la licence GPLv3+ voir https://www.gnu.org/licenses/gpl-3.0.fr.html
/// pour la licence CeCILL voir https://cecill.info/index.fr.html
#define MINIL_INCLUS

/// pour utiliser les extensions GNU
#define _GNU_SOURCE 1

#include <stdio.h>		/* entrée sortie standard */
#include <stdlib.h>		/* utilitaires standard divers */

/// La bibliothèque GNU readline permet d'éditer et d'auto completer
/// une ligne de commande....  Elle est utilisée par zsh.org et GNU bash
/// GNU readline pour une ligne de commande
/// éditable, voir https://fr.wikipedia.org/wiki/GNU_Readline
/// et www-ppti.ufr-info-p6.jussieu.fr/doc-online/PHP/html/book.readline.html
/// et https://github.com/gnu-mirror-unofficial/readline
/// £ GNU readline
#include <readline/readline.h>

/**
   La bibliothèque GNU libunistring www.gnu.org/software/libunistring/
   manipule convenablement les chaînes de caractères UTF8 (Unicode)
   dont certains (comme É ou § ....) nécessitent plusieurs octets pour
   un seul caractère affichable.  Lire aussi
   https://fr.wikipedia.org/wiki/UTF-8
**/
#include <unitypes.h>
#include <unistr.h>
#include <unictype.h>


/// un tableau de nombres premiers croissants et terminé par 0
extern const unsigned mi_tableau_premiers[];

/// [dans main.c:] renvoie un nombre premier supérieur à l'argument
/// (ou 0 en échec):
extern unsigned mi_premier_apres (unsigned);

/// [dans util.c:] recherche dans une chaîne de caractères encodée
/// UTF8 un caractère (multi-octets) bizarre ou non-imprimable (dont
/// la tabulation), et renvoie sa position en octets, ou négatif si
/// rien n'est trouvé
extern int mi_position_caractere_bizarre (const char*);

/// donne le n-ième argument de programme
extern const char *mi_arg_prog_n (int n);
/// donne le nombre d'arguments de programme
extern int mi_prog_compte_arg (void);

#endif /*MINIL_INCLUS */
