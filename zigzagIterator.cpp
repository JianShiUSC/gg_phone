class ZigzagIterator {
private:
    vector<int> num1;
    vector<int> num2;
    int size1;
    int size2;
    int count;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        size1 = v1.size();
        size2 = v2.size();
        count = 0;
        num1 = v1;
        num2 = v2;
    }

    int next() {
        int minSize = min(size1, size2);
        ++count;
        if(count <= minSize * 2) {
            if(count%2 == 1) {
                return num1[(count - 1)/2];
            } else {
                return num2[count / 2 - 1];
            }
        } else {
            if(size1 > size2) {
                return num1[count - size2 - 1];
            } else {
                return num2[count - size1 - 1];
            }
        }
    }

    bool hasNext() {
        if(count < size1 + size2) {
            return true;
        } else {
            return false;
        }
    }
};

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        i1 = v1.begin(), i2 = v2.begin(), e1 = v1.end(), e2 = v2.end();
        flag = false;
    }

    int next() {
        flag = !flag;
        if (flag) {
            if (i1 != e1) return  *i1++;
            else return *i2++;
        } else {
            if (i2 != e2) return *i2++;
            else return *i1++;
        }
    }

    bool hasNext() {
        return i1 != e1 || i2 != e2;
    }

private:
    vector<int>::iterator i1, i2, e1, e2;
    bool flag;
};

// vk version
class ZigzagIterator {
    vector<vector<int>::iterator> iters;
    vector<vector<int>::iterator> ends;
    int k;
    int flag;

public:
    ZigzagIterator(vector<vector<int>>& vk) {
        k = (int) vk.size();
        iters.resize(k);
        ends.resize(k);
        for (int i = 0; i < k; i++) {
            iters[i] = vk[i].begin();
            ends[i] = vk[i].end();
        }
        flag = 0;
    }

    int next() {
        int index;
        while (true){
            if (iters[flag] != ends[flag]) {
                index = flag;
                break;
            }
            flag++;
            flag = flag % k;
        }
        flag++;
        flag = flag % k;
        return *iters[index]++;
    }

    bool hasNext() {
        for (int i = 0; i < k; i++) {
            if (iters[i] != ends[i])
                return true;
        }
        return false;
    }
};
