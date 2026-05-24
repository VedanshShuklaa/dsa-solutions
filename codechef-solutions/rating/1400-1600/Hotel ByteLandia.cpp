/*
Problem: Hotel ByteLandia
Approach: Hashmap
Time: O(N + D) where N is number of days, and D is departure time
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, N;

	cin >> t;

	while(t--)
	{
		cin >> N;

		unordered_map<int, int> arrival;
		unordered_map<int, int> departure;

		int finalDeparture = 0;

		for(int i = 0; i < N; i++) {
			int val;
			cin >> val;
			arrival[val]++;
		}

		for(int i = 0; i < N; i++) {
			int val;
			cin >> val;
			departure[val]++;

			if(val > finalDeparture) finalDeparture = val;
		}

		int maxGuests = 0;
		int guests = 0;

		for(int i = 0; i <= finalDeparture; i++)
		{
			if(departure.count(i))
			{
				guests -= departure[i];
				departure[i] = 0;
			}

			if(arrival.count(i))
			{
				guests += arrival[i];
				arrival[i] = 0; 

				if(guests > maxGuests) maxGuests = guests;
			}
		}

		cout << maxGuests << "\n";
	}
}
