#include<iostream>
using namespace std;
int dist[10][10] = {
        {0,20,42,25},
        {20,0,30,34},
        {42,30,0,10},
        {25,34,10,0}
};
int n=4;//No of cities(vertices)
int VISITED_ALL = (1<<n) -1;//(mask, if all cities are visited)

int  tsp(int mask,int pos)
{	
	if(mask==VISITED_ALL){
		return dist[pos][0];
	}
	

	int ans = INT_MAX;

	//Visit all the unvisited cities and take the best route i.e. cost is minimum
	for(int city=0;city<n;city++){

		if((mask&(1<<city))==0){

			int newAns = dist[pos][city] + tsp( mask|(1<<city), city);
			ans = min(ans, newAns);
		}

	}
	
	return ans;
} 

int main(){
   
	cout<<"Travelling Saleman Distance is "<<tsp(1,0);

return 0;
}
