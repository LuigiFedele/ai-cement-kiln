/*
 * ARQUIVO: ia_forno_cimenteiro.c
 * DESCRIÇÃO: Implementação do modelo Perceptron minimalista
 * (6 entradas, 1 saída) treinado para prever a necessidade
 * de parada (engraxamento) do forno.
 * AMBIENTE: Microcontrolador IoT de baixa capacidade (512 KBs de memória).
 */

#include <stdio.h>

// Bias (peso do limiar/threshold)
#define W0 -1.0000 

// Pesos das 6 Entradas (x1 a x6)
#define W1 0.2467  
#define W2 0.1900 
#define W3 0.2733  
#define W4 0.9600 
#define W5 -0.3400  
#define W6 0.0800 

// =========================================================================
// FUNÇÃO DO NEURÔNIO
// =========================================================================

/**
 * @brief Simula a decisão do neurônio Perceptron.
 *
 * @param x1 Nível Sensor 1 (normalizado)
 * @param x2 Nível Sensor 2 (normalizado)
 * @param x3 Nível Sensor 3 (normalizado)
 * @param x4 Nível Sensor 4 (normalizado)
 * @param x5 Temperatura da Graxa (normalizada)
 * @param x6 Densidade da Graxa (normalizada)
 * @return int Retorna 1 (Produção Ativa) ou -1 (Parada Necessária)
 */
int tomar_decisao(float x1, float x2, float x3, float x4, float x5, float x6) {
    // 1. CÁLCULO DO SOMATÓRIO PONDERADO (f)
    // f = (x1*W1) + (x2*W2) + (x3*W3) + (x4*W4) + (x5*W5) + (x6*W6) + W0
    float f = (x1 * W1) + (x2 * W2) + (x3 * W3) +
              (x4 * W4) + (x5 * W5) + (x6 * W6) + W0;

    // 2. FUNÇÃO DE ATIVAÇÃO BINÁRIA (Sinal / Sign Function)
    if (f > 0.0) {
        // Saída = 1 (Produção Ativa: Manter as esteiras ligadas)
        return 1;
    } else {
        // Saída = -1 (Parada Necessária: Desativar as esteiras e desligar o forno)
        return -1;
    }
}

// =========================================================================
// LOOP PRINCIPAL (Simulação da leitura e decisão)
// =========================================================================

int main() {
    // SIMULAÇÃO DE LEITURA DOS SENSORES (Entradas Normalizadas)
    // Na prática, estas variáveis seriam lidas do hardware do sensor (GPIO/ADC).
    float entrada_sensores[6];
    int decisao;

    // =======================================================================
    // EXEMPLO 1: Condição de produção normal (Provavelmente Saída 1)
    // =======================================================================
    entrada_sensores[0] = 0.1; // x1
    entrada_sensores[1] = 0.2; // x2
    entrada_sensores[2] = 0.1; // x3
    entrada_sensores[3] = 0.2; // x4
    entrada_sensores[4] = 0.3; // x5
    entrada_sensores[5] = 0.4; // x6

    decisao = tomar_decisao(entrada_sensores[0], entrada_sensores[1],
                           entrada_sensores[2], entrada_sensores[3],
                           entrada_sensores[4], entrada_sensores[5]);

    printf("Condição 1: Leitura dos Sensores: {%.2f, %.2f, %.2f, %.2f, %.2f, %.2f}\n",
           entrada_sensores[0], entrada_sensores[1], entrada_sensores[2],
           entrada_sensores[3], entrada_sensores[4], entrada_sensores[5]);
    printf("Decisão do Neurônio (Saída): %d\n", decisao);
    printf("Ação Sugerida: %s\n\n", (decisao == 1) ? "MANTER PRODUÇÃO ATIVA" : "DESLIGAR FORNO/ESTEIRAS");

    // =======================================================================
    // EXEMPLO 2: Condição crítica (Provavelmente Saída -1)
    // Use uma amostra que resultaria em parada no seu treino.
    // =======================================================================
    entrada_sensores[0] = 0.8; // x1
    entrada_sensores[1] = 0.9; // x2
    entrada_sensores[2] = 0.7; // x3
    entrada_sensores[3] = 0.8; // x4
    entrada_sensores[4] = 0.9; // x5
    entrada_sensores[5] = 0.8; // x6

    decisao = tomar_decisao(entrada_sensores[0], entrada_sensores[1],
                           entrada_sensores[2], entrada_sensores[3],
                           entrada_sensores[4], entrada_sensores[5]);

    printf("Condição 2: Leitura dos Sensores: {%.2f, %.2f, %.2f, %.2f, %.2f, %.2f}\n",
           entrada_sensores[0], entrada_sensores[1], entrada_sensores[2],
           entrada_sensores[3], entrada_sensores[4], entrada_sensores[5]);
    printf("Decisão do Neurônio (Saída): %d\n", decisao);
    printf("Ação Sugerida: %s\n", (decisao == 1) ? "MANTER PRODUÇÃO ATIVA" : "DESLIGAR FORNO/ESTEIRAS");

    // O retorno no acionador real seria o comando de ativação/desativação
    // do atuador. Aqui, imprimimos o valor "1" ou "-1" conforme solicitado[cite: 95].
    return 0;
}