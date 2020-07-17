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
		void bfs(T source)
		{
			queue<T>q;
			map<T,bool>visited;
			q.push(source);
			visited[source]=true;
			while(!q.empty())
			{
				T vertex=q.front();
				q.pop();
				cout<<vertex<<" ";
				for(T nbr : adjlist[vertex])
				{
					if(!visited[nbr])
					{
						q.push(nbr);
						visited[nbr]=true;					}
				}
			}
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
	
	g.bfs("Ranchi");
	
	return 0;
}
