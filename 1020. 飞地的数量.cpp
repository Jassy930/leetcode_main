class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        int m=A.size();
        int n=A.at(0).size();
        vector<int> a(n,-1);
        vector<vector<int>> flag (m, a);
        int out=0;
        for(int i=0; i<flag.size(); i++)
        {
            if(A.at(i).at(0) == 1)
                setflag(A, i, 0, flag);
            if(A.at(i).at(n-1) == 1)
                setflag(A, i, n-1, flag);
        }
        for(int i=0; i<flag.at(0).size(); i++)
        {
            if(A.at(0).at(i) == 1)
                setflag(A, 0, i, flag);
            if(A.at(m-1).at(i) == 1)
                setflag(A, m-1, i, flag);
        }
        for(int i=0; i<flag.size(); i++)
        {
            for(int k=0; k<flag.at(0).size(); k++)
            {
                if(A.at(i).at(k) == 1 && flag.at(i).at(k) != 1) out++;
                // cout<<flag.at(i).at(k)<<",";
            }
            // cout<<endl;
        }
        
        return out;
    }
    
    void setflag(vector<vector<int>>& A, int i, int k, vector<vector<int>>& flag)
    {
        flag.at(i).at(k) = 1;
        if(i-1>0 && A.at(i-1).at(k) == 1 && flag.at(i-1).at(k) == -1) setflag(A, i-1, k, flag);
        if(i+1<A.size() && A.at(i+1).at(k) == 1 && flag.at(i+1).at(k) == -1) setflag(A, i+1, k, flag);
        if(k-1>0 && A.at(i).at(k-1) == 1 && flag.at(i).at(k-1) == -1) setflag(A, i, k-1, flag);
        if(k+1<A.at(0).size() && A.at(i).at(k+1) == 1 && flag.at(i).at(k+1) == -1) setflag(A, i, k+1, flag);
    }
    
    int getflag(vector<vector<int>>& A, int i, int k, vector<vector<int>> flag)
    {
        int m=0;
        if(A.at(i-1).at(k) == 1 && flag.at(i).at(k+1) == 1) return 1;
        else if(A.at(i-1).at(k) == 1) m+= getflag(A, i-1, k, flag);
        if(A.at(i+1).at(k) == 1 && flag.at(i+2).at(k+1) == 1) return 1; 
        else if(A.at(i+1).at(k) == 1) m+= getflag(A, i-1, k, flag);
        if(A.at(i).at(k-1) == 1 && flag.at(i+1).at(k) == 1) return 1; 
        else if(A.at(i).at(k-1) == 1) m+= getflag(A, i-1, k, flag);
        if(A.at(i).at(k+1) == 1 && flag.at(i+1).at(k+2) == 1) return 1; 
        else if(A.at(i).at(k+1) == 1) m+= getflag(A, i-1, k, flag);
        if(m>0) return 1;

    }
    
};