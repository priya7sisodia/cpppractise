class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        // Intution
        // The idea in here is really very simple. What we will do is we will maintain the spaces required for the words in the temporary vector and also the number of characters in the current word. If we found that the total lenght is greater than or equal to maximum length then we will perform the operation.

        int spacesReq;
        int currLen = 0;

        vector<string> temp;
        vector<string> result;

        for(auto &word : words){
            int wordLen = word.size();
            spacesReq = temp.size();
            if(currLen + wordLen + spacesReq > maxWidth){
                string answer = "";
                int spaces = maxWidth - currLen;
                if(temp.size() == 1){
                    answer = temp[0];
                    while(spaces --> 0) answer += " ";
                    result.push_back(answer);
                }
                else{
                    int spaceBetween = spaces / (temp.size() - 1);
                    int extraSpaces = maxWidth - currLen - spaceBetween * (temp.size() - 1);
                    answer = temp[0];
                    string bet = "";
                    while(spaceBetween --> 0) bet += " ";
                    for(int i = 1 ; i < temp.size() ; i++){
                        answer += bet;
                        if(extraSpaces > 0){
                            answer += " ";
                            extraSpaces -= 1;
                        }
                        answer += temp[i];
                    }
                    result.push_back(answer);
                }
                temp.clear();
                currLen = wordLen;
                temp.push_back(word);
            }
            else{
                currLen += wordLen;
                temp.push_back(word);
            }
        }

        if(temp.size() >= 1){
            string answer = temp[0];
            for(int i = 1 ; i < temp.size() ; i++){
                answer += " " + temp[i];
            }
            while(answer.size() < maxWidth) answer += " ";
            result.push_back(answer);
        }

        return result;

    }
};