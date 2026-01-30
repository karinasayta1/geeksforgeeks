class Solution {

  public:
    bool findSwapValues(vector<int>& a, vector<int>& b) {
        // Your code goes here
        long long suma = 0,  sumb = 0;
        
        for(int x : a) suma += x;
        
        for(int y : b) sumb += y;
        
        if((suma - sumb) % 2 != 0) 
            return false;
            
        int target = (suma - sumb) / 2;
        
        unordered_set<int> setb;
        
        for(int y : b){
            setb.insert(y);
        }
        
        for(int x : a){
            int y = x - target;
            if(setb.find(y) != setb.end()){
                return true;
            }
        }
        
        return false;
    }
    
};