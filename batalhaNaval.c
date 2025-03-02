#include <stdio.h>

#define LINHAS 10 //Define o tamanho do tabuleiro em linhas
#define COLUNAS 10 //Define o tamanho do tabuleiro em colunas

int tabuleiro[LINHAS][COLUNAS]; //Define o tabuleiro
int linha, coluna, linha2, coluna2, verificacao; //Define as variáveis de linha, coluna, linha2, coluna2 e verificação

void imprimirTabuleiro(int tabuleiro[LINHAS][COLUNAS]) //Função para imprimir o tabuleiro
{
  // int numero = 0;
  for (int i = 0; i < LINHAS; i++) //Loop para percorrer as linhas
  {
    for (int j = 0; j < COLUNAS; j++) //Loop para percorrer as colunas
    {
      printf("%d ", tabuleiro[i][j]); //Imprime o tabuleiro
    }
    printf("\n"); //Pula uma linha para o tabuleiro ficar organizado
  }
}
void posicao1(int linha, int coluna) //Função para posicionar o navio 1
{
  do //Loop de posicionamento
  {
    printf("\n\nEscolha uma linha de 1 a 10: "); //Pede para o usuário escolher uma linha
    scanf("%d", &linha); //Lê a linha escolhida
    printf("\n\nEscolha uma coluna de 1 a 10: "); //Pede para o usuário escolher uma coluna
    scanf("%d", &coluna); //Lê a coluna escolhida
    if (linha > 0 && linha <= LINHAS && coluna <= COLUNAS && coluna > 0) //Verifica se a linha e a coluna escolhidas estão dentro do tabuleiro
    {
      printf("Posições válidas.\n"); //Imprime que as posições são válidas
      tabuleiro[linha - 1][coluna - 1] = 3; //Posiciona o navio na posição escolhida
      verificacao = 0; //Atribui 0 à variável de verificação
      if (linha > 2) //verifica se a linha escolhida é ou não anterior a 3
      {
        tabuleiro[linha - 2][coluna - 1] = 3; //Posiciona o navio na linha anterior
        tabuleiro[linha - 3][coluna - 1] = 3; //Posiciona o navio na linha anterior à anterior
      }
      else //Se a linha escolhida for anterior a 3
      {
        tabuleiro[linha][coluna - 1] = 3; //Posiciona o navio na linha posterior
        tabuleiro[linha + 1][coluna - 1] = 3; //Posiciona o navio na linha posterior à posterior
      }
    }
    else //Se a linha e a coluna escolhidas não estiverem dentro do tabuleiro
    {
      printf("Posições inválidas.\n"); //Imprime que as posições são inválidas
      verificacao = 1; //Atribui 1 à variável de verificação
    }
  } while (verificacao == 1); //Enquanto a verificação for igual a 1, o loop continua e o jogador deve escolher outra posição
}
void posicao2(int linha2, int coluna2) //Função para posicionar o navio 2
{
  do //Loop de posicionamento
  {
    printf("\n\nEscolha uma linha de 1 a 10 para a segunda posição: "); //Pede para o usuário escolher uma linha para a segunda posição
    scanf("%d", &linha2); //Lê a linha escolhida
    printf("\n\nEscolha uma coluna de 1 a 10 para a segunda posição: "); //Pede para o usuário escolher uma coluna para a segunda posição
    scanf("%d", &coluna2); //Lê a coluna escolhida

    int sobreposicao = 0; //Inicializa a variável de sobreposição com 0
    if (tabuleiro[linha2 - 1][coluna2 - 1] == 3 || (coluna2 - 2 >= 0 && tabuleiro[linha2 - 1][coluna2 - 2] == 3) || (coluna2 - 3 >= 0 && tabuleiro[linha2 - 1][coluna2 - 3] == 3)) //Verifica se a posição escolhida está ocupada e/ou se está fora do tabuleiro
    {
      sobreposicao = 1; //Atribui 1 à variável de sobreposição se a posição estiver ocupada e/ou fora do tabuleiro
    }

    if (linha2 > 0 && linha2 <= LINHAS && coluna2 <= COLUNAS && coluna2 > 0 && tabuleiro[linha2 - 1][coluna2 - 1] != 3 && sobreposicao == 0) //Verifica se a linha e a coluna escolhidas estão dentro do tabuleiro e se a posição não está ocupada
    {
      printf("Posições válidas.\n"); //Imprime que as posições são válidas
      tabuleiro[linha2 - 1][coluna2 - 1] = 3; //Posiciona o navio na posição escolhida
      verificacao = 0; //Atribui 0 à variável de verificação
      if (coluna2 > 2) //Verifica se a coluna escolhida é ou não anterior a 3
      {
        tabuleiro[linha2 - 1][coluna2 - 2] = 3; //Posiciona o navio na coluna anterior
        tabuleiro[linha2 - 1][coluna2 - 3] = 3; //Posiciona o navio na coluna anterior à anterior
      }
      else //Se a coluna escolhida for anterior a 3
      {
        tabuleiro[linha2 - 1][coluna2] = 3; //Posiciona o navio na coluna posterior
        tabuleiro[linha2 - 1][coluna2 + 1] = 3; //Posiciona o navio na coluna posterior à posterior
      }
    }
    else //Se a linha e a coluna escolhidas não estiverem dentro do tabuleiro ou a posição estiver ocupada
    {
      printf("Posições inválidas ou ocupadas.\n"); //Imprime que as posições são inválidas ou ocupadas
      verificacao = 1; //Atribui 1 à variável de verificação
    }
  } while (verificacao == 1);
}

int main() //Função principal
{
  imprimirTabuleiro(tabuleiro); //Chama a função para imprimir o tabuleiro
  posicao1(linha, coluna); //Chama a função para posicionar o navio 1
  imprimirTabuleiro(tabuleiro); //Chama a função para imprimir o tabuleiro

  posicao2(linha2, coluna2); //Chama a função para posicionar o navio 2
  imprimirTabuleiro(tabuleiro); //Chama a função para imprimir o tabuleiro

  return 0; //Retorna 0
}