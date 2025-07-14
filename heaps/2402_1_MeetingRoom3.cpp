// leetcode url - https://leetcode.com/problems/meeting-rooms-iii/?envType=daily-question&envId=2025-07-12

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> res(n, 0);
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int> > available_rooms;

        for(int i = 0;i<n;i++)
        {
            available_rooms.push(i);
        }
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>> > meeting_end;
        int i = 0;

        while(i < meetings.size())
        {
            while( !meeting_end.empty() && meetings[i][0] >= meeting_end.top().first)
            {
                available_rooms.push(meeting_end.top().second);
                meeting_end.pop();
            }

            if(available_rooms.size())
            {
                int available_room = available_rooms.top();
                res[available_room]++;
                meeting_end.push({meetings[i][1], available_room});
                available_rooms.pop();
            }
            else
            {
                int available_room = meeting_end.top().second;
                res[available_room]++;
                long long new_end_time = meetings[i][1] - meetings[i][0] + meeting_end.top().first;
                meeting_end.pop();
                meeting_end.push({new_end_time, available_room});
            }
            i++;
        }

        int max_meetings = -1, max_meetings_room = -1;

        for(int i = 0; i < n;i++)
        {
            cout<<res[i]<<" ";
            if(res[i] > max_meetings)
            {
                max_meetings = res[i];
                max_meetings_room = i;
            }
        }

        return max_meetings_room;
    }
};
