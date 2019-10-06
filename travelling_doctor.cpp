//Travelling doctor
/*problem:
https://www.geeksforgeeks.org/samsung-interview-experience-set-39-campus-r-d-noida/
Sample input:T=1
	     Nodes=6 Edges=10 Time=40
	     u      v        probability
	     1	    2         0.3
	     1	    3 	      0.7
	     3	    3	      0.2
	     3	    4	      0.8
	     2	    4 	      1.0
	     4	    5	      0.9
	     4	    4	      0.1
	     5	    6 	      1
	     6	    3	      0.5
	     6	    6	      0.5
	     
	Output:6        //after 40 seconds, he will be in 6th division
*/
#include<iostream>
using namespace std;

int findPos(double** graph,int V,int src,int T) {
	int visited[V+1]={0};
	visited[src]=1;
	int currPos=src,nextPos;
	double highestProb;
	for(int t=0;t<T/10;t++) {
		highestProb=-1;
		for(int j=1;j<=V;j++) {
			if(graph[currPos][j]!=-1 && !visited[j] && graph[currPos][j]>highestProb) {
				highestProb=graph[currPos][j];
				nextPos=j;
			}
		}
		if(highestProb==-1){               //if there are no further division after current division, move dr. to next division
            currPos=(currPos+1)%(V+1);      //corner case
		}
		else currPos=nextPos;
		visited[currPos]=1;
	}
	return currPos;
}

int main() {
	int t; cin >> t;
	while(t--) {
		int V,E,T;
		cin >> V >> E >> T;
		double** graph=new double*[V+1];
		for(int i=0;i<=V;i++) {
			graph[i]=new double[V+1];
			for(int j=0;j<=V;j++)
				graph[i][j]=-1;
		}
		int u,v,start=1;          //if we always start with 1st division
		double prob,highestProb=-1;
		while(E--) {
			cin >> u >> v >> prob;
			graph[u][v]=prob;
			/*if(prob>highestProb) {              // if we start with highest probability division
				highestProb=prob;
				start=u;
			}*/
		}
		cout << findPos(graph,V,start,T) << endl;
	}
	return 0;
}
