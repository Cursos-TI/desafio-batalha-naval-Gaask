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
  do //Repetição do jogo
  {
    printf("\n\nOnde você quer posicionar seu navio? Digite a linha de 1 a 10: "); //Inicia odiálogo com usuário
    scanf("%d", &linha);
    printf("\nAgora, digite a coluna de 1 a 10: ");
    scanf("%d", &coluna);
    if (linha <= 10 && linha > 0 && coluna <= 10 && coluna > 0) //Verifica se a posição é válida
    {
      linhaJ = linha; //Faz com que o valor de exibição e posição da matriz sejam iguais
      colunaJ = coluna;
      tabuleiro[linha - 1][coluna - 1] = 3; //Posiciona o navio na posição que o jogador selecionou
      printf("\nVocê selecionou: linha %d, coluna %d.\n\n", linhaJ, colunaJ);
      valido = 1; //Valida a posição
      if (coluna > 8) //Se ele selecionou uma coluna acima da 8, adiciona 2 navios nas colunas de trás
      {
        tabuleiro[--linha][coluna - 2] = 3; // em matrizes, a linha 1 do jogador é = linha 0, por isso, decremento
        tabuleiro[linha][coluna - 3] = 3;   // as colunas são decrementadas para posicionar o navio horizontamente
      }
      else //Se não, adiciona os dois na frente
      {
        tabuleiro[--linha][coluna] = 3;
        tabuleiro[linha][++coluna] = 3;
      }
    }
    else //sSe a posição for inválida
    {
      printf("posições inválidas.\n");
    }
  } while (valido != 1);
  imprimirTabuleiro(tabuleiro);
}
void navio2()
{
  do //Inicializa o loop
  {
    printf("\n\nOnde você quer posicionar seu segundo navio? Digite a linha de 1 a 10: ");
    scanf("%d", &linha);
    printf("\nAgora, digite a coluna de 1 a 10: ");
    scanf("%d", &coluna);
    if (coluna > 0 && coluna <= 10 && linha > 0 && linha <= 10)
    {
      linhaJ = linha;
      colunaJ = coluna;

      // Verifica se as posições do navio estão livres
      if (tabuleiro[linha - 1][coluna - 1] == 3 ||
          (linha < 9 && tabuleiro[linha][coluna - 1] == 3) ||
          (linha < 8 && tabuleiro[linha + 1][coluna - 1] == 3))
      {
        printf("Posições inválidas.\n");
        valido = 0;
      }
      else if (linha < 8) //Se a linha que o jogador selecionou for menor que 8, adiciona 2 navios abaixo.
      {
        tabuleiro[linha - 1][coluna - 1] = 3;
        tabuleiro[linha][coluna - 1] = 3;
        tabuleiro[linha + 1][coluna - 1] = 3;
        valido = 1;
      }
      else //Se não, dois acima.
      {
        if (tabuleiro[linha - 2][coluna - 1] == 3 || tabuleiro[linha - 3][coluna - 1] == 3) //Valida as posições
        {
          printf("Posições inválidas.\n");
          valido = 0;
        }
        else
        {
          tabuleiro[linha - 1][coluna - 1] = 3;
          tabuleiro[linha - 2][coluna - 1] = 3;
          tabuleiro[linha - 3][coluna - 1] = 3;
          valido = 1;
        }
      }
    }
    else
    {
      printf("Posições inválidas.\n");
    }
  } while (valido != 1);
  imprimirTabuleiro(tabuleiro); //Imprime o tabuleiro
}

int main()
{
  printf("- - - VOCÊ ESTÁ JOGANDO BATALHA NAVAL - - -\n");
  printf("O tabuleiro é 10x10. O primeiro passo é você escolher onde posicionar o seu navio.\n\n");
  imprimirTabuleiro(tabuleiro); //Imprime o tabuleiro
  navio1(); //Chama a função de seleção do navio 1
  navio2(); //Chama a função de seleção do navio 2
  return 0; //Encerra
}