import numpy as np
import pandas as pd

data = pd.DataFrame({"v" : [10, 20 , 30 , 40, 12],
                     "w" : [1, 3, 5, 7, 9]})
w = 20


data["v/w"] = data["v"] / data["w"]
data.sort_values("v/w", inplace=True)
i = 0
maxOutput = 0

while w > 0 and i < data.shape[0]:
    if data.iloc[i]["w"] <= w:
        maxOutput += data.iloc[i]["v"]
        w -= data.iloc[i]["w"]
    else:
        maxOutput += data.iloc[i]["v/w"] * w  # 部分裝入
        w = 0
    i += 1
print(maxOutput)