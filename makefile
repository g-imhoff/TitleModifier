#Les variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic
EXEC = TitleModifier
SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=obj/%.o)
DEPS = $(wildcard header/*.h)

#Compile le programme en fonction de EXEC, OBJETS, CC, LDFLAGS
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

#Génère les fichiers .o dans un répertoire "temporaire" obj qui est créer juste avant la création des fichiers .o
obj/%.o: src/%.c $(DEPS)
	mkdir -p obj
	$(CC) $(CFLAGS) -o $@ -c $<

#Supprimer les dossiers obj, doc et supprimer main.exe
clean:
	rm -f $(EXEC)
	rm -rf obj

sanitizers: 
	make -f ./config/sanitizers.mk

format:
	@for file in $(SRC) $(DEPS); do \
		clang-format -i $$file; \
	done \

.phony: clean format sanitizers 