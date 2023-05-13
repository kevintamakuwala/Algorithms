/*
  Problem Link: https://leetcode.com/problems/solving-questions-with-brainpower/
  
  You are given a 0-indexed 2D integer array questions where questions[i] = [pointsi, brainpoweri].
  
  The array describes the questions of an exam, where you have to process the questions in order 
  (i.e., starting from question 0) and make a decision whether to solve or skip each question. 
  Solving question i will earn you pointsi points but you will be unable to solve each of the next brainpoweri questions. 
  If you skip question i, you get to make the decision on the next question.
  
  For example, given questions = [[3, 2], [4, 3], [4, 4], [2, 5]]:
  If question 0 is solved, you will earn 3 points but you will be unable to solve questions 1 and 2.
  If instead, question 0 is skipped and question 1 is solved, you will earn 4 points but
  you will be unable to solve questions 2 and 3.
  
  Return the maximum points you can earn for the exam.
*/

class Solution {
    // Memoization
    long long Memoization(vector<vector<int>>&questions,long long i,long long n,vector<long long>&dp)
    {
        if(i==n){
            return questions[i][0];
        }
        if(i>n) 
            return 0;
        if(dp[i]!=-1) return dp[i];
        long long take=questions[i][0] + Memoization(questions,i+questions[i][1]+1,n,dp);
        long long notTake=Memoization(questions,i+1,n,dp);
        return dp[i]= max(take,notTake);
    }
    // Tabulation
    long long Tabulation(vector<vector<int>>&questions,long long n,vector<long long>&dp)
    {                
        
        dp[n] = questions[0][0];
        for(int i=n;i>=0;i--)
        {
            long long take=questions[i][0] ;
            if(i + questions[i][1] + 1 <= n)
                take+= dp[i+questions[i][1]+1];
            long long notTake=0;
            if(i!=n)
            notTake+=dp[i+1];
            dp[i]= max(take,notTake);
        }    
        return dp[0];
    }
public:
    long long mostPoints(vector<vector<int>>& questions) 
    {
        long long n=questions.size();
        vector<long long>dp(n,-1);
        return Tabulation(questions,n-1,dp);
    }
};
