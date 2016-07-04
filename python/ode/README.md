# 二階常微分方程式

物理の問題として、二階の常微分方程式
$$\frac{d^2 x}{dt^2} + \gamma \frac{dx}{dt} + \omega^2 x = \epsilon f(t)$$

は頻出の問題である．odeintを用いて解く際には一階の微分方程式
$$\begin{split}\dot{x} &= p\\ \dot{p} &= -\gamma \dot{x} - \omega^2 x + \epsilon f(t)\end{split}$$

と変形して取り扱う方がよいであろう．

本例題では外力として
$$f(t) = \cos(\omega_2 t)$$

の強制振動を考える．


## 1
NonAuto:  $\dot{x}=NonAuto(x)$

