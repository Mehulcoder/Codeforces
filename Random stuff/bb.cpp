#include<bits/stdc++.h>
using namespace std;
#define MAXN 51
int x[]={0, 0, -1, 1};
int y[]={1, -1, 0, 0};

int solver(char board[][MAXN],int n, int m, int i, int j, vector<vector<int>> &visited, int p, int q){
    visited[i][j]=1;
    std::cout << "i- "<<i<<" j- "<<j<<" p- "<<p<<" q- "<<q << std::endl;
    
    for(int k=0;k<4;k++){
        if(i+x[k]<0 || j+y[k]<0 || i+x[k]>=m || j+y[k]>=n || board[i+x[k]][j+y[k]]!=board[i][j]){
    //        std::cout << "k- "<<k << std::endl;
            continue;
            
        }else if(visited[i+x[k]][j+y[k]]==0){
      //      std::cout << "K "<<k << std::endl;
        //    std::cout << "HERE" << std::endl;
          //   std::cout << "visited "<<visited[i][j] << std::endl;
            return solver(board, n, m, i+x[k], j+y[k], visited, i, j);
            
        }else if(visited[i+x[k]][j+y[k]]==1 && i+x[k]!=p && j+y[k]!=q){
            // std::cout << "K2 "<<k << std::endl;
    //        std::cout << "here" << std::endl;
            return 1;
         
        }
    
    
    
    }
    return 0;
}


int solve(char board[][MAXN],int n, int m)
{
    vector<vector<int>> visited(n, vector<int> (m, 0));
   
   for (int i = 0; i < n; i++) {
       for (int j = 0; j < m; j++) {
           
           if(visited[i][j]==1){
               continue;
           }
           
           if(solver(board, n, m, i, j, visited, i, j)==1){
              
               return 1;
           }
       }
   }
    
    
   
    return 0;
}





int main()
{
	int N,M,i;
	char board[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>board[i];
	}
	cout<<solve(board,N,M)<<endl;
}