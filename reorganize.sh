#!/usr/bin/env bash
set -euo pipefail

# Reorganization script for ArifulHridoy/Numerical_LAB--CSE-2208-_Project
# Usage: run from the repository root. Example:
#   bash reorganize.sh
#
# This script:
#  - creates src/, include/, input_examples/, output_examples/ and method subfolders
#  - moves existing MainProject method folders into src/<normalized_name> using git mv
#  - writes include/all_includes.h (if not present)
#  - replaces README.md with the updated README (backing up the old README to README.md.bak)
#  - stages and commits changes (commit message below)
#
# If you don't want an automatic commit, comment out the git commit line near the end.

REPO_ROOT="$(pwd)"

# list of target method folder names (normalized)
declare -a METHODS=(
  "bisection"
  "false_position"
  "newton_raphson"
  "secant"
  "runge_kutta_4th"
  "gauss_elimination"
  "gauss_jordan"
  "doolittle"
  "matrix_inversion"
  "interpolation_newton_forward"
  "interpolation_newton_backward"
  "newton_divided_difference"
  "linear_regression"
  "transcendental_regression"
  "polynomial_regression"
  "simpson_1_3"
  "simpson_3_8"
)

echo "Creating top-level directories..."
mkdir -p src include input_examples output_examples

# create src subfolders
for m in "${METHODS[@]}"; do
  mkdir -p "src/${m}"
done

echo "Attempting to move existing MainProject folders into src/ (using git mv when possible)..."

# map of existing MainProject folder names (quoted) -> new normalized src folder
declare -A MAP
MAP["MainProject/Bisection"]="src/bisection"
MAP["MainProject/False Position"]="src/false_position"
MAP["MainProject/Newton Raphson"]="src/newton_raphson"
MAP["MainProject/Secant"]="src/secant"
MAP["MainProject/Runge Kutta 4th Order"]="src/runge_kutta_4th"
MAP["MainProject/Gauss Elimination"]="src/gauss_elimination"
MAP["MainProject/Gauss Jordan Elimination"]="src/gauss_jordan"
MAP["MainProject/Doolittle Method"]="src/doolittle"
MAP["MainProject/Matrix Inversion"]="src/matrix_inversion"

# Move using git mv if available, otherwise fallback to mv
for srcpath in "
${!MAP[@]}"; do
  dest="${MAP[$srcpath]}"
  if [ -d "$srcpath" ]; then
    echo "Moving '$srcpath' -> '$dest'"
    if git rev-parse --is-inside-work-tree >/dev/null 2>&1; then
      git mv -k "$srcpath" "$dest" || mv -f "$srcpath" "$dest"
    else
      mv -f "$srcpath" "$dest"
    fi
  else
    echo "Skipped: '$srcpath' does not exist."
  fi
done

# If there are other method folders in MainProject not covered above, attempt to move them all
if [ -d "MainProject" ]; then
  echo "Checking for any remaining folders in MainProject to move into src/ (attempting safe moves)..."
  for entry in "MainProject"/*; do
    [ -e "$entry" ] || continue
    base="$(basename "$entry")"
    # skip files already moved (if any)
    dest="src/$(echo "$base" | tr '[:upper:]' '[:lower:]' | tr ' ' '_' | tr -c '[:alnum:]_ ' '_')"
    if [ ! -d "$dest" ]; then
      mkdir -p "$dest"
    fi
    if [ -d "$entry" ]; then
      echo "Moving remaining folder '$entry' -> '$dest'"
      if git rev-parse --is-inside-work-tree >/dev/null 2>&1; then
        git mv -k "$entry" "$dest" || mv -f "$entry" "$dest"
      else
        mv -f "$entry" "$dest"
      fi
    fi
  done
fi

# create include/all_includes.h if not present
INCLUDE_FILE="include/all_includes.h"
if [ -f "$INCLUDE_FILE" ]; then
  echo "Include file $INCLUDE_FILE already exists — leaving it untouched."
else
  echo "Writing $INCLUDE_FILE (single header including <bits/stdc++.h>)..."
  cat > "$INCLUDE_FILE" <<'EOF'
#ifndef ALL_INCLUDES_H
#define ALL_INCLUDES_H

// Single header to include common C++ STL headers quickly.
// Note: bits/stdc++.h is non-standard but widely supported on GCC/Clang in Linux.
// Use specific includes for portability when you port to other toolchains.

#include <bits/stdc++.h>

#endif // ALL_INCLUDES_H
EOF
  if git rev-parse --is-inside-work-tree >/dev/null 2>&1; then
    git add "$INCLUDE_FILE"
  fi
fi

# Backup current README and write the approved README content
if [ -f README.md ]; then
  echo "Backing up current README.md -> README.md.bak"
  cp README.md README.md.bak
fi

echo "Writing updated README.md..."
cat > README.md <<'EOF'
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
EOF

# Stage changes (if git repo)
if git rev-parse --is-inside-work-tree >/dev/null 2>&1; then
  echo "Staging changes..."
  git add README.md include/all_includes.h || true
  # Add newly moved folders (git mv already staged them)
git add src || true
git add input_examples output_examples || true

  echo "Committing changes..."
  git commit -m "Reorganize project structure: move MainProject methods into src/, add include/all_includes.h, update README" || echo "Nothing to commit or commit failed."
  echo "Done. Please push with: git push"
else
  echo "Not a git repository — created files and moved folders but did not commit."
fi

echo "Reorganization script completed."