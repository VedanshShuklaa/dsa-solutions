/*
Problem: 3635. Earliest Finish Time for Land and Water Rides II
Approach: Follow Instructions
Time: O(mlogn + nlogm)
*/

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) 
    {
        long long answer = 1e18;

        {
            int waterCount = waterStartTime.size();
            vector<pair<int, int>> waterRides(waterCount);

            for (int i = 0; i < waterCount; i++) {
                waterRides[i] = {waterStartTime[i], waterDuration[i]};
            }

            sort(waterRides.begin(), waterRides.end());

            vector<int> waterStarts(waterCount);
            vector<long long> prefixMinDuration(waterCount);
            vector<long long> suffixMinFinish(waterCount);

            for (int i = 0; i < waterCount; i++) {
                waterStarts[i] = waterRides[i].first;
            }

            prefixMinDuration[0] = waterRides[0].second;
            for (int i = 1; i < waterCount; i++) {
                prefixMinDuration[i] = min(prefixMinDuration[i - 1], (long long)waterRides[i].second);
            }

            suffixMinFinish[waterCount - 1] = (long long)waterRides[waterCount - 1].first + waterRides[waterCount - 1].second;
            for (int i = waterCount - 2; i >= 0; i--) {
                suffixMinFinish[i] = min(suffixMinFinish[i + 1],
                                         (long long)waterRides[i].first + waterRides[i].second);
            }

            for (int i = 0; i < (int)landStartTime.size(); i++) {
                long long landFinish = (long long)landStartTime[i] + landDuration[i];

                int pos = upper_bound(waterStarts.begin(), waterStarts.end(), landFinish) - waterStarts.begin();

                if (pos > 0) {
                    answer = min(answer, landFinish + prefixMinDuration[pos - 1]);
                }

                if (pos < waterCount) {
                    answer = min(answer, suffixMinFinish[pos]);
                }
            }
        }

        {
            int landCount = landStartTime.size();
            vector<pair<int, int>> landRides(landCount);

            for (int i = 0; i < landCount; i++) {
                landRides[i] = {landStartTime[i], landDuration[i]};
            }

            sort(landRides.begin(), landRides.end());

            vector<int> landStarts(landCount);
            vector<long long> prefixMinDuration(landCount);
            vector<long long> suffixMinFinish(landCount);

            for (int i = 0; i < landCount; i++) {
                landStarts[i] = landRides[i].first;
            }

            prefixMinDuration[0] = landRides[0].second;
            for (int i = 1; i < landCount; i++) {
                prefixMinDuration[i] = min(prefixMinDuration[i - 1], (long long)landRides[i].second);
            }

            suffixMinFinish[landCount - 1] = (long long)landRides[landCount - 1].first + landRides[landCount - 1].second;
            for (int i = landCount - 2; i >= 0; i--) {
                suffixMinFinish[i] = min(suffixMinFinish[i + 1],
                                         (long long)landRides[i].first + landRides[i].second);
            }

            for (int i = 0; i < (int)waterStartTime.size(); i++) {
                long long waterFinish = (long long)waterStartTime[i] + waterDuration[i];

                int pos = upper_bound(landStarts.begin(), landStarts.end(), waterFinish) - landStarts.begin();

                if (pos > 0) {
                    answer = min(answer, waterFinish + prefixMinDuration[pos - 1]);
                }

                if (pos < landCount) {
                    answer = min(answer, suffixMinFinish[pos]);
                }
            }
        }

        return (int)answer;
    }
};