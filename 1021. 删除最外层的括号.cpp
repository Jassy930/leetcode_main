class Solution {
public:
    string removeOuterParentheses(string S) {
        int p=0;
        int flag = 0;
        
        string out="";
        if(S.size()==0) return out;
        
        for(int i=0; i<S.size(); i++)
        {
            if(S.at(i) == '(') flag++;
            else flag--;
            // q++;
            if(flag == 0)
            {
                // if((q-p)>1)
                out=out + S.substr(p+1,i-p-1);
                p=i+1;
                // cout<<out<<",";
            }
        }
        return out;
    }
};