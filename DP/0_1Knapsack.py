import pandas as pd
import numpy as np

# 初始化數據
data = pd.DataFrame({
    "v": [10, 20, 30, 40, 12],  # 價值
    "w": [1, 3, 5, 7, 9]        # 重量
})
w = 15  # 背包最大容量

# 動態規劃表
dp = np.zeros([data.shape[0] + 1, w + 1])

# 動態規劃算法
for i in range(1, dp.shape[0]):
    vi = data.iloc[i - 1]["v"]  # 注意索引要減 1
    wi = data.iloc[i - 1]["w"]
    for j in range(1, dp.shape[1]):
        if j < wi:
            dp[i, j] = dp[i - 1, j]  # 不選當前物品
        else:
            dp[i, j] = max(dp[i - 1, j], vi + dp[i - 1, j - wi])  # 選或不選當前物品

# 輸出最大價值
print(dp[data.shape[0], w])