#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAX_COLUNAS 7
#define MAX_LINHAS 11

/*Função para receber a coluna para aceitar apenas valores entre 3 e 7
 * @return retorna o valor recebido da coluna para a inicialização da matriz
 *
 */
int receberColuna()
{
	int coluna;
	do
	{
		cout << "Insira um valor para a coluna da matriz (entre 3 e 7): \n";
		cin >> coluna;
		if (coluna < 3 || coluna > 7)
		{
			cout << "Valor invalido, o numero de colunas deve estar entre 3 e 7 \n";
		}
	} while (coluna < 3 || coluna > 7);
	return coluna;
}
/* Função para receber a linha que aceita apenas o valor 11
 *  @return retorna o valor recebido da linha para a inicialização da matriz
 */
int receberLinha()
{
	int linha;
	do
	{
		cout << "Insira um valor para a linha da matriz (deve ser 11): \n";
		cin >> linha;
		if (linha != 11)
		{
			cout << "Valor inválido, o numero de linhas deve ser 11 \n";
		}
	} while (linha != 11);
	return linha;
}
/*
 * Função para preencher a matriz com valores inseridos pelo usuário.
 *
 * Esta função percorre cada célula da matriz e solicita ao usuário que insira os valores
 * dos indicadores clínicos e diagnósticos dos pacientes. A última coluna da matriz
 * representa o diagnóstico do paciente, onde:
 * - 1 significa que o paciente está saudável.
 * - -1 significa que o paciente está doente.
 * - 0 significa que o paciente ainda não foi diagnosticado (última linha).
 *
 * Para os pacientes da 1ª à 10ª linha, o usuário deve inserir manualmente os valores
 * dos indicadores clínicos e o diagnóstico. Para o último paciente (11ª linha), o
 * diagnóstico é automaticamente definido como 0, indicando que ele ainda não foi
 * diagnosticado.
 *
 * @param matriz A matriz que será preenchida com os valores dos pacientes.
 * @param linha O número de linhas da matriz (sempre 11).
 * @param coluna O número de colunas da matriz (entre 3 e 7).
 */
void preencherMatriz(float matriz[MAX_LINHAS][MAX_COLUNAS], int linha, int coluna)
{
	for (int i = 0; i < linha; i++)
	{
		for (int j = 0; j < coluna; j++)
		{
			if (j == coluna - 1)
			{
				if (i == linha - 1)
				{
					matriz[i][j] = 0.0;
				}
				else
				{
					int diagnostico;
					do
					{
						cout << "Insira o diagnostico do paciente " << i + 1 << " (1 para saudavel, -1 para doente): ";
						cin >> diagnostico;
						if (diagnostico != 1 && diagnostico != -1)
						{
							cout << "Valor invalido! Digite 1 para saudavel ou -1 para doente.\n";
						}
					} while (diagnostico != 1 && diagnostico != -1);
					matriz[i][j] = (float)diagnostico;
				}
			}
			else
			{
				cout << "Insira o indicador clinico " << j + 1 << " do paciente " << i + 1 << ": ";
				cin >> matriz[i][j];
			}
		}
	}
}
/*
 * Função para que a matriz seja mostrada no terminal
 * @param matriz a tabela indicadora de saude
 * @param linha o numero de linhas que a matriz possui
 * @param coluna o numero de colunas que a matriz possui
 */
void mostrarMatriz(float matriz[MAX_LINHAS][MAX_COLUNAS], int linha, int coluna)
{
	cout << "\n========== TABELA DE PACIENTES ==========\n";
	for (int i = 0; i < linha; i++)
	{
		cout << "Paciente " << i + 1 << ": ";
		for (int j = 0; j < coluna; j++)
		{
			cout << "[ " << matriz[i][j] << " ] ";
		}
		cout << "\n--------------------------------------------------\n";
	}
}
/*
 * Função para calcular a distância euclidiana entre dois vetores
 * @param *p ponteira que direciona a uma fração da matriz
 * @param *q ponteira que direciona a outra fração da matriz
 * @param tamanho relaciona-se com o tamanho que essas frações possuem
 * @return valor da distancia euclidiana entre esses dois pontos
 */
float distanciaEuclidiana(float *p, float *q, int tamanho)
{
	float soma = 0;
	for (int i = 0; i < tamanho; i++)
	{
		soma += pow(q[i] - p[i], 2);
	}
	return sqrt(soma);
}
/*
 * Função para encontrar o índice do paciente mais próximo
 * @param matriz relaciona-se a tabela toda de indicador de saude
 * @param linha o numero de linhas que a tabela possui
 * @param coluna o numero total de colunas que a tabela possui
 * @return o indice do paciente mais proximo
 */
int pacienteMaisProximo(float matriz[MAX_LINHAS][MAX_COLUNAS], int linha, int coluna)
{
	int indiceMaisProximo = 0;
	float menorDistancia = distanciaEuclidiana(matriz[0], matriz[linha - 1], coluna - 1);

	for (int i = 1; i < linha - 1; i++)
	{
		float distancia = distanciaEuclidiana(matriz[i], matriz[linha - 1], coluna - 1);
		if (distancia < menorDistancia)
		{
			menorDistancia = distancia;
			indiceMaisProximo = i;
		}
	}

	return indiceMaisProximo;
}
/*
 *  Função para classificar o último paciente com base no paciente mais próximo
 * @param matriz tabela indicador de saude
 * @param linha o numero de linhas que a tabela possui
 * @param coluna o numero de colunas que a tabela possui
 */
void classificarPaciente(float matriz[][MAX_COLUNAS], int linha, int coluna)
{
	int indice = pacienteMaisProximo(matriz, linha, coluna);
	matriz[linha - 1][coluna - 1] = matriz[indice][coluna - 1];
}

int main()
{
	int coluna = receberColuna();
	int linha = receberLinha();
	float matriz[MAX_LINHAS][MAX_COLUNAS];

	preencherMatriz(matriz, linha, coluna);
	cout << "\n Paciente 11 ainda nao diagnosticado...";
	mostrarMatriz(matriz, linha, coluna);

	classificarPaciente(matriz, linha, coluna);

	cout << "\n========== TABELA FINAL ==========\n";
	mostrarMatriz(matriz, linha, coluna);

	if (matriz[linha - 1][coluna - 1] == 1)
	{
		cout << "PACIENTE 11 ESTA SAUDAVEL \n";
	}
	else
	{
		cout << "PACIENTE 11 ESTA DOENTE \n";
	}

	return 0;
}