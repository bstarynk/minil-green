# fichier Makefile ---- lancer "make" pour compiler
# pour l'utilitaire `GNU make` https://www.gnu.org/software/make
.PHONY: clean all indent plugins
# la commande de calcul d'empreinte (ou somme de contrôle)
MD5SUM= md5sum

# la commande pour supprimer les fichiers
RM= rm -vf

# le compilateur C habituel de Linux voir gcc.gnu.org
CC= gcc

# l'indenteur de code ASTYLE et ses options
ASTYLE= astyle
ASTYLEFLAGS= -s2 --style=gnu

## dépendance : GNU libunistring http://www.gnu.org/software/libunistring/
## dépendance : GNU readline http://www.gnu.org/software/readline
## dépendance: -ldl pour le chargement dynamique 
LDLIBS= -lunistring -lreadline -ldl -lm 

# les options du compilateur ; on veut le standard C99 amélioré par GCC
CFLAGS= -std=gnu99 $(OPTIMFLAGS) $(DIAGFLAGS) $(PREPROFLAGS) -DMINIL_GITID=\"$$(./get-short-git.sh)\"
# optimisation: faire make OPTIMFLAGS=-O1 dès que le logiciel fonctionne
OPTIMFLAGS= -Og
# diagnostics
DIAGFLAGS= -g -Wall -Wextra -Wmissing-prototypes
# preprocesseur
PREPROFLAGS= -I /usr/local/include/

# les fichiers sources et objets sont calculés
SRCFILES=$(wildcard [a-z]*.c)
OBJFILES=$(patsubst %.c,obj/%.o,$(SRCFILES))


# les fichiers d'extensions sont chacun compilés en un greffon
# ("plugin") chargé dynamiquement. Ils commencent chacun par X- (par
# exemple X-truc.c)
EXTFILES=$(wildcard X-*.c)
PLUGINFILES=$(patsubst %.c,obj/%.so,$(EXTFILES))

all: monminil greffons

clean:
	$(RM) obj/*.o monminil obj/*.so *~ *.orig

monminil: $(OBJFILES)
	$(CC) $(CFLAGS) $(OBJFILES) $(LDLIBS) -o $@

greffons: $(PLUGINFILES)

obj/%.o: %.c  minil.h | Makefile
	$(CC) -c $(CFLAGS) $< -o $@


obj/X-%.so: X-%.c  minil.h | Makefile
	$(CC) -fPIC -shared $(CFLAGS) $< -o $@ 

indent: | Makefile
	$(ASTYLE) $(ASTYLEFLAGS) minil.h
	$(ASTYLE) $(ASTYLEFLAGS) $(SRCFILES)

## fin fichier minil-green/Makefile
