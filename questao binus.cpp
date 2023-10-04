#include <iostream>

class No {
public:
    int dado;
    No* proximo;

    No(int dado) {
        this->dado = dado;
        proximo = NULL;
    }
};

class ListaEncadeada {
public:
    No* cabeca;

    ListaEncadeada() {
        cabeca = NULL;
    }

    void adicionar(int dado) {
        No* novoNo = new No(dado);
        novoNo->proximo = cabeca;
        cabeca = novoNo;
    }

    void reverterIntervalo(int inicio, int fim) {
        if (inicio >= fim || cabeca == NULL) {
            return;
        }

        No* anterior = NULL;
        No* atual = cabeca;
        No* proximo = NULL;
        No* inicioNode = NULL;
        No* fimNode = NULL;
        No* prevInicio = NULL;

        int pos = 1;

        while (pos < inicio) {
            prevInicio = atual;
            atual = atual->proximo;
            pos++;
        }
        inicioNode = atual;

        while (pos <= fim) {
            proximo = atual->proximo;
            atual->proximo = anterior;
            anterior = atual;
            atual = proximo;
            pos++;
        }
        fimNode = anterior;

        if (prevInicio != NULL) {
            prevInicio->proximo = fimNode;
        } else {
            cabeca = fimNode;
        }

        inicioNode->proximo = atual;
    }

    void imprimir() {
        No* atual = cabeca;
        while (atual != NULL) {
            std::cout << atual->dado << " ";
            atual = atual->proximo;
        }
        std::cout << std::endl;
    }

    ~ListaEncadeada() {
        while (cabeca != NULL) {
            No* temp = cabeca;
            cabeca = cabeca->proximo;
            delete temp;
        }
    }
};

int main() {
    ListaEncadeada minhaLista;
    minhaLista.adicionar(10);
    minhaLista.adicionar(20);
    minhaLista.adicionar(30);
    minhaLista.adicionar(40);
    minhaLista.adicionar(50);

    int inicio = 2;
    int fim = 4;

    std::cout << "Lista original: ";
    minhaLista.imprimir();

    minhaLista.reverterIntervalo(inicio, fim);

    std::cout << "Lista com intervalo revertido: ";
    minhaLista.imprimir();

    return 0;
}

