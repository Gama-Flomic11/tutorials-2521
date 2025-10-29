# Tutorial Notes We Misses This Week
## Solving Abstract Problems

Suppose you have $n$  variables $(x_1, x_2, ...,x_n)$, $m$ equalities of the form $x_i = x_j$ (where $i \neq j$) and $k$ inequalities of the form $x_i \neq x_j$ (where $i \neq j$).
Come up with an algorithm (described in plain English or pseudocode) to determine whether this system of equations is consistent or contradictory.

Example

1. Suppose you have three variables $(x_1, x_2, ...,x_n)$, the equality $x_1 = x_2$ and 2 inequalities $x_1 \neq x_3$ and $x_2 \neq x_3$. 
    - Consistent as
    
    $$
    x_1 = x_2 = 2
    $$
    
    and
    
    $$
    x_3 = 2
    $$
    
    Or if we set any value of $x_i$ for $i \in \{1,2,3\}$ then the other values follow and do not contradict the initial assignment / other assignments. 
    
2. Suppose you have three variables $(x_1, x_2, ...,x_n)$, the equalities $x_1 = x_2$ and $x_1 = x_3$ and 1 inequality $x_2 \neq x_3$. 
    - Inconsistent as when you set
    
    $$
    x_1 = 1\\ \implies x_2 = x_1 = 1,\,\;\; x_3 = x_1 = 1 \\ \text{But} \;\;\;\; x_2 \neq x_3
    $$
    
    From the third inequality so clearly this cannot be true.
    
    ## Hint (Reasoning for the algorithm) (The algorithm)
    
    Use a graph, vertices are the $x_i$ and edges are those that are equal, e.g.
    
    (Images 1 and 2 Attached in the email go here).
    
    Notice that to satisfy correctly all nodes in a connected component must connect to all other nodes in that component otherwise not satisfied.
    
    ## Answer in Algorithm Form
    
    - Construct a graph from the variables and equalities where:
        - Each vertex represents a variable
        - For each equality xi=xj, insert an edge between i and j
    - Compute the connected components array
    - For each inequality xi≠xj:
        - If xi and xj are in the same connected component, then return false
    - Return true
## Write a function to check whether a path, supplied as an array of `struct edge`s is an Euler path. Assume the function has interface: (7 min 55)

`bool isEulerPath(Graph g, **struct** **edge** e[], int nE)`

where `e[]` is an array of `nE` edges, in path order.

```c
bool isEulerPath(Graph g, struct edge e[], int nE) {

}
```

## Hints

- Check that the graph contains all edges because the number of edges given might be incorrect
- Check all the edges are actually in the graph e.g. g→edges[e[i].v because the edges might not be in the graph
- Check whether the path actually is a path, e.g does the ending edge of the last edge have the same vertex as the starting of the next
- Finally are all edges done exactly once
    - Need to check backwards and forwards basically a double loop through the edge array.

## Answer

```c
// check whether a given path is a Euler path
bool isEulerPath(Graph g, struct edge e[], int nE) {
	assert(g != NULL);

	// includes all edges
	if (g->nE != nE) {
		return false;
	}

	// edges are actually in the graph
	for (int i = 0; i < nE; i++) {
		if (g->edges[e[i].v][e[i].w] == 0) {
			return false;
		}
	}

	// is actually a path
	for (int i = 0; i < nE - 1; i++) {
		if (e[i].w != e[i + 1].v) {
			return false;
		}
	}

	// includes edges exactly once
	for (int i = 0; i < nE; i++) {
		for (int j = i + 1; j < nE; j++) {
			if (e[i].v == e[j].v && e[i].w == e[j].w) return false;
			if (e[i].v == e[j].w && e[i].w == e[j].v) return false;
		}
	}
	
	return true;
}
```