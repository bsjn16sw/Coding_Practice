class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        int mid;
        
        if(x == 1)  return 1;

        while(left <= right){
            mid = (left + right) / 2;
            if(mid == left) return mid;
            
            if(x == pow(mid, 2))
                return mid;
            // NOT right = mid + 1
            // x != pow(mid, 2) does not mean that
            // mid is out of sight.
            else if(x < pow(mid, 2))
                right = mid;
            else
                left = mid;
        }
        
        return 0;
    }
};
