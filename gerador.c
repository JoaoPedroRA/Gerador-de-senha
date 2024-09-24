#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    char simbolos[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')'};

    char numeros[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    char letras[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                     'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                     'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                     'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    int digitos = sizeof(numeros) / sizeof(char);
    int quant_simbolos = sizeof(simbolos) / sizeof(char);
    int num_letras = sizeof(letras) / sizeof(char);

    srand(time(NULL));

    int tamanho_senha = 0;
    int tipo_senha;

    printf("               ŊERADOR ðE æENH@S\n");
    printf(" \n");

    // Menu para o usuario escolher o tamanho da senha, o que ele vai incluir e etc.
    do
    {
        printf("Qual o tamanho da sua senha?(Máx. 32): ");
        scanf("%i", &tamanho_senha);
    } while (tamanho_senha < 1 || tamanho_senha > 32);

    do
    {
        printf("Somente números (1)\n");
        printf("Somente letras (2)\n");
        printf("Somente Caracteres Especiais (3)\n");
        printf("Letras e números(4)\n");
        printf("Letras e Caracteres Especiais (5)\n");
        printf("Números e Caracteres Especiais (6)\n");
        printf("Letras, números e Caracteres Especiais (7)\n");

        scanf("%i", &tipo_senha);
    } while (tipo_senha < 1 || tipo_senha > 7);

    printf("Senha gerada: ");

    // gerador de senhas
    switch (tipo_senha)
    {
    // senha com somente  letras
    case 1:
        for (int i = 1; i <= tamanho_senha; i++)
        {
            int random_index = rand() % digitos; // indice randomico baseado na quantidade digitos
            printf("%c", numeros[random_index]);
        }
        break;
    // senha com somente números
    case 2:
        for (int i = 1; i <= tamanho_senha; i++)
        {
            int random_index = rand() % num_letras;
            printf("%c", letras[random_index]);
        }
        break;

    case 3: // senha com somente  simbolos
        for (int i = 1; i <= tamanho_senha; i++)
        {
            int random_index = rand() % quant_simbolos;
            printf("%c", simbolos[random_index]);
        }
        break;

    // Senha com Letras e números
    case 4:
        for (int i = 1; i <= tamanho_senha; i++)
        {
            int aleatorio = rand() % 2;
            char caractere;
            switch (aleatorio)
            {
            case 0:
                caractere = numeros[rand() % digitos];
                break;

            case 1:
                caractere = letras[rand() % num_letras];
                break;
            }
            printf("%c", caractere);
        }
        break;

    // Letras e Caracteres especiais
    case 5:
        for (int i = 1; i <= tamanho_senha; i++)
        {
            int aleatorio = rand() % 2;
            char caractere;
            switch (aleatorio)
            {
            case 0:
                caractere = simbolos[rand() % quant_simbolos];
                break;

            case 1:
                caractere = letras[rand() % num_letras];
                break;
            }
            printf("%c", caractere);
        }
        break;

    // Senha com caracteres especiais e números
    case 6:
        for (int i = 1; i <= tamanho_senha; i++)
        {
            int aleatorio = rand() % 2;
            char caractere;
            switch (aleatorio)
            {
            case 0:
                caractere = numeros[rand() % digitos];
                break;

            case 1:
                caractere = simbolos[rand() % quant_simbolos];
                break;
            }
            printf("%c", caractere);
        }
        break;

    // Senha com letras, números e caracteres especiais
    case 7:
        for (int i = 1; i <= tamanho_senha; i++)
        {
            int aleatorio = rand() % 3;
            char caractere;
            switch (aleatorio)
            {
            case 0:
                caractere = numeros[rand() % digitos];
                break;

            case 1:
                caractere = letras[rand() % num_letras];
                break;

            case 2:
                caractere = simbolos[rand() % quant_simbolos];
                break;
            }
            printf("%c", caractere);
        }
        break;
    }
    printf("\n");

    return 0;
}