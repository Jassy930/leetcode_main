class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> out;
        int m=0;
        for(int i=0; i<A.size(); i++)
        {
            m = m*2 + A.at(i);
            m = m%5;
            if(m==0) out.push_back(true);
            else out.push_back(false);
        }
        return out;
    }
};