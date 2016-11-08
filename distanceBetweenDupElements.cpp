// Given a float array, 如果有两个duplicated element的index之差小于等于给定的X就返回TRUE
bool distanceBetweenDupElement(vector<float> arr, int X) {
    unordered_map<float, int> mm;
    for(int i = 0; i < arr.size(); i++) {
        if(mm.find(arr[i]) == mm.end()) {
            mm[arr[i]] = i;
        } else {
            if(i - mm[arr[i]] <= X) return true;
            else mm[arr[i]] = i;
        }
    }
    return false;
}

int main() {
    vector<float> arr = {1.0, 2.0, 2.0, 5.0};
    cout << distanceBetweenDupElement(arr, 1) << endl;
}
