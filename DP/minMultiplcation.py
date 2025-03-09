# 想法： 計算片段最小值，再透過兩片段組合，加上組合成本 m * k * n
# 比較不同分割片段，最小值爲所求 
import numpy as np

data = np.array([[10, 6],
                 [6, 12],
                 [12, 5],
                 [5, 50],
                 [50, 3],
                ], dtype=int)

n = len(data)
dp = np.zeros((n, n), dtype=int)

# Dynamic programming to calculate the minimum multiplication cost
for length in range(1, n):  # Length of the chain segment
    for i in range(n - length):  # Starting index of the segment
        j = i + length  # Ending index of the segment
        dp[i, j] = 1000000
        for k in range(i, j):  # Possible split points
            cost = (dp[i, k] + dp[k + 1, j] + 
                    data[i, 0] * data[k, 1] * data[j, 1])
            dp[i, j] = min(dp[i, j], cost)

print("Minimum multiplication costs:")
print(dp)