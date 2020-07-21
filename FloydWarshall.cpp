#include<iostream>
using namespace std;
#define INF 99999
const int n=4;
void printmatrix(int M[n][n])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(M[i][j]!=INF)
			cout<<M[i][j]<<'\t';
			else
			cout<<"INF"<<'\t';
		}
		cout<<endl;
	}
}
void floydWarshall(int graph[n][n])
{
	int M[n][n];
	for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		M[i][j]=graph[i][j];
	}
	}
	for(int k=0;k<n;k++)
	{
	for(int i=0;i<n;i++)
	{
	for(int j=0;j<n;j++)
	{
		if(M[i][k]+M[k][j]<M[i][j])
	M[i][j]=M[i][k]+M[k][j];
	}
	}
	}
	printmatrix(M);
}

int main()
{
	int graph[n][n]={{0,3,INF,5},{2,0,INF,4},{INF,1,0,INF},{INF,INF,2,0}};
	floydWarshall(graph);
	return 0;
}
