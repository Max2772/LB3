#include <iostream>

using namespace std;

long int pow(long int num, long n){
    long int res = 1;
    for(int i = 0; i < n; i++){
        res *= num;
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

int main(){
    cout << "Программа, вычисляющая с помощью цикла do while сумму ряда ((1/2^n) + (1/3^n)) с точностью dn < ε\nГде ε = 10^-3\n";
    cout << "Выполнил Бибиков Максим, группа 453502\n";
    while(true){
        cout << "Введите 1, если хотите выполнить программу, или 2, если хотите завершить работу программы\n";
        int type = readIntegerInLine();
        if(type == 2)
            break;
        else if(type != 1 && type != 2)
            continue;

        long double d_temp, d = 0, E = 0.001;
        long int n_temp = 1;
        do
        {
            d_temp = 1 / (double)pow(2, n_temp) + 1 / (double)pow(3, n_temp);
            d += d_temp;
            n_temp++;
        } while (d_temp >= E);

        cout << "Ответ задачи: " << d << '\n';
    }
    return 0;
}