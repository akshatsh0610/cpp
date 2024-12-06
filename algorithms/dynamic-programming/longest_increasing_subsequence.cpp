#include <iostream>
#include <vector>
using namespace std;
int longestIncreasingSubsequenceThroughTabulation(int A[],int size){
    int dp[size];
    for(int i=0;i<size;i++) dp[i] = 1;
    for(int i=1;i<size;i++){
        for(int j=0;j<i;j++){
            if(A[j]<A[i]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    int lis = 0;
    for(int i=0;i<size;i++) {
    	lis = max(lis,dp[i]);
    }
    
    return lis;
}
int longestIncreasingSubsequenceThroughMemoization(int A[],int idx,int prev,int size,vector<vector<int>>&dp){
	if(idx>=size)
		return 0;
	if(dp[idx][prev+1]!=-1){
		return dp[idx][prev+1];
	}
	int choise1=0;
	int choise2=0;
	if(prev==-1){
		choise1=1+longestIncreasingSubsequenceThroughMemoization(A,idx+1,idx,size);
	}
	if(A[prev]<A[idx]){
		choise1=1+longestIncreasingSubsequenceThroughMemoization(A,idx+1,idx,size);
	}
	choise2=longestIncreasingSubsequenceThroughMemoization(A,idx+1,prev,size);
	return dp[idx][prev+1]=max(choise1,choise2);	
}
int main() {
	
	int A[] = {1,3,5,9,8};
	cout<<"Tabulation -> "<<endl;
	cout<<longestIncreasingSubsequenceThroughTabulation(A,5)<<endl;
	vector<vector<int>>dp(size,vector<int>(size,-1));
	cout<<"Memoization -> "<<endl;
	cout<<longestIncreasingSubsequenceThroughMemoization(A,0,-1,5,dp)<<endl;
	return 0;
}
