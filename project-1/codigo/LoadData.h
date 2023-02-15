#ifndef FEUP_DA_GOODSDELIVERYLOGISTICS_LOADDATA_H
#define FEUP_DA_GOODSDELIVERYLOGISTICS_LOADDATA_H

#include "Armazem.h"

class LoadData {
public:
    /**
     * Função para carregar todos os dados de um armazém
     *
     * @param a é o armazém para onde vão ser carregados os dados
     */
    LoadData(Armazem &a, int percentagem);
    /**
     * Função para carregar os dados dos estafetas de um armazém
     *
     * @param a é o armazém para onde vão ser carregados os estafetas
     */
    void loadEstafetas(Armazem &a, int numEstafetas);
    /**
     * Função para carregar os dados das encomendas de um armazém
     *
     * @param a é o armazém para onde vão ser carregadas as encomendas
     */
    void loadEncomendas(Armazem &a, int numEncomendas);
};

#endif //FEUP_DA_GOODSDELIVERYLOGISTICS_LOADDATA_H
