#include <iostream>
#define pi 3.14159265358979323846
#define TPI 6.28318530717958647692

using namespace std;

long double pow(long double num, long n){
    long double res = 1;
    for(int i = 0; i < n; i++){
        res *= num;
    }
    return res;
}

long int factorial(int n){
    long int res = 1;
    for(int i = 1; i <= n; i++){
        res *= i;
    }
    return res;
}

long double sin(long double x, int terms = 10){
    if(x > TPI)
        x = x - ((unsigned long long)(x / TPI) * TPI);
    else if(x < -TPI)
        x = x - ((signed long long)(x / TPI) * TPI);
    long double sinX = 0.0;
    for (int n = 0; n < terms; ++n) {
        long double term = pow(-1, n) * pow(x, 2 * n + 1) / factorial(2 * n + 1);
        sinX += term;
    }
    return sinX;
}

long double cos(long double x, int terms = 10){
    if(x > TPI)
        x = x - ((unsigned long long)(x / TPI) * TPI);
    else if(x < -TPI)
        x = x - ((signed long long)(x / TPI) * TPI);
    long double cosX = 0.0;
    for (int n = 0; n < terms; ++n) {
        long double term = pow(-1, n) * ((pow(x, 2 * n) / (double)(factorial(2 * n))));
        cosX += term;
    }
    return cosX;
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

int main(){
    cout << "Программа, вычисляющая значения функции y = sin(x) - cos(x) с помощью цикла for на отрезке [A,B] в точках X = A + i * H\nГде H = (B - A) / M, M = 20, A = 0, B = pi / 2\n";
    cout << "Выполнил Бибиков Максим, группа 453502\n";
    while(true){
        cout << "Введите 1, если хотите выполнить программу, или 2, если хотите завершить работу программы\n";
        int type = readIntegerInLine();
        if(type == 2)
            break;
        else if(type != 1 && type != 2)
            continue;

        int A = 0, M = 20;
        double H,
        B = pi / 2, line = 0, y;
        H = (B - A) / M;
        for(int i = 0; line <= B;i++, line = (A + i * H)){
            y = sin(line) - cos(line);
            cout << "Значение функции y(" << i << ") равно " << y << '\n';
        }

    }
    return 0;
}
