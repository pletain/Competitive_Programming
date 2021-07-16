/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>


using namespace std;

int Answer;

int main(int argc, char** argv)
{
    setbuf(stdout, NULL);
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		int N;
		
		int data[100001][100001];
        bool check[100001];
        
        cin >> N;
		for(int i=1; i<=N; i++)
		{
		    cin >> data[i][i];
		    int temp = i + data[i][i];
		    if(temp <= N){
		        data[i][temp] = 1;
		    }
		}
		
		for(int i=1; i<=N; i++){
		    int cur = i;
			if(check[cur] != 1){
				while(){
		        int next = cur + data[cur][cur];
		        if(data[cur][next] == 1){
		            check[next] = 1;
		            cur = next;
		        }
		        else{
		            Answer++;
		            break;
		        }
		    }
			}
		    
		}
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}
	
		// Print the answer to standard output(screen).

	return 0;//Your program should return 0 on normal termination.
}
