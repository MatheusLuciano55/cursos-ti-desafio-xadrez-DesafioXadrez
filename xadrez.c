/*
 * Arquivo: xadrez.c
 * Autor: [Seu Nome]
 * Descrição: Simulação do movimento das peças de xadrez (Torre, Bispo e Rainha)
 * utilizando diferentes estruturas de repetição (for, while, do-while)
 * conforme o desafio proposto.
 */

#include <stdio.h> // Biblioteca padrão de entrada/saída para usar printf

// Definição de constantes para o número de casas a mover
#define CASAS_TORRE 5
#define CASAS_BISPO 5
#define CASAS_RAINHA 8

/*
 * Função principal (main)
 * Ponto de entrada do programa.
 */
int main() {
    
    // Declaração de variáveis de controle para os loops
    // Usaremos variáveis diferentes para 'while' e 'do-while'
    // A variável do 'for' será declarada dentro do próprio loop
    int contador_while;
    int contador_do_while;

    printf("Iniciando simulação de movimentos de xadrez...\n\n");

    // --- 1. Simulação da Torre (usando 'for') ---
    // A Torre deve mover-se 5 casas para a Direita.
    // O loop 'for' é ideal para quando sabemos exatamente quantas vezes
    // queremos que o bloco de código seja executado.
    
    printf("--- Simulação da Torre (%d casas para Direita) ---\n", CASAS_TORRE);

    // i = 0: Inicializa o contador 'i' em 0.
    // i < CASAS_TORRE: A condição de parada. O loop executa enquanto 'i' for 0, 1, 2, 3, 4 (total de 5 vezes).
    // i++: Incrementa 'i' em 1 ao final de cada iteração.
    for (int i = 0; i < CASAS_TORRE; i++) {
        // Imprime a direção do movimento a cada casa percorrida
        printf("Direita\n");
    }

    printf("\n"); // Adiciona uma linha em branco para melhor legibilidade

    // --- 2. Simulação do Bispo (usando 'while') ---
    // O Bispo deve mover-se 5 casas na diagonal (Cima, Direita).
    // O loop 'while' verifica a condição ANTES de executar o bloco.
    
    printf("--- Simulação do Bispo (%d casas para Cima, Direita) ---\n", CASAS_BISPO);

    contador_while = 0; // 1. Inicialização da variável de controle

    // 2. Condição de parada: O loop executa enquanto o contador for menor que 5.
    while (contador_while < CASAS_BISPO) {
        // Imprime a direção do movimento diagonal
        printf("Cima, Direita\n");
        
        contador_while++; // 3. Incremento da variável de controle DENTRO do loop
    }

    printf("\n"); // Adiciona uma linha em branco

    // --- 3. Simulação da Rainha (usando 'do-while') ---
    // A Rainha deve mover-se 8 casas para a Esquerda.
    // O loop 'do-while' executa o bloco de código PELO MENOS UMA VEZ
    // e só então verifica a condição.
    
    printf("--- Simulação da Rainha (%d casas para Esquerda) ---\n", CASAS_RAINHA);

    contador_do_while = 0; // 1. Inicialização da variável de controle

    do {
        // Imprime a direção do movimento
        printf("Esquerda\n");
        
        contador_do_while++; // 3. Incremento da variável de controle DENTRO do loop

    } while (contador_do_while < CASAS_RAINHA); // 2. Condição de parada (verificada no final)

    printf("\nSimulação concluída.\n");
    
    return 0; // Indica que o programa foi executado com sucesso
}
