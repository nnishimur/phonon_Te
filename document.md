# Block diagonalization of the dynamical matrix by crystal angular momentum (CAM)
Due to screw symmetry, the following equation holds for the dynamical matrix
$\underline{V} _ {L,1}(k _ z)$.
$$\underline{V} _ {L,1}(k _ z)
=\underline{C} _ 3\underline{V} _ {L,1}(k _ z)\underline{C} _ 3^{\mathrm{T}}$$
Here, $\underline{C} _ 3$ can be written as
$\underline{C} _ 3
=T\otimes C _ 3$
using the following translation
$T$
and 3-fold rotation
$C _ 3$.
$$T = \left(
\begin{matrix} 
0&0&1\newline
1&0&0\newline
0&1&0
\end{matrix} 
\right)\newline
C _ 3 = \left(
\begin{matrix} 
\cos(2\pi/3)&-\sin(2\pi/3)&0\newline
\sin(2\pi/3)&\cos(2\pi/3)&0\newline
0&0&1
\end{matrix} 
\right)$$
Let $\zeta=e^{2\pi i/3}$.
The eigenvectors of $T$ are
$$
u _ 0=
\left(
\begin{matrix} 
1/\sqrt{3}\newline1/\sqrt{3}\newline1/\sqrt{3}
\end{matrix} 
\right)
~~~~
(\text{eigenvalue is}~1),
$$
$$
u _ 1=
\left(
\begin{matrix} 
1/\sqrt{3}\newline\zeta^{-1}/\sqrt{3}\newline\zeta/\sqrt{3}
\end{matrix} 
\right)
~~~~
(\text{eigenvalue is}~\zeta),
$$
$$
u _ 2=
\left(
\begin{matrix}
1/\sqrt{3}\newline\zeta/\sqrt{3}\newline\zeta^{-1}/\sqrt{3}
\end{matrix} 
\right)
~~~~
(\text{eigenvalue is}~\zeta^{-1}).
$$
The eigenvectors of $C _ 3$ are
$$
w _ 0=
\left(
\begin{matrix} 
0\newline0\newline1
\end{matrix} 
\right)
~~~~
(\text{eigenvalue is}~1),
$$
$$
w _ 1=
\left(
\begin{matrix} 
1/\sqrt{2}\newline-i/\sqrt{2}\newline0
\end{matrix} 
\right)
~~~~
(\text{eigenvalue is}~\zeta),
$$
$$
w _ 2=
\left(
\begin{matrix} 
1/\sqrt{2} \newline i/\sqrt{2}\newline0
\end{matrix} 
\right)
~~~~
(\text{eigenvalue is}~\zeta^{-1}).
$$
From these, the eigenvectors of
$\underline{C} _ 3
=T\otimes C _ 3$
can be constructed.
$$
u _ 0\otimes w _ 0,~
u _ 1\otimes w _ 2,~
u _ 2\otimes w _ 1~~~~
(\text{eigenvalue is}~1)
$$
$$
u _ 0\otimes w _ 1,~
u _ 1\otimes w _ 0,~
u _ 2\otimes w _ 2~~~~
(\text{eigenvalue is}~\zeta)
$$
$$
u _ 0\otimes w _ 2,~
u _ 1\otimes w _ 1,~
u _ 2\otimes w _ 0~~~~
(\text{eigenvalue is}~\zeta^{-1})
$$
Since these eigenvectors form an orthonormal system, the matrix
$$
P=\left(
\begin{matrix} 
u _ 0\otimes w _ 0&
u _ 1\otimes w _ 2&
u _ 2\otimes w _ 1&
u _ 0\otimes w _ 1&
u _ 1\otimes w _ 0&
u _ 2\otimes w _ 2&
u _ 0\otimes w _ 2&
u _ 1\otimes w _ 1&
u _ 2\otimes w _ 0
\end{matrix} 
\right)
$$
is a unitary matrix.
Using this,
$\underline{C} _ 3$
can be diagonalized as
$$
P^\dagger\underline{C} _ 3P
=\left(
\begin{matrix} 
I&O&O\newline
O&\zeta I&O\newline
O&O&\zeta^{-1}I
\end{matrix} 
\right).
$$
Here,
$$
I=\left(
\begin{matrix} 
1&0&0\newline
0&1&0\newline
0&0&1
\end{matrix} 
\right),~
O=\left(
\begin{matrix} 
0&0&0\newline
0&0&0\newline
0&0&0
\end{matrix} 
\right).
$$
The eigenvalues
$1, \zeta, \zeta^{-1}$
of
$\underline{C} _ 3$
correspond to the crystal angular momenta (CAM)
$m=0, 1, -1$.
Since
$\underline{V} _ {L,1}(k _ z)$
and
$\underline{C} _ 3$
commute,
$\underline{V} _ {L,1}(k _ z)$
can be block diagonalized using
$P$
as
$$
P^\dagger\underline{V} _ {L,1}(k _ z)P
=\left(
\begin{matrix} 
D _ 0&O&O\newline
O&D _ 1&O\newline
O&O&D _ 2
\end{matrix} 
\right).
$$
