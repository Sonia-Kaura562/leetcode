class Twitter {
public:
    Twitter() {
        
    }
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> followers;
    int time = 0;
    void postTweet(int userId, int tweetId) {
        time++;
        tweets[userId].push_back({time, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> total;
        int size = tweets[userId].size();
        for(int i = 0; i < size; i++) {
            total.push_back(tweets[userId][i]);
        }
        // int foloSize = followers[userId].size();
        // vector<int>tf(followers[userId]);
        for(auto i : followers[userId]) {
            for(auto j : tweets[i]) {
                total.push_back(j);
            }
        }
        // for(int i = 0; i < foloSize; i++) {
        //     int foloo = tf[i];
        //     for(int j = 0; j < tweets[foloo].size(); j++) {
        //         total.push_back(tweets[foloo][i]);
        //     }
        // }
        vector<int>ans;
        sort(total.begin(), total.end());
        reverse(total.begin(), total.end());
        int maxi = min(10, (int)total.size());
        for(int i = 0; i < maxi; i++) {
            ans.push_back(total[i].second);
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followers.find(followerId) != followers.end()) {
            followers[followerId].erase(followeeId);
        }
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