# problem-archive

好题 / trick 归档

## [CF1155D Beautiful Array](https://codeforces.com/contest/1155/problem/D)

很经典的 dp 状态设计，根据题目给的操作划分为操作前、操作中、操作后。

## [Gym105143K Party Games](https://codeforces.com/gym/105143/problem/K)

来源： 2024 ICPC National Invitational Collegiate Programming Contest, Wuhan Site

只需知道

$$
\bigoplus_{i=1}^{n}i =
\begin{cases}
n &\quad{n \bmod 4 = 0} \\
1 &\quad{n \bmod 4 = 1} \\
n+1 &\quad{n \bmod 4 = 2} \\
0 &\quad{n \bmod 4 = 3}
\end{cases}
$$

## [CF1890E1 Doremy's Drying Plan (Easy Version)](https://codeforces.com/contest/1890/problem/E1)

给出数轴上的一系列线段，通过优先队列在 $O(W \log n)$ 的时间内维护每个点被哪些线段所覆盖，其中 $W$ 为值域。

## [CF1436E Complicated Computations](https://codeforces.com/contest/1436/problem/E)

**枚举 mex**，问题转化成查询区间 mex，这是一个经典问题，可以用莫队或者主席树解决，[模板题](https://www.luogu.com.cn/problem/P4137)。

类似的题目还有 [Gym104768 Barkley II](https://codeforces.com/gym/104768/problem/I)，来源： 2023 China Collegiate Programming Contest (CCPC) Guilin Onsite
