class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int, int> timemap;
        for (int i=0; i<time.size(); i++)
        {
            map<int, int>::iterator it = timemap.find(time.at(i)%60);
            if(it != timemap.end())
            {
                timemap[time.at(i)%60]++;
            }
            else
            {
                timemap[time.at(i)%60] = 1;
            }
        }
        
        int out = 0;
        map<int, int>::iterator ii;
        // for(ii=timemap.begin(); ii!=timemap.end(); ii++)
        // {
        //     cout<<ii->first<<","<<ii->second<<"|";
        // }
        for(ii=timemap.begin(); ii!=timemap.end(); ii++)
        {
            if(ii->first == 0 || ii->first == 30){
                out+=(ii->second) * (ii->second-1) /2;
                // cout<<(ii->second) * (ii->second-1) /2<<"|";
            }
            else if(ii->first < 30){
                map<int,int>::iterator it = timemap.find(60 - ii->first);
                if(it != timemap.end())
                {
                    out+=ii->second * it->second;
                    // cout<<ii->second * it->second;
                    // timemap.erase(it);
                }
            }
        }
        return out;
        
        
    }
};