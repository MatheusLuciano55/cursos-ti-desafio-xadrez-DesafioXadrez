/*
 * Arquivo: xadrez.c
 * Autor: [Seu Nome]
 * Descrição: Simulação do movimento das peças de xadrez (Torre, Bispo, Rainha e Cavalo)
 * utilizando diferentes estruturas de repetição (for, while, do-while) e
 * loops aninhados para o Cavalo.
 */

#include <stdio.h> // Biblioteca padrão de entrada/saída para usar printf

// --- Constantes para as peças anteriores ---
#define CASAS_TORRE 5
#define CASAS_BISPO 5
#define CASAS_RAINHA 8

// --- Constantes para o Cavalo ---
// Definimos o número de movimentos 'L' (neste caso, apenas 1)
#define MOVIMENTOS_L_CAVALO 1 
// Definimos os passos de cada componente do 'L'
#define PASSOS_VERTICAIS_CAVALO 2
#define PASSOS_HORIZONTAIS_CAVALO 1


/*
 * Função principal (main)
 * Ponto de entrada do programa.
 */
int main() {
    
    // Declaração de variáveis de controle para os loops
    int contador_while;
    int contador_do_while;

    printf("Iniciando simulação de movimentos de xadrez...\n\n");

    // --- 1. Simulação da Torre (usando 'for') ---
    // A Torre deve mover-se 5 casas para a Direita.
    
    printf("--- Simulação da Torre (%d casas para Direita) ---\n", CASAS_TORRE);

    // O loop 'for' é usado pois sabemos o número exato de iterações.
    for (int i = 0; i < CASAS_TORRE; i++) {
        printf("Direita\n");
    }

    printf("\n"); // Adiciona uma linha em branco para melhor legibilidade

    // --- 2. Simulação do Bispo (usando 'while') ---
    // O Bispo deve mover-se 5 casas na diagonal (Cima, Direita).
    
    printf("--- Simulação do Bispo (%d casas para Cima, Direita) ---\n", CASAS_BISPO);

    contador_while = 0; // 1. Inicialização

    // O loop 'while' verifica a condição (2) antes de executar.
    while (contador_while < CASAS_BISPO) {
        printf("Cima, Direita\n");
        contador_while++; // 3. Incremento
    }

    printf("\n"); // Adiciona uma linha em branco

    // --- 3. Simulação da Rainha (usando 'do-while') ---
    // A Rainha deve mover-se 8 casas para a Esquerda.
    
    printf("--- Simulação da Rainha (%d casas para Esquerda) ---\n", CASAS_RAINHA);

    contador_do_while = 0; // 1. Inicialização

    // O loop 'do-while' executa o bloco primeiro e verifica a condição (2) depois.
    do {
        printf("Esquerda\n");
        contador_do_while++; // 3. Incremento
    } while (contador_do_while < CASAS_RAINHA); 

    printf("\n"); // Adiciona uma linha em branco (Requisito)

    // --- 4. Simulação do Cavalo (usando 'for' e 'while' aninhados) ---
    // O Cavalo deve mover-se 2 casas para Baixo e 1 para Esquerda.
    // Usaremos um loop 'for' externo para controlar o número total de 
    // movimentos 'L' (neste caso, 1) e loops 'while' internos
    // para os passos de cada componente do 'L'.
    
    printf("--- Simulação do Cavalo (L: %d Baixo, %d Esquerda) ---\n", 
           PASSOS_VERTICAIS_CAVALO, PASSOS_HORIZONTAIS_CAVALO);

    // Loop externo (FOR) - Controla quantos movimentos 'L' o cavalo fará.
    // Executa 1 vez (de l_move = 0 até l_move < 1).
    for (int l_move = 0; l_move < MOVIMENTOS_L_CAVALO; l_move++) {
        
        // Comentário: Início da estrutura de loops aninhados.
        
        // Loop interno 1 (WHILE) - Simula os passos verticais.
        // Este loop 'while' está ANINHADO dentro do loop 'for'.
        // (Cumprindo o requisito de 'for' + 'while' aninhados).
        int v_passos = 0; // Inicializa contador de passos verticais
        while (v_passos < PASSOS_VERTICAIS_CAVALO) {
            printf("Baixo\n");
            v_passos++;
        }

        // Loop interno 2 (WHILE) - Simula os passos horizontais.
        // Este loop também está aninhado no 'for' e é executado
        // em sequência após o primeiro loop interno.
        int h_passos = 0; // Inicializa contador de passos horizontais
        while (h_passos < PASSOS_HORIZONTAIS_CAVALO) {
            printf("Esquerda\n");
            h_passos++;
        }
        
        // Comentário: Fim da estrutura de loops aninhados.
    }


    printf("\nSimulação concluída.\n");
    
    return 0; // Indica que o programa foi executado com sucesso
}
