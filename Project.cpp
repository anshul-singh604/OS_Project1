#include <iostream> 

#include<windows.h>

using namespace std; 

long display(bool prompt=false)

{

        /*

        Display Function Used for displaying the question at the starting of program

        */

        cout<<"\n\n\n";

        cout<<"\t\t ||                                                                                         ||\n";

        cout<<"\t\t=================================================================================================\n";

        cout<<"\t\t ||                                Operating System                                         ||\n";

        cout<<"\t\t ||                                               --Anshul Singh                            ||\n";

        cout<<"\t\t ||                                                                                         ||\n";

        cout<<"\t\t ||                                                                                         ||\n";
                                                                                        
        cout<<"\t\t || /*  Consider that a system has P resources of same type. These resources are            ||\n";

        cout<<"\t\t ||     shared by Q processes time to time. All processes request and  release the          ||\n";

        cout<<"\t\t ||     resources one at a time. Generate a solution to demonstrate that, the system        ||\n";

        cout<<"\t\t ||     is in safe state  when following conditions are satisfied.            */            ||\n";

        cout<<"\t\t ||                                                                                         ||\n";

        cout<<"\t\t ||                                                                                         ||\n";

 
        cout<<"\t\t=================================================================================================\n";

        cout<<"\t\t ||     /*Conditions :                                                                      ||\n";

        cout<<"\t\t ||     1. Maximum resource need of each process is between 1 and P.                        ||\n";

        cout<<"\t\t ||     2. Summation of all maximum needs is less than P+Q.                                 ||\n";

        cout<<"\t\t ||                                                                                         ||\n";

        cout<<"\t\t=================================================================================================\n";

        cout<<"\t\t ||                                                                                         ||\n";

        if(prompt==false)

        {

                cout<<"Please Wait While Program Loads . . . ";

                Sleep(5000);               

                system("CLS");

                display(true);                       //Recursion

                return 0;

        }

        cout<<"\n";

        cout<<"Program Successfully Loaded\n";

        system("pause");

        system("CLS");

        return 0;

} 

int main() 

{ 

    display();

    int n, m, i, j, k;                                   //variable Declaration

    int alloc[10][10];								     // Allocation Matrix 
 
        cout<<"Enter no. of process:" ;					 //Number of process

        cin>>n;

        cout<<"Enter no. of resources:";                 //Number of resourcess

        cin>>m;
        
        if(n>=m){
		

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

                    	    cout<<alloc[i][j]<<"\t";

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

        	                cout<<max[i][j]<<"\t";

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

        		        cout<<avail[i]<<"\t";

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

       	                 cout<<need[i][j]<<"\t";

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

        		        cout<<avail[y]<<"\t";
	
        			}

        			cout<<"\n";

  

    			cout << "The SAFE Sequence generated is:" << endl; 

    			for (i = 0; i < n-1; i++) 

      			cout << " P" << ans[i] << " ->"; 

    			cout << " P" << ans[n-1] <<endl;
			 
        }
        
		else
		
		{
		cout << "/*  Here the number of RESOURCES exceeds number of PROCESSES which voilates the 1st codition, Thus Any output cannot be generated . " << endl; 
	    cout << "    So please re-run the program and enter number of RESOURCES less than number of PROCESSES to execute the code successfully.   */" << endl; 
		} 
        system("pause");

    return 0; 

} 
