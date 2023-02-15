#ifndef FEUP_DA_GOODSDELIVERYLOGISTICS_MENU_H
#define FEUP_DA_GOODSDELIVERYLOGISTICS_MENU_H

#include <stack>
#include <iostream>

#include "Armazem.h"
#include "Encomenda.h"
#include "Estafeta.h"
#include "LoadData.h"

class Menu {
private:
    Armazem a;
    stack<int> lastMenu;
    int option;
public:
    Menu();
    /**
     * Função para ler a opção de operação que pretende realizar
     *
     * @param minOption é o limite inferior das opções disponibilizadas
     * @param maxOption é o limite superior das opções disponibilizadas
     */
    void readOption(const unsigned& minOption, const unsigned& maxOption);
    /**
     * Função para processar o menu escolhido
     */
    void processOption();
    /**
     * Executa o menu inicial
     */
    void menu0();
    /**
     * Executa o cenário 1
     */
    void menu1();
    /**
     * Executa o cenário 2
     */
    void menu2();
    /**
     * Executa o cenário 3
     */
    void menu3();
    /**
     * Executa a funcionalidade extra em que pode medir a eficiência da empresa
     * consoante a otimização que pretende
     */
    void menu4();
};

#endif //FEUP_DA_GOODSDELIVERYLOGISTICS_MENU_H
