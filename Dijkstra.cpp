//Single Source Shortest Path(SSSP) for Weighted Graph
#include<iostream>
#include<unordered_map>
#include<list>
#include<set>
using namespace std;

template<typename T>
class Graph{
	unordered_map<T,list<pair<T,int>>>m;
	public:
		void addedge(T src,T des ,int weight,bool bidir=true)
		{
			m[src].push_back(make_pair(des,weight));
			if(bidir) m[des].push_back(make_pair(src,weight));
		}
		void printAdjList()
		{
			for(auto i:m)
			{
				cout<<i.first<<"-->";
				for(auto nbr: i.second)
				cout<<"("<<nbr.first<<","<<nbr.second<<")";
				cout<<endl;
			}
		}
		void dijkstra(T src)
		{
			unordered_map<T,int> dist;
			for(auto i: m)
			dist[i.first]=INT_MAX;
			
			set<pair<int,T>>s;
			dist[src]=0;
			s.insert(make_pair(0,src));
			while(!s.empty())
			{
				auto p=*(s.begin());
				int dis=p.first;
				T city=p.second;
				s.erase(s.begin());
				for(auto nbr:m[city])
				{
					if(dis+nbr.second<dist[nbr.first])
					{   T dest=nbr.first;
						auto f=s.find(make_pair(dist[dest],dest));
						if(f!=s.end())
						s.erase(f);
						dist[dest]=dis+nbr.second;
						s.insert(make_pair(dist[dest],dest));
						
					}
				}
				
			}
			for(auto d:dist)
				cout<<d.first<<" is at a distance of "<<d.second<<endl;
		}
};
int main()
{
	Graph<string> G;
	G.addedge("Amritsar","Delhi",1);
	G.addedge("Amritsar","Jaipur",4);
	G.addedge("Jaipur","Delhi",2);
	G.addedge("Jaipur","Mumbai",8);
	G.addedge("Bhopal","Agra",2);
	G.addedge("Mumbai","Bhopal",3);
	G.addedge("Agra","Delhi",1);
	G.dijkstra("Amritsar");
	return 0;
}

