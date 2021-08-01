#include<iostream>
#include<string>
using namespace std;
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int T, n, avg, elite;
	int score[1000]={0,};
	double per;
	
	cin >> T;
	for(int i=0; i<T; i++){
		avg = 0;
		elite = 0;
		cin >> n;
		
		for(int j=0 ; j<n; j++){
			cin >> score[j];
			avg = avg + score[j];
		}
		avg = avg / n;
		for(int j=0 ; j<n; j++){
			if(score[j] > avg)
				elite++;
		}
		
		
		per = (double)elite/n*100;
		
		cout << fixed;
		cout.precision(3);
		cout << per << "%" << '\n';
	}

	}
