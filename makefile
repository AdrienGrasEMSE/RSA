# Nom de l'exécutable final
TARGET = main

# Compilateur
CXX = g++

# Options du compilateur
CXXFLAGS = -Wall -Wextra -std=c++17 -g

# Fichiers source
SRCS = main.cpp Word_2048.cpp

# Fichiers objets (générés automatiquement à partir des sources)
OBJS = $(SRCS:.cpp=.o)

# Règle principale : construire l'exécutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Règle pour construire les fichiers objets
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage des fichiers générés
clean:
	rm -f $(OBJS) $(TARGET)

# Règle pour exécuter le programme
run: $(TARGET)
	./$(TARGET)

# Dépendances automatiques
depend: $(SRCS)
	$(CXX) -MM $(SRCS) > .depend

-include .depend
