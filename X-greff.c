/* fichier minil-green/X-greff.c */
#include "minil.h"

/// signature de la fonction genérée
typedef void minigreff_signature_t (void);
extern void minilgreff_essai(void);

void minilgreff_essai(void)
{
  void* greffon = NULL;
  void* adfun = NULL;
  time_t maintenant= 0;
  time (&maintenant);
  FILE*fgen = fopen("X-greffgen.c", "w");
  printf("minilgreff_essai avec git %s\n", MINIL_GITID);
  fprintf (fgen, "// fichier X-greffgen.c genéré par minilgreff_essai git %s\n", MINIL_GITID);
  fprintf (fgen, "#include \"minil.h\"\n");
  fprintf (fgen, "void minigreff_genéré(void) {\n");
  fputs ("  printf(\"%s git %s\\n\", __FUNCTION__, MINIL_GITID\n", fgen);
  fprintf (fgen, "  // l'heure de la génération\n");
  fprintf (fgen, "  puts(\"%s\");\n", ctime(&maintenant));
  fprintf (fgen, "} // fin minigreff_genéré\n");
  fprintf (fgen, "/// fin du fichier généré X-greffgen.c\n");
  fclose(fgen);
  fflush(NULL);
  int ok = system ("make X-greffgen.so");
  fflush(NULL);
  if (!ok) {
    fprintf(stderr, "commande make X-greffgen.so échouée\n");
    exit(EXIT_FAILURE);
  };
    char cwdbuf[256];
    memset (cwdbuf, 0, sizeof(cwdbuf));
    getcwd(cwdbuf, sizeof(cwdbuf)-1);
  greffon = dlopen("./X-greffgen.so", RTLD_NOW);
  if (!greffon) {
    fprintf(stderr, "dlopen du greffon ./X-greffgen.so dans %s (%s)\n",
	    cwdbuf, dlerror());
    exit (EXIT_FAILURE);
  };
  adfun = dlsym(greffon, "minigreff_genéré");
  if (!adfun) {
    fprintf(stderr, "dlsym minigreff_généré dans %s\n"
	    "\t du greffon ./X-greffgen.so échoue (%s)\n",
	    cwdbuf, dlerror());
    exit (EXIT_FAILURE);
  };
  /// appel indirect de fonction
  (*(minigreff_signature_t*)(adfun)) ();
} /* fin minilgreff_essai */

/* fin fichier minil-green/X-greff.c */
