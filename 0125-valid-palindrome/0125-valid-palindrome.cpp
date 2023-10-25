class Solution {
public:
    bool isPalindrome(string s) {

        int n = s.size();

        for (int i = 0 ; i < n; i++)
        {
        if (ispunct(s[i]))
        {
            s.erase(i--, 1);
            n = s.size();
        }
        }


        s.erase(remove(s.begin(), s.end(), ' '), s.end());




        transform(s.begin() , s.end() , s.begin() , :: tolower);

        int i = 0;
        int j = s.size() - 1;
        while(i<j)
        {
            if((s[i] >='a' || s[i] <= 'z'))
            {
                if(s[i] == s[j])
                {
                    i++;
                    j--;
                }
                else{return false;}
            }
            else if((s[i] <='a' && s[i] >= 'z') ){
                i++;
            }
            else if((s[j] <='a' && s[j] >= 'z') ){
                j++;
            }
            
            
        }
        return true;
    }
};