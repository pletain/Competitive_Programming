#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int n;
int crd[2][16];
double w[16][16];
double memo[16][1 << 16];

double tsp(int pos, int mask){
	if(mask == ((1 << n) - 1)){
		 if (w[pos][0] == 0)
            return 987654321;
		else
			return w[pos][0];
	}
	
	if(memo[pos][mask] != 0)
		return memo[pos][mask];

	double ans = 987654321;
	for(int nxt = 1; nxt < n; nxt++){
		if(((mask & (1 << nxt))) == 0 && (w[pos][nxt] != 0)){
				ans = min(ans, w[pos][nxt] + tsp(nxt, (mask | (1 << nxt))));
			}
		}
	return memo[pos][mask] = ans;
}
 
void input(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> crd[0][i];
		cin >> crd[1][i];
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			w[i][j] = sqrt(pow(crd[0][i] - crd[0][j],2) + pow(crd[1][i] - crd[1][j],2));
		}
	}
}

int main(){
	input();
	printf("%lf", tsp(0, 1));
	
	return 0;
}

