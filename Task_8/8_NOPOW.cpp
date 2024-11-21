#include <iostream>

using namespace std;

long int readIntegerInLine() {
    long int number;
    while (!(cin >> number) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Ошибка ввода. Введите заново: ";
    }
    
    return number;
}

int main(){
    cout << "Программа, вычисляющая сумму последовательности 2^(i) * (-1)^(i) * a[i] без использования pow\n";
    cout << "Выполнил Бибиков Максим, группа 453502\n";
    while(true){
        cout << "Введите 1, если хотите выполнить программу, или 2, если хотите завершить работу программы\n";
        int type = readIntegerInLine();
        if(type == 2)
            break;
        else if(type != 1 && type != 2)
            continue;
        
        cout << "Введите n (n - целое неотрицательное число ): ";
        long int n;
        while(true){
        n = readIntegerInLine();
        if(n < 0){
            cout << "Некорректный ввод. Введите новое число: ";
            continue;
        }
        break;
        }

        long int res = 0, two = 1; int minus = 1;
        for(int i = 0;i < n; i++){
            cout << "Введите a[" << i << "]: ";
            long int a = readIntegerInLine();
            res += a * minus * two;
            minus *= -1; two *= 2;
        }

        cout << "Результат вычислений: " << res << '\n';
    }
    
    return 0;
}
