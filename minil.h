#ifndef MINIL_INCLUS
/// fichier minil-green/minil.h (licence GPLv3+)
/// SPDX-License-Identifier: GPL-3.0-or-later
/// (C) copyright © Basile Starynkevitch 2026
/// par Basile STARYNKEVITCH, 92340 Bourg-la-Reine, France
/// courriel basile@starynkevitch.net
/// En France, sous licence CeCILL https://cecill.info/
#define MINIL_INCLUS
#define _GNU_SOURCE 1

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

/**
   La bibliothèque GNU libunistring www.gnu.org/software/libunistring/
   manipule convenablement les chaînes de caractères UTF8 (Unicode).
   Lire aussi https://fr.wikipedia.org/wiki/UTF-8
**/
#include <unitypes.h>
#include <unistr.h>

extern const unsigned mi_tableau_premiers[];

/// renvoie un nombre premier supérieur à l'argument (ou 0 en échec):
extern unsigned mi_premier_apres(unsigned);

/// donne le n-ième argument de programme
extern const char* mi_arg_prog_n(int n);
/// donne le nombre d'arguments de programme
extern int mi_prog_compte_arg(void);

#endif /*MINIL_INCLUS */
