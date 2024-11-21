#include <iostream>
#include <cmath>

using namespace std;

double Factorial(int n){
    double res = 1;
    for(int i = 1; i <= n; i++){
        res *= i;
    }
    return res;
}

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

long double readDoubleInLine() {
    long double number;
    while (!(cin >> number) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Ошибка ввода. Введите заново: ";
    }
    
    return number;
}

long double S(long double x, int n){
    long double res = 1;
    for(int i = 1; i <= n; i++){
        res += ((((cos(i * M_PI/(double)4))) / (double)Factorial(i))) * pow(x, i);
    }
    return res;
}

long double Y(long double x){
    long double res = exp(x * cos(M_PI/(double)4)) * cos(x * sin(M_PI/(double)4));
    return res;
}

int main(){
    cout << "Программа, вычисляющая значения функций S(x) и Y(x), где значние S(x) считается разложением в ряд до n элемента, а Y(x) с помощью стандартных функций\n";
    cout << "Выполнил Бибиков Максим, группа 453502, Вариант 3\n";
    while(true){
        cout << "Введите 1, если хотите выполнить программу, или 2, если хотите завершить работу программы\n";
        int type = readIntegerInLine();
        if(type == 2)
            break;
        else if(type != 1 && type != 2)
            continue;
        
        cout << "Впишите число членов ряда (n - целое неотрицательное число): ";
        int n;
        while(true){
            n = readIntegerInLine();
            if(n < 0){
                cout << "Некорректный ввод, введие n: ";
                continue;
            }
            break;
        }
        cout << "Впишите сколько раз вы хотите посчитать функцию (m - целое неотрицательное число): ";
        int m;
        while(true){
            m = readIntegerInLine();
            if(m < 0){
                cout << "Некорректный ввод, введие m: ";
                continue;
            }
            break;
        }

        for(int i = 0; i < m; i++){
            cout << "Введите x, для которо нужно посчитать значение функции(x - вещественное число 0.1 до 1): ";
            long double x;
            while(true){
                x = readDoubleInLine();
                if(x < 0.1 || x > 1){
                     cout << "Некорректный ввод, введие x: ";
                     continue;
                }
                break;
            }
            cout << "Значение функции, полученное разложением в ряд равно: " << S(x, n) << '\n';
            cout << "Значение функции, полученное с помощью стандартных функций равно: " << Y(x) << '\n';
        }

    }
    return 0;
}
