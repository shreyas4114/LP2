#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Job {
    int jobId;
    int dead;
    int profit;
};

bool compare(Job a, Job b) {
    return (a.profit > b.profit);
}

void schedule(vector<Job> &arr) {

    int n = arr.size();
    sort(arr.begin(), arr.end(), compare);

    int maxProfit = 0;
    int maxDead = -1;
    for (int i = 0; i < n; i++)
    {
        maxDead = max(maxDead, arr[i].dead);
    }

    vector<int> slots(maxDead+1, -1);
    vector<int> result(maxDead, -1);

    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead; j >= 0; j--)
        {
            if(slots[j] == -1) {
                slots[j] = i;
                result[j-1] = arr[i].jobId;
                maxProfit += arr[i].profit;
                break;
            }
        }
        
    }

    cout << "\nJob Schedule:\n";
    for(int i=0; i<maxDead; i++) {                                              
        if (result[i] != -1)
            cout << "Time Slot: " << i+1 << "  Job ID: " << result[i] << endl;
    }
    cout << "Max Profit: " << maxProfit << endl;
}

int main()
{
    vector<Job> jobs;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enter Job Details\n";
        cout << "2. Perform Job Scheduling\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                Job j;
                cout << "Enter Job ID: ";
                cin >> j.jobId;
                cout << "Enter Deadline: ";
                cin >> j.dead;
                cout << "Enter Profit: ";
                cin >> j.profit;
                jobs.push_back(j);
                break;
            }
            case 2:
                if(jobs.empty()) {
                    cout << "No jobs available. Please enter jobs first.\n";
                } else {
                    schedule(jobs);
                }
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while(choice != 3);
    
    return 0;
}