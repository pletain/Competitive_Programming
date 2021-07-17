You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>

using namespace std;



int main(int argc, char** argv)
{
int T, test_case;
setbuf(stdout, NULL);
/*
  The freopen function below opens input.txt file in read only mode, and afterward,
  the program will read from input.txt file instead of standard(keyboard) input.
  To test your program, you may save input data in input.txt file,
  and use freopen function to read from the file when using cin function.
  You may remove the comment symbols(//) in the below statement and use it.
  Use #include<cstdio> or #include <stdio.h> to use the function in your program.
  But before submission, you must remove the freopen function or rewrite comment symbols(//).
*/

// freopen("input.txt", "r", stdin);


scanf("%d", &T);
for(test_case = 0; test_case  < T; test_case++)
{

int n, t;
scanf("%d", &n);
scanf("%d", &t);
int binaryB[n+1], binaryA[n+1];

int fix[n+1]={0,};
for(int i=1; i<n+1; i++){
   scanf("%1d",&binaryB[i]);

if(binaryB[i] == 0){ //0이면 모든 요소 0으로 fix
if(i+t <= n){
binaryA[i+t] = 0;
           fix[i+t] = 1;
       }
       if(i-t >= 1){
           binaryA[i-t] = 0;
           fix[i-t] = 1;
       }
   }
else if(i <= t){ // 양쪽 t로부터 fix값
       binaryA[i+t] = binaryB[i];
       fix[i+t] = 1;
   }
   else if(i > n-t){
       binaryA[i-t] = binaryB[i];
       fix[i-t] = 1;
   }


}


for(int i=1+t; i<n+1-t; i++){

  if(binaryB[i] == 1){ //1일때 한쪽만 정해져 있다면.
 
  if(fix[i-t] == 1 && fix[i+t] == 0){
  if(binaryA[i-t] == 1){
  binaryA[i+t] = 0;
  }
  else{
  binaryA[i+t] = 1;
  }
          fix[i+t] = 1;
      }
   else if(fix[i-t] == 0 && fix[i+t] == 1){
  if(binaryA[i+t] == 1){
  binaryA[i-t] = 0;
  }
  else{
  binaryA[i-t] = 1;
  }
          fix[i-t] = 1;
      }  

  }
}



int i=1, j;
while(i<n+1){
if(fix[i]==0){
j=i;
binaryA[j]=0;
break;
}
i++;
}
int flag = 0;
while(j<=n){
j=j+t+t;
if(flag == 0){
binaryA[j] = 1;
flag = 1;
}
else{
binaryA[j] = 0;
flag = 0;
}

}



printf("Case # %d\n",test_case+1);
for(int i=1; i<n+1; i++){
printf("%d",binaryA[i]);
}
printf("\n");
}

return 0;//Your program should return 0 on normal termination.
}
