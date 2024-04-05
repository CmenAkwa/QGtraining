import numpy as np
import matplotlib.pyplot as plt


# 更新每个智能体的意见
def update_opinions(opinions, interaction_threshold):
    new_opinions = np.copy(opinions)
    # 遍历每个智能体
    for i in range(len(opinions)):
        # 找到与智能体i意见差异小于阈值的邻居
        neighbor_indices = np.where(np.abs(opinions - opinions[i]) < interaction_threshold)[0]
        # 计算邻居意见的平均值，只考虑那些差异小于阈值的邻居
        if neighbor_indices.size > 0:
            new_opinions[i] = np.mean(opinions[neighbor_indices])
    return new_opinions


# 初始化智能体的意见（均匀分布在半无限区间上）取0-30模拟半无限，最后画图画到0-8
num_agents = 2000  # 智能体数量
opinions = np.linspace(0, 30, num_agents, endpoint=False)  # 均匀分布的意见
interaction_threshold = 1  # 交互阈值
# 设置迭代次数
max_iterations = 16
# 记录每个智能体的意见变化
opinion_history = np.zeros((num_agents, max_iterations))
# 运行模拟
for iteration in range(max_iterations):
    opinions = update_opinions(opinions, interaction_threshold)
    opinion_history[:, iteration] = opinions

# 绘制每个智能体的意见变化趋势
plt.figure(figsize=(10, 5))
for i in range(num_agents):  # 循环绘制每个智能体的曲线
    plt.plot(range(max_iterations), opinion_history[i, :], label=f'Agent {i + 1}')

plt.title('Fig.3')
plt.xlabel('t')
plt.ylim(0, 8.15)
plt.show()
