import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import norm  # pdf函数引入


def update_opinions(opinions, interaction_threshold, num_agents):
    # 初始化新的意见数组
    new_opinions = np.copy(opinions)
    # 遍历每个智能体
    for i in range(num_agents):
        # 找到与智能体i意见差异小于阈值的邻居
        neighbor_indices = np.where(np.abs(opinions - opinions[i]) < interaction_threshold)[0]
        # 计算邻居意见的平均值，只考虑那些差异小于阈值的邻居
        if neighbor_indices.size > 0:
            new_opinions[i] = np.mean(opinions[neighbor_indices])
    return new_opinions

num_agents_low_density = 760  # 第一个区间的智能体数量
num_agents_high_density = 1745  # 第二个区间的智能体数量

# 生成第一个区间的意见（低密度）
mean_low = 1.25  # 第一个区间的均值
std_low = 0.6  # 第一个区间的标准差
opinions_low_density = norm.rvs(mean_low, std_low, size=num_agents_low_density)

# 生成第二个区间的意见（高密度）
mean_high = 2.75  # 第二个区间的均值
std_high = 0.2  # 第二个区间的标准差
opinions_high_density = norm.rvs(mean_high, std_high, size=num_agents_high_density)

# 合并
opinions = np.concatenate((opinions_low_density, opinions_high_density))

# 设置阈值
interaction_threshold = 1
# 设置迭代次数
max_iterations = 7

# 每个智能体的意见变化
opinion_history = {i: [] for i in range(num_agents_low_density + num_agents_high_density)}

for iteration in range(max_iterations):
    opinions = update_opinions(opinions, interaction_threshold, len(opinions))
    for i in range(len(opinions)):
        opinion_history[i].append(opinions[i])

# 绘制
plt.figure(figsize=(10, 5))
for i in range(len(opinions)):
    plt.plot(range(max_iterations), opinion_history[i])

plt.title('Fig. 6')
plt.xlabel('t')
plt.show()
