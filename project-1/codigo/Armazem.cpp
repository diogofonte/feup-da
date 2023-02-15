#include <algorithm>
#include "Armazem.h"
#include <vector>
#include <list>
#include <chrono>
#include <iostream>

Armazem::Armazem() {
    estafetas = list<Estafeta>();
    encomendas = list<Encomenda>();
    encomendasExpresso = list<Encomenda>();
}

void Armazem::setEstafetas(const list<Estafeta> &e) {
    estafetas = e;
}

void Armazem::setEncomendas(const list<Encomenda> &e) {
    encomendas = e;
}

void Armazem::setEncomendasExpresso(const list<Encomenda> &e) {
    encomendasExpresso = e;
}

list<Estafeta> Armazem::getEstafetas() const {
    return estafetas;
}

list<Encomenda> Armazem::getEncomendas() const {
    return encomendas;
}

list<Encomenda> Armazem::getEncomendasExpresso() const {
    return encomendasExpresso;
}

void Armazem::addEstafeta(const Estafeta &e) {
    estafetas.push_back(e);
}

void Armazem::addEncomenda(const Encomenda &e) {
    encomendas.push_back(e);
}

void Armazem::addEncomendaExpresso(const Encomenda &e) {
    encomendasExpresso.push_back(e);
}

bool Armazem::sortEstafetasByMax(const Estafeta &e1, const Estafeta &e2) {
    return e1.getPesoMax() + e1.getVolMax() < e2.getPesoMax() + e2.getVolMax();
}

bool Armazem::sortEncomendasByMax(const Encomenda &e1, const Encomenda &e2) {
    if(max(e1.getPeso(), e1.getVolume()) == max(e2.getPeso(), e2.getVolume())) {
        return min(e1.getPeso(), e1.getVolume()) < min(e2.getPeso(), e2.getVolume());
    }
    return max(e1.getPeso(), e1.getVolume()) < max(e2.getPeso(), e2.getVolume());
}

bool Armazem::sortEncomendasByDuration(const Encomenda& e1, const Encomenda& e2) {
    return e1.getDuracao() < e2.getDuracao();
}

int Armazem::minimizarNumEstafetas() { // cenário 1

    int numEstafetas = 0;

    encomendas.sort(sortEncomendasByMax);
    list<Encomenda>::iterator itEn = encomendas.begin();

    estafetas.sort(sortEstafetasByMax);
    estafetas.reverse();
    list<Estafeta>::iterator itEs = estafetas.begin();

    for (itEs; itEs != estafetas.end(); itEs++) {
        for (itEn; itEn != encomendas.end(); itEn++) {
            if (itEn->getVolume() + itEs->getVolumeAtual() <= itEs->getVolMax() && itEn->getPeso() + itEs->getPesoAtual() <= itEs->getPesoMax()) {
                if(itEs->getEncomendas().size() == 0) numEstafetas++;
                itEs->addEncomenda(*itEn);
                itEn = encomendas.erase(itEn);
                itEn--;
            }
        }
        itEn = encomendas.begin();
    }

    return numEstafetas;
}

bool Armazem::sortEstafetasByCost(const Estafeta &e1, const Estafeta &e2) {
    return ((e1.getPesoMax()+e1.getVolMax())/e1.getCusto()) > ((e2.getPesoMax()+e2.getVolMax())/e2.getCusto());
}

void Armazem::multidimensionalKnapsack(vector<vector<vector<int>>> &dynNoRep){
    auto encomendaItr = encomendas.begin();
    for(int i = 1; i <= dynNoRep.size()-1; i++, encomendaItr++) {
        for (int j = 0; j <= dynNoRep[i].size()-1; j++) {
            for (int h = 0; h <= dynNoRep[i][j].size()-1; h++) {
                if (encomendaItr->getPeso() > j) dynNoRep[i][j][h] = dynNoRep[i - 1][j][h];
                else {
                    if (encomendaItr->getVolume() > h) dynNoRep[i][j][h] = dynNoRep[i - 1][j][h];
                    else dynNoRep[i][j][h] = max(dynNoRep[i - 1][j][h], dynNoRep[i - 1][j - encomendaItr->getPeso()][h - encomendaItr->getVolume()] + encomendaItr->getRecompensa());
                }
            }
        }
    }
}

int Armazem::maximizarLucro() { // cenario 2
    estafetas.sort(sortEstafetasByCost);
    int profit=0;
    for(auto estafetasItr = estafetas.begin(); estafetasItr!=estafetas.end(); estafetasItr++){
        vector<vector<vector<int>>> dynNoRep(encomendas.size()+1, vector<vector<int>>(estafetasItr->getPesoMax()+1, vector<int>(estafetasItr->getVolMax()+1, 0)));
        multidimensionalKnapsack(dynNoRep);
        int j = estafetasItr->getPesoMax(), h = estafetasItr->getVolMax(), finalValue = 0;
        auto encomendaItr = encomendas.rbegin();
        for(int i = (int)encomendas.size(); i > 0; i--, encomendaItr++) {
            if(dynNoRep[i][j][h] != dynNoRep[i - 1][j][h]) {
                finalValue += encomendaItr->getRecompensa();
                j -= encomendaItr->getPeso();
                h -= encomendaItr->getVolume();
            }
        }
        if(finalValue - estafetasItr->getCusto() > 0){
            profit+=finalValue - estafetasItr->getCusto();
            j = estafetasItr->getPesoMax(), h = estafetasItr->getVolMax();
            encomendaItr = encomendas.rbegin();
            for(int i = (int)encomendas.size(); i > 0; i--) {
                if(dynNoRep[i][j][h] != dynNoRep[i - 1][j][h]) {
                    estafetasItr->addEncomenda(*encomendaItr);
                    j -= encomendaItr->getPeso();
                    h -= encomendaItr->getVolume();
                    encomendaItr = decltype(encomendaItr){ encomendas.erase(std::next(encomendaItr).base()) };
                }else ++encomendaItr;
            }
        }else break;
    }

    return profit;
}

int Armazem::maximizarNumEncomendasExpresso() { //cenario 3
    encomendas.sort(sortEncomendasByDuration);

    int tempoDisponivel = (17 - 9) * 3600;
    int numEncomendas = 0;
    int tempoGasto = 0;

    for(auto itr = encomendas.begin() ; itr != encomendas.end(); itr++) {
        if ((tempoDisponivel - itr->getDuracao() >= 0) ) {
            numEncomendas++;
            addEncomendaExpresso(*itr);
            tempoDisponivel -= (itr->getDuracao());
            tempoGasto += itr->getDuracao();
            itr = encomendas.erase(itr);
            itr--;
        }
    }

    return tempoGasto/numEncomendas;
}

double Armazem::calcularEficiencia(int cenario) {
    int numEncomendas = encomendas.size();

    if (cenario == 1) minimizarNumEstafetas();

    else if (cenario == 2) maximizarLucro();

    else if (cenario == 3) maximizarNumEncomendasExpresso();

    int numEncomendasEntregues = numEncomendas - encomendas.size();

    return (double)numEncomendasEntregues / (double)numEncomendas;
}
