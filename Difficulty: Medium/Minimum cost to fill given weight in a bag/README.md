<h2><a href="https://www.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/1?page=4&category=Dynamic%20Programming&sortBy=submissions">Minimum cost to fill given weight in a bag</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">You are given an array <strong>arr[]</strong>, where <strong>arr[i] </strong>represents the cost of a packet containing <strong>exactly i</strong> kg of oranges (1-based indexing).&nbsp; </span><span style="font-size: 18px;">You are also given an integer <strong>w</strong>, representing the total weight of oranges you need to buy. Find</span><span style="font-size: 18px;">&nbsp;the <strong>minimum </strong>cost required to purchase <strong>exactly w </strong>kg of oranges.</span></p>
<p><span style="font-size: 18px;"><strong>Note:</strong><br></span></p>
<ul>
<li><span style="font-size: 18px;">cost[i] = -1 means that a packet of i kg is not available.</span></li>
<li><span style="font-size: 18px;">You can buy any number of packets of the available sizes (infinite supply).</span></li>
<li><span style="font-size: 18px;">If it is not possible to form exactly w kg, return -1.</span></li>
</ul>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input</strong>: arr[] = [20, 10, 4, 50, 100], w = 5
<strong>Output:</strong> 14
<strong>Explanation</strong>: The minimum cost is 14 by purchasing a 2kg packet for 10 and a 3kg packet for 4.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input</strong>: arr[] = [-1, -1, 4, 3, -1], w = 5
<strong>Output:</strong> -1
<strong>Explanation</strong>: It is not possible to buy 5 kgs.</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ arr.size(), w ≤ 2*10<sup>3</sup></span><br><span style="font-size: 18px;">1 ≤ arr[i] ≤ 10<sup>5</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Algorithms</code>&nbsp;