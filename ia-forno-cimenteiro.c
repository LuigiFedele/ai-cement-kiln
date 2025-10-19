#include <stdio.h>

#define W0 -1.0000
#define W1 0.2467
#define W2 0.1900
#define W3 0.2733
#define W4 0.9600
#define W5 -0.3400
#define W6 0.0800

/**
* @brief Simula a decisão do neurônio Perceptron.
* @param x1 Nível Sensor 1 (normalizado)
* @param x2 Nível Sensor 2 (normalizado)
* @param x3 Nível Sensor 3 (normalizado)
* @param x4 Nível Sensor 4 (normalizado)
* @param x5 Temperatura da Graxa (normalizada)
* @param x6 Densidade da Graxa (normalizada)
* @return int Retorna 1 (Produção Ativa) ou -1 (Parada Necessária)
*/

int tomar_decisao(float x1, float x2, float x3, float x4, float x5, float x6) {
	float f = (x1 * W1) + (x2 * W2) + (x3 * W3) + (x4 * W4) + (x5 * W5) + (x6 * W6) + W0;
	if (f > 0.0) {
		return 1;
	} else {
		return -1;
	}
}

  

int main() {
	float entrada_sensores[6];
	int decisao;

	entrada_sensores[0] = 0.1;
	entrada_sensores[1] = 0.2;
	entrada_sensores[2] = 0.1;
	entrada_sensores[3] = 0.2;
	entrada_sensores[4] = 0.3;
	entrada_sensores[5] = 0.4;

	decisao = tomar_decisao(entrada_sensores[0], entrada_sensores[1], entrada_sensores[2], entrada_sensores[3], entrada_sensores[4], entrada_sensores[5]);
  
	
	printf("Condição 1: Leitura dos Sensores: {%.2f, %.2f, %.2f, %.2f, %.2f, %.2f}\n", entrada_sensores[0], entrada_sensores[1], entrada_sensores[2], entrada_sensores[3], entrada_sensores[4], entrada_sensores[5]);
	
	printf("Decisão do Neurônio (Saída): %d\n", decisao);
	printf("Ação Sugerida: %s\n\n", (decisao == 1) ? "MANTER PRODUÇÃO ATIVA" : "DESLIGAR FORNO/ESTEIRAS");

	entrada_sensores[0] = 0.8;
	entrada_sensores[1] = 0.9;
	entrada_sensores[2] = 0.7;
	entrada_sensores[3] = 0.8;
	entrada_sensores[4] = 0.9;
	entrada_sensores[5] = 0.8;

	decisao = tomar_decisao(entrada_sensores[0], entrada_sensores[1], entrada_sensores[2], entrada_sensores[3], entrada_sensores[4], entrada_sensores[5]);

  

	printf("Condição 2: Leitura dos Sensores: {%.2f, %.2f, %.2f, %.2f, %.2f, %.2f}\n", entrada_sensores[0], entrada_sensores[1], entrada_sensores[2], entrada_sensores[3], entrada_sensores[4], entrada_sensores[5]);

	printf("Decisão do Neurônio (Saída): %d\n", decisao);
	printf("Ação Sugerida: %s\n", (decisao == 1) ? "MANTER PRODUÇÃO ATIVA" : "DESLIGAR FORNO/ESTEIRAS");
	return 0;
}