class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> out;
        
        out.push_back(vector<int>{r0, c0});
        
        for(int i=1;i<R+C;i++)
        {
            for(int k=0; k<=i; k++)
            {
                // cout<<r0+i-k<<","<<c0+k<<endl;
                if(val(r0+i-k,c0+k,R,C))
                    out.push_back(vector<int>{r0+i-k,c0+k});
                // cout<<r0-i+k<<","<<c0-k<<endl;
                if(val(r0-i+k,c0-k,R,C))
                    out.push_back(vector<int>{r0-i+k,c0-k});
                // cout<<r0+i+k<<","<<c0-k<<endl;
                if(val(r0+i-k,c0-k,R,C) && k!=0 && k!=i)
                    out.push_back(vector<int>{r0+i-k,c0-k});
                // cout<<r0-i-k<<","<<c0+k<<endl;
                if(val(r0-i+k,c0+k,R,C) && k!=0 && k!=i)
                    out.push_back(vector<int>{r0-i+k,c0+k});
                
            }
        }
    
        return out;
    }
    
    bool val(int r,int c,int R, int C)
    {
        if(r>=0 && r<R && c>=0 && c<C) return true;
        return false;
    }
};