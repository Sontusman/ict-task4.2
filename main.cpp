#include <stdio.h>
#include <math.h>
#include "head.h"

int main(){
    double a, b, error; //верхняя граница, нижняя граница, допустимая ошибка
    int N;
    printf("Enter the number of points"); //важно, a>b, не перепутай, сначала вводим верхнюю грань
    scanf("%d", &N);//начальное число узлов
    //Введем пределы интегрирования и допустимую ошибку
    printf("Enter the limits of integrating and the error");
    scanf("%lf\n%lf\n%lf\n", &a, &b, &error);
    double step = (a-b)/N; //посчитали шаг
    double current_error_rectangle = abs(rectangle(b, step, N)-analyt_integral(a, b)); //ошибки по обоим методам
    double current_error_trapetions = abs(trapetion(b, step, N)-analyt_integral(a, b));
    int number_of_iterations=0; //счетчик кол-ва увеличений кол-ва узлов (Ангелуц просил)
    //входим в проверку по критерию рунге, надо снизить ошибку путем увеличения дискретности
    while(current_error_rectangle>error ||current_error_trapetions>error){ //берем 2 ошибки по разным методам
        N*=2; //увеличили в 2 раза кол-во узлов
        step = (a-b)/N; //сразу пересчитали шаг
        current_error_rectangle = abs(rectangle(b, step, N)-analyt_integral(a, b));//пересчитали ошибку перед 
        current_error_trapetions = abs(trapetion(b, step, N)-analyt_integral(a, b)); //проверкой в начале нового витка цикла
        number_of_iterations+=1; //счетчик кол-ва увеличений работает стабильно
    }
    printf("Number of interations done: %d;\n", number_of_iterations); //вывели кол-во увеличений
    printf("Calculated by rectangle method: %lf;\n", rectangle(b, step, N)); //че получилось прямоугольниками
    printf("Error calculating by rectangle method: %lf;\n", current_error_rectangle); //ошибка прямоугольниками
    printf("Calculated by trapetion method %lf;\n", trapetion(b, step, N)); //че получилось трапециями
    printf("Error calculating by trapetion method: %lf;\n", current_error_trapetions); //ошибка трапециями
    printf("Calculated analytically %lf;\n", analyt_integral(a, b)); //что должно получиться
}