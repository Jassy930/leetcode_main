class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int out=0;
        vector<int> divp;
        vector<int> divn;
        int pn = 0;
        for(int i=0; i<costs.size(); i++)
        {
            if(costs.at(i).at(0)<costs.at(i).at(1))
            {
                out+=costs.at(i).at(0);
                divp.push_back(costs.at(i).at(1)-costs.at(i).at(0));
                pn++;
            }
            else
            {
                out+=costs.at(i).at(1);
                divn.push_back(costs.at(i).at(0)-costs.at(i).at(1));
                pn--;
            }
        }
        
        sort(divp.begin(), divp.end());
        sort(divn.begin(), divn.end());
        pn = pn/2;
        
        if(pn>0)
        {
            for(int i=0; i<pn; i++)
            {
                out+=divp.at(i);
            }
        }
        else
        {
            pn = -1*pn;
            for(int i=0; i<pn; i++)
            {
                out+=divn.at(i);
            }
        }
        
        return out;
    }
};