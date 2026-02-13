# Block diagonalization of the dynamical matrix using crystal angular momentum (CAM)
Due to screw symmetry, the dynamical matrix $\underline{V}_{L,1}(k_z)$ satisfies the following relation:

$$
\underline{V} _ {L,1}(k _ z)
=\underline{C} _ 3\underline{V} _ {L,1}(k _ z)\underline{C} _ 3^{\mathrm{T}}
$$

or equivalently,

$$
\underline{V} _ {L,1}(k _ z)\underline{C} _ 3
=\underline{C} _ 3\underline{V} _ {L,1}(k _ z).
$$

Here,
$\underline{C} _ 3$
is screw operation defined as follows:

$$\underline{C} _ 3 = 
\begin{pmatrix} 
O&O&C _ 3\newline
C _ 3&O&O\newline
O&C _ 3&O
\end{pmatrix}.
$$

$\underline{C} _ 3$
is an orthogonal matrix expressed as
$\underline{C} _ 3 = T\otimes C _ 3$,
where
$T$
is the translation matrix and 
$C _ 3$
is the 3-fold rotation matrix, defined as follows:

$$T = 
\begin{pmatrix} 
0&0&1\newline
1&0&0\newline
0&1&0
\end{pmatrix},
$$

$$
C _ 3 =
\begin{pmatrix} 
\cos(2\pi/3)&-\sin(2\pi/3)&0\newline
\sin(2\pi/3)&\cos(2\pi/3)&0\newline
0&0&1
\end{pmatrix}.
$$

Let $\zeta=e^{2\pi i/3}$.
The eigenvectors of $T$ are given by:

$$
u _ 0=
\begin{pmatrix} 
1/\sqrt{3}\newline1/\sqrt{3}\newline1/\sqrt{3}
\end{pmatrix} 
\quad
(\text{eigenvalue is}\quad1),
$$

$$
u _ 1=
\begin{pmatrix} 
1/\sqrt{3}\newline\zeta^{-1}/\sqrt{3}\newline\zeta/\sqrt{3}
\end{pmatrix} 
\quad
(\text{eigenvalue is}\quad\zeta),
$$

$$
u _ 2=
\begin{pmatrix}
1/\sqrt{3}\newline\zeta/\sqrt{3}\newline\zeta^{-1}/\sqrt{3}
\end{pmatrix} 
\quad
(\text{eigenvalue is}\quad\zeta^{-1}).
$$

The eigenvectors of $C_3$ are given by:

$$
w _ 0=
\begin{pmatrix} 
0\newline0\newline1
\end{pmatrix} 
\quad
(\text{eigenvalue is}\quad1),
$$

$$
w _ 1=
\begin{pmatrix} 
1/\sqrt{2}\newline-i/\sqrt{2}\newline0
\end{pmatrix} 
\quad
(\text{eigenvalue is}\quad\zeta),
$$

$$
w _ 2=
\begin{pmatrix} 
1/\sqrt{2} \newline i/\sqrt{2}\newline0
\end{pmatrix} 
\quad
(\text{eigenvalue is}\quad\zeta^{-1}).
$$

From these, we can construct the eigenvectors of $\underline{C} _ 3 = T\otimes C _ 3$:

$$
u _ 0\otimes w _ 0,\quad
u _ 1\otimes w _ 2,\quad
u _ 2\otimes w _ 1\quad
(\text{eigenvalue is}\quad1)
$$

$$
u _ 0\otimes w _ 1,\quad
u _ 1\otimes w _ 0,\quad
u _ 2\otimes w _ 2\quad
(\text{eigenvalue is}\quad\zeta)
$$

$$
u _ 0\otimes w _ 2,\quad
u _ 1\otimes w _ 1,\quad
u _ 2\otimes w _ 0\quad
(\text{eigenvalue is}\quad\zeta^{-1})
$$

Since these eigenvectors form an orthonormal basis, the matrix

$$
P=
\begin{pmatrix} 
u _ 0\otimes w _ 0&
u _ 1\otimes w _ 2&
u _ 2\otimes w _ 1&
u _ 0\otimes w _ 1&
u _ 1\otimes w _ 0&
u _ 2\otimes w _ 2&
u _ 0\otimes w _ 2&
u _ 1\otimes w _ 1&
u _ 2\otimes w _ 0
\end{pmatrix} 
$$

is unitary.
Using this matrix,
$\underline{C} _ 3$
can be diagonalized as:

$$
P^\dagger\underline{C} _ 3P
=\begin{pmatrix} 
I&O&O\newline
O&\zeta I&O\newline
O&O&\zeta^{-1}I
\end{pmatrix}.
$$

The eigenvalues
$1, \zeta, \zeta^{-1}$
of
$\underline{C}_3$
correspond to the crystal angular momenta (CAM)
$m=0, 1, -1$,
respectively.
Since
$\underline{V} _ {L,1}(k _ z)$
and
$\underline{C} _ 3$
commute,
$\underline{V} _ {L,1}(k _ z)$
can be block-diagonalized using
$P$
as follows:

$$
P^\dagger\underline{V} _ {L,1}(k _ z)P
=\begin{pmatrix} 
D _ 0&O&O\newline
O&D _ 1&O\newline
O&O&D _ 2
\end{pmatrix}.
$$
