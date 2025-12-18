# [cite_start]实验二 [cite: 1]

---

## [cite_start]题目 1 [cite: 2]

* [cite_start]**实验内容**：给定一个字符串，统计每个字符出现的次数 [cite: 3]。

---

## [cite_start]题目 2 [cite: 4]

* [cite_start]**实验内容**：给定一个长度为 $n$ 的数组 `nums`，对其进行原地反转 [cite: 5]。
* [cite_start]**空间复杂度要求**：$O(1)$ [cite: 5]。
* [cite_start]**反转逻辑说明**：反转是指 `nums[i]` 中保存原来 `nums[n-1-i]` 的值 [cite: 5]。

---

## [cite_start]题目 3 [cite: 6]

### 1. 计算公式定义
对于多项式计算，分别采用以下三种公式：

* [cite_start]**公式 1（直接计算法）** [cite: 7]：
    $$f_1(x) = a_0 + a_1x + \dots + a_{n-1}x^{n-1} + a_nx^n$$
* [cite_start]**公式 2（秦九韶算法/嵌套法）** [cite: 8]：
    $$f_2(x) = a_0 + x(a_1 + x(\dots a_{n-1} + x a_n \dots))$$
* [cite_start]**公式 3（特定级数）** [cite: 10]：
    $$f_3(x) = 1 + \sum_{i=1}^{n} \frac{x^i}{i}$$

### 2. 算法实现要求
* [cite_start]**数据初始化**：系数 $a_0, a_1, \dots, a_n$（其中 $0 \le a_i \le 9$）由伪随机数 `rand()` 获得，并采用多项式结构存储 [cite: 9]。
* [cite_start]**编程任务**：针对公式 1 和公式 2，分别采用**迭代法**和**递归法**各编写两个函数 `F1a`、`F2a` 和 `F1b`、`F2b` [cite: 9]。
* [cite_start]**特定值求解**：取 $x = 1.1$，计算 $f_3(x)$ 的值 [cite: 11]。

### 3. 性能测试与对比
* [cite_start]**测试规模 $n$**：$\{1, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 60, 70, 80, 90, 100\}$ [cite: 12]。
* [cite_start]**性能指标**：利用 `clock()` 函数，获得四个算法在同一计算机上的运行时间 [cite: 12]。
* **成果提交**：
    * [cite_start]**对比表格**：每行代表一个算法，每列为 $n$ 的一个取值 [cite: 12]。
    * [cite_start]**可视化分析**：将表格数据转为图形（如使用 Excel、MATLAB 或 Python Matplotlib） [cite: 13]。

---

## [cite_start]附加题 [cite: 14]

* [cite_start]**实验内容**：给定一个字符串 $s$，找到 $s$ 中最长的回文字串 [cite: 15]。
* [cite_start]**定义**：回文串是指正着读和反着读都一样的字符串 [cite: 15]。