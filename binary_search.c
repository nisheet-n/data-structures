
#include <iostream>
#include <time.h>
using namespace std;


int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		if (arr[mid] == x)
			return mid;
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

	
		return binarySearch(arr, mid + 1, r, x);
	}

	
	return -1;
}

int main()
{
    clock_t start, end;
    double cpu_time_used;
	int n,x;
	cout<<"enter size of the array\n";
	cin>>n;
	int arr[n];
	cout<<"enter elements\n";
	for(int i=0;i<n;i++)
	cin>>arr[i];
	cout<<"enter element to be searched\n";
	cin>>x;
	start=clock();
	int result = binarySearch(arr, 0, n - 1, x);
	end=clock();
	cpu_time_used = ((double)(end - start) / CLOCKS_PER_SEC);
	(result == -1) ? cout << "Element is not present in array"
				: cout << "Element is present at index " << result<<endl;
				cout<<"time taken ="<<cpu_time_used<<endl;
	return 0;
}





