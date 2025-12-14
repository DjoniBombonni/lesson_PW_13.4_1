#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main() {
    int N;
    do {
        printf("Введите размер массива (положительное целое число): ");
        if (scanf("%d", &N) != 1) {
            //Очистка буфера от некорректного ввода (буквы, символы)
            while (getchar() != '\n');
            printf("Ошибка: введите корректное целое число.\n");
            N = 0;  //Сброс, чтобы цикл продолжился
        }
        else if (N <= 0) {
            printf("Ошибка: размер должен быть положительным.\n");
        }
    } while (N <= 0);

    double *array = (double *)malloc(N * sizeof(double));
    if (array == NULL) {
        printf("Ошибка выделения памяти!\n");
        printf("Перезапустите программу и попробуйте снова.\n");
        return 1;
    }

    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        double t = (double)i / N; //нормированное время
        array[i] = sin(2 * M_PI * t); //гармонический сигнал (синусоида)
        //добавляем шумовую компоненту: случайное значение от -0.1 до 0.1
        array[i] += ((double)rand() / RAND_MAX - 0.5) * 0.2;
    }

    printf("Массив сигнала:\n");
    for (int i = 0; i < N; i++) {
        printf("%.4f ", array[i]);
    }
    printf("\n");

    free(array);
    return 0;
}
//