// This Algorithm used to find Strongly Connected component of a graph or for checking strongly component graph.
// Strongly Connected Component :-  if we can reach from every vertex to every other vertex in a component then it is called strongly connected component.
// Strongly Connected Graph:-if in a graph every vertex is reachable from every another vertex then it is Strongly Connected Graph.
            
//  In above graph  there is total 4 strongly connected component.
// Component             vertex
// 1                              0 , 2 ,1
// 2                              3
// 3                              4,6,5
// 4                               7
// Note:-single vertex is always strongly connected.   
// Kosaraju algorithm:-
// step1:-Perform DFS traversal of graph push node to stack before returning.
// Step2:-Find transpose of a graph by reversing the edges.
// Step3:-Pop node one by one from stack and again do DFS traversal on modified graph keep popping nodes each successful DFS traversal give 1 Strongly Connected Component.


// CODE:-

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//for adjacency list of a graph
vector<int> arr1[51];

//for transpose of agraph
vector<int> arr2[51];


int visited[51];
int visited2[51];
stack<int> st;
int r;

//DFS Traversal of a graph
void DFS(int node){

    visited[node]=1;
    for(int child: arr1[node]){

        if(visited[child]!=1){
            DFS(child);

        }
    }
    st.push(node);
}

//DFS traversal of modified graph
void DFS2(int node){
    cout<<node<<" ";
    visited2[node]=1;
    for(int child: arr2[node]){
    if(visited2[child]!=1){
            DFS2(child);

        }
    }

}
int main(){

    int n,m,x,y;

    /*n is number of vertex and m is number of edge
    x and y is representing path between x and y  */
    cout<<"Enter number of vertex and number of edge"<<endl;
    cin>>n>>m;
    while(m--){
        cout<<"enter vertex having edge in ----> this way"<<endl;
        cin>>x>>y;
        //this is for undirected graph

        arr1[x].push_back(y);
        arr2[y].push_back(x);
    }

    DFS(0);
    cout<<" strongly connected component "<<endl;
    while(!st.empty()){
        int k=st.top();
        st.pop();
        if(visited2[k]!=1){
            r++;
            cout<<endl;
            DFS2(k);
        }


    }
    cout<<endl;
    cout<<"Total number of strongly connected component = "<<r<<" follows above "<<endl;



    return 0;
}