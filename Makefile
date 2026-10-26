# fichier Makefile ---- lancer "make" pour compiler
# pour l'utilitaire `GNU make` https://www.gnu.org/software/make
.PHONY: clean all indent
# la commande de calcul d'empreinte (ou somme de contrôle)
MD5SUM= md5sum

# la commande pour supprimer les fichiers
RM= rm -vf

# le compilateur C
CC= gcc

# l'indenteur de code ASTYLE et ses options
ASTYLE= astyle
ASTYLEFLAGS= -s2 --style=gnu

## dépendance : GNU libunistring http://www.gnu.org/software/libunistring/
## dépendance : GNU readline http://www.gnu.org/software/readline
LDLIBS= -lunistring -lreadline

# les options du compilateur ; on veut le standard C99 amélioré par GCC
CFLAGS= -std=gnu99 $(OPTIMFLAGS) $(DIAGFLAGS) $(PREPROFLAGS)
# optimisation:
OPTIMFLAGS= -g -O
# diagnostics
DIAGFLAGS= -Wall -Wextra -Wmissing-prototypes
# preprocesseur
PREPROFLAGS= -I /usr/local/include/

# les fichiers sources et objets sont calculés
SRCFILES=$(wildcard *.c)
OBJFILES=$(patsubst %.c,obj/%.o,$(SRCFILES))

all: monminil

clean:
	$(RM) obj/*.o monminil *~ *.orig

monminil: $(OBJFILES)
	$(CC) $(CFLAGS) $(OBJFILES) $(LDLIBS) -o $@

obj/%.o: %.c  | minil.h Makefile
	$(CC) -c $(CFLAGS) $^ -o $@ 

indent: | Makefile
	$(ASTYLE) $(ASTYLEFLAGS) minil.h
	$(ASTYLE) $(ASTYLEFLAGS) $(SRCFILES)

## fin fichier minil-green/Makefile
