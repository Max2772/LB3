#include <iostream>
#include <cmath>

const long double PI = 3.141592653589793238462643383279502884L;
const long double TWO_PI = 2.0L * PI;
const long double e = 2.718281828459045235360287471352662497L;

using namespace std;

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

long double SQRT(long double x) {
    long double left = 0, right = x + 1;

    for (int i = 0; i < 200; i++) {
        long double middle = (left + right) / 2;
        if (middle * middle < x) {
            left = middle;
        } else {
            right = middle;
        }
    }

    return left;
}

long double POW(long double num, long long n){
    long double res = 1;
    for(int i = 0; i < n; i++){
        res *= num;
    }
    return res;
}

long double factorial(int n){
    long double res = 1;
    for(int i = 1; i <= n; i++){
        res *= i;
    }
    return res;
}

long double ABS(long double num){
    if(num < 0)
        num *= -1;
    return num;
}

long double ugol(long double x){
    if(x > 1e20){
        x = 0;
    }else{
        if(x >= 0){
            unsigned long long quotient = static_cast<unsigned long long>(x / TWO_PI);
            x -= quotient * TWO_PI;
        }else{
            signed long long quotient = static_cast<signed long long>(x / TWO_PI);
            x -= quotient * TWO_PI;
        }

        if (x > PI) {
            x -= TWO_PI;
        } else if (x < -PI) {
            x += TWO_PI;
        }
    }

    return x;
}

long double SIN(long double x, long double nothing) {
    x = ugol(x); 

    long double sum = 0.0;
    long double term = x;
    long double x_square = x * x;
    int sign = 1;

    const int terms = 25; 

    for (int n = 1; n <= terms; ++n) {
        sum += sign * term;
        term *= x_square / ((2 * n) * (2 * n + 1));
        sign *= -1;
    }

    return sum;
}

long double COS(long double SINX, long double x) {
    long double COSX = SQRT(1.0 - SINX * SINX);
    x = ugol(x);
    if (x > PI / 2 || x < -PI / 2) {
        COSX *= -1;
    }

    return COSX;
}

long double ln(long double x, long double nothing){
    long int count = 0, n = 1;
    while(x > 1){
        x /= e;
        count++;
    }
    while(x < 1e-4){
        x *= e;
        count--;
    }
    long double res = 0, ter = x - 1;
    while(ABS(ter) > 1e-8){
        res += ter;
        ter *= -(x - 1) * n / (n + 1);
        n++;
    }
    return res + double(count);
}

long double myMin(long double a, long double b, long double c){
    if(a < b && a < c)
        return a;
    else if(b < a && b < c)
        return b;
    else
        return c;
}

int main(){
    cout << "Программа, вычисляющая минимальное значение функций a = SIN(x), b = COS(x), c = ln(|x|) при заданном x\n";
    cout << "Выполнил Бибиков Максим, группа 453502\n";
    while(true){
        cout << "Введите 1, если хотите выполнить программу, или 2, если хотите завершить работу программы\n";
        int type = readDoubleInLine();
        if(type == 2)
            break;
        else if(type != 1 && type != 2)
            continue;
        
        cout << "Введите любой x: ";
        long double x = readDoubleInLine();

        long double(*p[3])(long double) = {};
        p[0] = &SIN;
        p[1] = &COS;
        p[2] = &ln;


        long double a,b,c;
        a = p[0](x);
        b = p[1](x);
        c = p[2](x);

        cout << "mySin(" << x << ") = ";
        printf("%.18Lf",a);
        cout << " sin(" << x << ") = " << sin(x) << '\n';
        cout << "myCos(" << x << ") = ";
        printf("%.18Lf",b);
        cout << " cos(" << x << ") = " << cos(x) << '\n';
        cout << "myLnx(" << x << ") = ";
        printf("%.18Lf",c);
        cout << " ln(" << x << ") = " << log(x) << '\n';
        cout << "Минимальное значение: ";
        printf("%.18Lf",myMin(a,b,c));
        cout << '\n';
    }
    return 0;
}
