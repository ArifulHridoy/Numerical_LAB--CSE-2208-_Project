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
  <summary><h3>📊 Non-Linear Equation Solving</h3></summary>
  <details>
    <summary><strong>Bisection Method</strong></summary>

-  [Report](./src/Bisection/Bisection.txt) 

-  [Cpp Code](./src/Bisection/Bisection.cpp) 

-  [Input](./src/Bisection/Input.txt) 

-  [Output](./src/Bisection/Output.txt) 

</details> <details> <summary><strong>False Position (Regula Falsi)</strong></summary>

-  [Report](./src/False%20Position/falsePosition.txt) 

-  [Cpp Code](./src/False%20Position/falsePosition.cpp) 

-  [Input](./src/False%20Position/Input.txt) 

-  [Output](./src/False%20Position/Output.txt)

</details> <details> <summary><strong>Newton Raphson Method</strong></summary>

-  [Report](./src/Newton%20Raphson/NewtonRaphson.txt) 

-  [Cpp Code](./src/Newton%20Raphson/NewtonRaphson.cpp) 

-  [Input](./src/Newton%20Raphson/Input.txt) 

-  [Output](./src/Newton%20Raphson/Output.txt)

</details> <details> <summary><strong>Secant Method</strong></summary>

-  [Report](./src/Secant/Secant.txt) 

-  [Cpp Code](./src/Secant/Secant.cpp) 

-  [Input](./src/Secant/Input.txt) 

-  [Output](./src/Secant/Output.txt)

</details> </details>


<details> <summary><h3>🔢 Linear Equation Solving</h3></summary> <details> <summary><strong>Gauss Elimination</strong></summary>

-  [Report](./src/Gauss%20Elimination/Gauss%20Elimination.txt) 

-  [Cpp Code](./src/Gauss%20Elimination/GaussElimination.cpp) 

-  [Input](./src/Gauss%20Elimination/Input.txt) 

-  [Output](./src/Gauss%20Elimination/Output.txt)

</details> <details> <summary><strong>Gauss-Jordan Elimination</strong></summary>

-  [Report](./src/Gauss%20Jordan%20Elimination/GaussJordanElimination.txt) 

-  [Cpp Code](./src/Gauss%20Jordan%20Elimination/GaussJordanElimination.cpp) 

-  [Input](./src/Gauss%20Jordan%20Elimination/Input.txt) 

-  [Output](./src/Gauss%20Jordan%20Elimination/Output.txt)

</details> <details> <summary><strong>LU Decomposition (Doolittle Method)</strong></summary>

-  [Report](./src/LU%20Decomposition/DoolittleMethod.txt) 

-  [Cpp Code](./src/LU%20Decomposition/DoolittleMethod.cpp) 

-  [Input](./src/LU%20Decomposition/Input.txt) 

-  [Output](./src/LU%20Decomposition/Output.txt)

</details> <details> <summary><strong>Matrix Inversion</strong></summary>

-  [Report](./src/Matrix%20Inversion/MatrixInversion.txt) 

-  [Cpp Code](./src/Matrix%20Inversion/MatrixInversion.cpp) 

-  [Input](./src/Matrix%20Inversion/Input.txt) 

-  [Output](./src/Matrix%20Inversion/Output.txt)

</details> </details>


<details> <summary><h3>🧮 Differential Equation Solving</h3></summary> <details> <summary><strong>Runge-Kutta 4th Order (RK4)</strong></summary>

-  [Report](./src/Runge%20Kutta%204th%20Order/RungeKutta4thOrder.txt) 

-  [Cpp Code](./src/Runge%20Kutta%204th%20Order/RungeKutta4thOrder.cpp) 

-  [Input](./src/Runge%20Kutta%204th%20Order/Input.txt) 

-  [Output](./src/Runge%20Kutta%204th%20Order/Output.txt)

</details> </details>


<details> <summary><h3>📈 Interpolation Methods</h3></summary> <details> <summary><strong>Newton's Forward Interpolation</strong></summary>

-  [Report](./src/Newton%20Forward%20Interpolation/NewtonForwardInterpolation.txt) 

-  [Cpp Code](./src/Newton%20Forward%20Interpolation/NewtonForwardInterpolation.cpp) 

-  [Input](./src/Newton%20Forward%20Interpolation/Input.txt) 

-  [Output](./src/Newton%20Forward%20Interpolation/Output.txt)

</details> <details> <summary><strong>Newton's Backward Interpolation</strong></summary>

-  [Report](./src/Newton%20Backwardward%20Interpolation/NewtonBackwardwardInterpolation.txt) 

-  [Cpp Code](./src/Newton%20Backwardward%20Interpolation/NewtonBackwardwardInterpolation.cpp) 

-  [Input](./src/Newton%20Backwardward%20Interpolation/Input.txt) 

-  [Output](./src/Newton%20Backwardward%20Interpolation/Output.txt)

</details> <details> <summary><strong>Newton's Divided Difference Interpolation</strong></summary>

-  [Report](./src/Newton%20Divided%20Difference%20Interpolation/NewtonDividedDifferenceInterpolation.txt) 

-  [Cpp Code](./src/Newton%20Divided%20Difference%20Interpolation/NewtonDividedDifferenceInterpolation.cpp) 

-  [Input](./src/Newton%20Divided%20Difference%20Interpolation/Input.txt) 

-  [Output](./src/Newton%20Divided%20Difference%20Interpolation/Output.txt)

</details> </details>


<details> <summary><h3>📐 Numerical Differentiation</h3></summary> <details> <summary><strong>Differentiation by Forward Interpolation</strong></summary>

-  [Report](./src/Differentiation%20by%20Forward%20Interpolation/DifferentiationForward.txt) 

-  [Cpp Code](./src/Differentiation%20by%20Forward%20Interpolation/DifferentiationForward.cpp) 

-  [Input](./src/Differentiation%20by%20Forward%20Interpolation/Input.txt) 

-  [Output](./src/Differentiation%20by%20Forward%20Interpolation/Output.txt)

</details> <details> <summary><strong>Differentiation by Backward Interpolation</strong></summary>

-  [Report](./src/Differentiation%20by%20Backward%20Interpolation/DifferentiationBackward.txt) 

-  [Cpp Code](./src/Differentiation%20by%20Backward%20Interpolation/DifferentiationBackward.cpp) 

-  [Input](./src/Differentiation%20by%20Backward%20Interpolation/Input.txt) 

-  [Output](./src/Differentiation%20by%20Backward%20Interpolation/Output.txt)

</details> </details>


<details> <summary><h3>📉 Curve Fitting / Regression</h3></summary> <details> <summary><strong>Linear Regression</strong></summary>

-  [Report](./src/Linear%20Regression/linearRegression.txt) 

-  [Cpp Code](./src/Linear%20Regression/linearRegression.cpp) 

-  [Input](./src/Linear%20Regression/Input.txt) 

-  [Output](./src/Linear%20Regression/Output.txt)

</details> <details> <summary><strong>Polynomial Regression</strong></summary>

-  [Report](./src/Polynomial%20Regression/PolynomialRegression.txt) 

-  [Cpp Code](./src/Polynomial%20Regression/PolynomialRegression.cpp) 

-  [Input](./src/Polynomial%20Regression/Input.txt) 

-  [Output](./src/Polynomial%20Regression/Output.txt)

</details> <details> <summary><strong>Transcendental Regression</strong></summary>

-  [Report](./src/Trancendental%20Regression/TrancendentalRegression.txt) 

-  [Cpp Code](./src/Trancendental%20Regression/TrancendentalRegression.cpp) 

-  [Input](./src/Trancendental%20Regression/Input.txt) 

-  [Output](./src/Trancendental%20Regression/Output.txt)

</details> </details>


<details> <summary><h3>∫ Numerical Integration</h3></summary> <details> <summary><strong>Simpson's 1/3 Rule</strong></summary>

-  [Report](./src/Simpson%201_3/Simpson1_3.txt) 

-  [Cpp Code](./src/Simpson%201_3/Simpson1_3.cpp) 

-  [Input](./src/Simpson%201_3/Input.txt) 

-  [Output](./src/Simpson%201_3/Output.txt)

</details> <details> <summary><strong>Simpson's 3/8 Rule</strong></summary>

-  [Report](./src/Simpson%203_8/Simpson3_8.txt) 

-  [Cpp Code](./src/Simpson%203_8/Simpson3_8.cpp) 

-  [Input](./src/Simpson%203_8/Input.txt) 

-  [Output](./src/Simpson%203_8/Output.txt)

</details> </details>

##  Purpose of This Repository
- Provide **clean C++ codes** for numerical methods. 
- Serve as a **learning resource & simulation** for Numerical Methods   
- Combine all classical numerical methods in one project.  

##  Author
**1. Md. Toufiq Hasan & Roll : 2207049**  
**2. Shahriar Abdullah & Roll : 2207050**  
**3. Ariful Islam Sheikh & Roll : 2207051**
