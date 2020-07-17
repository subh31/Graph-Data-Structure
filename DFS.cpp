#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;
template<typename T>
class Graph
{map<T,list<T>> adjlist;
	public:
		void addedge(T u,T v,bool bidir)
		{
			adjlist[u].push_back(v);
			if(bidir)
			adjlist[v].push_back(u);
		}
		void printAdjList()
		{
			for(auto i:adjlist)
			{
				cout<<i.first<<"--->";
				for(T nbr:i.second)
				cout<<nbr<<" ";
				cout<<endl;
			}
		}
		void dfsHelper(T source,map<T,bool>&visited)
		{
			visited[source]=true;
			cout<<source<<" ";
			for(T nbr:adjlist[source])
			if(!visited[nbr]) dfsHelper(nbr,visited);
		}
		void dfs(T source)
		{
		
			map<T,bool>visited;
			dfsHelper(source,visited);
			
		}
};

int main()
{
	Graph<string>g;
	g.addedge("Ranchi","Jamshedpur",true);
	g.addedge("Ranchi","Dhanbad",true);
	g.addedge("Dhanbad","Bokaro",true);
	g.addedge("Jamshedpur","Chaibasa",true);
	g.addedge("Bokaro","Silli",false);
	
	g.dfs("Ranchi");
	
	return 0;
}
