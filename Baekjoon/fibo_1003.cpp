#include<iostream>
using namespace std;
int N;
int num;
int fibo[2][41]={0,};

int fibonacci_zero(int n){
	 if (n == 0) {
        return 1; 
    }
	else if(n == 1){
		return 0;
	}
	else if(fibo[0][n] != 0)
		return fibo[0][n];
	else{
		return fibo[0][n] = (fibonacci_zero(n-1) + fibonacci_zero(n-2));
	}
}

int fibonacci_one(int n){
	 if (n == 1) {
        return 1; 
    }
	else if(n == 0){
		return 0;
	}
	else if(fibo[1][n] != 0)
		return fibo[1][n];
	else{
		return fibo[1][n] = fibonacci_one(n-1) + fibonacci_one(n-2);
	}
}


int main(){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> num;
		cout << fibonacci_zero(num) << " " << fibonacci_one(num) << '\n';
	}
	return 0;
}
