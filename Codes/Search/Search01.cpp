#include<iostream>
using namespace std;
int BinarySearch(int arr[], int n, int x)
{
	int left = 0;
	int right = n - 1;
	int count = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] >= x)
		{
			count += right - mid + 1;
			right = mid - 1;
		}
		else left = mid + 1;
	}
	return count;
}
int main()
{
	int t, n;
	cin >> n >> t;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int giatricantim;
	int* test = new int[t];
	for (int i = 0; i < t; i++)
	{
		cin >> test[i];
	}
	for (int i = 0; i < t; i++)
	{
		cout << BinarySearch(arr, n, test[i]) << endl;
	}
	return 0;
}