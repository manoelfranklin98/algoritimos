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

    int contarOcorrencias(int numero) {
        int contador = 0;
        No* atual = cabeca;

        while (atual != NULL) {
            if (atual->dado == numero) {
                contador++;
            }
            atual = atual->proximo;
        }

        return contador;
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
    minhaLista.adicionar(30); // Adicionando outro 30 para teste

    int numeroBuscado = 30;

    std::cout << "Lista: ";
    minhaLista.imprimir();

    int ocorrencias = minhaLista.contarOcorrencias(numeroBuscado);

    std::cout << "O n�mero " << numeroBuscado << " ocorre " << ocorrencias << " vezes na lista." << std::endl;

    return 0;
}

