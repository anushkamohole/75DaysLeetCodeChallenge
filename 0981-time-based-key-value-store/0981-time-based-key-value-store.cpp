class TimeMap {
public:

    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {

        if (mp.find(key) == mp.end())
            return "";

        vector<pair<int, string>>& v = mp[key];

        int left = 0;
        int right = v.size() - 1;

        int ans = -1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (v[mid].first <= timestamp) {

                // Valid timestamp
                ans = mid;

                // Try to find a larger valid timestamp
                left = mid + 1;
            }
            else {

                // Timestamp is too large
                right = mid - 1;
            }
        }

        if (ans == -1)
            return "";

        return v[ans].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */