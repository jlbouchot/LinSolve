LinSolvers
==========

This is a repository self contained and self implemented versions of some numerical linear algebra tools.
The idea behind it is to have an easy to use toolbox for learning computational tools. 
The audience in mind is first and foremost myself, used as a way to relearn C programming but keeping a use for teaching computational students some basic maths. 
With this in mind, I would expect math undergraduates to enjoy a bit of programming and gain a bit more experience with some of the numerical tools developed in class. 
On the other hand, computer science students might enjoy a bit more of exposition to numerical methods and scientific computing, surely a feature worth investigating to become a better and all-round computer scientist. 

This is by no means a commercial software. It is only done on my free time (which I have little). 
I will try to combine some of these tools with another one of my project which is developing vision systems on the edge, with real time solutions, which require fast optimisation algorithms and solvers. 
This justifies the use of C -- but obviously, I could go with anything else. The fun lies in the doing!


Includes
========

* Cholesky (LLtranspose) decomposition of a positive definite symmetric matrix.  (might require a bit more testing)
* Some math types (Matrix, Vector, what I call a Cholesky vector)

Soon to come
============

Based on the ideas developed in [this paper](https://publications.ics.forth.gr/_publications/0201-P0401-lourakis-levenberg.pdf), I intend to compare the Dogleg optimisation with a Levenberg Marquardt optimization in bundle adjustment (which is used in 3D vision).
Hence, the following topics will be included in the near future: 
* Dog leg optimisation 
* Basic gradient descent
* Levenberg Marquardt (non linear) least squares

For later 
=========

Soon after, I will look at various optimisation, among which: 
* Proximal methods for L1, Total variation
* Discrepancy methods
* GMRES, BiCG, CG and the likes
* [Multiplication less coordinate descent](https://sampta2019.sciencesconf.org/273591/document)

Notes
=====

This is developed using code::blocks and gcc / g++ compilers. 
The main file is a C++ calling underlying C-compiled solvers. 
The reason behind this is that I want to have access to some C++ library for some aspects of the final project (say OpenCV or scikit learn) while keeping the heavy computations / optimisation in C. 
While this is not necessary, it was and still is an interesting software engineering aspect which I had never done before and about which I was curious. 

This is released freely. It does not mean it is completely free from copyright. 
I would appreciate appropriate credit wherever credit is due and, why not, a little email saying how and where you used this: jlbmathit@gmail.com .
Similarly, should you have something in mind and wish me to work on it or contribute yourself, let me know!
