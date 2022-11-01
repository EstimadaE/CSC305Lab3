#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <numeric>

using namespace std;

struct pro/*cess/job*/{ 
    int id; // id through 0 to n 
    string status =""; // set to running 
    int psize;// 
    int memTag;

};

struct mpart/*memory partitions*/{
    int id;
    bool use;    
    int msize;
    int proTag;


};

void firstFit(pro pro[], mpart mpart , int plen, int mlen)
{


    
    int mpartWaste, proWaste;
    bool t;
    vector<int> waste(plen);
    for (int i = 0; i < plen; i++)
    {
        pro[i].status = "wait";
        for (int j = 0; i < mlen; j++)
        {
             if (pro[i].psize <= mpart[j].msize && mpart[j].use == false)
             {
                pro[i].memTag = mpart[j].id;
                pro[i].status = "run";
                mpart[j].use = true;
                mpart[j].proTag = pro[i].id;
                waste[i] = mpart[j].msize - pro[i].psize;
                mpart[j].msize -= pro[i].psize;
                break;              
             }
        }
    }

    cout << "First Fit" << endl;
    cout << endl;
    cout << "Job ID\t\tPartition ID\t\tWaste\t\t\tStatus" << endl;

    for (int i = 0; i < plen; i++)
    {
        cout << pro[i].id << "\t\t" << pro[i].memTag << "\t\t\t";

        if (i >= waste.size())
        {
            cout << "0" << "\t\t\t" << pro[i].status << endl;
        }

        else 
        {
            cout << waste.at(i) << "\t\t\t" << pro[i].status << endl;

        }
    }

    cout << "Total Waste: " << accumulate(waste.begin(), waste.end(), 0) << endl;
	cout << "=================================================================================" << endl;

}

void nextFit(pro* , mpart*, int plen, int mlen )
{
    cout <<endl;
}

void bestFit(pro* , mpart*,int plen,int mlen )
{
        cout <<endl;

}

void worstFit(pro* , mpart*,int plen,int mlen )
{
        cout <<endl;

}


int main()
{

    
    int proVeclen, mpartVeclen, proIn, mpartIn;

    cout << "Enter amount of processes: " << endl;

    cin >> proVeclen;

    pro process[proVeclen]; // size of array

    cout << "Enter " << proVeclen << " processess memory: " << endl; 

    for (int i = 0; i < proVeclen;i++)
    {
        cin >> proIn;
        process[i].psize = proIn;
        process[i].id = i;
    }
    

    cout << "Enter amount of Memory Partitions" <<endl;

    cin >> mpartVeclen;

    mpart mem[mpartVeclen]; 

    
    cout << "Enter " << mpartVeclen << " Memory Partition size: " << endl;

    for (int i = 0; i < mpartVeclen; i++)
    {
        cin >> mpartIn;
        mem[i].msize = mpartIn;
        mem[i].id = i;        
    } 

    firstFit(process,mem,proVeclen,mpartVeclen);
    
    return 0;
}



void worstFitDynamic(Processes process[], int n,Partition partition[], int m) {
	//Create vector to store waste from partitions
	vector<int> waste(n);

	for (int i = 0; i < n; i++) {
		int worstIndex = -1;
		process[i].status = "wait";
		for (int j = 0; j < m; j++) {
			if (partition[j].Size >= process[i].Size && !partition[j].inUsed) {
				if (worstIndex == -1) {
					worstIndex = j;
				}
				else if (partition[worstIndex].Size < partition[j].Size) {
					worstIndex = j;
				}
			}
		}

		vector<int> partitionSize; // temp vector

		for (int i =0; i<m; i++)
		{
			partitionSize.push_back(partition[i].Size);
		}


		if (worstIndex != -1) {
			process[i].partitionID = worstIndex + 1;
			process[i].status = "run";
			partition[worstIndex].inUsed = true;
			partition[worstIndex].processID = process[i].id;
			waste[i] = partition[worstIndex].Size - process[i].Size;
			partition[worstIndex].Size -= process[i].Size;
			
			if (waste[i] > 0) {
				partitionSize.insert(partitionSize.begin() + worstIndex + 1, waste[i]);
				partition.resize(partition.size() + 1);
				partition[worstIndex + 1].id = worstIndex + 1.1;
				partition[worstIndex + 1].inUsed = false;

				for (int i : partitionSize)
					cout << i << ' ';

				cout << endl;
			}
		}
	}

	cout << "==========================Worst Fit Algorithm Dynamic============================" << endl;
	cout << "Job ID\t\tPartition ID\t\tWaste\t\t\tStatus" << endl;
	for (int i = 0; i < n; i++) {
		cout << process[i].id << "\t\t" << process[i].partitionID << "\t\t\t";

		if (i < waste.size()) {
			cout << waste.at(i) << "\t\t\t" << process[i].status << endl;
		}
		else {
			cout << "0" << "\t\t\t" << process[i].status << endl;;
		}
	}
	cout << "Total Waste: " << accumulate(waste.begin(), waste.end(), 0) << endl;
	cout << "=================================================================================" << endl;
}

