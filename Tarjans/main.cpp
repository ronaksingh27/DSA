#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; // Adjacency list

void DFS(int u, vector<int>& disc, vector<int>& low, vector<bool>& presentStack, stack<int>& myStack) {
    static int time = 0;
    disc[u] = low[u] = time++;
    myStack.push(u);
    presentStack[u] = true;

    for (int v : adj[u]) {
        if (disc[v] == -1) {
            DFS(v, disc, low, presentStack, myStack);
            low[u] = min(low[u], low[v]);
        } else if (presentStack[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (disc[u] == low[u]) {
        cout << "SCC is : ";
        while (myStack.top() != u) {
            cout << myStack.top() << " ";
            presentStack[myStack.top()] = false;
            myStack.pop();
        }
        cout << myStack.top() << " ";
        presentStack[myStack.top()] = false;
        myStack.pop();
        cout << endl;
    }
}

void findSCC_TarjansAlgo(int V) {
    vector<int> disc(V, -1), low(V, -1);
    vector<bool> presentStack(V, false);
    stack<int> myStack;

    for (int i = 0; i < V; i++) {
        if (disc[i] == -1) {
            DFS(i, disc, low, presentStack, myStack);
        }
    }
}

int main() {
    int V = 5; // Number of vertices
    adj.resize(V);
    
    // Test Case 1: Simple graph with no SCCs
    /*
    V = 4; // Adjust number of vertices
    adj.resize(V);
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    */

    // Test Case 2: Graph with one SCC (cycle)
    
    // V = 4; // Adjust number of vertices
    // adj.resize(V);
    // adj[0].push_back(1);
    // adj[1].push_back(2);
    // adj[2].push_back(0);
    

    // Test Case 3: Multiple SCCs
    // V = 5; // Adjust number of vertices
    // adj.resize(V);
    // adj[0].push_back(1);
    // adj[1].push_back(0);
    // adj[2].push_back(3);
    // adj[3].push_back(2);

    // Test Case 4: Disconnected graph
    // V = 5; // Adjust number of vertices
    // adj.resize(V);
    // adj[0].push_back(1);
    // adj[2].push_back(3);

    // Test Case 5: Complete graph
    V = 3; // Adjust number of vertices
    adj.resize(V);
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(1);


    findSCC_TarjansAlgo(V);
    
    return 0;
}
