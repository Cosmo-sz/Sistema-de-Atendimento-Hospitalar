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

class ListaMedicos 
{
private:
    No* inicio;

public:
    ListaMedicos() 
    {
        inicio = nullptr;
    }

    ~ListaMedicos() {
        while (inicio != nullptr) 
        {
            No* temp = inicio;
            inicio = inicio->prox;
            delete temp;
        }
    }

    void adicionarMedico(string nome) 
    {
        No* novo = new No{nome, 0, nullptr};

        if (inicio == nullptr) 
        {
            inicio = novo;
        } else {
            No* atual = inicio;

            while (atual->prox != nullptr) 
            {
                atual = atual->prox;
            }

            atual->prox = novo;
        }

        cout << "Medico adicionado: " << nome << endl;
    }

    string chamarMedico() 
    {
        if (inicio == nullptr) 
        {
            cout << "Nenhum medico disponivel." << endl;
            return "";
        }

        No* temp = inicio;
        string nome = temp->nome;

        inicio = inicio->prox;
        delete temp;

        adicionarMedico(nome);

        cout << "Medico chamado: " << nome << endl;
        return nome;
    }

    void percorrer() 
    {
        No* atual = inicio;

        cout << "\n=== MEDICOS DISPONIVEIS ===" << endl;

        if (atual == nullptr) 
        {
            cout << "Nenhum medico cadastrado." << endl;
            return;
        }

        while (atual != nullptr) 
        {
            cout << atual->nome << endl;
            atual = atual->prox;
        }
    }
};

int main() 
{
    FilaPacientes pacientes;
    PilhaHistorico historico;
    ListaMedicos medicos;

    cout << "=== HOSPITAL CAMPO REAL ===" << endl;

    medicos.adicionarMedico("Dr. Carlos");
    medicos.adicionarMedico("Dra. Ana");
    medicos.adicionarMedico("Dr. Pedro");

    pacientes.enqueue("Joao", 2);
    pacientes.enqueue("Maria", 3);
    pacientes.enqueue("Pedro", 1);

    cout << "\nTotal de pacientes: "
         << pacientes.tamanho() << endl;

    pacientes.frente_peak();
    medicos.percorrer();
        cout << "\n=== INICIANDO ATENDIMENTOS ===" << endl;

    while (!pacientes.vazia()) 
    {
        string medico = medicos.chamarMedico();

        if (medico.empty()) 
        {
            break;
        }

        pacientes.frente_peak();
        historico.push(medico);
        pacientes.dequeue();
    }

    historico.peek();
    historico.imprimirHistorico();

    medicos.percorrer();

    return 0;
}