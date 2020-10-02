//Prim's Algorithm for minimum spanning tree 1MS17IS051
#include <iostream>
using namespace std;

//get the weighted matrix(matrix with distances on the edges mentioned)
void get_matrix(int numberOfNodes,int W[20][20])
{

	cout << "Enter the weighted adjacency matrix: " << endl;

	for (int i=0; i<numberOfNodes; i++)
		for(int j=0; j<numberOfNodes; j++)
			cin >> W[i][j];
}

// Prim's Algorithm

void prim(int numberOfNodes,int W[20][20])
{
	int source;
	int min, min_cost=0;
	int visited[20]; //Create a new array visited[] and assign all the values 
	int a,b,u,v;
	int numberOfEdges = 1;


	for(int i=0; i<numberOfNodes; i++)
		visited[i] = 0; // assign the set of edges to 0 E(t) = 0

	cout << "Enter the index of source node: " << endl;
	cin >> source;
	visited[source] = 1;

	//Creating Minimum cost spanning tree

	//Variable names are quite clearly explaining this loop
	while(numberOfEdges < numberOfNodes) 
	{
		min = 999;

		for(int i=0; i<numberOfNodes; i++)
		{
			for(int j=0; j<numberOfNodes; j++)
			{
				if(W[i][j] < min)	// if the weight of node is less than the minimum 
				{
					
					if (visited[i]) // if there occours a visited node(Starts with source as visited[source] = 1
					{
						min = W[i][j]; // assign new minimum and repeat the process till all nodes are visited
						a = u = i;
						b = v = j;
					} // end of else for inner if
				} // end of outer if
			}// end of inner for loop
		} // end of outer for loop

		if(visited[u]==0 || visited[v]==0)	//While there are still un-visited nodes, print the min weight
		{
			cout << "Number of edges in created tree vertices= " << numberOfEdges++<<endl;
			cout << a << "->" << b << " = " << min <<endl;
			min_cost = min_cost + min;
			visited[b] = 1;  // Change the status at index b=v=j to visited.
		}

		W[a][b] = W[b][a] = 999; //The vertices already printed(added to tree vertices) need not be visited again.
			
	} // end of while

	cout << "Minimum Cost = " << min_cost << endl;
		
} // end of prim

int main()
{
	int W[20][20];
	int numberOfNodes;
	cout << "Enter the number of nodes: ";
	cin >> numberOfNodes;

	get_matrix(numberOfNodes, W);
	prim(numberOfNodes, W);

	return 0;

}



