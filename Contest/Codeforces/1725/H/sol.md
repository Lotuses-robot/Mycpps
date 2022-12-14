# sol for 1725H 

有一个显然的结论

$\forall a_i, a_j, \operatorname{concat}(a_i, a_j)\equiv\operatorname{concat}(a_j, a_i) \pmod 3$  

可以感性理解：$a_i$ 与 $a_j$ 各位之和唯一，余数是与之相同的，那么必然同余。

>  那么就有 $\operatorname{concat}(a_i, a_j)\times\operatorname{concat}(a_j, a_i) \equiv (0,1) \pmod 3$，因为 $2^2= 4 \to 4 \bmod 3 = 1$。

这里想歪了没有得到一般性结论；

应该是 原式与 $(a_i + a_j) ^ 2 + a_i\times a_j$ 同余

所以对于 $a_i$ 与 $a_j$ 同余不同的情况来分类讨论

| Z 的值 |  0   |  1   |  2   |
| :----: | :--: | :--: | :--: |
|   0    |  0   |  1   |  1   |
|   1    |  1   |  2   |  2   |
|   2    |  1   |  2   |  2   |

此时发现 $Z$ 取 $0, 1, 2$ 都有可能，所以如何选择 $Z$ 呢？

题目还有颜色机制。

所以当 $\{a\}$ 中 $|0| \le n/2$ 把所有 $0$ 放进一组里，可以发现 $0$ 与 $0$ 就发生不了反应了， 而且 $Z$ 的取值中只有 $0,0$ 组合才能凑出 $0$，此时选 $Z = 0$；

又当 $|0| > n/2$ 时，可以直接选 $Z = 2$ ，将 $0$ 放满一个颜色，那么就只有 $0$ 能与其他数发生反应，不可能出现 $2$。

所以必然可以；；；；；无 $-1$ 情况 $lol$

