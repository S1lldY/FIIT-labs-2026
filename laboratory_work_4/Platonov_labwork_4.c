#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char info[11][4][40] = {
        {"0000", "Хлеб", "40", "5"},
        {"0001", "Молоко", "80", "25"},
        {"0002", "Шоколад", "150", "30"},
        {"0003", "Вода 0.5", "50", "20"},
        {"0004", "Печенье", "200", "50"},
        {"0005", "Coca-Cola 0.5", "160", "10"},
        {"0006", "Туалетная бумага 8 шт.", "350", "15"},
        {"0007", "Жевательная резинка", "43", "5"},
        {"0008", "Йогурт питьевой 0.5", "75", "20"},
        {"0009", "Сыр", "299", "15"},
        {"0010", "Майонез", "259", "30"}
    };

    int vibor;
    int lastproduct = -1;
    char barcode[20];
    int a[11] = {0};

    while (1) {
        printf("\nВыберите действие:\n");
        printf("1. Сканировать товар\n");
        printf("2. Показать товар\n");
        printf("3. Добавить товар в чек\n");
        printf("4. Сформировать чек\n");
        printf("5. Рассчитать сумму к оплате\n");
        printf("0. Выход\n");

        if (scanf("%d", &vibor) != 1) {
            printf("Ошибка ввода.\n");
            return 1;
        }

            if (vibor == 0) 
            break;

            else if (vibor == 1) {
            printf("Введите штрих-код из 4 цифр: ");
            scanf("%s", barcode);
            lastproduct = -1;

            for (int i = 0; i < 11; i++) {
                if (barcode[0] == info[i][0][0] &&
                    barcode[1] == info[i][0][1] &&
                    barcode[2] == info[i][0][2] &&
                    barcode[3] == info[i][0][3]) {
                    lastproduct = i;
                    printf("Отсканирован товар: %s\n", info[i][1]);
                    break;
                }
            }
            if (lastproduct == -1) printf("Товар не найден.\n");
            }

            else if (vibor == 2) {
            if (lastproduct == -1) {
                printf("Сначала отсканируйте товар.\n");
            } else {
                printf("%s, цена: %s руб., скидка: %s%%\n",info[lastproduct][1],info[lastproduct][2],info[lastproduct][3]);
            }
            }

            else if (vibor == 3) {
            if (lastproduct == -1) {
                printf("Сначала отсканируйте товар.\n");
            } else {
                a[lastproduct]++;
                printf("Товар добавлен в чек.\n");
            }
            }

            else if (vibor == 4 || vibor == 5) {
                int total = 0;
                int count = 0;
                float discount = 0;

                for (int i = 0; i < 11; i++) {
                    if (a[i] > 0) {
                        int price = atoi(info[i][2]);
                        int percent = atoi(info[i][3]);

                        count = 1;
                        total += price * a[i];
                        discount += price * a[i] * percent / 100.0;
                    }
                }
                if (count == 0) {
                printf("Чек пуст. Сначала добавьте товар.\n");
                continue;
                }

                if (vibor == 4) {
                    printf("\n----- ЧЕК -----\n");

                    for (int i = 0; i < 11; i++) {
                        if (a[i] > 0) {
                            int price = atoi(info[i][2]);
                            printf("%s — %d руб. x %d = %d руб.\n",
                                info[i][1], price, a[i],
                                price * a[i]);
                        }
                    }
                    printf("Стоимость товаров: %d руб.\n", total);
                    printf("Суммарная скидка: %.1f руб.\n", discount);
                }
                printf("К оплате: %.1f руб.\n", total - discount);
            }

            else {
            printf("Нет такого пункта меню.\n");
            }
    }

    return 0;

}