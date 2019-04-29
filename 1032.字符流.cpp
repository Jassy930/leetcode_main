class StreamChecker {

    class TrieNode {
        public: 
        bool isword;
        map<char, TrieNode> nexts;

        TrieNode() {
            isword = false;
            nexts = map<char, TrieNode>();
        }
    };
    
public:
    TrieNode root;
    vector<char> queryletter;
    StreamChecker(vector<string>& words) {
        root.isword = false;
        for(auto i = 0; i<words.size(); i++)
        {
            TrieNode *p = &root;
            
            for(int k=words[i].size()-1; k>=0; k--)
            {
                if((p->nexts).count(words[i][k]) == 0)
                    p->nexts[words[i][k]]=TrieNode();
                p = &(p->nexts[words[i][k]]);
            }
            p->isword = true;
        }
    }
    
    bool query(char letter) {
        queryletter.push_back(letter);
        TrieNode *p = &root;
        for(int i=queryletter.size()-1; i>=0; i--)
        {
            if((p->nexts).count(queryletter[i]) == 0)
                return false;
            if((p->nexts[queryletter[i]]).isword)
                return true;
            p = &(p->nexts[queryletter[i]]);
        }
        return false;
        // return (p->nexts[letter]).isword;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */