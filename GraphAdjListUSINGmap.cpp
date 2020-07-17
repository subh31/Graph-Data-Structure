#include<iostream>
#include<map>
#include<list>
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
};

int main()
{
	Graph<string>g;
	g.addedge("Ranchi","Jamshedpur",true);
	g.addedge("Jamshedpur","Dhanbad",true);
	g.addedge("Dhanbad","Bokaro",true);
	g.addedge("Bokaro","Silli",false);
	g.printAdjList();
	
	return 0;
}
