class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> out;
        for(int i=0; i<queries.size(); i++)
        {
            int j=0;
            for(int k=0; k<queries.at(i).size(); k++)
            {
                if(j<pattern.size() && (queries.at(i).at(k) == pattern.at(j)))
                {
                    j++;
                }
                else if(j<=pattern.size() && queries.at(i).at(k)<'a' && (j==pattern.size() || (queries.at(i).at(k) != pattern.at(j))))
                {
                     
                    j=pattern.size()+1;
                }
            }
            if(j == pattern.size()) out.push_back(true);
            else out.push_back(false);
        }
        return out;
    }
};