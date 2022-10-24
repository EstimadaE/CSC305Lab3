#include<bits/stdc++.h>
using namespace std;

void bestFit(int blockSize[], int m, int processSize[], int n)
{
   
    int allocation[n];

    memset(allocation, -1, sizeof(allocation));

    for (int i=0; i<n; i++)
    {
        int bestIdx = -1;
        for (int j=0; j<m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (blockSize[bestIdx] > blockSize[j])
                    bestIdx = j;
            }
        }

        
        if (bestIdx != -1)
        {
           
            allocation[i] = bestIdx;

            
            blockSize[bestIdx] -= processSize[i];
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock no.\tWaste\n";
    for (int i = 0; i < n; i++)
    {
        cout << "   " << i+1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

void firstFit(int blockSize[], int m,
              int processSize[], int n)
{
    
    int allocation[n];
 
    
    memset(allocation, -1, sizeof(allocation));
 
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                
                allocation[i] = j;
 
                
                blockSize[j] -= processSize[i];
 
                break;
            }
        }
    }


 
    cout << "\nProcess No.\tProcess Size\tBlock no.\tWaste\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i+1 << "\t\t"
             << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}


void nextFit(int blockSize[], int m, int processSize[], int n)
{
    
    int allocation[n], j = 0;
 
    
    memset(allocation, -1, sizeof(allocation));
 
    for (int i = 0; i < n; i++) {
 
       
        while (j < m) {
 
            if (blockSize[j] >= processSize[i]) {
 
                
                allocation[i] = j;
 
                
                blockSize[j] -= processSize[i];
 
                break;
            }
 
           
            j = (j + 1) % m;
        }
    }
 
    cout << "\nProcess No.\tProcess Size\tBlock no.\tWaste\n";
    for (int i = 0; i < n; i++) {
        cout << " " << i + 1 << "\t\t" << processSize[i]
             << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}


void worstFit(int blockSize[], int m, int processSize[],
                                                 int n)
{
    
    int allocation[n];
 
    
    memset(allocation, -1, sizeof(allocation));
 
   
    for (int i=0; i<n; i++)
    {
        
        int wstIdx = -1;
        for (int j=0; j<m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (wstIdx == -1)
                    wstIdx = j;
                else if (blockSize[wstIdx] < blockSize[j])
                    wstIdx = j;
            }
        }
 
        
        if (wstIdx != -1)
        {
            
            allocation[i] = wstIdx;
 
            
            blockSize[wstIdx] -= processSize[i];
        }
    }
 
    cout << "test\nProcess No.\tProcess Size\tBlock no.\tWaste\n";
    for (int i = 0; i < n; i++)
    {
        cout << "   " << i+1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}




int main()
{
     int blockSize[] = { 5, 10, 20 };
    int processSize[] = { 10, 20, 5 };
    int m = sizeof(blockSize)/sizeof(blockSize[0]);
    int n = sizeof(processSize)/sizeof(processSize[0]);


    


    return 0 ;
}