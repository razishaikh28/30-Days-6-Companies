//Solution-1
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

//Solution-2
class Solution {
public:
    string getHint(string secret, string guess) {
       int secretFre[10] = {0}; 
       int guessFre[10] = {0};
       int cows = 0, bulls = 0;
       for(int i=0; i<secret.size(); i++){
           if(secret[i] == guess[i]){
               bulls++;
           }
           else{
                //Conversion of string characters to integer
                secretFre[secret[i] - '0']++;
                guessFre[guess[i] - '0']++;
           }
       }
       for(int i=0; i<10; i++){
           // consider minimum value as it should match with the guess too
           cows += min(secretFre[i],guessFre[i]);
       }
       return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
