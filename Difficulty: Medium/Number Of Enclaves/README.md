<h2><a href="https://www.geeksforgeeks.org/problems/number-of-enclaves/1?page=2&category=Graph&sortBy=submissions">Number Of Enclaves</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">You are given an <strong>n&nbsp;x m</strong>&nbsp;binary matrix <strong>grid</strong>, where <strong>0</strong> represents a sea cell and <strong>1</strong> represents a land cell.</span></p>
<p><span style="font-size: 18px;">A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.</span></p>
<p><span style="font-size: 18px;">Find the number of land cells in <strong>grid</strong> for which we cannot walk off the boundary of the grid in any number of moves.</span></p>
<p><strong><span style="font-size: 18px;">Examples:</span></strong></p>
<pre><span style="font-size: 18px;"><strong><span style="font-size: 18px;">Input:</span> </strong></span><span style="font-size: 18px;">grid[][] = [[0, 0, 0, 0],
               [1, 0, 1, 0],
               [0, 1, 1, 0],
               [0, 0, 0, 0]]</span>
<span style="font-size: 18px;"><strong><span style="font-size: 18px;">Output:</span> </strong></span><span style="font-size: 18px;">3</span>
<span style="font-size: 18px;"><strong>Explanation:</strong></span>
<span style="font-size: 18px;">0 0 0 0
1 0 <strong>1</strong> 0
0 <strong>1</strong> <strong>1</strong> 0
0 0 0 0</span>
<span style="font-size: 18px;">The highlighted cells represent the land cells.</span>
</pre>
<pre><span style="font-size: 18px;"><strong><span style="font-size: 18px;">Input:</span> </strong></span><span style="font-size: 18px;">grid[][] = [[0, 0, 0, 1],
               [0, 1, 1, 0],
               [0, 1, 1, 0],
               [0, 0, 0, 1],
               [0, 1, 1, 0]]</span>
<span style="font-size: 18px;"><strong><span style="font-size: 18px;">Output:</span> </strong></span><span style="font-size: 18px;">4</span>
<span style="font-size: 18px;"><strong>Explanation:</strong></span>
<span style="font-size: 18px;">0 0 0 1
0 <strong>1</strong> <strong>1</strong> 0
0 <strong>1</strong> <strong>1</strong> 0
0 0 0 1
0 1 1 0</span>
<span style="font-size: 18px;">The highlighted cells represent the land cells.</span></pre>
<p><strong><span style="font-size: 18px;">Constraints:<br></span></strong><span style="font-size: 18px;">1 ≤ n, m ≤ 500<br></span><span style="font-size: 18px;">0 ≤ grid[i][j] ≤ 1</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Google</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>DFS</code>&nbsp;<code>Matrix</code>&nbsp;<code>Graph</code>&nbsp;<code>BFS</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;