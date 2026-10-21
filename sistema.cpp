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

class PilhaHistorico 
{
private:
    No* topo;

public:
    PilhaHistorico() 
    {
        topo = nullptr;
    }

    ~PilhaHistorico() {
        while (topo != nullptr) 
        {
            No* temp = topo;
            topo = topo->prox;
            delete temp;
        }
    }

    void push(string nome) 
    {
        No* novo = new No{nome, 0, topo};
        topo = novo;
    }

    void pop() {
        if (topo == nullptr) 
        {
            cout << "Historico vazio." << endl;
            return;
        }

        No* temp = topo;
        cout << "Removido do historico: " << temp->nome << endl;
        topo = topo->prox;
        delete temp;
    }

    void peek() {
        if (topo == nullptr) 
        {
            cout << "Historico vazio." << endl;
            return;
        }

        cout << "Ultimo atendimento: " << topo->nome << endl;
    }

    void imprimirHistorico() 
    {
        if (topo == nullptr) 
        {
            cout << "Nenhum atendimento registrado." << endl;
            return;
        }

        No* auxiliar = nullptr;
        No* atual = topo;

        while (atual != nullptr) 
        {
            No* novo = new No{atual->nome, atual->urgencia, auxiliar};
            auxiliar = novo;
            atual = atual->prox;
        }

        cout << "\n=== RELATORIO DE ATENDIMENTOS ===" << endl;

        while (auxiliar != nullptr) 
        {
            cout << auxiliar->nome << endl;

            No* temp = auxiliar;
            auxiliar = auxiliar->prox;
            delete temp;
        }
    }
};