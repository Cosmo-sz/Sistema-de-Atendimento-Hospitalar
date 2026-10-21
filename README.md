🏥 Sistema de Atendimento Hospitalar

Sistema desenvolvido em C++ para simular o atendimento de pacientes do Hospital Campo Real, utilizando estruturas de dados lineares implementadas manualmente.

📚 Disciplina

Programação e Sistemas Computacionais II

Tema: Estruturas de Dados Lineares (EDL)

Professor: Giovane Galvão
Instituição: Campo Real — Engenharia de Software

👥 Squad

Nome do squad: Cosmos

Integrantes:

- Pierre dos Santos Coelho
- Rafael Del Antonio
- Lucas  Geraldo Rosa
- Leticia hardt da luz

---

🎯 Objetivo

Desenvolver um sistema simples para gerenciamento de atendimento hospitalar utilizando três estruturas de dados lineares:

- Fila (FIFO) — gerenciamento dos pacientes;
- Pilha (LIFO) — armazenamento do histórico de atendimentos;
- Lista Encadeada — gerenciamento dos médicos disponíveis.

O sistema também possui um relatório final dos atendimentos realizados.

---

🧩 Funcionalidades

R1 — Fila de Pacientes

A fila utiliza o conceito FIFO (First In, First Out).

Funcionalidades implementadas:

- "enqueue(nome, urgencia)" — adiciona um paciente à fila;
- "dequeue()" — remove o paciente da frente;
- "frente_peak()" — consulta o primeiro paciente sem removê-lo;
- "tamanho()" — retorna a quantidade de pacientes.

Os níveis de urgência são:

- "1" — Baixa
- "2" — Média
- "3" — Alta

R2 — Histórico de Atendimentos

O histórico utiliza uma Pilha (LIFO).

Funcionalidades:

- "push(nome)" — adiciona um atendimento ao histórico;
- "pop()" — remove o atendimento mais recente;
- "peek()" — consulta o atendimento do topo sem removê-lo.

R3 — Lista de Médicos

Os médicos são armazenados em uma Lista Encadeada.

Funcionalidades:

- "adicionarMedico(nome)" — adiciona um médico à lista;
- "chamarMedico()" — chama o próximo médico disponível;
- "percorrer()" — lista os médicos cadastrados.

Após realizar um atendimento, o médico retorna à lista de disponíveis.

R4 — Relatório Final

O sistema registra todos os atendimentos realizados e permite visualizar o histórico.

O relatório:

- mostra os atendimentos do mais recente para o mais antigo;
- utiliza uma pilha auxiliar para preservar os dados;
- não destrói o histórico original.

---

🛠️ Tecnologias

- C++
- C++17
- Estruturas de Dados Lineares
- Lista Encadeada
- Ponteiros
- Alocação dinâmica de memória

Não foram utilizadas classes da STL, como:

- "vector"
- "queue"
- "stack"
- "list"

Toda a implementação foi realizada manualmente utilizando a "struct No" fornecida no template.

---

▶️ Como compilar

É necessário possuir o compilador g++ instalado.

Execute no terminal:

g++ -std=c++17 -Wall -o atendimento atendimento_template.cpp

Para executar:

./atendimento

No Windows, caso necessário:

atendimento.exe

---

💻 Exemplo de saída

=== SISTEMA DE ATENDIMENTO HOSPITALAR ===

--- PACIENTES NA FILA ---
Paciente: Ana | Urgência: 3
Paciente: Carlos | Urgência: 2
Paciente: Maria | Urgência: 1

--- CHAMANDO PACIENTES ---

Atendendo: Ana
Médico: Dr. João

Atendendo: Carlos
Médico: Dra. Maria

Atendendo: Maria
Médico: Dr. João

--- MÉDICOS DISPONÍVEIS ---
Dr. João
Dra. Maria

--- HISTÓRICO DE ATENDIMENTOS ---
Maria
Carlos
Ana

--- RELATÓRIO FINAL ---
Atendimentos realizados: 3

«A saída acima é apenas um exemplo. A saída real pode variar conforme os dados utilizados no programa.»

---

🧠 Estruturas utilizadas

Estrutura| Aplicação| Regra
Fila| Pacientes| FIFO
Pilha| Histórico| LIFO
Lista Encadeada| Médicos| Encadeamento por ponteiros

---

💾 Gerenciamento de memória

Todos os nós criados dinamicamente com "new" possuem seu respectivo "delete", evitando vazamentos de memória.

O projeto também foi desenvolvido para compilar sem warnings utilizando:

g++ -std=c++17 -Wall

---

📌 Requisitos atendidos

- [x] R1 — Fila de pacientes
- [x] R2 — Histórico com pilha
- [x] R3 — Lista de médicos
- [x] R4 — Relatório final
- [x] Sem utilização de classes da STL
- [x] Gerenciamento de memória com "new"/"delete"
- [x] Compilação com C++17
- [x] README com instruções de compilação e exemplo de saída

---

📁 Estrutura do projeto

squad-atendimento-[nome]/
├── atendimento_template.cpp
└── README.md

---

👨‍💻 Commits

O desenvolvimento foi dividido em commits por requisito:

R1: Implementa fila de pacientes
R2: Implementa histórico com pilha
R3: Implementa lista de médicos
R4: Implementa relatório final

Cada requisito possui seu respectivo commit para facilitar o acompanhamento do desenvolvimento.