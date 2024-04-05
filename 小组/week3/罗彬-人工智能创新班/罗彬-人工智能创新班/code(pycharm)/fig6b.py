import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import norm

# 更新每个智能体的意见
def update_opinions(opinions, interaction_threshold):
    new_opinions = np.copy(opinions)
    for i in range(len(opinions)):
        neighbor_indices = np.where(np.abs(opinions - opinions[i]) < interaction_threshold)[0]
        if neighbor_indices.size > 0:
            new_opinions[i] = np.mean(opinions[neighbor_indices])
    return new_opinions

# 初始化参数
num_agents = 5001
mean_low = 1.25
std_low = 0.35
mean_high = 2.75
std_high = 0.2

# 生成第一个区间的意见（低密度）
num_agents_low_density = int(num_agents * 0.4)
opinions_low_density = norm.rvs(mean_low, std_low, size=num_agents_low_density)

# 生成第二个区间的意见（高密度）
num_agents_high_density = num_agents - num_agents_low_density
opinions_high_density = norm.rvs(mean_high, std_high, size=num_agents_high_density)

# 合并
opinions = np.concatenate((opinions_low_density, opinions_high_density))

# 设置阈值和迭代次数
interaction_threshold = 1
max_iterations = 20
# 初始化意见变化记录数组
opinion_history = np.zeros((num_agents, max_iterations))
for iteration in range(max_iterations):
    opinions = update_opinions(opinions, interaction_threshold)
    opinion_history[:, iteration] = opinions

plt.figure(figsize=(10, 5))
for i in range(num_agents):
    plt.plot(range(max_iterations), opinion_history[i])

plt.title('Fig.6b')
plt.xlabel('t')
plt.show()