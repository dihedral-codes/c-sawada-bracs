#include <stdio.h>		
#include <stdlib.h>

int N = 8, K = 2;
int *a;
int total = 0;

void print() {
  int j;
	
	for (j = 1; j <= N; j++)
	  printf("%d", a[j]); 
	
	printf("\n");
  
  total++;
}

int checkrev(int t, int i) {

  int j;
		
	for (j = i + 1; j <= (t + 1) / 2; j++) {
		if (a[j] < a[t - j + 1])
      return(0);
		if (a[j] > a[t - j + 1])
      return(-1);
	}

	return(1);
}

void generate(int t, int p, int r, int u, int v, int RS) {

  int j, rev;
	
	if (t - 1 > (((N - r) / 2) + r)) {
		if (a[t - 1] > a[N - t + 2 + r])
      RS = 0;
		else if (a[t - 1] < a[N - t + 2 + r])
      RS = 1;
	}
  	
  if (t > N) {
		if ((RS == 0) && ((N % p == 0)))
      print();  
	} else {

		a[t] = a[t - p];  
		
    if (a[t] == a[1])
      v++;
		else
      v = 0; 
		
    if ((u == -1) && (a[t - 1] != a[1]))
      u = r = t - 2;
		
		if ((u != -1) && (t == N) && (a[N] == a[1]))
      {} 
		else if (u == v) { 
			rev = checkrev(t, u);	
			if (rev == 0)
        generate(t + 1, p, r, u, v, RS);
			if (rev == 1)
        generate(t + 1, p, t, u, v, 0); 
		} 
		else
      generate(t + 1, p, r, u, v, RS);
		
    for (j = a[t - p] + 1; j <= K - 1; j++) {
			a[t] = j;  
			generate(t + 1, t, r, u, 0, RS);
		}
  }
}

int main() {
  
  a = malloc(sizeof(int) * N);
 
  a[0] = a[1] = 0;
	
  generate(1,1,1,-1,0,0);

	printf("\nTotal = %d\n\n", total);
	
  return 0;
}
