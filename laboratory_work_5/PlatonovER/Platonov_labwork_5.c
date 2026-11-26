#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(unsigned int *a, unsigned int *b)
{
    unsigned int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(unsigned int *a, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1])
                swap(&a[j], &a[j + 1]);
        }
    }
}

void vstavkaSort(unsigned int *a, int n)
{
    for (int i = 1; i < n; i++) {
        int k = i;

        for (int j = i - 1; j >= 0; j--) {
            if (a[k] < a[j]) {
                swap(&a[k], &a[j]);
                k--;
            } else {
                break;
            }
        }
    }
}



void merge(unsigned int *a, unsigned int *b,
           int n, int m, unsigned int *c)
{
    int j = 0;
    int k = 0;

    for (int i = 0; i < n + m; i++) {
        if (j == n) {
            c[i] = b[k++];
        } else if (k == m) {
            c[i] = a[j++];
        } else {
            if (a[j] < b[k])
                c[i] = a[j++];
            else
                c[i] = b[k++];
        }
    }
}

void mergeSort(unsigned int *a, int n, unsigned int *b)
{
    if (n == 1)
        return;

    mergeSort(&a[0], n / 2, &b[0]);
    mergeSort(&a[n / 2], n - n / 2, &b[n / 2]);

    merge(&a[0], &a[n / 2], n / 2, n - n / 2, &b[0]);

    for (int i = 0; i < n; i++)
        a[i] = b[i];
}



unsigned int get_max(unsigned int *mas, int n)
{
    unsigned int max = mas[0];

    for (int i = 1; i < n; i++) {
        if (mas[i] > max)
            max = mas[i];
    }

    return max;
}

void CountingSort(unsigned int *mas, int n, unsigned int div)
{
    unsigned int count[10] = {0};
    unsigned int *output = malloc(n * sizeof(unsigned int));

    for (int i = 0; i < n; i++) {
        unsigned int digit = (mas[i] / div) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        unsigned int digit = (mas[i] / div) % 10;
        output[count[digit] - 1] = mas[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++)
        mas[i] = output[i];

    free(output);
}

void RadixSort(unsigned int *mas, int n)
{
    unsigned int max = get_max(mas, n);

    for (unsigned int div = 1; max / div > 0; div *= 10) {
        CountingSort(mas, n, div);
    }
}

int main(void) {
    int choice;
    int n;
    double start;
    double end;
    double sort_time;
    double bubble_time;

    printf("\nВыберите сортировку:\n");
    printf("1 — вставками\n");
    printf("2 — MergeSort\n");
    printf("3 — RadixSort\n\n");
    scanf("%d", &choice);

    printf("Введите длину массива: ");
    scanf("%d", &n);

    for (int k = 1; k <= 4; k *= 2) {
        int m = n * k;

        unsigned int *a = malloc(m * sizeof(unsigned int));
        unsigned int *c = malloc(m * sizeof(unsigned int));

        for (int i = 0; i < m; i++) {
            a[i] = rand() % 10000;
            c[i] = a[i];
        }

        start = (double)clock() / CLOCKS_PER_SEC;
        bubbleSort(c, m);
        end = (double)clock() / CLOCKS_PER_SEC;

        bubble_time = end - start;

        switch (choice) {
            case 1: {
                start = (double)clock() / CLOCKS_PER_SEC;
                vstavkaSort(a, m);
                end = (double)clock() / CLOCKS_PER_SEC;
                break;
            }

            case 2: {
                unsigned int *b = malloc(m * sizeof(unsigned int));

                start = (double)clock() / CLOCKS_PER_SEC;
                mergeSort(a, m, b);
                end = (double)clock() / CLOCKS_PER_SEC;

                free(b);
                break;
            }

            case 3: {
                start = (double)clock() / CLOCKS_PER_SEC;
                RadixSort(a, m);
                end = (double)clock() / CLOCKS_PER_SEC;
                break;
            }

            default:
                free(a);
                free(c);
                return 0;
        }

        sort_time = end - start;

        printf("\nКоличество элементов: %d\n", m);
        printf("Выбранная сортировка: %.6f секунд\n", sort_time);
        printf("Сортировка пузырьком: %.6f секунд\n", bubble_time);
        printf("Разница: %.6f секунд\n", bubble_time - sort_time);

        free(a);
        free(c);
    }

    return 0;
}