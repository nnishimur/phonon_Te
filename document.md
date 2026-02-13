# Block diagonalization of the dynamical matrix by crystal angular momentum (CAM)
Due to screw symmetry, the following equation holds for the dynamical matrix
$\underline{V}_{L,1}(k_z)$.
$$\underline{V}_{L,1}(k_z)
=\underline{C}_3\underline{V}_{L,1}(k_z)\underline{C}_3^{\mathrm{T}}$$
Here, $\underline{C}_3$ can be written as
$\underline{C}_3
=T\otimes C_3$
using the following translation
$T$
and 3-fold rotation
$C_3$.
$$T = \left(
\begin{matrix} 
0&0&1\\
1&0&0\\
0&1&0
\end{matrix} 
\right)$$
$$C_3 = \left(
\begin{matrix} 
\cos(2\pi/3)&-\sin(2\pi/3)&0\\
\sin(2\pi/3)&\cos(2\pi/3)&0\\
0&0&1
\end{matrix} 
\right)$$
Let $\zeta=e^{2\pi i/3}$.
The eigenvectors of $T$ are
$$
u_0=
\left(
\begin{matrix} 
1/\sqrt{3}\\1/\sqrt{3}\\1/\sqrt{3}
\end{matrix} 
\right)
~~~~
(\text{eigenvalue is}~1),
$$
$$
u_1=
\left(
\begin{matrix} 
1/\sqrt{3}\\\zeta^{-1}/\sqrt{3}\\\zeta/\sqrt{3}
\end{matrix} 
\right)
~~~~
(\text{eigenvalue is}~\zeta),
$$
$$
u_2=
\left(
\begin{matrix}
1/\sqrt{3}\\\zeta/\sqrt{3}\\\zeta^{-1}/\sqrt{3}
\end{matrix} 
\right)
~~~~
(\text{eigenvalue is}~\zeta^{-1}).
$$
The eigenvectors of $C_3$ are
$$
w_0=
\left(
\begin{matrix} 
0\\0\\1
\end{matrix} 
\right)
~~~~
(\text{eigenvalue is}~1),
$$
$$
w_1=
\left(
\begin{matrix} 
1/\sqrt{2}\\-i/\sqrt{2}\\0
\end{matrix} 
\right)
~~~~
(\text{eigenvalue is}~\zeta),
$$
$$
w_2=
\left(
\begin{matrix} 
1/\sqrt{2} \\i/\sqrt{2}\\0
\end{matrix} 
\right)
~~~~
(\text{eigenvalue is}~\zeta^{-1}).
$$
From these, the eigenvectors of
$\underline{C}_3
=T\otimes C_3$
can be constructed.
$$
u_0\otimes w_0,~
u_1\otimes w_2,~
u_2\otimes w_1~~~~
(\text{eigenvalue is}~1)
$$
$$
u_0\otimes w_1,~
u_1\otimes w_0,~
u_2\otimes w_2~~~~
(\text{eigenvalue is}~\zeta)
$$
$$
u_0\otimes w_2,~
u_1\otimes w_1,~
u_2\otimes w_0~~~~
(\text{eigenvalue is}~\zeta^{-1})
$$
Since these eigenvectors form an orthonormal system, the matrix
$$
P=\left(
\begin{matrix} 
u_0\otimes w_0&
u_1\otimes w_2&
u_2\otimes w_1&
u_0\otimes w_1&
u_1\otimes w_0&
u_2\otimes w_2&
u_0\otimes w_2&
u_1\otimes w_1&
u_2\otimes w_0
\end{matrix} 
\right)
$$
is a unitary matrix.
Using this,
$\underline{C}_3$
can be diagonalized as
$$
P^\dagger\underline{C}_3P
=\left(
\begin{matrix} 
I&O&O\\
O&\zeta I&O\\
O&O&\zeta^{-1}I
\end{matrix} 
\right).
$$
Here,
$$
I=\left(
\begin{matrix} 
1&0&0\\
0&1&0\\
0&0&1
\end{matrix} 
\right),~
O=\left(
\begin{matrix} 
0&0&0\\
0&0&0\\
0&0&0
\end{matrix} 
\right).
$$
The eigenvalues
$1, \zeta, \zeta^{-1}$
of
$\underline{C}_3$
correspond to the crystal angular momenta (CAM)
$m=0, 1, -1$.
Since
$\underline{V}_{L,1}(k_z)$
and
$\underline{C}_3$
commute,
$\underline{V}_{L,1}(k_z)$
can be block diagonalized using
$P$
as
$$
P^\dagger\underline{V}_{L,1}(k_z)P
=\left(
\begin{matrix} 
D_0&O&O\\
O&D_1&O\\
O&O&D_2
\end{matrix} 
\right).
$$
