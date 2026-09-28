# Data Structures Laboratory (DSL-1)

A collection of foundational data structures and algorithm implementations written in **C** and **C++**. This repository covers core linear data structures, classical matrix operations, sparse matrix representations, expression conversions, and basic searching techniques.

---

## Repository Structure

```text
├── Matrices & Sparse Representations
│   ├── addorsubofmatrix.cpp        # Matrix addition and subtraction
│   ├── multiplicationofmatrix.cpp   # Standard matrix multiplication
│   ├── transposeofmatrix.cpp       # Matrix transposition
│   ├── compact_matrix.c            # Sparse matrix triplet representation
│   ├── simple_transpose.c          # Simple transpose of a sparse matrix
│   ├── fast_transpose.c            # Fast transpose of a sparse matrix (O(cols + non-zeros))
│   └── Addofsparsematrix.cpp       # Addition of two sparse matrices
│
├── Stacks & Expression Parsing
│   ├── stack.c                     # Array-based stack implementation (Push, Pop, Peek)
│   ├── infixtopostfix.c            # Infix to Postfix expression conversion
│   ├── infixtoprefix.c             # Infix to Prefix expression conversion
│   ├── postfixtoinfix.c            # Postfix to Infix expression conversion
│   └── prefixtoinfix.c             # Prefix to Infix expression conversion
│
├── Queues
│   └── linear_queue.c              # Linear queue implementation (Enqueue, Dequeue)
│
└── Algorithms
    └── search.c                    # Linear and binary search implementations
