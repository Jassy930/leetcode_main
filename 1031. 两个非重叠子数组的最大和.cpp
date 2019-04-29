class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        vector<int> ll;
        vector<int> mm;
        int out = 0;
        int l=0;
        int m=0;
        for(int i=0;i<A.size(); i++)
        {
            l+=A.at(i);
            m+=A.at(i);
            if(i-L>=0) 
                l-=A.at(i-L);
            if(i-M>=0) 
                m-=A.at(i-M);
            // if(i>L-1)
                ll.push_back(l);
                mm.push_back(m);
        }
        
        for(int i=L-1; i<A.size()-M; i++)
        {
            for(int k=i+M; k<A.size(); k++)
            {
                out = max(out, ll.at(i)+mm.at(k));
            }
        }
        
        for(int i=M-1; i<A.size()-L; i++)
        {
            for(int k=i+L; k<A.size(); k++)
            {
                out = max(out, ll.at(k)+mm.at(i));
            }
        }
        
        // for(int i=0;i<ll.size(); i++) cout<<ll.at(i)<<",";
        // cout<<endl;
        // for(int i=0;i<mm.size(); i++) cout<<mm.at(i)<<",";
        
        
        return out;
    }
};