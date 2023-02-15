#ifndef FEUP_DA_GOODSDELIVERYLOGISTICS_ARMAZEM_H
#define FEUP_DA_GOODSDELIVERYLOGISTICS_ARMAZEM_H

#include <list>
#include <vector>

#include "Estafeta.h"
#include "Encomenda.h"

using namespace std;

class Armazem {
private:
    /**
     * conjunto dos estafetas registados na empresa
     */
    list<Estafeta> estafetas;
    /**
     * conjunto de pedidos de encomendas que ainda não foram entregues
     */
    list<Encomenda> encomendas;
    /**
     * conjunto de pedidos de encomendas expresso que a empresa tem para fazer
     */
    list<Encomenda> encomendasExpresso;
public:
    Armazem();
    /**
     * Atualiza o conjunto de estafetas que está registado na empresa
     * @param e é o objeto que contém as informações sobre cada estafeta
     */
    void setEstafetas(const list<Estafeta> &e);
    /**
     * Atualiza o conjunto de encomendas que a empresa tem por realizar
     * @param e é o objeto que contém as informações sobre cada encomenda
     */
    void setEncomendas(const list<Encomenda> &e);
    /**
     * Atualiza o conjunto de encomendas expresso que a empresa tem para fazer
     * @param e é o objeto que contém as informações sobre cada encomenda
     */
    void setEncomendasExpresso(const list<Encomenda> &e);
    /**
     *
     * @return todos os estafetas registados na empresa
     */
    list<Estafeta> getEstafetas() const;
    /**
     *
     * @return todas as encomendas que ainda não foram atribuídas a nenhum estafeta
     */
     list<Encomenda> getEncomendas() const;
     /**
      *
      * @return todas as encomendas expresso a serem entregues pela carrinha da empresa
      */
     list<Encomenda> getEncomendasExpresso() const;
    /**
     * Adiciona um novo estafeta à lista de estafetas
     * @param e é o novo estafeta a ser adicionado
     */
    void addEstafeta(const Estafeta &e);
    /**
     * Adiciona uma nova encomenda à lista de encomendas
     * @param e é a nova encomenda a ser adicionada
     */
    void addEncomenda(const Encomenda &e);
    /**
     * Adiciona uma nova encomenda expresso à lista de encomendas expresso
     * @param e é a nova encomenda expresso a ser adionada
     */
    void addEncomendaExpresso(const Encomenda &e);
    /**
     * Critério de ordenação de estafetas, pela soma do valor de peso
     * e volume que podiam transportar
     * @param e1 é um estafeta
     * @param e2 é outro estafeta
     * @return true se e1 < e2 de acordo com o critério, caso contrário false
     */
    static bool sortEstafetasByMax(const Estafeta &e1, const Estafeta &e2);
    /**
     * Critério de ordenação de encomendas, de acordo com
     * o seu valor de peso ou volume ocupado
     * (conforme qual dos dois fosse o máximo entre ambos)
     * @param e1 é uma encomenda
     * @param e2 é outra encomenda
     * @return true se e1 < e2 de acordo com o critério, caso contrário false
     */
    static bool sortEncomendasByMax(const Encomenda &e1, const Encomenda &e2);
    /**
     * Critério de ordenação de encomendas de acordo com
     * o tempo total relacionado com a sua entrega
     * @param e1 é uma encomenda
     * @param e2 é outra encomenda
     * @return true se e1 < e2 de acordo com o critério, caso contrário false
     */
    static bool sortEncomendasByDuration(const Encomenda& e1, const Encomenda& e2);
    /**
     * Critério de ordenação de estafetas, pelo custo associado
     * ao seu trabalho
     * @param e1 é um estafeta
     * @param e2 é outro estafeta
     * @return true se e1 < e2 de acordo com o critério, caso contrário false
     */
    static bool sortEstafetasByCost(const Estafeta &e1, const Estafeta &e2);
    /**
     * Critério de ordenação de encomendas de acordo com
     * o valor de recompensa que a empresa recebe pelas mesmas
     * @param e1 é uma encomenda
     * @param e2 é outra encomenda
     * @return true se e1 < e2 de acordo com o critério, caso contrário false
     */
    int minimizarNumEstafetas();
    /**
     * Função auxiliar para o algoritmo do cenário 2
     *
     * @param dynNoRep
     */
    void multidimensionalKnapsack(vector<vector<vector<int>>> &dynNoRep);
    /**
     * Cenário 2
     * Função para otimizar o lucro da empresa (diferença entre a receita total e o custo total)
     * para a entrega de todos os pedidos ou do maior número de pedidos, num dia
     *
     * @return valor do lucro total máximo
     */
    int maximizarLucro();
    /**
     * Cenário 3
     * Função para otimizar o número de entregas expresso completadas num dia de trabalho da empresa
     *
     * @return número de encomendas máximas realizadas no dia
     */
    int maximizarNumEncomendasExpresso();
    /**
     * Funcionalidade extra
     * Medir a eficiência da operação da empresa, em termos do quociente entre o número de
     * pedidos efetivamente entregues e o número de pedidos recebidos num dia
     *
     * @param cenario é o cenário de entrega escolhido pelo utilizador para efeito de cálculo
     * @return
     */
    double calcularEficiencia(int cenario);
};

#endif //FEUP_DA_GOODSDELIVERYLOGISTICS_ARMAZEM_H
