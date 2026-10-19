#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int length, number, proverka, bulls, cows;
    printf("\nВведите длину загадываемого числа (2-5):\n");
    if (scanf("%i",&length) != 1 || length < 2 || length > 5) {
        printf("\nНеверная длина. Ошибка ввода.\n");
        return 1;
    }

    int *computer = malloc(length * sizeof(int));
    int *polsovatel = malloc(length * sizeof(int));

    if (computer == NULL || polsovatel == NULL) {
        free(computer);
        free(polsovatel);
        return 1;
    }

    for (int i = 0; i < length; i++) {
        computer[i] = rand() % 10;

        if (i == 0 && computer[i] == 0) {
            i--;
            continue;
        }

        for (int l = 0; l < i; l++) {
            if (computer[i] == computer[l]) {
                i--;
                break;
            }
        }
    }

    do {
        printf("\nВведите свое число:\n");
        if (scanf("%i",&number) != 1) {
            break;
        }

        for (int i = length - 1; i >= 0; i--) {
            polsovatel[i] = number % 10;
            number /= 10;
        }

        proverka = 1;

        if (number != 0 || polsovatel[0] <= 0)
            proverka = 0;
        
        for (int i = 0; i < length; i++)
            for (int l = 0; l < i; l++)
                if (computer[i] == computer[l])
                    proverka = 0;
    
        bulls = 0;
        cows = 0;

        if (proverka == 0) {
            printf("\nОшибка ввода. Необходимо ввести %i разных цифр без нуля в начале\n",length);
            continue;
        }

        for (int i = 0; i < length; i++)
            for (int l = 0; l < length; l++)
                if (polsovatel[i] == computer[l]) {
                    if (i == l)
                        bulls++;
                    else
                        cows++;
                }
        
        printf("\nВ вашем числе %i быков и %i коров.\n",bulls,cows);
    } while (bulls != length);

    if (bulls == length) 
        printf("\nВы угадали мое число!\n");

    free(polsovatel);
    free(computer);
    return 0;
}