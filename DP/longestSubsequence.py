import numpy as np
s2 = "acacbaacbcaa"
s1 = "acbcaca"

dp = np.zeros([len(s1)+1, len(s2)+1])
for i in range(1, dp.shape[0]):
    for j in range(1, dp.shape[1]):
        if s1[i-1] == s2[j-1]:
            dp[i,j] = dp[i-1, j-1] + 1
        else:
            dp[i,j] = max(dp[i-1,j], dp[i,j-1])
            
print(dp)