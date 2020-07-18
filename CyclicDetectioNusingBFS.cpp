#include<iostream>
#include<map>
#include<unordered_map>
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
		bool cyclicHelper(T source,map<T,bool>&visited)
		{	unordered_map<T,T> parent;
			queue<T> q;
			visited[source]=true;
			parent[source]=source;//The starting vertex does not have a parent
			q.push(source);
			while(!q.empty())
			{
				int f=q.front();
				q.pop();
				for(auto nbr:adjlist[f])
				{
					if(!visited[nbr])
					{visited[nbr]=true;
					q.push(nbr);
					parent[nbr]=f;
					}
					else if(parent[f]!=nbr)
					return true;
				}
				
			}
			return false;
		}
		bool iscycle()
		{
			map<T,bool> visited;
			for(auto i:adjlist)
			{
				T vertex=i.first;
				if(!visited[vertex])
				return(cyclicHelper(vertex,visited));
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
