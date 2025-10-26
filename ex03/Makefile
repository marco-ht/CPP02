# Nome del progetto
NAME    = fixed

# Compiler e flags
CC      = c++
CFLAGS  = -Wall -Werror -Wextra -std=c++98

# Directory dei sorgenti e degli oggetti
SRC_DIR = .
OBJ_DIR = objs

# Lista dei file sorgente e relativi oggetti
SRC     = $(SRC_DIR)/main.cpp $(SRC_DIR)/Fixed.cpp $(SRC_DIR)/Point.cpp $(SRC_DIR)/bsp.cpp
OBJ     = $(OBJ_DIR)/main.o $(OBJ_DIR)/Fixed.o $(OBJ_DIR)/Point.o $(OBJ_DIR)/bsp.o

# Comando di rimozione
RM      = rm -rf

# Target di default
all: $(NAME)

# Regola per creare l'eseguibile, dipendente da oggetti
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Regola per compilare i file .c in file .o all'interno della directory obj
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Creazione della directory degli oggetti, se non esiste
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Pulizia dei file oggetto
clean:
	$(RM) $(OBJ_DIR)

# Pulizia completa: rimuove l'eseguibile e gli oggetti
fclean: clean
	$(RM) $(NAME)

# Ricompilazione totale
re: fclean all