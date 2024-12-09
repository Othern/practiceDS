import numpy as np

s1 = "abcdefgkblcd"
s2 = "avefgdckblcddd"

# Initialize DP table
# dp 儲存s1的前i和s2的前j個結尾相同的字串數
dp = np.zeros((len(s1) + 1, len(s2) + 1))
m = 0
mi = [0,0]
# Populate DP table
for i in range(1, len(s1) + 1):
    for j in range(1, len(s2) + 1):
        # 比較當s1[i] 與 s2[j]
        if s1[i - 1] == s2[j - 1]:  # Compare characters at (i-1) and (j-1)
            dp[i, j] = dp[i - 1, j - 1] + 1
            if dp[i,j] > m:
                m = max(m,dp[i, j])
                mi = [i,j]
            # 不一樣則保持為0

result = ""
while(mi[0] > 0 and mi[1] > 0):
    result = s1[int(mi[0] - 1)] + result
    mi[0]-=1
    mi[1]-=1
    if(dp[mi[0],mi[1]] == 0):
        break
print(result, len(result))
