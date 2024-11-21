    #include <iostream>

    using namespace std;

    long double pow(long double num, long int n){
        long double res = 1;
        for(int i = 0; i < n; i++){
            res *= num;
        }
        return res;
    }

    long int digitsCount(long int num){
        int res = 0;
        while(num > 0){
            num /= 10;
            res++;
        }
        return res;
    }

    bool armstrongNum(long int num){
        int cnt = digitsCount(num);
        long int sum = 0; long int num_temp = num;
        while(num_temp > 0){
            sum += pow(num_temp % 10, cnt);
            num_temp /= 10;
        }
        if(sum == num)
            return 1;
        else
            return 0;
    }

    int main(){
            long int N;
            cin >> N;

            cout << "Числа Армстронга: ";
            for(int i = 1; i < N; i++){
                if(armstrongNum(i))
                    cout << i << ' '; 
            }
            
            cout << '\n';

        return 0;
    }
