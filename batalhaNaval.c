#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHAS 10  // Define o tamanho do tabuleiro em linhas
#define COLUNAS 10 // Define o tamanho do tabuleiro em colunas

int tabuleiro[LINHAS][COLUNAS];                                                                     // Define o tabuleiro
int linha, coluna, linha2, coluna2, linha3, coluna3, linha4, coluna4, linha5, coluna5, verificacao; // Define as variáveis de linha, coluna, linha2, coluna2 e verificação

void imprimirTabuleiro(int tabuleiro[LINHAS][COLUNAS]) // Função para imprimir o tabuleiro
{
  // Imprimindo o formato de um cone

  // int numero = 0;
  // tabuleiro[3][5] = 3; // Posiciona o cone
  // tabuleiro[4][4] = 3; // Posiciona o cone
  // tabuleiro[4][5] = 3; // Posiciona o cone
  // tabuleiro[4][6] = 3; // Posiciona o cone
  // tabuleiro[5][3] = 3; // Posiciona o cone
  // tabuleiro[5][4] = 3; // Posiciona o cone
  // tabuleiro[5][5] = 3; // Posiciona o cone
  // tabuleiro[5][6] = 3; // Posiciona o cone
  // tabuleiro[5][7] = 3; // Posiciona o cone

  for (int i = 0; i < LINHAS; i++) // Loop para percorrer as linhas
  {
    for (int j = 0; j < COLUNAS; j++) // Loop para percorrer as colunas
    {
      printf("%d ", tabuleiro[i][j]); // Imprime o tabuleiro
    }
    printf("\n"); // Pula uma linha para o tabuleiro ficar organizado
  }
}
void posicao1(int linha, int coluna) // Função para posicionar o navio 1
{
  do // Loop de posicionamento
  {
    printf("\n\nEscolha uma linha de 1 a 10: ");                         // Pede para o usuário escolher uma linha
    scanf("%d", &linha);                                                 // Lê a linha escolhida
    printf("\n\nEscolha uma coluna de 1 a 10: ");                        // Pede para o usuário escolher uma coluna
    scanf("%d", &coluna);                                                // Lê a coluna escolhida
    if (linha > 0 && linha <= LINHAS && coluna <= COLUNAS && coluna > 0) // Verifica se a linha e a coluna escolhidas estão dentro do tabuleiro
    {
      printf("Posições válidas.\n");        // Imprime que as posições são válidas
      tabuleiro[linha - 1][coluna - 1] = 3; // Posiciona o navio na posição escolhida
      verificacao = 0;                      // Atribui 0 à variável de verificação
      if (linha > 2)                        // verifica se a linha escolhida é ou não anterior a 3
      {
        tabuleiro[linha - 2][coluna - 1] = 3; // Posiciona o navio na linha anterior
        tabuleiro[linha - 3][coluna - 1] = 3; // Posiciona o navio na linha anterior à anterior
      }
      else // Se a linha escolhida for anterior a 3
      {
        tabuleiro[linha][coluna - 1] = 3;     // Posiciona o navio na linha posterior
        tabuleiro[linha + 1][coluna - 1] = 3; // Posiciona o navio na linha posterior à posterior
      }
    }
    else // Se a linha e a coluna escolhidas não estiverem dentro do tabuleiro
    {
      printf("Posições inválidas.\n"); // Imprime que as posições são inválidas
      verificacao = 1;                 // Atribui 1 à variável de verificação
    }
  } while (verificacao == 1); // Enquanto a verificação for igual a 1, o loop continua e o jogador deve escolher outra posição
}
void posicao2(int linha2, int coluna2) // Função para posicionar o navio 2
{
  do // Loop de posicionamento
  {
    printf("\n\nEscolha uma linha de 1 a 10 para a segunda posição: ");  // Pede para o usuário escolher uma linha para a segunda posição
    scanf("%d", &linha2);                                                // Lê a linha escolhida
    printf("\n\nEscolha uma coluna de 1 a 10 para a segunda posição: "); // Pede para o usuário escolher uma coluna para a segunda posição
    scanf("%d", &coluna2);                                               // Lê a coluna escolhida

    int sobreposicao = 0; // Inicializa a variável de sobreposição com 0
    if (tabuleiro[linha2 - 1][coluna2 - 1] == 3 ||
        (coluna2 - 2 >= 0 && tabuleiro[linha2 - 1][coluna2 - 2] == 3) ||
        (coluna2 - 3 >= 0 && tabuleiro[linha2 - 1][coluna2 - 3] == 3)) // Verifica se a posição escolhida está ocupada e/ou se está fora do tabuleiro
    {
      sobreposicao = 1; // Atribui 1 à variável de sobreposição se a posição estiver ocupada e/ou fora do tabuleiro
    }

    if (linha2 > 0 && linha2 <= LINHAS && coluna2 <= COLUNAS && coluna2 > 0 &&
        tabuleiro[linha2 - 1][coluna2 - 1] != 3 && sobreposicao == 0) // Verifica se a linha e a coluna escolhidas estão dentro do tabuleiro e se a posição não está ocupada
    {
      printf("Posições válidas.\n");          // Imprime que as posições são válidas
      tabuleiro[linha2 - 1][coluna2 - 1] = 3; // Posiciona o navio na posição escolhida
      verificacao = 0;                        // Atribui 0 à variável de verificação
      if (coluna2 > 2)                        // Verifica se a coluna escolhida é ou não anterior a 3
      {
        tabuleiro[linha2 - 1][coluna2 - 2] = 3; // Posiciona o navio na coluna anterior
        tabuleiro[linha2 - 1][coluna2 - 3] = 3; // Posiciona o navio na coluna anterior à anterior
      }
      else // Se a coluna escolhida for anterior a 3
      {
        tabuleiro[linha2 - 1][coluna2] = 3;     // Posiciona o navio na coluna posterior
        tabuleiro[linha2 - 1][coluna2 + 1] = 3; // Posiciona o navio na coluna posterior à posterior
      }
    }
    else // Se a linha e a coluna escolhidas não estiverem dentro do tabuleiro ou a posição estiver ocupada
    {
      printf("Posições inválidas ou ocupadas.\n"); // Imprime que as posições são inválidas ou ocupadas
      verificacao = 1;                             // Atribui 1 à variável de verificação
    }
  } while (verificacao == 1);
}
void posicao3(int linha3, int coluna3) // Função para posicionar o navio 3
{
  do // Loop de posicionamento
  {
    printf("\n\nEscolha uma linha de 1 a 10 para a terceira posição: ");  // Pede para o usuário escolher uma linha para a terceira posição
    scanf("%d", &linha3);                                                 // Lê a linha escolhida
    printf("\n\nEscolha uma coluna de 1 a 10 para a terceira posição: "); // Pede para o usuário escolher uma coluna para a terceira posição
    scanf("%d", &coluna3);                                                // Lê a coluna escolhida

    int sobreposicao = 0;                            // Inicializa a variável de sobreposição com 0
    if (tabuleiro[linha3 - 1][coluna3 - 1] == 3 ||   // Verifica se a posição escolhida está ocupada
        (tabuleiro[linha3 - 2][coluna3 - 2] == 3) || // Verifica se a posição anterior na diagonal está ocupada
        (tabuleiro[linha3 - 3][coluna3 - 3] == 3))   // Verifica se a posição anterior à anterior na diagonal está ocupada
    {
      sobreposicao = 1; // Atribui 1 à variável de sobreposição se a posição estiver ocupada e/ou fora do tabuleiro
    }

    if (linha3 > 0 && linha3 <= LINHAS && coluna3 <= COLUNAS && coluna3 > 0 &&
        tabuleiro[linha3 - 1][coluna3 - 1] != 3 && sobreposicao == 0) // Verifica se a linha e a coluna escolhidas estão dentro do tabuleiro e se a posição não está ocupada
    {
      printf("Posições válidas.\n");          // Imprime que as posições são válidas
      tabuleiro[linha3 - 1][coluna3 - 1] = 3; // Posiciona o navio na posição escolhida
      verificacao = 0;                        // Atribui 0 à variável de verificação

      if (linha3 > 3 && coluna3 > 3) // Verifica se a coluna escolhida é ou não anterior a 3
      {
        tabuleiro[linha3 - 2][coluna3 - 2] = 3; // Posiciona o navio na coluna anterior
        tabuleiro[linha3 - 3][coluna3 - 3] = 3; // Posiciona o navio na coluna anterior à anterior
      }
      else if (linha3 + 2 < LINHAS && coluna3 + 2 < COLUNAS) // Se a coluna escolhida for anterior a 3
      {
        tabuleiro[linha3][coluna3] = 3;         // Posiciona o navio na coluna posterior
        tabuleiro[linha3 + 1][coluna3 + 1] = 3; // Posiciona o navio na coluna posterior à posterior
      }
    }
    else // Se a linha e a coluna escolhidas não estiverem dentro do tabuleiro ou a posição estiver ocupada
    {
      printf("Posições inválidas ou ocupadas. O navio não cabe na diagonal.\n"); // Imprime que as posições são inválidas ou ocupadas
      verificacao = 1;                                                           // Atribui 1 à variável de verificação
    }
  } while (verificacao == 1); // Enquanto a verificação for igual a 1, o loop continua e o jogador deve escolher outra posição
}
void posicao4(int linha4, int coluna4) // Função para posicionar o navio 4
{
  do // Loop de posicionamento
  {
    printf("\n\nEscolha uma linha de 1 a 10 para a quarta posição: ");  // Pede para o usuário escolher uma linha para a quarta posição
    scanf("%d", &linha4);                                               // Lê a linha escolhida
    printf("\n\nEscolha uma coluna de 1 a 10 para a quarta posição: "); // Pede para o usuário escolher uma coluna para a quarta posição
    scanf("%d", &coluna4);                                              // Lê a coluna escolhida

    int sobreposicao = 0; // Inicializa a variável de sobreposição com 0

    // Verifica se a posição escolhida está ocupada
    if (tabuleiro[linha4 - 1][coluna4 - 1] == 3 ||                                               // Verifica se a posição escolhida está ocupada
        (linha4 - 2 >= 0 && coluna4 + 2 < COLUNAS && tabuleiro[linha4 - 2][coluna4 + 2] == 3) || // Verifica se a posição anterior na diagonal está ocupada
        (linha4 - 3 >= 0 && coluna4 + 3 < COLUNAS && tabuleiro[linha4 - 3][coluna4 + 3] == 3) || // Verifica se a posição anterior à anterior na diagonal está ocupada
        (linha4 + 2 < LINHAS && coluna4 - 2 >= 0 && tabuleiro[linha4 + 2][coluna4 - 2] == 3) ||  // Verifica se a posição posterior na diagonal está ocupada
        (linha4 + 3 < LINHAS && coluna4 - 3 >= 0 && tabuleiro[linha4 + 3][coluna4 - 3] == 3))    // Verifica se a posição posterior à posterior na diagonal está ocupada
    {
      sobreposicao = 1; // Atribui 1 à variável de sobreposição se a posição estiver ocupada
    }

    // Verifica se a linha e a coluna escolhidas estão dentro do tabuleiro e se a posição não está ocupada
    if (linha4 > 0 && coluna4 > 0 && linha4 <= LINHAS && coluna4 <= COLUNAS && // Verifica se a linha e a coluna escolhidas estão dentro do tabuleiro
        tabuleiro[linha4 - 1][coluna4 - 1] != 3 && sobreposicao == 0)          // Verifica se a posição não está ocupada
    {
      tabuleiro[linha4 - 1][coluna4 - 1] = 3; // Posiciona o navio na posição escolhida
      verificacao = 0;                        // Atribui 0 à variável de verificação

      // Verifica se há espaço suficiente para posicionar na diagonal inversa direita
      if (linha4 > 2 && coluna4 > 2) // Verifica se a linha e a coluna escolhidas são ou não anteriores a 3
      {
        if (tabuleiro[linha4 - 2][coluna4 - 2] != 3 && tabuleiro[linha4 - 3][coluna4 - 3] != 3) // Verifica se as posições anteriores na diagonal estão ocupadas
        {
          tabuleiro[linha4 - 2][coluna4 - 2] = 3; // Posiciona o navio na linha e coluna anterior na diagonal inversa
          tabuleiro[linha4 - 3][coluna4 - 3] = 3; // Posiciona o navio na linha e coluna anterior à anterior na diagonal inversa
        }
        else // Se não há espaço suficiente em nenhuma das diagonais inversas
        {
          printf("Posições inválidas. O navio não cabe nas diagonais disponíveis.\n"); // Imprime que as posições são inválidas
          verificacao = 1;                                                             // Atribui 1 à variável de verificação
        }
      }
      // Verifica se há espaço suficiente para posicionar na diagonal inversa esquerda
      else if (linha4 < 8 && coluna4 < 8) // Verifica se a linha e a coluna escolhidas são ou não posteriores a 3
      {
        if (tabuleiro[linha4][coluna4] != 3 && tabuleiro[linha4 + 1][coluna4 + 1] != 3) // Verifica se as posições posteriores na diagonal estão ocupadas
        {
          tabuleiro[linha4][coluna4] = 3;         // Posiciona o navio na linha e coluna posterior na diagonal inversa
          tabuleiro[linha4 + 1][coluna4 + 1] = 3; // Posiciona o navio na linha e coluna posterior à posterior na diagonal inversa
        }
        else // Se não há espaço suficiente em nenhuma das diagonais inversas
        {
          printf("Posições inválidas. O navio não cabe nas diagonais disponíveis.\n"); // Imprime que as posições são inválidas
          verificacao = 1;                                                             // Atribui 1 à variável de verificação
        }
      }
    }
    else // Se a linha e a coluna escolhidas não estiverem dentro do tabuleiro ou a posição estiver ocupada
    {
      printf("Posições inválidas ou ocupadas.\n"); // Imprime que as posições são inválidas ou ocupadas
      verificacao = 1;                             // Atribui 1 à variável de verificação
    }
  } while (verificacao == 1);
}
void cone(int linha5, int coluna5)
{
  srand(time(NULL));

  int numero = rand() % 6 + 3;
  int numero2 = rand() % 6 + 3;

  printf("Linha: %d e ", numero);
  printf("coluna: %d\n", numero2);

  tabuleiro[numero - 1][numero2 - 1] = 5;
  tabuleiro[numero][numero2 - 2] = 5;
  tabuleiro[numero][numero2 - 1] = 5;
  tabuleiro[numero][numero2] = 5;
  tabuleiro[numero + 1][numero2 - 3] = 5;
  tabuleiro[numero + 1][numero2 - 2] = 5;
  tabuleiro[numero + 1][numero2 - 1] = 5;
  tabuleiro[numero + 1][numero2] = 5;
  tabuleiro[numero + 1][numero2 + 1] = 5;
}
void cruz(int linha6, int coluna6)
{
  srand(time(NULL));

  int numero = rand() % 5 + 3;
  int numero2 = rand() % 5 + 3;

  printf("Linha: %d e ", numero);
  printf("coluna: %d\n", numero2);
}
void octaedro(int linha7, int coluna7)
{
}

int main() // Função principal
{
  cone(linha5, coluna5);
  imprimirTabuleiro(tabuleiro); // Chama a função para imprimir o tabuleiro
  posicao1(linha, coluna);      // Chama a função para posicionar o navio 1
  imprimirTabuleiro(tabuleiro); // Chama a função para imprimir o tabuleiro

  posicao2(linha2, coluna2);    // Chama a função para posicionar o navio 2
  imprimirTabuleiro(tabuleiro); // Chama a função para imprimir o tabuleiro

  posicao3(linha3, coluna3);    // Chama a função para posicionar o navio 3
  imprimirTabuleiro(tabuleiro); // Chama a função para imprimir o tabuleiro

  posicao4(linha4, coluna4);    // Chama a função para posicionar o navio 4
  imprimirTabuleiro(tabuleiro); // Chama a função para imprimir o tabuleiro

  return 0; // Retorna 0
}