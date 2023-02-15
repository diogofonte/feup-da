#ifndef FEUP_DA_GOODSDELIVERYLOGISTICS_ENCOMENDA_H
#define FEUP_DA_GOODSDELIVERYLOGISTICS_ENCOMENDA_H
#include <iterator>
#include <list>
class Encomenda {
private:
    /**
     * volume da encomenda
     */
    int volume;
    /**
     * peso da encomenda
     */
    int peso;
    /**
     * valor que a empresa receberá como recompensa pela encomenda
     */
    int recompensa;
    /**
     * tempo estimado da entrega do pedido
     */
    int duracao;
public:
    Encomenda(int v, int p, int r, int d);
    /**
     *
     * @return volume da encomenda
     */
    int getVolume() const;
    /**
     *
     * @return peso da encomenda
     */
    int getPeso() const;
    /**
     *
     * @return valor que a empresa receberá como recompensa pela encomenda
     */
    int getRecompensa() const;
    /**
     *
     * @return tempo estimado da entrega do pedido
     */
    int getDuracao() const;
    /**
     * Função para comparar encomendas
     *
     * @param e é a encomenda a comparar
     * @return true se this == e, false se this != e
     */
    bool operator == (const Encomenda &e) const;
};

#endif //FEUP_DA_GOODSDELIVERYLOGISTICS_ENCOMENDA_H
