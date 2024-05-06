#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;


void addlst(int src,int dst,map adjlist)
{
    adjlst[src].push_back(dest);
    adjlst[dest].push_back(src);
}

void dfs(int node)
{
    visited[node]=true;
    cout<<node<<" ";
    for(int i:adjlist[node])
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }
}

void bfs()
{
    if(q.empty())
    {
        return;
    }
    int node=q.front();
    q.pop();
    cout<<node<<" ";

    for(int i:adjlst[node])
    {
        if(!visited[i])
        {
            visited[i]=true;
            q.push(i)
        }
    }
    bfs();
}

int main()
{
    map<int,list<int>>adjlist;
    map<int,bool>visited;
    queue<int>q;
    addlst(0,1);
    addlst(0,2);
    addlst(0,3);
    addlst(1,3);
    addlst(3,4);
    addlst(4,5);
    addlst(2,6);
    q.push(0);
    visited[0]=true;
    bfs();
    

    return 0;
}