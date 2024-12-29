# 🌟 Dynamic Programming (DP) Guide  

Dynamic Programming (DP) is a powerful optimization technique that solves complex problems by breaking them down into smaller, overlapping subproblems and solving each only once.  

---

## 🚀 Key Concepts  

### 1. Overlapping Subproblems  
Problems that solve the same subproblems multiple times.  
- **Example**: Fibonacci sequence, where `Fib(n) = Fib(n-1) + Fib(n-2)`.  

### 2. Optimal Substructure  
Solutions can be constructed using the solutions of its subproblems.  
- **Example**: Shortest path in a graph (Dijkstra, Bellman-Ford).  

### 3. Memoization (Top-Down Approach)  
- Recursive method that stores previously computed results to avoid recomputation.  

### 4. Tabulation (Bottom-Up Approach)  
- Iterative method that solves all smaller subproblems first.  

---

## 🛠️ Steps to Solve a DP Problem  

1. Identify overlapping subproblems and optimal substructure.  
2. Define the state: `dp[i]` represents the solution to the problem for size `i`.  
3. Write the state transition relation/recurrence.  
4. Define base cases.  
5. Compute and return the final solution.  

---

## 🧩 Types of DP Problems  

1. **Linear DP**  
   - Examples: Fibonacci, Climbing Stairs, Minimum Path Sum.  

2. **Two-Dimensional DP**  
   - Examples: Longest Common Subsequence (LCS), Matrix Chain Multiplication.  

3. **DP on Subsequences**  
   - Examples: Subset Sum, Knapsack Problem.  

4. **DP with Bitmasking**  
   - Examples: Travelling Salesman Problem (TSP).  

5. **DP on Trees/Graphs**  
   - Examples: Maximum Path Sum in Binary Tree.  

---
