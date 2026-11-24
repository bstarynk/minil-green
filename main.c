/// fichier minil-green/main.c
/// SPDX-License-Identifier: GPL-3.0-or-later
/// (C) copyright © Basile Starynkevitch <basile@starynkevitch.net> 2026
/// par Basile STARYNKEVITCH, sous licence libre logicielle GPLv3+ ou CeCILL
/// pour la licence GPLv3+ voir https://www.gnu.org/licenses/gpl-3.0.fr.html
/// pour la licence CeCILL voir https://cecill.info/index.fr.html



#include "minil.h"

// un tableau croissant de certains nombres premiers,
// obtenu par exemple avec
/***
     /usr/games/primes 3 $[1<<32] \
     | awk '($1>p+p/10){print $1, ","; p=$1}'
     | fmt | indent
***/
const unsigned mi_tableau_premiers[] =
{
  3, 5, 7, 11, 13, 17, 19, 23, 29, 37, 41, 47, 53, 59,
  67, 79, 89, 101, 113, 127, 149, 167, 191, 211, 233, 257,
  283, 313, 347, 383, 431, 479, 541, 599, 659, 727, 809, 907, 1009, 1117,
  1229, 1361, 1499, 1657, 1823, 2011, 2213, 2437, 2683, 2953, 3251, 3581,
  3943, 4339, 4783, 5273, 5801, 6389, 7039, 7753, 8537, 9391, 10331,
  11369, 12511, 13763, 15149, 16673, 18341, 20177, 22229, 24469, 26921,
  29629, 32603, 35869, 39461, 43411, 47777, 52561, 57829, 63617, 69991,
  76991, 84691, 93169, 102497, 112757, 124067, 136481, 150131, 165161,
  181693, 199873, 219871, 241861, 266051, 292661, 321947, 354143, 389561,
  428531, 471389, 518533, 570389, 627433, 690187, 759223, 835207, 918733,
  1010617, 1111687, 1222889, 1345207, 1479733, 1627723, 1790501, 1969567,
  2166529, 2383219, 2621551, 2883733, 3172123, 3489347, 3838283, 4222117,
  4644329, 5108767, 5619667, 6181639, 6799811, 7479803, 8227787, 9050599,
  9955697, 10951273, 12046403, 13251047, 14576161, 16033799, 17637203,
  19400929, 21341053, 23475161, 25822679, 28404989, 31245491, 34370053,
  37807061, 41587807, 45746593, 50321261, 55353391, 60888739, 66977621,
  73675391, 81042947, 89147249, 98061979, 107868203, 118655027, 130520531,
  143572609, 157929907, 173722907, 191095213, 210204763, 231225257,
  254347801, 279782593, 307760897, 338536987, 372390691, 409629809,
  450592801, 495652109, 545217341, 599739083, 659713007, 725684317,
  798252779, 878078057, 965885863, 1062474559, 1168722059, 1285594279,
  1414153729, 1555569107, 1711126033, 1882238639, 2070462533, 2277508787,
  2505259681, 2755785653, 3031364227, 3334500667, 3667950739, 4034745863,
  // un seul zéro final
  0
};

/// fonction pour l'aide du programme
static void minil_green_help (const char *);

/// fonction pour donner la version du programme
static void minil_green_version (const char *);

/// fonction traitant les arguments du programme
static void minil_traiter_arguments_programme (int argc, const char **argv);

// donne un nom premier après l'argument.
unsigned
mi_premier_apres (unsigned n)
{
  const int nbprem
    = (int) (sizeof (mi_tableau_premiers) / sizeof (unsigned)) - 1;
  int lo = 0, hi = nbprem;
  int md = 0;
  while (lo + 5 < hi)
    {
      md = (lo + hi) / 2;
      if (n < mi_tableau_premiers[md])
        hi = md;
      else
        lo = md;
    };
  for (md = lo; md < hi; md++)
    if (mi_tableau_premiers[md] > n)
      return mi_tableau_premiers[md];
  return 0;
}				/* end mi_premier_apres */

/// traiter les arguments du programme, doit être en phase avec minil_gree_help
void
minil_traiter_arguments_programme (int argc, const char **argv)
{
  int n = -1;
  if (argc > 0 && strcmp (argv[1], "--version"))
    minil_green_version (argv[0]);
  if (argc > 0 && strcmp (argv[1], "--help"))
    minil_green_help (argv[0]);
  if (argc > 0 && (n = atoi (argv[1])) > 0)
    printf ("%s: après %d le nombre %d est premier ou nul\n",
            argv[0], n, (int) mi_premier_apres (n));
}				/* fin minil_traiter_arguments_programme */

//// en C main est toujours la fonction appelée en premier
int
main (int argc, char **argv)
{
  int n = 0;
  rl_initialize ();		/* initialise la bibliothèque GNU readline */
  minil_traiter_arguments_programme (argc, (const char **) argv);
#warning a completer fonction main
  return 0;
}				/* fin fonction main */

/// message d'aide avec --help
void
minil_green_help (const char *prog)
{
  printf ("%s est utilisable avec\n", prog);
  printf ("\t --help                    # cette aide\n");
  printf ("\t                           # £ get this help\n");
  printf ("\t --version                 # donne la version\n");
  printf ("\t --version                 # £ give version info \n");
#warning minil_green_help est une fonction d aide "à compléter"
  printf ("@@@ minil_green_help A COMPLETER %s:%d@@@@\n", __FILE__, __LINE__);
  fflush (NULL);
  exit (EXIT_SUCCESS);
}				/* fin minil_green_help */


/// message de version avec --version
void
minil_green_version (const char *prog)
{
  printf ("%s version %s (sur github.com/bstarynk/minil-green)\n",
          prog, MINIL_GITID);
  printf ("%s compilé  %s\n", prog, __DATE__);
  fflush (NULL);
  exit (EXIT_SUCCESS);
}				/* fin minil_green_version */


/**** fin du fichier mini-green/main.c ********/
