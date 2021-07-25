#include<iostream>
using namespace std;

int n;
int w[16][16];
int memo[16][1 << 16];

int tsp(int pos, int mask){
	if(mask == ((1 << n) - 1)){
		 if (w[pos][0] == 0)
            return 987654321;
		else
			return w[pos][0];
	}
	
	if(memo[pos][mask] != 0)
		return memo[pos][mask];

	int ans = 987654321;
	for(int nxt = 1; nxt < n; nxt++){
		if(((mask & (1 << nxt))) == 0 && (w[pos][nxt] != 0)){
				ans = min(ans, w[pos][nxt] + tsp(nxt, (mask | (1 << nxt))));
			}
		}
	return memo[pos][mask] = ans;
}

int main(){

	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> w[i][j];
		}
	}
	cout << tsp(0,1) << endl;
	
	return 0;
}

