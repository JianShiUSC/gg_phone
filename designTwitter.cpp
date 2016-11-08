class Twitter {
private:
    int count;
    unordered_map<int, unordered_set<int>> user;
    unordered_map<int, unordered_map<int, int>> tweets;
public:
    /** Initialize your data structure here. */
    Twitter() {
        count = 0;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        follow(userId, userId);
        tweets[userId].insert({count++, tweetId});
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

        for(auto it = user[userId].begin(); it != user[userId].end(); it++) {
            for(auto mm = tweets[*it].begin(); mm != tweets[*it].end(); mm++) {
                if(pq.size() < 10) {
                    pq.push({mm->first, mm->second});
                } else if(pq.top().first < mm->first) {
                    pq.push({mm->first, mm->second});
                    pq.pop();
                }
            }
        }
        res.resize(pq.size());
        for(int i = pq.size() - 1; i >= 0; i--) {
            res[i] = pq.top().second;
            pq.pop();
        }
        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        user[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId && user[followerId].find(followeeId) != user[followerId].end()) {
            user[followerId].erase(followeeId);
        }
    }

    struct cmp {
        bool operator()(pair<int, int>&a, pair<int, int>& b) {
            return a.first > b.first;
        }
    };
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
