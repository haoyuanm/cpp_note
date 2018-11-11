void quicksort(vector<int>& v, int start, int end) {
    if (start >= end) return;
    int i = start+1, j = end;
    while (i <= j) {
        if (v[j] < v[start]) {
            swap(v[i++], v[j]);
        } else j--;
    }
    swap(v[start], v[j]);
    quicksort(v, start, j-1);
    quicksort(v, j+1, end);
}