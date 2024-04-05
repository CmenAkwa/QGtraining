import numpy as np
import matplotlib.pyplot as plt


def update_opinions(opinions, interaction_threshold):
    # 初始化新的意见数组
    new_opinions = np.copy(opinions)
    # 遍历每个智能体
    for i in range(len(opinions)):
        # 找到与智能体i意见差异小于阈值的邻居
        neighbor_indices = np.where(np.abs(opinions - opinions[i]) < interaction_threshold)[0]
        # 计算邻居意见的平均值，只考虑那些差异小于阈值的邻居
        if neighbor_indices.size > 0:
            new_opinions[i] = np.mean(opinions[neighbor_indices])
    return new_opinions
num_agents = 1000  # 智能体数量
opinions = np.linspace(0, 4, num_agents, endpoint=False)  # 均匀分布的意见
interaction_threshold = 1  # 交互阈值

# 设置迭代次数
max_iterations = 13

# 记录每个智能体的意见变化
opinion_history = np.zeros((num_agents, max_iterations))  # 每个智能体的意见历史

for iteration in range(max_iterations):
    opinions = update_opinions(opinions, interaction_threshold)
    opinion_history[:, iteration] = opinions
plt.figure(figsize=(10, 5))
for i in range(num_agents):
    plt.plot(range(max_iterations), opinion_history[i])

plt.title('Fig.4')
plt.xlabel('t')
plt.show()
