#include <iostream>

using namespace std;

void heapify(vector<int>& v, int index) {
    int left = index*2, right = index*2+1, len = v.size();
    if (left < len && v[left] < v[index]) {
        if (right < len) {
            if (v[left] <= v[right]) {
                swap(v[index], v[left]);
                heapify(v, left);
            }
        } else {
            swap(v[index], v[left]);
            heapify(v, left);
        }
    } else if (right < len && v[right] < v[index]) {
        swap(v[index], v[right]);
        heapify(v, right);
    }
}

void make_heap(vector<int>& v) {
    for (int i = v.size()/2; i >= 0; i--) heapify(v, i);
}

int pop(vector<int>& v) {
    int res = v[0];
    swap(v[0], v[v.size()-1]);
    v.pop_back();
    heapify(v, 0);
    return res;
}

int main() {
    vector<int> v{3,2,1,6,2,6,3,8};
    
    vector<int> res;
    make_heap(v);
    while (v.size()) {
        res.push_back(pop(v));
    }
    for (int i: res) cout <<i <<endl;
    
    return 0;
}
