// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

// Given a set of N jobs where each jobi has a deadline and profit associated with it.

// Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with job if and only if the job is completed by its deadline.

// Find the number of jobs done and the maximum profit.

// Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.

// Example 1:

// Input:
// N = 4
// Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
// Output:
// 2 60
// Explanation:
// Job1 and Job3 can be done with
// maximum profit of 60 (20+40).

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

class Solution
{
    // For Sorting by particular property--
    static bool comparator(Job x1, Job x2)
    {
        // For Desc Order--
        return x1.profit > x2.profit;
    }

public:
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        // All Available Time Slots--
        vector<int> time(n, 0);

        // Sort Job Array in desc order of profits--
        sort(arr, arr + n, comparator);

        int jobs = 0;
        int profits = 0;
        for (int i = 0; i < n; i++)
        {
            // Check if the job can be schedulable--
            for (int j = min(arr[i].dead - 1, n - 1); j >= 0; j--)
            {
                if (time[j] == 0)
                {
                    // Assign Job and Calculate Profits--
                    time[j] = 1;
                    jobs++;
                    profits = profits + arr[i].profit;
                    break;
                }
            }
        }

        return {jobs, profits};
    }
};
