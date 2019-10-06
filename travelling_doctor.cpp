//Travelling doctor
#include<iostream>
using namespace std;

int findPos(double** graph,int V,int src,int T) {
	int visited[V]={0};
	visited[src]=1;
	int currPos=src,nextPos;
	double highestProb;
	for(int t=0;t<T/10;t+=10) {
		highestProb=-1;
		for(int j=0;j<V;j++) {
			if(graph[currPos][j]!=-1 && !visited[j] && graph[currPos][j]>highestProb) {
				highestProb=graph[currPos][j];
				nextPos=j;
			}
		}
		if(highestProb==-1) break;
		currPos=nextPos;
		visited[currPos]=1;
	}
	return currPos;
}

int main() {
	int t; cin >> t;
	while(t--) {
		int V,E,T;
		cin >> V >> E >> T;
		double** graph=new double*[V];
		for(int i=0;i<V;i++) {
			graph[i]=new double[V];	
			for(int j=0;j<V;j++)
				graph[i][j]=-1;
		}
		int u,v,start;
		double prob,highestProb=-1;
		while(E--) {
			cin >> u >> v >> prob;
			graph[u][v]=prob;	
			if(prob>highestProb) {
				highestProb=prob;
				start=u;	
			}
		}
		cout << findPos(graph,V,start,T) << endl;
	}
	return 0;
}
