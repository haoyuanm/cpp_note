#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <unordered_set>
#include <queue>
#include <unordered_set>
#include <map>
#include <stack>
#include <string>
#include <set>
#include <numeric>

using namespace std;


void merge(vector<int>& v, int start, int mid, int end) {
    if (start > mid || mid == end) return;
    if (v[start] <= v[mid+1]) merge(v, start+1, mid, end);
    else {
        swap(v[start++], v[mid+1]);
        int j = mid+2;
        while (j <= end && v[j] < v[j-1]) {
            swap(v[start++], v[j++]);
        }
        merge(v, start, mid, end);
    }
}

void merge_sort(vector<int>& v, int start, int end) {
    if (start >= end) return;
    int mid = (start+end) / 2;
    merge_sort(v, start, mid);
    merge_sort(v, mid+1, end);
    merge(v, start, mid, end);
}

int main() {
    vector<int> v{3,2,1,6,2,6,3,8,2,4,1,9,2,5,3,9,0,1,2,3,4,6,3,8,5,2,3,9,5,6,7,3,9,0,12,5,2,3,9,8,7,6,5,6,7,6,5,4,4,7,9,3};
    
    merge_sort(v, 0, v.size()-1);
//    vector<int> v{1,2,3,6,2,3,6,8};
//    merge(v, 0, 3, 7);
    
    for (int i: v) cout <<i <<endl;
    
    return 0;
}

//required from 'static _ForwardIterator std::__uninitialized_default_n_1<_TrivialValueType>::__uninit_default_n(_ForwardIterator, _Size) [with _ForwardIterator = ExamRoom::Interval*; _Size = long unsigned int; bool _TrivialValueType = false]'
//Expected answer
//[null,0,9,4,2,null,5]
