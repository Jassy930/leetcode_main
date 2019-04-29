class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        map<int,int> mm;
        for(int i=0; i<clips.size(); i++)
        {
            mm[clips.at(i).at(0)] = max(mm[clips.at(i).at(0)], clips.at(i).at(1));
        }
        
        int out=1;
        int t=mm[0];
        if(t == 0) return -1;
        if(t >= T) return out;
        int tt=t;
        for(auto m = mm.begin(); m!= mm.end(); m++)
        {
            if(m->first <= t)
            {
                tt = max(tt, m->second);
            }
            else if(m->first > t)
            {
                t=tt;
                out++;
                if(m->first > t) return -1;
            }
                // return -1;
            // int tt=t;
            // while(m!= mm.end() && m->first <= t)
            // {
            //     tt = max(tt, m->second);
            //     m++;
            // }
            // tt = max(tt, m->second);
            // m++;
            
            // t = tt;
            // cout<<t<<",";
            if(tt>=T) return out+1;

        }
        return -1;
        // return out;
    }
};