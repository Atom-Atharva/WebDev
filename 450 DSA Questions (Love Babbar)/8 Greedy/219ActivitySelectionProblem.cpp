// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

// There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
// What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

// Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Create pair vector--
        vector<pair<int, int>> meetings;
        for (int i = 0; i < n; i++)
        {
            pair<int, int> temp = {start[i], end[i]};
            meetings.push_back(temp);
        }

        // By Default sorted by first element of pair--
        sort(meetings.begin(), meetings.end());

        // Seprates Overlapped Meetings--
        int st = meetings[0].first;
        int en = meetings[0].second;
        int meeting = 1;
        for (int i = 1; i < n; i++)
        {
            if (meetings[i].first > en)
            {   
                st = meetings[i].first;
                en = meetings[i].second;

                meeting++;
            }

            if (meetings[i].second < en)
            {
                st = meetings[i].first;
                en = meetings[i].second;
            }
        }

        return meeting;
    }
};