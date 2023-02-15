#ifndef FEUP_DA_GOODSDELIVERYLOGISTICS_ESTAFETA_H
#define FEUP_DA_GOODSDELIVERYLOGISTICS_ESTAFETA_H

#include "Encomenda.h"
#include <list>

using namespace std;

class Estafeta {
private:
    /**
     * volume máximo que o estafeta pode carregar
     */
    int volMax;
    /**
     * peso máximo que o estafeta pode carregar
     */
    int pesoMax;
    /**
     * valor do custo de transporte do estafeta
     */
    int custo;
    /**
     * volume total das encomendas até agora atribuídas ao estafeta
     */
    int volAtual;
    /**
     * peso total das encomendas até agora atribuídas ao estafeta
     */
    int pesoAtual;
    /**
     * lista com as encomendas que o estafeta tem atualmente atribuídas
     */
    list<Encomenda> encomendas;
public:
    Estafeta(int vm, int pm, int c, int va, int pa, list<Encomenda> e);
    /**
     *
     * @return volume máximo que o estafeta pode carregar
     */
    int getVolMax() const;
    /**
     *
     * @return peso máximo que o estafeta pode carregar
     */
    int getPesoMax() const;
    /**
     *
     * @return valor do custo de transporte do estafeta
     */
    int getCusto() const;
    /**
     *
     * @return volume total das encomendas até agora atribuídas ao estafeta
     */
    int getVolumeAtual() const;
    /**
     *
     * @return peso total das encomendas até agora atribuídas ao estafeta
     */
    list<Encomenda> getEncomendas() const;
    /**
     *
     * @return peso atual qdo total de encomendas atualmente atribuídas ao estafeta
     */
    int getPesoAtual() const;
    /**
     * Acrescenta uma nova encomenda à respetiva lista
     * @param e é a nova encomenda
     */
    bool addEncomenda(const Encomenda &e);
    /**
     * Função para comparar estafetas
     *
     * @param e é o estafeta a comparar
     * @return true se this == e, false se this != e
     */
    bool operator == (const Estafeta &e) const;
};

#endif //FEUP_DA_GOODSDELIVERYLOGISTICS_ESTAFETA_H