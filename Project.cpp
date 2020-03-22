#include <iostream> 
using namespace std; 
  
int main() 
{ 
    int n, m, i, j, k; 
    int alloc[10][10];
        cout<<"Enter no. of process:" ;
        cin>>n;
        cout<<"Enter no. of resources:";
        cin>>m;
        cout<<"Enter Allocation Matrix Elements : \n";
        for(i=1; i<=n; i++)
        {
                for(j=1; j<=m; j++)
                {
                        cout<<" ";
                        cin>>alloc[i][j];
                }
        }
        cout<<"\n----- Allocation Matrix ----------\n";
        for(i=1; i<=n; i++)
        {
                for(j=1; j<=m; j++)
                {
                        cout<<" "<<alloc[i][j]<<" ";
                }
                cout<<"\n";
        }


    int max[10][10];
        cout<<"\n Enter Maximum Matrix Elements : \n";
        for(i=1; i<=n; i++)
        {
                for(j=1; j<=m; j++)
                {
                        cout<<" ";
                        cin>>max[i][j];
                }
        }
        cout<<"\n----- Maximum Matrix ----------\n";
        for(i=1; i<=n; i++)
        {
                for(j=1; j<=m; j++)
                {
                        cout<<" "<<max[i][j]<<" ";
                }
                cout<<"\n";
        }
    
    int avail[10];
        cout<<"\n Enter Avail Matrix Elements : \n";
        for(i=1;i<=m;i++)
        {
        		cout<<" ";
        		cin>>avail[i];
		}
		cout<<"\n----- Avail Matrix ----------\n";
        for(i=1;i<=m;i++)
        {
        		cout<<" "<<avail[i]<<" ";
		}
		cout<<"\n";
		
		
		
	int f[n], ans[n], ind = 0; 
    for (k = 0; k < n; k++) { 
        f[k] = 0; 
    } 
    
    int need[n][m]; 
    for (i = 1; i <=n; i++) 
	{ 
        for (j = 1; j <=m; j++)
		{
		    need[i][j] = max[i][j] - alloc[i][j];
	    }
    } 
    
    cout<<"\n-----Remaining Need Memory----------\n";
        for(i=1; i<=n; i++)
        {
                for(j=1; j<=m; j++)
                {
                        cout<<" "<<need[i][j]<<" ";
                }
                cout<<"\n";
        }
    
     
    
    int y = 0; 
    for (k = 0; k <= n; k++) { 
        for (i = 0; i <= n; i++) { 
            if (f[i] == 0) { 
  
                int flag = 0; 
                for (j = 1; j <= m; j++) { 
                    if (need[i][j] > avail[j]){ 
                        flag = 1; 
                        break; 
                    } 
                } 
  
                if (flag == 0) { 
                    ans[ind++] = i; 
                    for (y = 1; y <= m; y++) 
                        avail[y] += alloc[i][y]; 
                    
                    f[i] = 1; 
                } 
            } 
        } 
    } 
    
    	cout<<"\n----- Avail Memory after operation ----------\n";
        for(y=1;y<=m;y++)
        {
        		cout<<" "<<avail[y]<<" ";
		}
		cout<<"\n";
  
    cout << "The SAFE Sequence generated is:" << endl; 
    for (i = 0; i < n-1; i++) 
        cout << " P" << ans[i] << " ->"; 
    cout << " P" << ans[n-1] <<endl; 
  
    return 0; 
} 

