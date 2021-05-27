#pragma once
void printSol(vector<vector<int>>& G, vector<int>& colors) {
	for (int i = 1; i < G.size(); i++) {
		cout << "Vertex  ----    color\n";
		cout << i << "    ----    " << colors[i] << endl;
	}
	cout << "\n";
}

bool isSafe(vector<vector<int>>& G, vector<int>& colors) {
	for (int i = 1; i < G.size(); i++) {
		for (int j = i + 1; j < G.size(); j++) {
			if (G[i][j] && colors[i] == colors[j])	//here we check if there is an edge b/w i and j now we check if there's an edge then is the color of the vertices i and j are same
				return false;
		}
	}
	return true;
}
bool solveGC(vector<vector<int>>& G, vector<int>& colors, int m, int i) {
	if (i == G.size()) {
		if(isSafe(G,colors))
			return true;
		return false;
	}

	for (int j = 0; j < m; j++) {
		colors[i] = j;

		if (solveGC(G, colors, m, i + 1))
			return true;

		colors[i] = 0;
	}

	return false;
}

void GraphColoring() {
	int V,m;
	cout << "Enter the number of vertices in the Graph : ";
	cin >> V;
	V = V + 1;
	vector<vector<int>>G(V,vector<int>(V,0));
	vector<int>colors(G.size(),0);

	cout << "Enter the vertices of the graph (Since the graphs we are working\non are undirected, therfore the edge b/w a pair of vertices are bidirectional)\n\n";
	cout << "Enter 0 if there's no edge b/w pair of vertices else 1 if there's is one\n\n";
	for (int i = 1; i < V; i++) {
		for (int j = 1; j < V; j++) {
			if (i == j) {
				G[i][j] = 0;
			}
			else {
				if (G[i][j] == 0) {
					cout << "Is there an edge b/w " << i << " and " << j << " : ";
					cin >> G[i][j];
					G[j][i] = G[i][j];
				}
			}
		}
	}

	cout << "\nEnter the number of colors : ";
	cin >> m;

	if (solveGC(G, colors, m, 1)) {
		printSol(G, colors);
	}
	else {
		cout << "The graph is not colorable, Hence increase the number of colors\n";
	}
}