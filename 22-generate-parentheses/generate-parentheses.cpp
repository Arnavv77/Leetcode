class Solution {
public:
    vector<string> result;
    
    // Function to check if the generated parenthesis string is valid
    bool isValid(string str) {
        int count = 0;
        
        for(char ch : str) {
            if(ch == '(')
                count++;
            else
                count--;
            if(count < 0)
                return false;
        }
        return count == 0;
    }
    
    // Recursive function to generate all possible combinations
    void solve(string& curr, int n) {
        // Base case: if current string length reaches 2*n
        if(curr.length() == 2 * n) {
            if(isValid(curr)) {
                result.push_back(curr);
            }
            return;
        }

        // Add '(' and recurse
        curr.push_back('(');
        solve(curr, n);
        curr.pop_back(); // Backtrack

        // Add ')' and recurse
        curr.push_back(')');
        solve(curr, n);
        curr.pop_back(); // Backtrack (completes the logic shown on screen)
    }

    // Main function
    vector<string> generateParenthesis(int n) {
        string curr = "";

        solve(curr, n);

        return result;
    }
};