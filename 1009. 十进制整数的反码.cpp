class Solution {
public:
    int bitwiseComplement(int num) {
        if(num == 0) return 1;
        unsigned int i=1;
        while(num>=i){
            i=i<<1;
        }
        return num^(i-1);
    }
};