#include "Estafeta.h"

Estafeta::Estafeta(int vm, int pm, int c, int va, int pa, list<Encomenda> e): volMax(vm), pesoMax(pm), custo(c), volAtual(va), pesoAtual(pa), encomendas(e){}

int Estafeta::getVolMax() const {
    return volMax;
}

int Estafeta::getPesoMax() const {
    return pesoMax;
}

int Estafeta::getCusto() const {
    return custo;
}

int Estafeta::getVolumeAtual() const {
    return volAtual;
}

int Estafeta::getPesoAtual() const {
    return pesoAtual;
}

list<Encomenda> Estafeta::getEncomendas() const {
    return encomendas;
}

bool Estafeta::addEncomenda(const Encomenda &e) {
    if (volMax < volAtual + e.getVolume() || pesoMax < pesoAtual + e.getPeso()) {
        return false;
    }

    encomendas.push_back(e);
    volAtual += e.getVolume();
    pesoAtual += e.getPeso();

    return true;
}

bool Estafeta::operator == (const Estafeta &e) const {
    return volMax == e.getVolMax() &&
           pesoMax == e.getPesoMax() &&
           volAtual == e.getVolumeAtual() &&
           pesoAtual == e.getPesoAtual() &&
           encomendas == e.getEncomendas() &&
           custo == e.getCusto();
}