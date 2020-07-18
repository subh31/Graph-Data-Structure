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
		bool cyclicHelper(T source,map<T,bool>&visited,T parent)
		{
			visited[source]=true;
			for(T nbr:adjlist[source])
			if(!visited[nbr]) return cyclicHelper(nbr,visited,source);
			else if(nbr!=parent) return true;
			return false;
		}
		bool iscycle()
		{
			map<T,bool> visited;
			for(auto i:adjlist)
			{
				T vertex=i.first;
				if(!visited[vertex])
				return(cyclicHelper(vertex,visited,-1));//As the first vertex is not having any parent
			}
			return false;
		}
};

int main()
{
	Graph<int>g;
	g.addedge(0,1,true);
	g.addedge(1,2,true);
	g.addedge(2,3,true);
	g.addedge(3,4,true);
	g.addedge(4,0,true);
	if(g.iscycle())
	cout<<"Graph is cyclic";
	else cout<<"Graph is not cyclic";
	
	return 0;
}
