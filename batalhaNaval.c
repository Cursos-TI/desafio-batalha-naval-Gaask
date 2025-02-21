#include <stdio.h>

int linha, linhaJ, coluna, colunaJ, valido = 0; // linhaJ é o que é exibido, linha é o que de fato é calculado
int tabuleiro[10][10] = {0};                    // Inicializa um tabuleiro 10x10. = 0 indica que todos os valores do tabuleiro são 0.

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[10][10]) // Função que chama a matriz como argumento
{
  for (int i = 0; i < 10; i++) // Loop para percorrer e definir as 10 linhas como 0
  {
    for (int j = 0; j < 10; j++) // Loop para percorrer e definir as 10 colunas como 0
    {
      printf("%d ", tabuleiro[i][j]); // Imprime o tabuleiro com um espaço entre os "0" e "3"
      // Se o \n estiver aqui, a saída será "0" linha por linha
    }
    printf("\n"); // Pula a linha dentro do loop de linha, para formatar o tabuleiro como um quadrado
  }
}
void navio1()
{
  do
  {
    printf("\n\nOnde você quer posicionar seu navio? Digite a linha de 1 a 10: ");
    scanf("%d", &linha);
    printf("\nAgora, digite a coluna de 1 a 10: ");
    scanf("%d", &coluna);
    if (linha <= 10 && linha > 0 && coluna <= 10 && coluna > 0)
    {
      linhaJ = linha;
      colunaJ = coluna;
      tabuleiro[linha - 1][coluna - 1] = 3;
      printf("\nVocê selecionou: linha %d, coluna %d.\n\n", linhaJ, colunaJ);
      valido = 1;
      if (coluna > 8)
      {
        tabuleiro[--linha][coluna - 2] = 3; // em matrizes, a linha 1 do jogador é = linha 0, por isso, decremento
        tabuleiro[linha][coluna - 3] = 3;   // as colunas são decrementadas para posicionar o navio horizontamente
      }
      else
      {
        tabuleiro[--linha][coluna] = 3;
        tabuleiro[linha][++coluna] = 3;
      }
    }
    else
    {
      printf("posições inválidas.\n");
    }
  } while (valido != 1);
  imprimirTabuleiro(tabuleiro);
}
void navio2()
{
  do
  {
    printf("\n\nOnde você quer posicionar seu segundo navio? Digite a linha de 1 a 10: ");
    scanf("%d", &linha);
    printf("\nAgora, digite a coluna de 1 a 10: ");
    scanf("%d", &coluna);
    if (coluna > 0 && coluna <= 10 && linha > 0 && linha <= 10)
    {
      linhaJ = linha;
      colunaJ = coluna;
      tabuleiro[linha - 1][coluna - 1] = 3;
      printf("\nVocê selecionou: linha %d, coluna %d.\n\n", linhaJ, colunaJ);
      valido = 1;
      if (linha < 8)
      {
        tabuleiro[linha][--coluna] = 3;
        tabuleiro[++linha][coluna] = 3;
      }
      else
      {
        tabuleiro[linha - 2][--coluna] = 3;
        tabuleiro[linha - 3][coluna] = 3;
      }
    }
    else
    {
      printf("posições inválidas.\n");
    }
  } while (valido != 1);
  imprimirTabuleiro(tabuleiro);
}

int main()
{
  printf("- - - VOCÊ ESTÁ JOGANDO BATALHA NAVAL - - -\n");
  printf("O tabuleiro é 10x10. O primeiro passo é você escolher onde posicionar o seu navio.\n\n");
  imprimirTabuleiro(tabuleiro);
  navio1();
  navio2();
  return 0;
}