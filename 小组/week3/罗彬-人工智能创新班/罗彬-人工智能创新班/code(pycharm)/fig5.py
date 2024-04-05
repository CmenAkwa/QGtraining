import numpy as np
import matplotlib.pyplot as plt


# 更新每个智能体的意见
def update_opinions(opinions, interaction_threshold):
    # 初始化新的意见数组
    new_opinions = np.copy(opinions)
    # 遍历每个智能体
    for i in range(len(opinions)):
        # 找到与智能体i意见差异小于阈值的邻居
        neighbor_indices = np.where(np.abs(opinions[i] - opinions) < interaction_threshold)[0]
        # 计算邻居意见的平均值，只考虑那些差异小于阈值的邻居
        if neighbor_indices.size > 0:
            new_opinions[i] = np.mean(opinions[neighbor_indices])
    return new_opinions


# 初始化智能体的意见
num_agents_low_density = 251  # 第一个区间的智能体数量
num_agents_high_density = 500  # 第二个区间的智能体数量
opinions_low_density = np.linspace(0, 2.5, num_agents_low_density, endpoint=False)
opinions_high_density = np.linspace(2.5, 3, num_agents_high_density, endpoint=False)
opinions = np.concatenate((opinions_low_density, opinions_high_density))

# 设置阈值
interaction_threshold = 1
# 设置迭代次数
max_iterations = 5  # 迭代次数

# 记录每个智能体的意见变化
opinion_history = {i: [] for i in range(num_agents_low_density + num_agents_high_density)}

# 运行模拟
for iteration in range(max_iterations):
    opinions = update_opinions(opinions, interaction_threshold)
    for i in range(num_agents_low_density + num_agents_high_density):
        opinion_history[i].append(opinions[i])

# 获取智能体1和智能体500的最终意见值
opinion1 = opinion_history[0][-1]
opinion2 = opinion_history[499][-1]
distance = opinion2 - opinion1
# 绘制每个智能体的意见变化趋势
plt.figure(figsize=(10, 5))
for i in range(num_agents_low_density + num_agents_high_density):
    plt.plot(range(max_iterations), opinion_history[i], label=f'Agent {i + 1}')

#在图上标注意见集合的值
plt.text(0, opinion1, f'Opinion 1: {opinion1:.2f}', color='blue', fontsize=10)
plt.text(0, opinion2, f'Opinion 2: {opinion2:.2f}', color='blue', fontsize=10)
print(distance)
plt.title('Fig.5')
plt.xlabel('Iteration')
plt.ylabel('Opinion')
plt.show()
