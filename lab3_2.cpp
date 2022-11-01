#include <iostream>
#include <numeric>
#include <vector>
#include <string>
//n is process size.
using namespace std;

struct Processes {
	int id;
	string status;
    int Size;
	int partitionID;
};

struct Partition {
	int id;
	bool inUsed;
    int Size;
	int processID;
};



void firstFit(vector<Processes> process, int n,vector<Partition> partition, int m) 
{
	vector<int> waste(n);
	
	for (int i = 0; i < n; i++) {
		process[i].status = "wait";
		for (int j = 0; j < m; j++) {
			if (partition[j].Size >= process[i].Size && partition[j].inUsed != true) {
				process[i].partitionID = partition[j].id;
				process[i].status = "run";
				partition[j].inUsed = true;
				partition[j].processID = process[i].id;
				waste[i] = partition[j].Size - process[i].Size;
				partition[j].Size -= process[i].Size;
				break;
			}
		}
	}

	cout << "===============================First Fit Algorithm============================" << endl;
	cout << "Job ID\t\tPartition ID\t\tWaste\t\t\tStatus" << endl;
	for (int i = 0; i < n; i++) {
		cout << process[i].id << "\t\t" << process[i].partitionID << "\t\t\t";

		if (i >= waste.size()) {
			cout << "0" << "\t\t\t" << process[i].status << endl;;
		}
		else {
			cout << waste.at(i) << "\t\t\t" << process[i].status << endl;
		}
	}
	cout << "Total Waste: " << accumulate(waste.begin(), waste.end(), 0) << endl;
	cout  << endl;
}

void nextFit(vector<Processes> process, int n,vector<Partition> partition, int m)  {
	vector<int> waste(n);
	int j = 0;

	for (int i = 0; i < n; i++) {
		int count = 0;
		process[i].status = "wait";
		while (count < m) {
			if (partition[j].Size >= process[i].Size && partition[j].inUsed != true) {
				process[i].partitionID = partition[j].id;
				process[i].status = "run";
				partition[j].inUsed = true;
				partition[j].processID = process[i].id;
				waste[i] = partition[j].Size - process[i].Size;
				partition[j].Size -= process[i].Size;
				break;
			}
			j = (j + 1) % m;
			count += 1;
		}
	}

	cout << "=============================Next Fit Algorithm================================" << endl;
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
	cout <<  endl;
}

void bestFit(vector<Processes> process, int n,vector<Partition> partition, int m) 
{
	vector<int> waste(n);

	for (int i = 0; i < n; i++) {
		int bestIndex = -1;
		process[i].status = "wait";
		for (int j = 0; j < m; j++) {
			if (partition[j].Size >= process[i].Size && partition[j].inUsed != true) {
				if (bestIndex == -1) {
					bestIndex = j;
				}
				else if (partition[bestIndex].Size > partition[j].Size) {
					bestIndex = j;
				} 
			}
		}
		
		if (bestIndex != -1) {
			process[i].partitionID = bestIndex + 1;
			process[i].status = "run";
			partition[bestIndex].inUsed = true;
			partition[bestIndex].processID = process[i].id;
			waste[i] = partition[bestIndex].Size - process[i].Size;
			partition[bestIndex].Size -= process[i].Size;
		}
	}

	cout << "==============================Best Fit Algorithm=============================" << endl;
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
	cout  << endl;
}

void worstFitFixed(vector<Processes> process, int n,vector<Partition> partition, int m) {
	vector<int> waste(n);

	for (int i = 0; i < n; i++) {
		int worstIndex = -1;
		process[i].status = "wait";
		for (int j = 0; j < m; j++) {
			if (partition[j].Size >= process[i].Size && partition[j].inUsed != true) {
				if (worstIndex == -1) {
					worstIndex = j;
				}
				else if (partition[worstIndex].Size < partition[j].Size) {
					worstIndex = j;
				}
			}
		}

		if (worstIndex != -1) {
			process[i].partitionID = worstIndex + 1;
			process[i].status = "run";
			partition[worstIndex].inUsed = true;
			partition[worstIndex].processID = process[i].id;
			waste[i] = partition[worstIndex].Size - process[i].Size;
			partition[worstIndex].Size -= process[i].Size;
		}
	}

	cout << "=========================Worst Fit Algorithm Fixed============================" << endl;
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
	cout << "Total Waste: " << accumulate(waste.begin(), waste.end(), 0) << endl <<endl;
	
}

void worstFitDynamic(vector<Processes> process, int n,vector<Partition> partition, int m) {
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
	
}


int main() {
	
	int proVeclen, mpartVeclen, proIn, mpartIn;

    cout << "Enter amount of processes: " << endl;

    cin >> proVeclen;

    vector<Processes> process; // size of array
	Processes pTemp; 


    cout << "Enter " << proVeclen << " processess memory: " << endl; 

    for (int i = 0; i < proVeclen;i++)
    {
        cin >> proIn;
		pTemp.Size = proIn;
		pTemp.id = i+1;
		process.push_back(pTemp); 
    }
    

    cout << "Enter amount of Memory Partitions" <<endl;

    cin >> mpartVeclen;

    vector<Partition> mem;
	Partition mTemp; 

    
    cout << "Enter " << mpartVeclen << " Memory Partition size: " << endl;

    for (int i = 0; i < mpartVeclen; i++)
    {
        cin >> mpartIn;
        mTemp.Size = mpartIn;
		mTemp.id = i+1;
		mem.push_back(mTemp);        
    } 

    firstFit(process,proVeclen,mem,mpartVeclen);
    nextFit(process,proVeclen,mem,mpartVeclen);
    bestFit(process,proVeclen,mem,mpartVeclen);
    worstFitFixed(process,proVeclen,mem,mpartVeclen);
    worstFitDynamic(process,proVeclen,mem,mpartVeclen);
	return 0;
}