/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] 键盘行
 *
 * https://leetcode-cn.com/problems/keyboard-row/description/
 *
 * algorithms
 * Easy (64.75%)
 * Total Accepted:    5.6K
 * Total Submissions: 8.6K
 * Testcase Example:  '["Hello","Alaska","Dad","Peace"]'
 *
 * 给定一个单词列表，只返回可以使用在键盘同一行的字母打印出来的单词。键盘如下图所示。
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 输入: ["Hello", "Alaska", "Dad", "Peace"]
 * 输出: ["Alaska", "Dad"]
 * 
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 你可以重复使用键盘上同一字符。
 * 你可以假设输入的字符串将只包含字母。
 * 
 */
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> out;
        map<char,int> keymap;
        keymap['q']=0;
        keymap['w']=0;
        keymap['e']=0;
        keymap['r']=0;
        keymap['t']=0;
        keymap['y']=0;
        keymap['u']=0;
        keymap['i']=0;
        keymap['o']=0;
        keymap['p']=0;
        keymap['a']=1;
        keymap['s']=1;
        keymap['d']=1;
        keymap['f']=1;
        keymap['g']=1;
        keymap['h']=1;
        keymap['j']=1;
        keymap['k']=1;
        keymap['l']=1;
        keymap['z']=2;
        keymap['x']=2;
        keymap['c']=2;
        keymap['v']=2;
        keymap['b']=2;
        keymap['n']=2;
        keymap['m']=2;
        for(int i=0; i<words.size(); i++)
        {
            int m = keymap[(words.at(i).at(0)<'a'?words.at(i).at(0)+32:words.at(i).at(0))];
            int n = 0;
            for(int k=0; k<words.at(i).size(); k++)
            {
                char q = words.at(i).at(k);
                if (q<'a') q+=32;
                cout<<keymap[q];
                if(keymap[q] != m) n++;
            }
            if(n == 0) out.push_back(words.at(i));
        }
        return out;
    }
};

