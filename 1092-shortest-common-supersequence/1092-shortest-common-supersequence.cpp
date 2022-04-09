class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        return SCS(str1,str2,str1.size(),str2.size());
    }
    string SCS(string X, string Y, int n, int m) {
	int dp[n + 1][m + 1]; 

	
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (X[i - 1] == Y[j - 1]) 
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else 
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

	int i = n, j = m;
	string scs = "";
	while (i > 0 && j > 0) {
		if (X[i - 1] == Y[j - 1]) {  
			scs += X[i - 1]; 
			i--, j--; 
		}
		else if (dp[i][j - 1] > dp[i - 1][j]) {
			scs += Y[j - 1]; 
			j--;
		}
		else {
			scs += X[i - 1]; 
			i--;
		}
	}

	while (i > 0) {
		scs += X[i - 1];
		i--;
	}

	while (j > 0) {
		scs += Y[j - 1]; 
		j--;
	}

	reverse(scs.begin(), scs.end());

	return scs;
}
};