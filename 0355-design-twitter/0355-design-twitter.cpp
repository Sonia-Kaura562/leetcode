class Twitter {
public:
        int time = 0;
        unordered_map<int, vector<pair<int, int>>>tweets;
        unordered_map<int, unordered_set<int>>following;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>>v;
        vector<int>ans;
        for(auto it : tweets[userId]) {
            v.push_back(it);
        }

        for(auto i : following[userId]) {
            for(auto j : tweets[i]) {
                v.push_back(j);
            }
        }

        sort(v.begin(), v.end(), greater<pair<int, int>>());
        for(int i = 0; i < min(10, (int)v.size()); i++) {
            ans.push_back(v[i].second);
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */