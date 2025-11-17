#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//==============================================================
// Estrutura que representa cada sala da mansão
//==============================================================
typedef struct Sala {
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

//==============================================================
// Função: criarSala
// Cria dinamicamente uma sala com o nome informado
//==============================================================
Sala* criarSala(char nome[]) {
    Sala *nova = (Sala*) malloc(sizeof(Sala));

    if (nova == NULL) {
        printf("Erro ao alocar memoria para a sala.\n");
        exit(1);
    }

    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;

    return nova;
}

//==============================================================
// Função: explorarSalas
// Permite ao jogador explorar a mansão interativamente
//==============================================================
void explorarSalas(Sala *atual) {
    char escolha;

    while (1) {
        printf("\nVocê está em: %s\n", atual->nome);

        // Se chegou em um nó-folha (sem caminhos)
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Você chegou a um cômodo sem saídas. Fim da exploração!\n");
            break;
        }

        printf("Escolha seu caminho:\n");
        if (atual->esquerda != NULL) printf("[e] Ir para a esquerda (%s)\n", atual->esquerda->nome);
        if (atual->direita != NULL) printf("[d] Ir para a direita (%s)\n", atual->direita->nome);
        printf("[s] Sair da exploração\n");
        printf("Opção: ");

        scanf(" %c", &escolha);

        if (escolha == 'e' && atual->esquerda != NULL) {
            atual = atual->esquerda;
        } else if (escolha == 'd' && atual->direita != NULL) {
            atual = atual->direita;
        } else if (escolha == 's') {
            printf("Exploração encerrada pelo jogador.\n");
            break;
        } else {
            printf("Opção inválida! Tente novamente.\n");
        }
    }
}


// Desafio Detective Quest
// Tema 4 - Árvores e Tabela Hash
// Este código inicial serve como base para o desenvolvimento das estruturas de navegação, pistas e suspeitos.
// Use as instruções de cada região para desenvolver o sistema completo com árvore binária, árvore de busca e tabela hash.

int main() {

    // Criando manualmente o mapa da mansão (árvore binária fixa)
    Sala *hall      = criarSala("Hall de Entrada");
    Sala *salaEstar = criarSala("Sala de Estar");
    Sala *cozinha   = criarSala("Cozinha");
    Sala *biblioteca= criarSala("Biblioteca");
    Sala *jardim    = criarSala("Jardim");

    // Montando a árvore
    hall->esquerda = salaEstar;
    hall->direita  = cozinha;

    salaEstar->esquerda = biblioteca;  // exemplo de caminho
    salaEstar->direita  = jardim;      // outro caminho

    // Iniciando a exploração
    printf("=== Detective Quest: Explorador da Mansão ===\n");
    printf("Bem-vindo ao sistema de exploração da mansão!\n");

    explorarSalas(hall);
    
    // 🌱 Nível Novato: Mapa da Mansão com Árvore Binária
    //
    // - Crie uma struct Sala com nome, e dois ponteiros: esquerda e direita.
    // - Use funções como criarSala(), conectarSalas() e explorarSalas().
    // - A árvore pode ser fixa: Hall de Entrada, Biblioteca, Cozinha, Sótão etc.
    // - O jogador deve poder explorar indo à esquerda (e) ou à direita (d).
    // - Finalize a exploração com uma opção de saída (s).
    // - Exiba o nome da sala a cada movimento.
    // - Use recursão ou laços para caminhar pela árvore.
    // - Nenhuma inserção dinâmica é necessária neste nível.

    // 🔍 Nível Aventureiro: Armazenamento de Pistas com Árvore de Busca
    //
    // - Crie uma struct Pista com campo texto (string).
    // - Crie uma árvore binária de busca (BST) para inserir as pistas coletadas.
    // - Ao visitar salas específicas, adicione pistas automaticamente com inserirBST().
    // - Implemente uma função para exibir as pistas em ordem alfabética (emOrdem()).
    // - Utilize alocação dinâmica e comparação de strings (strcmp) para organizar.
    // - Não precisa remover ou balancear a árvore.
    // - Use funções para modularizar: inserirPista(), listarPistas().
    // - A árvore de pistas deve ser exibida quando o jogador quiser revisar evidências.

    // 🧠 Nível Mestre: Relacionamento de Pistas com Suspeitos via Hash
    //
    // - Crie uma struct Suspeito contendo nome e lista de pistas associadas.
    // - Crie uma tabela hash (ex: array de ponteiros para listas encadeadas).
    // - A chave pode ser o nome do suspeito ou derivada das pistas.
    // - Implemente uma função inserirHash(pista, suspeito) para registrar relações.
    // - Crie uma função para mostrar todos os suspeitos e suas respectivas pistas.
    // - Adicione um contador para saber qual suspeito foi mais citado.
    // - Exiba ao final o “suspeito mais provável” baseado nas pistas coletadas.
    // - Para hashing simples, pode usar soma dos valores ASCII do nome ou primeira letra.
    // - Em caso de colisão, use lista encadeada para tratar.
    // - Modularize com funções como inicializarHash(), buscarSuspeito(), listarAssociacoes().

    return 0;
}

