class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum =0;
        for(int i=0; i<A.size(); i++)
        {
            sum+=A.at(i);
        }
        if(sum%3!=0) return false;
        sum = sum/3;
        
        int count = 3;
        int i=0;
        int csum=0;
        while(i<A.size())
        {
            csum+=A.at(i);
            if(csum == sum)
            {
                csum = 0;
                count--;
            }
            i++;
        }
        if(count == 0) return true;
        return false;
    }
};