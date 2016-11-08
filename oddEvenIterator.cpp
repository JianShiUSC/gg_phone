class oddEvenIterator {
private:
    vector<int> num;
    int count;
    int cursor;
    int preVal;
public:
    oddEvenIterator(vector<int>& v1) {
        num = v1;
        count = 0;
        cursor = -1;
    }

    int next() {
        if(cursor == num.size() - 1 && count == 0) return -1;
        if(count == 0) {
            count = num[++cursor];
            preVal = num[++cursor];
        }
        count--;
        return preVal;
    }
};


int main() {
    vector<int> num = {3,8,1,9,2,12};
    oddEvenIterator sol(num);
    cout << sol.next() << endl;
    cout << sol.next() << endl;
    cout << sol.next() << endl;
    cout << sol.next() << endl;
    cout << sol.next() << endl;
    cout << sol.next() << endl;
    cout << sol.next() << endl;
    cout << sol.next() << endl;
    cout << sol.next() << endl;
    cout << sol.next() << endl;
    cout << sol.next() << endl;
    cout << sol.next() << endl;
    cout << sol.next() << endl;
    cout << sol.next() << endl;
    cout << sol.next() << endl;
    cout << sol.next() << endl;
}
