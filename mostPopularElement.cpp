// 给一个sorted array，找most popular element。只要数量超过N/4就算most popular，N是array的size
vector<int> mostPopularElement(vector<int> nums) {
    int size = (int)nums.size();
    int popularFactor = size / 4;
    vector<int> res;
    int sameCount = 1;

    for(int i = 0; i < size - 1; i++) {
        if(nums[i] == nums[i+1]) {
            sameCount++;
        } else {
            if(sameCount >= popularFactor) {
                res.push_back(nums[i]);
            }
            sameCount = 1;
        }
    }
    if(sameCount >= popularFactor) res.push_back(nums.back());
    return res;
}


int main() {
    vector<int> nums = {1,2,3,4};
    mostPopularElement(nums);
}


// what if unsorted? what if to find elements appear more than n/k times
/*
using extra k-1 space to store elements and their counts. Because there can never be more than k-1 elements in output. Traverse through the
input array and update candidates array at every step.
*/
struct elementCount {
    int element;
    int count;
};

vector<int> mostPopularElement(vector<int> nums, int k) {
    int size = nums.size();
    if(k < 2) return nums;
    vector<int> res;
    vector<elementCount> temp(k-1);

    for(int i = 0; i < k-1; i++) {
        temp[i].count = 0;
    }

    for(int i = 0; i < size; i++) {
        int j;
        // nums[i] already exist
        for(j = 0; j < k-1; j++) {
            if(temp[j].element == nums[i]) {
                temp[j].count++;
                break;
            }
        }
        // nums[i] not exist in temp
        if(j == k-1) {
            int pos;
            for(pos = 0; pos < k-1; pos++) {
                if(temp[pos].count == 0) {
                    temp[pos].element = nums[i];
                    temp[pos].count = 1;
                    break;
                }
            }
            if(pos == k-1) {
                for(pos = 0; pos < k; pos++) {
                    temp[pos].count--;
                }
            }
        }
    }

    for(int i = 0; i < k-1; i++) {
        int count = 0;
        for(int j = 0; j < size; j++) {
            if(nums[j] == temp[i].element) count++;
        }
        if(count > size/k) {
            res.push_back(temp[i].element);
        }
    }
    return res;
}

int main() {
    vector<int> nums = {1,1,1,2,2,3,3,4};
    mostPopularElement(nums, 4);
}
