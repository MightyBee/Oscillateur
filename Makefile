CXX = g++
CC  = $(CXX)

# Les différents répertoires
CDIR=code
HDIR=head
ODIR=obj
EDIR=exe

BIN=testVecteur

CXXFLAGS = -std=c++1z

# Partie commentÃ©e : choisissez les options que vous voulez avoir
#                    en dÃ©commentant la/les lignes correspondantes
#
CXXFLAGS += -pedantic -Wall         # pour les purs et durs
CXXFLAGS += -g                      # pour debugger
# CXXFLAGS += -pg                   # pour profiler
# LDFLAGS  += -pg                   # pour profiler
# CXXFLAGS += -O2                   # pour optimiser la vitesse

# Où trouver les différents sources *.cpp qu'il faudra compiler pour créer les objets correspondants
SRC= $(wildcard $(CDIR)/*.cpp)
OBJ= $(SRC:$(CDIR)/%.cpp=$(ODIR)/%.o)

all: $(BIN)

#Création de l'exécutable
testVecteur: $(OBJ)
	$(CXX) -o $(EDIR)/$@ $^ $(CXXFLAGS)

# Création des différents *.o à partir des *.cpp
$(ODIR)/%.o: $(CDIR)/%.cpp $(HDIR)/%.h
	$(CXX) -o $@ -c $< $(CXXFLAGS)

#Vecteur.o: Vecteur.cc Vecteur.h

#testVecteur.o: testVecteur.cc Vecteur.h

#testVecteur: testVecteur.o Vecteur.o
