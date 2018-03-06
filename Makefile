CXX = g++
CC  = $(CXX)

CXXFLAGS = -std=c++1z

# Partie commentÃ©e : choisissez les options que vous voulez avoir
#                    en dÃ©commentant la/les lignes correspondantes
#
CXXFLAGS += -pedantic -Wall         # pour les purs et durs
CXXFLAGS += -g                      # pour debugger
# CXXFLAGS += -pg                   # pour profiler
# LDFLAGS  += -pg                   # pour profiler
# CXXFLAGS += -O2                   # pour optimiser la vitesse

all: testVecteur

Vecteur.o: Vecteur.cc Vecteur.h

testVecteur.o: testVecteur.cc Vecteur.h

testVecteur: testVecteur.o Vecteur.o
