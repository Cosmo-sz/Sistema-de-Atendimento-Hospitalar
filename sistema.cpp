#include <iostream>
#include <string>
using namespace std;

struct No 
{
    string nome;
    int urgencia;
    No* prox;
};

class FilaPacientes 
{
private:
    No* inicio;
    No* fim;
    int quantidade;

public:
    FilaPacientes() 
    {
        inicio = nullptr;
        fim = nullptr;
        quantidade = 0;
    }

    ~FilaPacientes() {
        while (inicio != nullptr) 
        {
            No* temp = inicio;
            inicio = inicio->prox;
            delete temp;
        }
    }

    void enqueue(string nome, int urgencia) {
        No* novo = new No{nome, urgencia, nullptr};

        if (fim == nullptr) 
        {
            inicio = novo;
            fim = novo;
        } else 
        {
            fim->prox = novo;
            fim = novo;
        }

        quantidade++;
        cout << "Paciente adicionado: " << nome << endl;
    }

    void dequeue() {
    if (inicio == nullptr) 
    {
        cout << "Fila de pacientes vazia." << endl;
        return;
    }

    No* temp = inicio;

    cout << "Atendendo paciente: " << temp->nome
         << " | Urgencia: " << temp->urgencia << endl;

    inicio = inicio->prox;

    if (inicio == nullptr) 
    {
        fim = nullptr;
    }

    delete temp;
    quantidade--;
    }

    void frente_peak() {
        if (inicio == nullptr) 
        {
            cout << "Fila de pacientes vazia." << endl;
            return;
        }

        cout << "Proximo paciente: " << inicio->nome
            << " | Urgencia: " << inicio->urgencia << endl;
    }

    int tamanho() 
    {
        int total = 0;
        No* atual = inicio;

        while (atual != nullptr) {
            total++;
            atual = atual->prox;
        }

        return total;
    }

    bool vazia() 
    {
        return inicio == nullptr;
    }
};

