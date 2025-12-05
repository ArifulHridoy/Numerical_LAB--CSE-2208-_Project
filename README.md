# 📘 Numerical Methods in C++

## 📖 Overview

Numerical Methods are mathematical techniques used to **approximate solutions** to problems that may not have exact analytical solutions. They are widely used in engineering, physics, computer science and many applied fields.

This project is a collection of classical **Numerical Methods implemented in C++**, organized for easy learning and practical use. Each method includes:

- **A C++ implementation** demonstrating the algorithm  
- **A text explanation** detailing the steps, formulas, and sample problems  

The project covers three main areas:

1. **Non-Linear Equation Solving (Root-Finding Methods):** Bisection, False Position, Newton-Raphson, Secant  
2. **Linear Algebra Methods:** Gauss Elimination, Gauss-Jordan Elimination, Doolittle (LU Decomposition), Matrix Inversion  
3. **Differential Equation Solvers:** Runge-Kutta 4th Order (RK4)  

This repository contains C++ implementations of popular **Numerical Methods**.  
Each method has its own folder containing:

## 📁 Folder Structure

Each folder includes:
- `method.cpp` → C++ Implementation  
- `method.txt` → Explanation / Notes  
- Example input files are in `input_examples/`  
- Example output files are in `output_examples/`  

Top-level layout:
- src/
  - bisection
  - false_position
  - newton_raphson
  - secant
  - runge_kutta_4th
  - gauss_elimination
  - gauss_jordan
  - doolittle
  - matrix_inversion
  - interpolation_newton_forward
  - interpolation_newton_backward
  - newton_divided_difference
  - linear_regression
  - transcendental_regression
  - polynomial_regression
  - simpson_1_3
  - simpson_3_8
- include/
- input_examples/
- output_examples/

All `.cpp` files can **take input from a file** and **write output into a file**.

## 🔢 Numerical Methods

<details>
<summary><strong><span style="font-size:20px;">Non-Linear Equation Solve</span></strong></summary>

- ▶ [Bisection](./src/bisection)  
- ▶ [False Position (Regula Falsi)](./src/false_position)  
- ▶ [Newton Raphson](./src/newton_raphson)  
- ▶ [Secant Method](./src/secant)
</details>

<details>
<summary><strong><span style="font-size:20px;">Linear Equation Solve</span></strong></summary>

- ▶ [Gauss Elimination](./src/gauss_elimination)  
- ▶ [Gauss Jordan Elimination](./src/gauss_jordan)  
- ▶ [Doolittle Method (LU Decomposition)](./src/doolittle)  
- ▶ [Matrix Inversion](./src/matrix_inversion)
</details>

<details>
<summary><strong><span style="font-size:20px;">Differential Equation Solve</span></strong></summary>

- ▶ [Runge Kutta 4th Order (RK4)](./src/runge_kutta_4th)
</details>

<details>
<summary><strong><span style="font-size:20px;">Interpolation Methods</span></strong></summary>

- ▶ [Newton’s Forward Interpolation](./src/interpolation_newton_forward)  
- ▶ [Newton’s Backward Interpolation](./src/interpolation_newton_backward)  
- ▶ [Newton’s Divided Difference Method](./src/newton_divided_difference)
</details>

<details>
<summary><strong><span style="font-size:20px;">Curve Fitting / Regression Methods</span></strong></summary>

- ▶ [Linear Regression](./src/linear_regression)  
- ▶ [Transcendental Regression](./src/transcendental_regression)  
- ▶ [Polynomial Regression](./src/polynomial_regression)
</details>

<details>
<summary><strong><span style="font-size:20px;">Numerical Integration Methods</span></strong></summary>

- ▶ [Simpson’s 1/3 Rule](./src/simpson_1_3)  
- ▶ [Simpson’s 3/8 Rule](./src/simpson_3_8)
</details>

## 🎯 Purpose of This Repository
- Provide **clean C++ codes** for numerical methods. 
- Serve as a **learning resource & simulation** for Numerical Methods   
- Combine all classical numerical methods in one project.  

## 👨‍💻 Author
**1. Md. Toufiq Hasan & Roll : 2207049**  
**2. Shahriar Abdullah & Roll : 2207050**  
**3. Ariful Islam Sheikh & Roll : 2207051**
