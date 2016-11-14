struct Votes {
    string candidates;
    int timestamp;
    Votes(string name, int time) : candidates(name), timestamp(time) {}
};

class Solution {
public:
    string topVote(vector<Votes*> votes, int givenTime) {
        unordered_map<string, int> mm;
        int maxCount = 0;
        string person;

        for(auto v : votes) {
            if(v->timestamp < givenTime) {
                mm[v->candidates]++;
            }
        }

        for(auto it : mm) {
            if(it.second > maxCount) {
                maxCount = it.second;
                person = it.first;
            }
        }
        return person;
    }

    vector<string> topVotes(vector<Votes*> votes, int givenTime) {
        unordered_map<string, int> mm;
        vector<string> res;
        int maxCount = 0;

        for(auto v : votes) {
            if(v->timestamp < givenTime) {
                mm[v->candidates]++;
                maxCount = max(maxCount, mm[v->candidates]);
            }
        }

        for(auto it : mm) {
            if(it.second == maxCount) {
                res.push_back(it.first);
            }
        }
        return res;
    }

    static bool compare(pair<string, int>& p1, pair<string, int>& p2) {
        return (p1.second > p2.second) || (p1.second == p2.second && p1.first < p2.first);
    }

    vector<string> topKVotes(vector<Votes*> votes, int givenTime, int K) {
        unordered_map<string, int> mm;
        vector<string> res;

        for(auto v : votes) {
            if(v->timestamp < givenTime) {
                mm[v->candidates]++;
            }
        }
        vector<pair<string, int>> vv(mm.begin(), mm.end());
        sort(vv.begin(), vv.end(), compare);

        for(int i = 0; i < min((int)vv.size(), K); i++) {
            res.push_back(vv[i].first);
        }
        return res;
    }

    int timeRange(vector<string> candidates, vector<Votes*> votes, int now) {
        int size = (int)candidates.size();

        for(int i = 1; i <= now; i++) {
            vector<string> temp = topKVotes(votes, i, size);
            if(isEqual(candidates, temp)) return i;
        }
        return -1;
    }

    bool isEqual(vector<string> v1, vector<string> v2) {
        int size = (int)v1.size();
        int size2 = (int)v2.size();
        if(size != size2) return false;
        for(int i = 0; i < size; i++) {
            if(v1[i] != v2[i]) return false;
        }
        return true;
    }
};


int main() {
    Votes* v1 = new Votes("p1",1);
    Votes* v2 = new Votes("p1",2);
    Votes* v3 = new Votes("p1",3);
    Votes* v4 = new Votes("p1",4);
    Votes* v5 = new Votes("p2",5);
    Votes* v6 = new Votes("p2",6);
    Votes* v7 = new Votes("p2",7);
    Votes* v8 = new Votes("p3",8);
    Votes* v9 = new Votes("p4",9);
    Votes* v10 = new Votes("p4",10);

    vector<Votes*> votes;
    votes.push_back(v1);
    votes.push_back(v2);
    votes.push_back(v3);
    votes.push_back(v4);
    votes.push_back(v5);
    votes.push_back(v6);
    votes.push_back(v7);
    votes.push_back(v8);
    votes.push_back(v9);
    votes.push_back(v10);

    Solution sol;
//    cout << sol.topVote(votes, 5) << endl;
//    sol.topVotes(votes, 11);
//    sol.topKVotes(votes, 4, 2);
    vector<string> candidates = {"p1", "p2"};
    cout << sol.timeRange(candidates, votes, 11) << endl;
}
