#include <iostream>
#define PI 3.14159265359

using namespace std;

int readIntegerInLine() {
    int number;
    while (!(cin >> number) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Ошибка ввода. Введите заново: ";
    }
    
    return number;
}

double pow(double num, long n){
    double res = 1;
    for(int i = 0; i < n; i++){
        res *= num;
    }
    return res;
}

double factorial(int n){
    double res = 1;
    for(int i = 1; i <= n; i++){
        res *= i;
    }
    return res;
}


double Asin(double x, int terms = 50) {
    double asinX = 0;
    for (int n = 0; n < terms; ++n) {
        double term = (factorial(2 * n) / (double)(pow(pow(2,n) * factorial(n), 2))) *  (pow(x, 2 * n + 1) / (double)(2 * n + 1));
        asinX += term;
    }
    return asinX;
}

double abs(double num){
    if(num < 0)
        num *= -1;
    return num;
}

int main(){
    cout << "Программа, вычисляющая приближенный корень уравнения f(x) = arcsin(x) - x + x^2 - 1, где x ∈ [0;1]\n";
    cout << "Выполнил Бибиков Максим, группа 453502, Вариант 3\n";
    while(true){
        cout << "Введите 1, если хотите выполнить программу, или 2, если хотите завершить работу программы\n";
        int type = readIntegerInLine();
        if(type == 2)
            break;
        else if(type != 1 && type != 2)
            continue;
        
        cout << "Впишите на сколько частей разделить промежуток(n - натуральное число): ";
        int n;
        while(true){
            n = readIntegerInLine();
            if(n < 1){
                cout << "Некорректный ввод, введие n: ";
                continue;
            }
            break;
        }

        long double step = 1 / (double)n;
        long double x,res = 99999999, step_temp, step_res;
        step_temp = step; step_res = step;

        for(int i = 0; i < n; i++, step_temp += step){
            long double x = abs(Asin(step_temp) - step_temp + pow(step_temp, 2) - 1);
            if(res >= x){
                res = x;
                step_res = step_temp;
            }
        }

        cout << "Приближенный корень x = " << step_res << ";\nПогрешность равна: " << res << '\n';
    }
    return 0;
}
