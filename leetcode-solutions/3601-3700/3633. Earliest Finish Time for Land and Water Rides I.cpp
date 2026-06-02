/*
Problem: Earliest Finish Time for Land and Water Rides I
Approach: Brute Force
Time: O(m * n) where m is number of land activity, n is number of water activity
*/

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int minTime = 1e9;

        for(int i = 0; i < landStartTime.size(); i++)	// Assuming we do land activity first
        {
        	int endTime = landStartTime[i] + landDuration[i];	// Time when current land activity ends
        	for(int j = 0; j < waterStartTime.size(); j++)
        	{
        		if(waterStartTime[j] <= endTime)
        		{
        			int totalTimeTaken = endTime + waterDuration[j];
        			if(totalTimeTaken < minTime) minTime = totalTimeTaken;
        		} else
        		{
        			int totalTimeTaken = endTime + (waterStartTime[j] - endTime) + waterDuration[j];
        			if(totalTimeTaken < minTime) minTime = totalTimeTaken;
        		}
        	}
        }

        for(int i = 0; i < waterStartTime.size(); i++)	// Assuming we do water activity first
        {
        	int endTime = waterStartTime[i] + waterDuration[i];	// Time when current water activity ends
        	for(int j = 0; j < landStartTime.size(); j++)
        	{
        		if(landStartTime[j] <= endTime)
        		{
        			int totalTimeTaken = endTime + landDuration[j];
        			if(totalTimeTaken < minTime) minTime = totalTimeTaken;
        		} else
        		{
        			int totalTimeTaken = endTime + (landStartTime[j] - endTime) + landDuration[j];
        			if(totalTimeTaken < minTime) minTime = totalTimeTaken;
        		}
        	}
        }

        return minTime;
    }
};