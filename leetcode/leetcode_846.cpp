class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int len = hand.size();
        // If len is not multiple of W, return false.
        if(len % W) return false;
        int groupNum = len / W;
        
        // Multiset insertion
        multiset<int> s;
        for(int i=0; i<len; i++)
            s.insert(hand[i]);
        
        int pivot;
        for(int i=0; i<groupNum; i++){
            // First elem of one group
            pivot = *(s.begin());
            s.erase(s.begin());
            // Find rest elems
            for(int j=0; j<W-1; j++){
                auto itr = s.find(++pivot);
                if(itr == s.end())  return false;
                s.erase(itr);
            }
        }
        
        return true;
    }
};
