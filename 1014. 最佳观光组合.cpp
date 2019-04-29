class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int out = A.at(1)+A.at(0)-1;
        int good = max(A.at(1), A.at(0)-1)-1;
        for(int i=2; i<A.size(); i++)
        {
            // cout<<out<<","<<good<<"|";
            out = max(out, A.at(i)+good);
            good = max(good-1, A.at(i)-1);
        }
        return out; 
    }
};