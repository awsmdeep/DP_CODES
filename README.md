
    ###########################################
    #              Dynamic Programming        #
    ###########################################

    Dynamic Programming (DP) is an optimization technique that solves complex problems by 
    breaking them down into overlapping subproblems and solving each subproblem only once.

    ==================================================
    Key Concepts:
    ==================================================
    1. Overlapping Subproblems:
       - A problem is said to have overlapping subproblems if the same subproblems are solved multiple times.
       - Example: Fibonacci numbers, where Fib(n) = Fib(n-1) + Fib(n-2).

    2. Optimal Substructure:
       - A problem has optimal substructure if its solution can be constructed from the solutions of its subproblems.
       - Example: Shortest path in a graph (Dijkstra, Bellman-Ford).

    3. Memoization (Top-Down Approach):
       - Recursively solve the problem and store results of solved subproblems to avoid recomputation.

    4. Tabulation (Bottom-Up Approach):
       - Iteratively solve the problem, solving all smaller subproblems first and using their results to solve larger subproblems.

    ==================================================
    Steps to Solve a DP Problem:
    ==================================================
    1. Identify if the problem has overlapping subproblems and optimal substructure.
    2. Define the state:
       - dp[i] represents the solution to the problem for input size i.
    3. Formulate the state transition relation/recurrence.
    4. Base case(s).
    5. Compute and return the solution.

    ==================================================
    Types of DP Problems:
    ==================================================
    1. Linear DP:
       - Examples: Fibonacci, Climbing Stairs, Minimum Path Sum.
    2. Two-Dimensional DP:
       - Examples: Longest Common Subsequence (LCS), Matrix Chain Multiplication.
    3. DP on Subsequences:
       - Examples: Subset Sum, Knapsack Problem.
    4. DP with Bitmasking:
       - Examples: Travelling Salesman Problem (TSP).
    5. DP on Trees/Graphs:
       - Examples: Maximum Path Sum in Binary Tree.

    ==================================================
    Example 1: Fibonacci Sequence (Memoization)
    ==================================================
