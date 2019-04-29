class Solution {
public:
    string baseNeg2(int N) {
        // 0   1   2   3   4   5
        // 1   -2  4   -8  16  -32
        if(N==0) return "0";
        vector<int> numm;
        
        while(N>0)
        {
            numm.push_back(N%4);
            numm.push_back(0);
            N = N/4;
        }
        // numm.push_back(0);
        // numm.push_back(0);
        // numm.push_back(0);
        for(int i=0; i<numm.size(); i++)
        {
            if(numm.at(i)==2 || numm.at(i)==3)
            {
                numm.at(i) -= 2;
                if(i+1>=numm.size()) numm.push_back(1);
                else numm.at(i+1) ++;
                
                if(i+2>=numm.size()) numm.push_back(1);
                else numm.at(i+2) ++;
            }
            if(numm.at(i)==4)
            {
                numm.at(i) -= 4;
                if(i+1>=numm.size()) numm.push_back(0);
                if(i+2>=numm.size()) numm.push_back(1);
                else numm.at(i+2) ++;
                // numm.at(i+2) ++;
            }
            // cout<<numm.at(i);
        }
        // cout<<endl;
        int flag = 0;
        stringstream out;
        for(auto i=numm.rbegin(); i!=numm.rend(); i++)
        {
            flag+=(*i);
            if(flag!=0) out<< (*i);
        }
        return out.str();
    }
};