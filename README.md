#  Numerical Methods in C++

##  Overview

Numerical Methods are mathematical techniques used to **approximate solutions** to problems that may not have exact analytical solutions. They are widely used in engineering, physics, computer science and many applied fields.

This project is a collection of classical **Numerical Methods implemented in C++**, organized for easy learning and practical use. Each method includes:

- **A C++ implementation** demonstrating the algorithm  
- **A text explanation** detailing the steps, formulas, and sample problems  

The project covers these areas:

1. **Non-Linear Equation Solving (Root-Finding Methods):** Bisection, False Position, Newton-Raphson, Secant  
2. **Linear Algebra Methods:** Gauss Elimination, Gauss-Jordan Elimination, LU Decomposition (Doolittle), Matrix Inversion  
3. **Differential Equation Solvers:** Runge-Kutta 4th Order (RK4)
4. **Interpolation Methods:** Newton Forward, Newton Backward, Newton Divided Difference
5. **Curve Fitting Methods:** Linear Regression, Polynomial Regression, Transcendental Regression
6. **Numerical Differentiation:** Forward Interpolation Differentiation, Backward Interpolation Differentiation
7. **Numerical Integration Methods:** Simpson's 1/3 Rule, Simpson's 3/8 Rule

This repository contains C++ implementations of popular **Numerical Methods**.  
Each method has its own folder containing:

##  Folder Structure

Each folder includes:
- `method.cpp`  C++ Implementation  
- `method.txt`  Explanation / Notes  
- Example input files are in `input.txt/`  
- Example output files are in `output.txt/`  

Top-level layout:
- src/
  - Bisection/
  - False Position/
  - Newton Raphson/
  - Secant/
  - Runge Kutta 4th Order/
  - Gauss Elimination/
  - Gauss Jordan Elimination/
  - LU Decomposition/
  - Matrix Inversion/
  - Newton Forward Interpolation/
  - Newton Backward Interpolation/
  - Newton Divided Difference Interpolation/
  - Differentiation by Forward Interpolation/
  - Differentiation by Backward Interpolation/
  - Linear Regression/
  - Polynomial Regression/
  - Transcendental Regression/
  - Simpson 1_3/
  - Simpson 3_8/
- include/


##  Numerical Methods

<details>
<summary><strong><span style="font-size:20px;">Non-Linear Equation Solving</span></strong></summary>

-  [Bisection Method](./src/Bisection)  
-  [False Position (Regula Falsi)](./src/False%20Position)  
-  [Newton Raphson Method](./src/Newton%20Raphson)  
-  [Secant Method](./src/Secant)
</details>

<details>
<summary><strong><span style="font-size:20px;">Linear Equation Solving</span></strong></summary>

-  [Gauss Elimination](./src/Gauss%20Elimination)  
-  [Gauss-Jordan Elimination](./src/Gauss%20Jordan%20Elimination)  
-  [LU Decomposition (Doolittle Method)](./src/LU%20Decomposition)  
-  [Matrix Inversion](./src/Matrix%20Inversion)
</details>

<details>
<summary><strong><span style="font-size:20px;">Differential Equation Solving</span></strong></summary>

-  [Runge-Kutta 4th Order (RK4)](./src/Runge%20Kutta%204th%20Order)
</details>

<details>
<summary><strong><span style="font-size:20px;">Interpolation Methods</span></strong></summary>

-  [Newton''s Forward Interpolation](./src/Newton%20Forward%20Interpolation)  
-  [Newton''s Backward Interpolation](./src/Newton%20Backwardward%20Interpolation)  
-  [Newton''s Divided Difference Interpolation](./src/Newton%20Divided%20Difference%20Interpolation)
</details>

<details>
<summary><strong><span style="font-size:20px;">Numerical Differentiation</span></strong></summary>

-  [Differentiation by Forward Interpolation](./src/Differentiation%20by%20Forward%20Interpolation)  
-  [Differentiation by Backward Interpolation](./src/Differentiation%20by%20Backward%20Interpolation)
</details>

<details>
<summary><strong><span style="font-size:20px;">Curve Fitting / Regression Methods</span></strong></summary>

-  [Linear Regression](./src/Linear%20Regression)  
-  [Polynomial Regression](./src/Polynomial%20Regression)  
-  [Transcendental Regression](./src/Trancendental%20Regression)
</details>

<details>
<summary><strong><span style="font-size:20px;">Numerical Integration Methods</span></strong></summary>

-  [Simpson''s 1/3 Rule](./src/Simpson%201_3)  
-  [Simpson''s 3/8 Rule](./src/Simpson%203_8)
</details>

##  Purpose of This Repository
- Provide **clean C++ codes** for numerical methods. 
- Serve as a **learning resource & simulation** for Numerical Methods   
- Combine all classical numerical methods in one project.  

##  Author
**1. Md. Toufiq Hasan & Roll : 2207049**  
**2. Shahriar Abdullah & Roll : 2207050**  
**3. Ariful Islam Sheikh & Roll : 2207051**
