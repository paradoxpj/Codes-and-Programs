void printTopologicalOrder()
{
    //Assuming nodes in 0-indexing 0->n-1
    //n=no. of nodes, adj-> adjacency list representation of graph
    vector<int>inDegree(n,0);
    //updating in degree for each node:
    for(auto x:adj) for(auto y:x) inDegree[y]++;
    queue<int>q;
    for(int i=0;i<n;i++) if(inDegree[i]==0) q.push(i);
    vector<int>topo; //to store the topological order
    int s=0; //to store count of visited nodes
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        topo.push_back(x);
        for(auto it:a[x])
            if(--inDegree[it]==0) q.push(it);
        s++; // incrementing visited nodes
    }
    if(s==n) //print topo
    else cout<<"The Graph is cyclic";
}