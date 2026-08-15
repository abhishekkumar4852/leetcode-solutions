class LFUCache {
public:
    int capacity;
    int minFreq;

    // key -> {value, frequency}
    unordered_map<int, pair<int, int>> keyToValFreq;

    // frequency -> list of keys
    // front = most recently used
    // back = least recently used
    unordered_map<int, list<int>> freqToList;

    // key -> iterator in its frequency list
    unordered_map<int, list<int>::iterator> keyToIterator;

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    void updateFreq(int key) {
        int freq = keyToValFreq[key].second;

        // Remove key from old frequency list
        freqToList[freq].erase(keyToIterator[key]);

        // If this was the last key with minFreq
        if (freqToList[freq].empty()) {
            freqToList.erase(freq);

            if (minFreq == freq) {
                minFreq++;
            }
        }

        // Increase frequency
        keyToValFreq[key].second++;

        int newFreq = freq + 1;

        // Add key to front of new frequency list
        freqToList[newFreq].push_front(key);
        keyToIterator[key] = freqToList[newFreq].begin();
    }

    int get(int key) {
        if (keyToValFreq.find(key) == keyToValFreq.end()) {
            return -1;
        }

        int value = keyToValFreq[key].first;

        updateFreq(key);

        return value;
    }

    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }

        // Key already exists
        if (keyToValFreq.find(key) != keyToValFreq.end()) {
            keyToValFreq[key].first = value;

            updateFreq(key);

            return;
        }

        // Cache is full
        if (keyToValFreq.size() == capacity) {
            // Remove least recently used key
            // among keys having minimum frequency
            int keyToRemove = freqToList[minFreq].back();

            freqToList[minFreq].pop_back();

            if (freqToList[minFreq].empty()) {
                freqToList.erase(minFreq);
            }

            keyToIterator.erase(keyToRemove);
            keyToValFreq.erase(keyToRemove);
        }

        // Insert new key with frequency = 1
        keyToValFreq[key] = {value, 1};

        freqToList[1].push_front(key);
        keyToIterator[key] = freqToList[1].begin();

        minFreq = 1;
    }
};