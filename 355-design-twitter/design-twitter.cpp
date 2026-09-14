class Twitter {
public:
    int timer = 0;

    // user -> list of {time, tweetId}
    unordered_map<int, vector<pair<int,int>>> tweets;

    // user -> followed users
    unordered_map<int, unordered_set<int>> followList;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        
        priority_queue<pair<int,int>> pq;
        
        // Add user's own tweets
        for(auto &tweet : tweets[userId]) {
            pq.push(tweet);
        }
        
        // Add followed users' tweets
        for(int followee : followList[userId]) {
            for(auto &tweet : tweets[followee]) {
                pq.push(tweet);
            }
        }
        
        vector<int> ans;
        
        while(!pq.empty() && ans.size() < 10) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId)
            return;
        
        followList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followList[followerId].erase(followeeId);
    }
};
 