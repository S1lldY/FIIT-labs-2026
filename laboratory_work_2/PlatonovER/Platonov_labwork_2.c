#include <stdio.h>
#include <stdlib.h>

int game_1 (void) {
    int x = 1 + rand() % 1000;
    int variant;
    int k = 0;
    printf("\n\nНачинайте угадывать число\n\n");
    do {
        scanf("\n\n%i", &variant);
        if (variant == x) {
            printf("\n\nЧисло угадано!\n");
            k += 1;
            printf("Вам понадобилось %i попыток\n\n",k);
            break;
        } else if (variant < x) {
            printf("\n\nЗагаданное число больше вашего\n\n");
            k += 1;
        } else {
            printf("\n\nЗагаданное число меньше вашего\n\n");
            k += 1;
        }
    } while (1);
    return 0;
}

int game_2 (void) {
    char znak;
    int a;
    int k = 0;
    printf("\n\nВведите ваше число\n\n");
    scanf("%i",&a);
    int x = 500;
    int x0 = x / 2;
    do {
        printf("\n\nВаше число %i?\n",x);
        scanf(" %c",&znak);
        if (znak == '=') {
            printf("\n\nУра, я угадал, ваше число равно %i!\n",x);
            k += 1;
            printf("Мне понадобилось %i попыток\n\n",k);
            break;
        } else if (znak == '<') {
            x = x - x0;
            k += 1;
            if (x0 > 1)
                x0 = x0 / 2;
        } else if (znak == '>') {
            x = x + x0;
            k += 1;
            if (x0 > 1)
                x0 = x0 / 2;
        }
    } while (1);
    return 0;
}

int main(void) {
    int game;
    printf("\n\nВ какую игру вы хотите сыграть?\n1 - Программа загадывает число\n2 - Вы загадываете число\n\n");
    scanf("%i",&game);
    switch (game) {
        case 1:
            game_1();
            break;
        case 2:
            game_2();
            break;
    }
    return 0;
}
