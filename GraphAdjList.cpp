#include<iostream>
#include<list>
using namespace std;
class Graph
{int v;
list<int> *l;
	public:
		Graph(int v)
		{
			this-> v=v;
			l=new list<int>[v];
		}
		void addedge(int u,int v,bool bidir)
		{
			l[u].push_back(v);
			if(bidir)
			l[v].push_back(u);
		}
		void printAdjList()
		{
			for(int i=0;i<v;i++)
			{
				cout<<i<<"--->";
				for(int node:l[i])
				cout<<node<<" ";
				cout<<endl;
			}
		}
};

int main()
{
	Graph g(5);
	g.addedge(0,1,true);
	g.addedge(1,2,true);
	g.addedge(2,3,true);
	g.addedge(3,4,true);
	g.addedge(4,1,false);
	g.printAdjList();
	
	return 0;
}
