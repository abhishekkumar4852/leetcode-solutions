class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0 ){
            return false;
        }

        sort(hand.begin() , hand.end());

        map<int,int> freq;

        for(int i = 0 ; i < hand.size() ; i++){
            freq[hand[i]]++;
        }

        for(int i = 0 ; i < hand.size() ; i++){
            int card = hand[i];

            if(freq[card] == 0){
                continue;
            }
            for(int j = 0 ; j < groupSize ; j++){
                int current = card + j;

                if(freq[current] == 0){
                    return false;
                }

                freq[current]--;
            }
        }
        return true;
        
    }
};