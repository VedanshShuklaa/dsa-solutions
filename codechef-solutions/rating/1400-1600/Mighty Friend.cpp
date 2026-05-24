#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while(t--)
	{
		int N, K;
		cin >> N;
		cin >> K;

		vector<int> A;

		for(int i = 0; i < N; i++)
		{
			int val;
			cin >> val;
			A.push_back(val);
		}

		for(int i = 0; i < K; i++)
		{
			int motuMax = -1;
			int tomuMin = 9999999;

			int motuMaxIdx = -1;
			int tomuMinIdx = -1;

			for(int j = 0; j < N; j++)
			{
				if(j%2 == 0 && A[j] > motuMax)
				{
					motuMax = A[j];
					motuMaxIdx = j;
				} 

				if(j%2 != 0 && A[j] < tomuMin)
				{
					tomuMin = A[j];
					tomuMinIdx = j;
				}
			}

			int temp = A[motuMaxIdx];
			A[tomuMinIdx] = A[motuMaxIdx];
			A[motuMaxIdx] = temp;
		}

		int sumMotu = 0;
		int sumTomu = 0;

		for(int i = 0; i < N; i++)
		{
			if(i%2 == 0) sumMotu += A[i];
			else sumTomu += A[i];
		}

		if(sumTomu > sumMotu) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
}
