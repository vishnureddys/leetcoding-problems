class LRUCache {
private:
    list<pair<int, int>> items;
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    int capacity;
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;
        items.splice(items.begin(), items, cache[key]);
        return cache[key]->second;        
    }
    
    void put(int key, int value) {
        if (cache.find(key) == cache.end()) {
            if (items.size() == capacity) {
                cache.erase(items.back().first);
                items.pop_back();
            }
            items.push_front(make_pair(key, value));
            cache[key] = items.begin();
        } else {
            cache[key]->second = value;
            items.splice(items.begin(), items, cache[key]);
        }        
    }
};

