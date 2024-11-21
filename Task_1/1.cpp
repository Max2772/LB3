#include <iostream>

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

int main(){
    cout << "Программа, вычисляющая с помощью цикла for сумму (ai-bi)^2 для i от 1 до 30\n";
    cout << "Выполнил Бибиков Максим, группа 453502\n";
    while(true){
        cout << "Введите 1, если хотите выполнить программу, или 2, если хотите завершить работу программы\n";
        int type = readIntegerInLine();
        if(type == 2)
            break;
        else if(type != 1 && type != 2)
            continue;

        long long int A, B, N = 0;

        for(int i = 1; i <= 30; i++){
            if(i % 2 == 0){
                A = i / 2; B = i * i * i;
            }else{
                A = i; B = i * i;
            }
            N = N + (A - B) * (A - B);
        }

        cout << "Ответ задачи: " << N << '\n';
    }
    return 0;
}