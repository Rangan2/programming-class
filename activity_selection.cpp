#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> maxMeeting (vector<vector<int>> meetings) {
    /*for (int i = 0; i < meetings.size(); i++) {
        sort(meetings[i.second].begin(), meetings[i.second].end()); // not working
    }*/

    sort(meetings.begin(), meetings.end(), [](const auto &a, const auto &b) { // custom comparator used
        return a[1] < b[1];
    });

    vector<vector<int>> schdeuledMeetings;

    int prevSecond = -1;
    for (int i = 0; i < meetings.size(); i++) {

        
        int currentFirst = meetings[i][0];
        int currentSecond = meetings[i][1];
        if (i == 0) {
            schdeuledMeetings.push_back(meetings[i]);
            
        } else if (i > 0 && currentFirst >= prevSecond) {
            schdeuledMeetings.push_back(meetings[i]);
            
        }
        prevSecond = meetings[i][1];
        
        
    }

    return schdeuledMeetings;
}


int main() {
    vector<vector<int>> meetings = {{1, 3}, {2, 4}, {4, 5}, {4, 6}, {6, 8}};

    vector<vector<int>> scheduled_meetings = maxMeeting(meetings);
    cout << "scheduled meetings are : ";
    for (auto& i : scheduled_meetings) {
        cout << "{" << i[0] << "," << " " << i[1] << "}"<< "," << " ";
    }
    return 0;
}


/*
sort the meetings in the basis of which ends earliest

*/