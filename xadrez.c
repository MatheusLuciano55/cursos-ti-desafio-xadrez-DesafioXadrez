/*
 * Arquivo: xadrez.c
 * Autor: [Seu Nome]
 * Descrição: Simulação avançada do movimento de peças de xadrez.
 * - Torre, Bispo e Rainha usam Funções Recursivas.
 * - Cavalo usa Loops Aninhados Complexos (com break/continue).
 * - O Bispo implementa recursão (loop externo) e loop 'for' (loop interno).
 */

#include <stdio.h> // Biblioteca padrão de entrada/saída

// --- Constantes de Movimento ---

// Torre: 5 casas para a direita
#define CASAS_TORRE 5

// Bispo: 5 casas na diagonal (Cima, Direita).
// Para a implementação (Recursão + Loop), trataremos como:
// 5 passos "verticais" (controlados pela recursão)
// 1 passo "horizontal" (controlado pelo loop 'for' interno)
#define CASAS_BISPO_V 5
#define CASAS_BISPO_H 1 // O loop interno roda 1 vez por passo vertical

// Rainha: 8 casas para a esquerda
#define CASAS_RAINHA 8

// Cavalo: 1 movimento em 'L' (2 Cima, 1 Direita)
#define MOVIMENTOS_L_CAVALO 1
#define PASSOS_V_CAVALO 2
#define PASSOS_H_CAVALO 1

// --- Protótipos das Funções Recursivas ---

/**
 * @brief Simula o movimento da Torre (Direita) usando recursão.
 * @param casas O número de casas restantes para mover.
 */
void moverTorreRec(int casas);

/**
 * @brief Simula o movimento da Rainha (Esquerda) usando recursão.
 * @param casas O número de casas restantes para mover.
 */
void moverRainhaRec(int casas);

/**
 * @brief Simula o movimento do Bispo (Cima, Direita) usando recursão E 
 * loops aninhados.
 * * A recursão simula o "loop externo" (movimento vertical).
 * O loop 'for' simula o "loop interno" (movimento horizontal).
 * * @param casas_v Casas verticais restantes (controladas pela recursão).
 * @param casas_h Casas horizontais por passo (controladas pelo loop 'for').
 */
void moverBispoRecAninhado(int casas_v, int casas_h);


/*
 * Função principal (main)
 * Ponto de entrada do programa.
 */
int main() {
    
    printf("Iniciando simulação avançada de movimentos de xadrez...\n\n");

    // --- 1. Simulação da Torre (usando Recursão) ---
    printf("--- Simulação da Torre (%d casas para Direita) [Recursivo] ---\n", CASAS_TORRE);
    // Chama a função recursiva para iniciar o movimento
    moverTorreRec(CASAS_TORRE);

    printf("\n"); // Adiciona uma linha em branco

    // --- 2. Simulação do Bispo (usando Recursão + Loop Aninhado) ---
    printf("--- Simulação do Bispo (%d casas Cima, Direita) [Recursão + Loop] ---\n", CASAS_BISPO_V);
    // Chama a função que combina recursão (loop externo) e 'for' (loop interno)
    moverBispoRecAninhado(CASAS_BISPO_V, CASAS_BISPO_H);

    printf("\n"); // Adiciona uma linha em branco

    // --- 3. Simulação da Rainha (usando Recursão) ---
    printf("--- Simulação da Rainha (%d casas para Esquerda) [Recursivo] ---\n", CASAS_RAINHA);
    // Chama a função recursiva para iniciar o movimento
    moverRainhaRec(CASAS_RAINHA);

    printf("\n"); // Adiciona uma linha em branco

    // --- 4. Simulação do Cavalo (usando Loops Complexos) ---
    // O Cavalo deve mover-se 2 casas para Cima e 1 para Direita.
    // Usamos loops aninhados com múltiplas variáveis, 'continue' e 'break'.
    
    printf("--- Simulação do Cavalo (L: %d Cima, %d Direita) [Loops Complexos] ---\n", 
           PASSOS_V_CAVALO, PASSOS_H_CAVALO);

    // Loop externo (FOR): Controla quantos movimentos 'L' completos faremos.
    // (Executa apenas 1 vez, conforme MOVIMENTOS_L_CAVALO)
    for (int l_move = 0; l_move < MOVIMENTOS_L_CAVALO; l_move++) {
        
        // Variáveis de controle múltiplas para o loop interno
        int total_passos = PASSOS_V_CAVALO + PASSOS_H_CAVALO;
        int passos_v_dados = 0; // Controla os passos verticais
        int passos_h_dados = 0; // Controla os passos horizontais

        // Loop interno (FOR): Itera pelo número total de passos (2+1 = 3)
        // Este loop simula cada etapa do movimento 'L'.
        for (int passo_atual = 1; passo_atual <= total_passos; passo_atual++) {
            
            // Condição 1: Movimento Vertical (Cima)
            if (passos_v_dados < PASSOS_V_CAVALO) {
                printf("Cima\n");
                passos_v_dados++;
                
                // [REQUISITO: uso do 'continue']
                // Pula o resto do loop e vai para a próxima iteração (passo_atual++)
                // Isso garante que ele só faça 1 passo (vertical) por iteração.
                continue; 
            }

            // Esta parte só é alcançada após os passos verticais terminarem
            // (graças ao 'continue' acima)
            
            // Condição 2: Movimento Horizontal (Direita)
            if (passos_h_dados < PASSOS_H_CAVALO) {
                printf("Direita\n");
                passos_h_dados++;
            }

            // Condição 3: Controle de fluxo com 'break'
            // [REQUISITO: uso do 'break']
            // Se já demos todos os passos horizontais necessários,
            // podemos sair do loop interno imediatamente,
            // mesmo que 'passo_atual' ainda não tenha chegado a 'total_passos'.
            if (passos_h_dados >= PASSOS_H_CAVALO) {
                //printf("DEBUG: Movimento L completado, saindo do loop interno.\n");
                break; // Sai do loop 'for' interno
            }
        }
    }

    printf("\nSimulação concluída.\n");
    
    return 0; // Indica que o programa foi executado com sucesso
}

// --- Definições das Funções Recursivas ---

/**
 * Definição da função recursiva da Torre.
 */
void moverTorreRec(int casas) {
    // 1. Caso Base (Condição de Parada)
    // Se não há mais casas para mover, a função para de se chamar.
    if (casas <= 0) {
        return;
    }
    
    // 2. Ação (Trabalho)
    // Imprime o movimento desta casa
    printf("Direita\n");
    
    // 3. Chamada Recursiva (Passo)
    // Chama a si mesma, reduzindo o problema (casas - 1)
    moverTorreRec(casas - 1);
}

/**
 * Definição da função recursiva da Rainha.
 */
void moverRainhaRec(int casas) {
    // 1. Caso Base (Condição de Parada)
    if (casas <= 0) {
        return;
    }
    
    // 2. Ação (Trabalho)
    printf("Esquerda\n");
    
    // 3. Chamada Recursiva (Passo)
    moverRainhaRec(casas - 1);
}

/**
 * Definição da função recursiva/aninhada do Bispo.
 */
void moverBispoRecAninhado(int casas_v, int casas_h) {
    // 1. Caso Base (Condição de Parada da Recursão - "Loop Externo")
    // Se não há mais passos "verticais", paramos.
    if (casas_v <= 0) {
        return;
    }

    // 2. Ação (Trabalho - "Loop Interno")
    // Este loop 'for' simula o "loop interno" (horizontal).
    // Conforme a constante (CASAS_BISPO_H = 1), ele executa 1 vez
    // para cada chamada recursiva (passo "vertical").
    for (int h = 0; h < casas_h; h++) {
        // A impressão combina as duas direções para a diagonal
        printf("Cima, Direita\n");
    }

    // 3. Chamada Recursiva (Passo - "Loop Externo")
    // Chama a si mesma, reduzindo o "passo vertical" (casas_v - 1)
    moverBispoRecAninhado(casas_v - 1, casas_h);
}
