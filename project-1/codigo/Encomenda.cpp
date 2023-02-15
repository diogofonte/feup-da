#include "Encomenda.h"

using namespace std;

Encomenda::Encomenda(int v, int p, int r, int d): volume(v), peso(p), recompensa(r), duracao(d) {}

int Encomenda::getVolume() const {
    return volume;
}

int Encomenda::getPeso() const {
    return peso;
}

int Encomenda::getRecompensa() const {
    return recompensa;
}

int Encomenda::getDuracao() const {
    return duracao;
}

bool Encomenda::operator == (const Encomenda &e) const {
    return volume == e.getVolume();
}


