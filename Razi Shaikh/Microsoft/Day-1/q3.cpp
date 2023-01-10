class Solution {
public:
    string getHint(string secret, string guess) {
        int b = 0;
        int c = 0;
        map<char , int>m;
        for(auto it : secret){m[it]++;}
        for(int i = 0;i<guess.size();i++){
            if(guess[i] == secret[i] && m[secret[i]] >0){
                m[secret[i]]--;
                b++;
            }  
        }
         for(int i = 0;i<guess.size();i++){
             if( guess[i] != secret[i] && m[guess[i]] > 0){
                c++;
                m[guess[i]]--;
            }  
        }
        return to_string(b) + "A" + to_string(c) +"B";
    }
};
