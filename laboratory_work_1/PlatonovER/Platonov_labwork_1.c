#include <stdio.h>

int main(void) {
    printf("\nВведите данные:\n1. Высота (от 180 до 220см)\n2. Ширина (от 80 до 120см)\n3. Глубина (от 50 до 90см)\n\n");
    int h, w, d;
    if (scanf("%d %d %d", &h, &w, &d) != 3) {
        printf("\nошибка ввода\n");
        return 1;
    }
    if ((h < 180 || h > 220) || (w < 80 || w > 120) || (d < 50 || d > 90)) {
        printf("\nошибка ввода\n");
        return 1;
    }
    float Vs = h * w * (5 / 10.0);
    float Vb = (h * d * (15 / 10.0)) * 2;
    float Vk = (w * d * (15 / 10.0)) * 2;
    float Vd = h * w * 1;
    int polki = (h - 1) / (40 + 1.5);
    float Vp = ((w - 3.0) * d * (15 / 10.0)) * polki;
    float plotnostd = 1.5;
    float plotnostDSP = 0.8;
    float plotnostDVP = 0.6;
    float massa = Vs * plotnostDVP + (Vb + Vp + Vk) * plotnostDSP + Vd * plotnostd;
    massa /= 1000.0;
    printf("\nмасса шкафа равна %.2f кг\n\n", massa);
}