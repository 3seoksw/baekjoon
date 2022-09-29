#include <iostream>
#include <algorithm>
using namespace std;

int n;
int heights[100000];

int histogram(int start, int end)
{
	if (start == end) {
		return heights[start];
	}
	
	int mid = (start + end) / 2;
	int result = max(histogram(start, mid), histogram(mid + 1, end));

	int l = mid;
	int r = mid;
	int temp = heights[mid];

	while (l > start || r < end) {
		int moveL = l > start ? heights[l - 1]: -1;
		int moveR = r < end ? heights[r + 1]: -1;

		if (moveL > moveR) {
			temp = min(temp, moveL);
			l--;
		}
		else {
			temp = min(temp, moveR);
			r++;
		}
		result = max(result, temp * (r - l + 1));
	}
	return result;
}

int main(void)
{
	do {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> heights[i];
		}
		cout << histogram(0, n - 1) << endl;
	} while (n != 0); 

	return 0;
}
