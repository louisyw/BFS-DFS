/*部分和问题：给定整数a[1],a[2],...,a[n],判断是否可以从中选出若干数，使它们的和恰好为k*/

#include <stdio.h>

typedef int bool;
#define TRUE 1
#define FALSE 0

#define SIZE 5

int a[SIZE]={1,2,3,4,7};

int k = 13;

bool DFS(int depth, int sum)
{
	if(depth == SIZE) return sum == k;

	if(DFS(depth+1, sum)) return TRUE;  

	if(DFS(depth+1, sum + a[depth])) return TRUE;  //add a[depth]

	return FALSE;
}

int main()
{
	if(DFS(0, 0)) printf("YES\n");
	else printf("NO\n");
	return 0;
}
