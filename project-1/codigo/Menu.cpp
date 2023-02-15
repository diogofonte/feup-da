#include <iomanip>
#include "Menu.h"

Menu::Menu(): option(0){
    int percentagem;

    cout << "Logistica Urbana para Entrega de Mercadorias" << endl;

    cout << "Insira a percentagem do dataset a usar (25, 50, 75, 100): ";
    cin >> percentagem;
    cout << endl;

    LoadData loadData(a, percentagem);

    lastMenu.push(0);   //'0' representa o menu inicial/principal
    menu0();
}

void Menu::readOption(const unsigned& minOption, const unsigned& maxOption) {
    bool validOption;
    do {
        cin >> option;
        if (cin.fail()) {
            if (cin.eof()) {
                cout << "OPERAÇÃO TERMINADA COM SUCESSO." << endl;
                exit (1);
            }
            else {
                validOption = false;
                cout << "OPÇÃO INVÁLIDA! TENTE NOVAMENTE" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }
        else if ((minOption <= option &&  option <= maxOption) || option == 0) {
            validOption = true;
            cin.ignore(1000, '\n');
        }
        else {  // O utilizador introduziu um inteiro invalido
            validOption = false;
            cout << "OPÇÃO INVÁLIDA! TENTE NOVAMENTE. " << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    } while (!validOption);
}

void Menu::processOption() {
    switch (option) {
        case 0: menu0();
            break;
        case 1: menu1();
            break;
        case 2: menu2();
            break;
        case 3: menu3();
            break;
        case 4: menu4();
    }
}

void Menu::menu0() {
    cout << "1. Visualizar otimização do número de estafetas" << endl; // cenario 1
    cout << "2. Visualizar otimização do lucro" << endl; // cenario 2
    cout << "3. Visualizar otimização das entregas expresso" << endl; // cenario 3
    cout << "4. Medir eficiência" << endl;
    cout << "0. Sair." << endl;
    cout << "\nESCOLHA UMA OPÇÃO:";
    readOption(0, 4);

    if (option) {
        lastMenu.push(0);
        processOption();
    }
    else {
        cout << "OPERAÇÃO TERMINADA COM SUCESSO";
        exit (0);
    }
}

void Menu::menu1() {
    list<Estafeta> estafetasInicial = a.getEstafetas();
    list<Encomenda> encomendasInicial = a.getEncomendas();

    cout << "É necessário um total de " << a.minimizarNumEstafetas()
         << " estafetas para entregar o máximo de encomendas para o dia de hoje" << endl;

    cout << "Estafeta\tVolume máximo permitido\t\tVolume ocupado\t\tPeso maximo permitido\t\tPeso ocupado" << endl;
    int i = 1;
    for (auto e: a.getEstafetas()) {
        cout << i << "\t\t" << e.getVolMax() << "\t\t\t\t" << e.getVolumeAtual() << "\t\t\t" << e.getPesoMax() << "\t\t\t\t" << e.getPesoAtual() << endl;
        i++;
    }

    a.setEstafetas(estafetasInicial);
    a.setEncomendas(encomendasInicial);

    cout << endl;
    option = lastMenu.top();
    lastMenu.pop();
    processOption();
}

void Menu::menu2() {
    list<Estafeta> estafetasInicial = a.getEstafetas();
    list<Encomenda> encomendasInicial = a.getEncomendas();

    cout << "O melhor lucro encontrado foi: " << a.maximizarLucro() << " euros" << endl;

    cout << "Estafeta\tVolume máximo permitido\t\tVolume ocupado\t\tPeso maximo permitido\t\tPeso ocupado" << endl;
    int i = 1;
    for (auto e: a.getEstafetas()) {
        cout << i << "\t\t" << e.getVolMax() << "\t\t\t\t" << e.getVolumeAtual() << "\t\t\t" << e.getPesoMax() << "\t\t\t\t" << e.getPesoAtual() << endl;
        i++;
    }

    a.setEstafetas(estafetasInicial);
    a.setEncomendas(encomendasInicial);

    cout << endl;
    option = lastMenu.top();
    lastMenu.pop();
    processOption();
}

void Menu::menu3() {
    list<Encomenda> encomendasInicial = a.getEncomendas();
    list<Encomenda> encomendasExpressoInicial = a.getEncomendasExpresso();

    int tempoMedio = a.maximizarNumEncomendasExpresso();

    cout << "O maior número de encomendas expresso entregues foi: " << a.getEncomendasExpresso().size() << ", as quais demoram um tempo médio de " << tempoMedio << " segundos a serem entregues" << endl;

    cout << "Encomenda\tVolume\t\t\t\tPeso\t\t\tRecompensa\t\tDuração" << endl;
    int i = 1;
    for (auto e: a.getEncomendasExpresso()) {
        cout << i << "\t\t" << e.getVolume() << "\t\t\t\t" << e.getPeso() << "\t\t\t" << e.getRecompensa() << "\t\t\t\t" << e.getDuracao() << endl;
        i++;
    }

    a.setEncomendas(encomendasInicial);
    a.setEncomendasExpresso(encomendasExpressoInicial);

    cout << endl;
    option = lastMenu.top();
    lastMenu.pop();
    processOption();
}

void Menu::menu4() {
    cout << "1. Medir eficiência pelo menor numero de estafetas necessários" << endl;
    cout << "2. Medir eficiência pelo maior lucro que se pode obter" << endl;
    cout << "3. Medir eficiência pela maior quantidade de encomendas expresso que se podem entregar" << endl;
    cout << "0. voltar" << endl;
    cout << "ESCOLHA UMA OPÇÃO: ";
    readOption(0, 3);

    if(option == 0) {
        menu0();
    }

    cout << "O quociente entre o número de entregas é de " << setprecision(1) << a.calcularEficiencia(option) << "\n" << endl;

    option = lastMenu.top();
    lastMenu.pop();
    processOption();
}