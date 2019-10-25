#include <iostream>
using namespace std;
#include <algorithm>

class edge {
  public:
    int source;
    int dest;
    int weight;


};

bool mycomp(edge a, edge b){
    return(a.weight<b.weight);
}

int findparent(int v, int* parent){
    if (parent[v] == v)
    {
        return v;
    }

    return findparent(parent[v], parent);


}

void kruskals(edge* input, int n, int e){
    sort(input, input+e, mycomp);
    
    edge* output = new edge[n-1];

    int* parent = new int[n];
    for (int i = 0; i < n; ++i)
    {
        parent[i] = i;
    }

    int count = 0;
    int i = 0;
    while(count!=n-1){
        edge currentedge = input[i];
        //Check if we can add current edge in MSR or not!

        int sourceparent = findparent(currentedge.source, parent);
        int destparent = findparent(currentedge.dest, parent);

        if(sourceparent != destparent){
            output[count] = currentedge;
            count++;
            parent[sourceparent] = destparent;
        }
        i++;
    }

    for (int i = 0; i < n-1; ++i)
    {   if(output[i].source < output[i].dest){
        cout<<output[i].source<<" "
        <<output[i].dest<<" "<<output[i].weight<<endl;
    }else{
        cout<<output[i].dest<<" "
        <<output[i].source<<" "<<output[i].weight<<endl;
    }
    }

}


int main()
{
    int n,e;
    cin>>n>>e;

    edge* input = new edge[e];

    for (int i = 0; i < e; ++i)
    {
        int p,q,r;
        cin>>p>>q>>r;
        input[i].source = p;
        input[i].dest = q;
        input[i].weight = r;

    }

    kruskals(input, n ,e);
    
    
    


  return 0;
}
 