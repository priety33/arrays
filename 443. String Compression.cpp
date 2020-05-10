class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size()==0) return 0;
        int i=0, pos=1;
        while(i<chars.size())
        {
            int j=i+1;
            while(j<chars.size() && chars[j]==chars[i]) j++;
            int n=j-i;
            chars.erase(chars.begin()+i+1, chars.begin()+i+1+n-1);
            int p=0;
            if(n!=1)
            {
                while(n){
                chars.insert(chars.begin()+pos, n%10+'0');
                n=n/10;
                p++;
                }
            }
            i=pos+p;
            pos=i+1;
        }
        return chars.size();
    }
};
