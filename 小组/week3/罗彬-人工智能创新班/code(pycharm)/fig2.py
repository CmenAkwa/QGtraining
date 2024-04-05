import numpy as np
import matplotlib.pyplot as plt


# 定义一个函数来更新每个智能体的意见
def update_opinions(opinions, interaction_threshold, num_agents):
    # 初始化新的意见数组
    new_opinions = np.copy(opinions)
    # 为每个智能体找到其邻居
    for i in range(num_agents):
        neighbors = np.where(np.abs(opinions - opinions[i]) < interaction_threshold)[0]
        if len(neighbors) > 0:
            # 计算邻居意见的平均值
            new_opinions[i] = np.mean(opinions[neighbors])
    return new_opinions


# 设置交互阈值
interaction_threshold = 1

# 初始化智能体的数量
num_agents = 600

# 初始化一个列表来存储每个智能体的最终意见
agent_final_opinions = []

# 循环不同长度的意见分布区间L
for L in np.arange(3, 35, 0.1):
    # 初始化智能体的意见（均匀分布在0到L-1之间）
    opinions = np.linspace(0, L, num_agents, endpoint=False)
    # 记录每个L值的最终意见
    agent_final_opinions_L = []

    # 运行模拟直到达到平衡状态
    max_iterations = 60  # 设置一个较大的迭代次数
    for _ in range(max_iterations):
        opinions = update_opinions(opinions, interaction_threshold, num_agents)

        # 检查是否有智能体的意见发生了变化，如果没有变化，则认为系统达到平衡
        if np.all(opinions == opinions[0]):
            break

    # 将最终意见减去L/2，以便将意见范围标准化到-L/2到L/2
    opinions -= L / 2

    # 记录每个智能体的最终意见
    agent_final_opinions.extend(opinions)

    # 绘制每个智能体的最终意见随L变化的趋势（蓝色数据点）
    plt.plot([L] * len(opinions), opinions, 'bo', markersize=1)

# 假设两条渐近线的斜率和截距
m = 0.57  # 斜率
b = 0  # 截距

# 绘制两条渐近线
plt.plot(np.arange(3, 35), m * np.arange(3, 35) + b, 'r--')
plt.plot(np.arange(3, 35), -m * np.arange(3, 35) + b, 'g--')
plt.xlabel('L')
plt.ylabel('x-2/L')
plt.show()
