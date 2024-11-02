class Solution {
public:
    bool isCircularSentence(string sentence) {
        char last = '$';
        for(int i=0; i<sentence.size(); i++){
            if(sentence[i] == ' '){
                continue;
            }
            char ch = sentence[i];

            if(i>1 && sentence[i-1]==' '){
                if(last != ch) return false;
            }
            last = ch;
        }

        if(sentence[0] != sentence.back()) return false;
        return true;
    }
};