#include <bits/stdc++.h>
using namespace std;

int in[100000], out[100000];
int t;

vector<vector<int>> tree;

void DFS(int r, int v)
{
    t++;

    in[r] = t;

    for(auto x : tree[r])
    {   
        if(x != v)
            DFS(x,r);
    }
    t++;

    out[r] = t;
}

int main()
{
    int nodes;

    cin >> nodes;

    tree.assign(200001,vector<int>());

    int a,b;

    for(int x = 0 ; x < nodes - 1 ; x++)
    {
        cin >> a >> b;

        tree[a].push_back(b);

        tree[b].push_back(a);
    }

    for(int x = 1 ; x < nodes + 1 ; x++)
    {
        cout << "Nodes Connected With " << x << " : ";

        for(int y = 0 ; y < tree[x].size() ; y++)
            cout << tree[x][y] << ' ';
        
        cout << endl;
    }


    int root;

    cin >> root;

    DFS(root,0);

    cout << endl;

    cout << "\nThe In-Out Time of Each Node is : -\n\n";

    for(int x = 1 ; x < nodes + 1 ; x++)
        cout << x << " : " << in[x] << " - " << out[x] << endl;   

    return 0;
}