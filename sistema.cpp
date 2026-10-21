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
};