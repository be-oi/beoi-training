int binary_search(vector<int> A, int v) {
	int low = 0;
	int high = A.size() - 1;
	while(low <= high) {
		int mid = (low + high)/2;
		if(A[mid]==v)
			return mid;
		if(A[mid] < v)
			low = mid + 1;
		if(A[mid] > v)
			high = mid - 1;
	}
	return -1; // Not found
}