#define _GNU_SOURCE

#include "helpers.h"
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

    // welcome to my notes on data structures.
    int main_topics();
    int ADTs();
    int counting_steps();
    int balanced_trees();
    int avl_trees();
    int union_of_AVLs();
    int weighted_balance_trees();

    // run
    weighted_balance_trees();

    return 0;
}

int main_topics() {
    // the main topics ill go over in these notes:

    // 1. balance trees
    // 2. hash tables
    // 3. graphs
    // 4. disjoint sets
    // 5. priority queues
    // 6. amortized analysis

    return 0;
}

int ADTs() {
    // ADT: Abstract Data Type
    // an ADT defines:
        // a set of objects
        // a set of operations that can be performed on said objects
        // possibly also their time and space costs (memory and performance)
        // DOESN'T DEFINE HOW THEY ARE IMPLEMENTED!!

    // the implementations of ADTs are called data structures

    // some things that make ADTs great
        // they just provide a specification; a framework for how things work
        // modularity: you can change the implementation without changing the interface
        // reusability: you can use the same ADT in different programs

    return 0;
}

int counting_steps() {
    int xlx = __LINE__; // for latex typesetting, just ignore.

    // lets take a look at the following algo. we will see how we can count the total number of steps.
    #define N 10
    int A[N] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int i = 1;
    while ( i < N ) {
        int v = A[i];
        int j = i;

        while ( j > 0 && A[j-1] > v ) {
            A[j] = A[j-1]; // move all the values up
            j--;
        }

        A[j] = v;
        i++;
    }
    // sorts the array to ascending
    // note at each iteration of the outer loop, the array is sorted up to i
    // this algorithm is known as insertion sort and has a worst case time complexity of O(n^2)

    // the inner while loop moves our 'v' value to its proper place in the sorted sublist (that goes up to i).
    print_int_arr(A, N);

    // lets try to count the steps this algorithm takes

    // COUNTING STEPS
        // getting/setting variables is 1 step
        // function call: 1 step for the call + 1 step to evaluate each argument + the steps inside the function
        // return statement: 1 step + the steps to evaluate the return value 
        // if/while condition: 1 step + the steps to evaluate the expressions
        // assignment: 1 step + the steps to evaluate the expression
        // arithmetic/boolean operators: 1 + the steps to evaluate the operands
        // array access: 1 step + the steps to evaluate the index
        // constants: free, they don't need to be evaluated

    // we can find the total steps by calculating the "cost" of each line and then multiplying by the "frequency"; the number of times that line runs.
    // lets count the steps for the insertion sort algorithm

    i = 1; 
    // 2 steps: 
        // - 1 for initializing (setting i)
        // - 1 for assigning 1 to i

    while ( i < N ) { 
    // 2 steps:
        // 1 for boolean comparison
        // 1 for evaluating (getting) i
        // 0 for "evaluating" N; it's a constant cause it's a macro
    // note that if we had len(A) instead (like for python), we would have 5 steps
            // 1 for boolean comparison
            // 1 for evaluating (getting) i
            // 1 for function call of len()
            // 1 for evaluating the argument A
            // 1 for returning the value of len()

        int v = A[i];
        // 5 steps:
            // 1 for assigning v
            // 1 for setting v
            // 1 for getting A
            // 1 for getting i
            // 1 for index access

        int j = i;
        // 3 steps:
            // 1 for setting j
            // 1 for assigning i to j
            // 1 for getting i

        while ( j > 0 && A[j-1] > v ) {
        // 10 or 3 steps:
        // 3 steps, happens if j <= 0:
            // 1 for while condition
            // 1 for boolean comparison
            // 1 for getting j
        // 10 steps, happens if j > 0:
            // 1 for while condition
            // 1 boolean comparison for j > 0 && A[j-1] > v (the whole thing)
            // 1 for boolean comparison j > 0
            // 1 for getting j
            // 1 for boolean comparison A[j-1] > v
            // 1 for getting A
            // 1 for getting j
            // 1 for calculating j-1
            // 1 for index access
            // 1 for getting v
    
            A[j] = A[j-1]; // move all the values up
            // 8 steps
                // 1 for getting A
                // 1 for getting j
                // 1 index access
                // 1 for assigning A[j-1] to A[j]
                // 1 for getting A
                // 1 for getting j
                // 1 for calculating j-1
                // 1 for index access

            j--; // j = j - 1
            // 4 steps:
                // 1 for getting j
                // 1 for assigning j-1 to j
                // 1 for getting j
                // 1 for calculating j-1
        }

        A[j] = v;
        // 5 steps:
            // 1 for getting A
            // 1 for getting j
            // 1 for index access
            // 1 for assigning v to A[j]
            // 1 for getting v

        i++; // i = i + 1
        // 4 steps:
            // 1 for getting i
            // 1 for assigning i+1 to i
            // 1 for getting i
            // 1 for calculating i+1
    }

    // now lets determine the WORST CASE frequency of each line. then we can multiply the cost by the frequency to get the total steps.
    
    i = 1; // 1 frequency
    while ( i < N ) { // N frequency: N-1 true + 1 false
        // the reason it's N-1 times true is because we loop N-1 times before it's false [1, N-1] inclusive.
        // would've been N times if i started at 0

        int v = A[i]; // 1 * (N-1) freq, recall N-1 times true
        int j = i; // 1 * (N-1) freq

        while ( j > 0 && A[j-1] > v ) { // (i + 1) * (N-1) freq : but i is not constant, it changes each iteration
            // worst case is loop runs all i times true, from j = i to j = 1 and 1 time false for j = 0
            // we use i because we can evaluate the sum later 
            // however, note that when calculating the total cost, we apply i for the "true" steps, and 1 for the "false" steps
            // this is because the true steps run i times and the false step just runs once.
            // recall the true steps were 10 and the false ones were 3, so we would have 10i + 3 for the total cost, and this would happen N - 1 times.
            A[j] = A[j-1]; // 1 * (i) * (N-1) freq
            j--; // 1 * (i) * (N-1) freq
        }

        A[j] = v; // 1 * (N-1) freq
        i++; // 1 * (N-1) freq
    }

    // now let's calculate the total cost.
    
    i = 1; // line 1
    while ( i < N ) { // line 2
        int v = A[i]; // line 3
        int j = i; // line 4

        while ( j > 0 && A[j-1] > v ) { // line 5
            A[j] = A[j-1]; // line 6
            j--; // line 7
        }

        A[j] = v; // line 8
        i++; // line 9
    }

    // line 1:
        // 2 steps * 1 freq = 2 total
    
    // line 2: (let's assume we have i < len(A) instead of i < N, so 5 steps).
        // 5 steps * N = 5N

    // line 3:
        // 5 steps * (N-1) = 5N - 5

    // line 4:
        // 3 steps * (N-1) = 3N - 3

    // line 8:
        // 5 steps * (N-1) = 5N - 5

    // line 9:
        // 4 steps * (N-1) = 4N - 4

    // so excluding the inner while loop, we have:
    // 2 + 5N + 5N - 5 + 3N - 3 + 5N - 5 + 4N - 4 = 22N - 22 + 2 
    // = 22N - 15

    // now let i be the i'th iteration of the outer loop
    // for the inner loop, we then have the following cost at each iteration of the outer loop:
    
    // line 5:
        // 10i + 3 steps

    // line 6:
        // 8i steps
    
    // line 7:
        // 4i steps

    // then in total, our while loop has the following cost:
    // (see the latex output.pdf file in this directory)
    new_tex("\\textbf{worst case cost}\n\nour cost of the inner loop is:\n");
    add_tex_output(
        "\\begin{align*}\n"
        "&\\sum_{i=1}^{N-1} (10i + 3) + 8i + 4i\\\\\n"
        "=&\\sum_{i=1}^{N-1} 22i + 3\n"
        "\\end{align*}"
    );

    add_tex_output(
        "so our total cost is:\n"
        "\\begin{align*}\n"
        "& 22N - 15 + \\sum_{i=1}^{N-1} 22i + 3\\\\\n"
        "&= 22N - 15 + 22\\frac{(n-1)n}{2} + 3 (n-1)\\\\\n"
        "&= 11n^2 + 14n - 18\n"
        "\\end{align*}"
    );

    // for the best cost, we can assume the inner loop runs 0 times, with only 1 false check.
    // this would give us a frequency of N-1 for line 5 and 0 for line 6 and 7

    // so the best case cost is:
    // 22N - 15 + (N-1)*10 = 32N - 25
    add_tex_output(
        "\\textbf{best case cost}\n\n"
        "\\vspace{5mm}\n"
        "for the best case, the inner loop runs 0 times, so we have:\n"
        "\\begin{align*}\n"
        "& 22N - 15 + 10(N-1)\\\\\n"
        "&= 32N - 25\n"
        "\\end{align*}"
    );

    return 0;
}

int balanced_trees() {
    // recall BSTs (binary search trees) 
    // BSTs are a type of binary tree where the left child is less than the parent and the right child is greater than the parent
    // eg:

    //      5
    //     / \
    //    3   7
    //   /   / \
    //  1   6   8

    // we can also choose <= for left or >= for right, it is a design decision.

    // searching in a BST actually has a worst case time complexity of O(n) if the tree is unbalanced. for example:

    //      1
    //       \
    //        2
    //         \
    //          3
    //           \
    //            4
    //             \
    //              5

    // this is akin to a linked list, and searching for 5 would take 5 steps.
    // to avoid this, we can use a balanced tree!
    // maintain a BST that always stays balanced. so the height of the tree is always log(n) where n is the number of nodes.

    // we have a few options for balanced trees:
        // AVL trees
        // red-black trees
        // splay trees
        // B-trees

    // in the next section we are going to explore AVL trees.

    return 0;
}

int avl_trees() {
    // AVL trees are a type of balanced binary search tree
    // they are named after their inventors: Adelson-Velsky and Landis
    // AVL trees work by maintaining a BALANCE FACTOR for each node
    // the balance factor of a node is the height of the left subtree - the height of the right subtree
        // balance_factor = height(left) - height(right)

    // AVL trees must maintain a balance factor of -1, 0, or 1 for each node
    
    // SEARCHING IN AVL
    // searching in an AVL tree is the same as searching in a BST

    // INSERTING INTO AN AVL TREE
    // when inserting into an AVL tree, we first insert the node as we would in a BST
    // then we update the balance factors of the nodes on the path from the root to the new node
    // if the balance factor of any node becomes -2 or 2, we need to rebalance the tree!
    // we can do this by "rotating" the tree

    // eg, consider the tree:
    //                              
    //                44   (-1)        // numbers in brackets are the balance factors. no brackets means 0
    //              /    \             //  leaves always have a balance factor of 0
    //            32       78  (1)
    //           /  \     /  \
    //         17   35   50   88
    //                  /  \
    //                48    62

    // adding a 45 would make the tree unbalanced!

    //                44   (-2)
    //              /     \            
    //            32         78  (2)
    //           /  \      /    \
    //         17   35   50 (1)   88
    //                  /  \
    //                48    62
    //               /
    //              45  

    // so we will "rotate" the tree to rebalance it. 
    // we pick the lowest node with a balance factor of 2 or -2, and rotate it in the direction that will balance the tree.
    // in this case we would rotation 78 to the right

    //                44   (-1)
    //              /     \
    //            32       50  (0)
    //           /  \     /  \
    //         17   35   48   78
    //                  /    /  \
    //                45    62   88

    // now the tree is balanced!

    // let's go over how ROTATIONS work in a little more depth
    // there are two types of rotations: CW and CCW

    // we do a CW rotation when the balance factor > 1, like in the example above
        // ie) the left subtree is too deep
        // during CW rotation:
        // 1. replace the parent with the left child, 
        // 2. make the left child's right child the parent's left child
        // 3. make the parent the right child of the left child
        // this can be seen from the example above and takes O(1) time

    // we do a CCW rotation when the balance factor < -1
        // ie) the right subtree is too deep:A
        // during CCW rotation:
        // 1. replace the parent with the right child
        // 2. make the right child's left child the parent's right child
        // 3. make the parent the left child of the right child

    // note that sometimes we need to do a DOUBLE ROTATION to balance the tree
    // this is when we have a zig-zag pattern in the tree
    // or more simply, when any child of the parent node we are rotating has a balance factor of the opposite sign 
    // for example, say we want to insert 46 into the tree:

    //                 44   (-1)
    //              /     \
    //            32       50  (0)
    //           /  \     /  \
    //         17   35   48   78
    //                  /    /  \
    //                45    62   88

    // we get:

    //                 44   (-2)
    //             /       \
    //          32          50 
    //         /  \       /     \
    //       17   35    48 (2)    78
    //                  /        /   \
    //                45 (-1)   62    88
    //                  \
    //                   46

    // note how 48 is our problem node, and it has a balance factor of 2
    // and that a child of 48, 45, has a balance factor of -1, which is the opposite sign
    // hence we will need to do a double rotation to balance the tree
    // first we will have to do a CCW rotation on 45, then a CW rotation on 48

    // first rotation:

    //                 44   
    //              /     \
    //            32       50  
    //           /  \     /  \
    //         17   35   48   78
    //                  /    /  \
    //                46    62   88
    //               /
    //              45

    // second rotation:

    //                 44   
    //             /       \
    //          32          50  
    //        /  \        /    \
    //      17   35     46     78
    //                 /  \    /  \
    //                45  48  62   88

    // in the next section we will go over how to implement an AVL tree in C

    return 0;
}

// we will implement an AVL tree in C in the following functions, see avl_implementation() for examples

typedef struct AVLNode {
    int value;
    int balance_factor;
    struct AVLNode* left;
    struct AVLNode* right;
} AVLNode;

AVLNode* AVL_init(int val) {
    AVLNode* new = malloc(sizeof(AVLNode));
    new->value = val;
    new->balance_factor = 0;
    new->left = NULL;
    new->right = NULL;
    return new;
}

int AVL_isleaf(AVLNode* tree) {
    return tree->left == NULL && tree->right == NULL;
}

int AVL_height(AVLNode* tree) {
    if (tree == NULL) {
        return 0;
    }
    int rh = AVL_height(tree->right);
    int lh = AVL_height(tree->left);
    return rh >=  lh ? 1 + rh : 1 + lh;
}
 
AVLNode* AVL_edge_find(AVLNode* tree, int val) {
    // return a valid edge node in tree which a new node containing val can be attached to while maintaining the BST property
    if ( tree->value == val ) {
        return tree; // return the node itself when it matches the value exactly
    }

    if ( val >= tree->value && tree->right != NULL ) {
        return AVL_edge_find(tree->right, val);

    }
    if ( val < tree->value && tree->left != NULL ) {
        return AVL_edge_find(tree->left, val);
    }

    return tree;
}

int AVL_insert(AVLNode* tree, int val) {
    AVLNode* new = AVL_init(val);
    AVLNode* parent = AVL_edge_find(tree, val); 
    if (parent->value >= val) {
        parent->right = new; // parent-> right should be NULL
        parent->balance_factor--;
    } else {
        parent->left = new; // parent-> left should be NULL
        parent->balance_factor++;
    }

    

    return 0;
}


int avl_implementation() {
    // TODO: copy over the implementation from closestAVL project
    

    return 0;
}

int augmented_data_structures() {
    // "augmented data structure" is a fancy term for an existing data structure modified to store additional information and / or perform additional operations.

    // lets make a task for ourselves: design a DS that implements an ordered set/dict and in addition to insert, delete, search, union, etc,. also supports two types of RANK QUERIES:
        // 1. RANK(S, k): given a key k in set S, what is the rank of k in S? ie: the key's position among the elements of S
        // 2. SELECT(S, r): given a rank r in set S, which key in S has rank r?

    // for example, in the set of values S = {3, 15, 27, 30, 35, 56}
    // rank(S, 15) = 2
    // select(S, 4) = 30

    // we can implement this using an AVL tree
    // for rank:
        // in-order traversal of the tree, and count the number of nodes visited until we reach the key
    // for select:
        // in order traversal of the tree, and return the key when we reach the r'th node

    // what is the complexity of rank? O(n)
    // what is the complexity of select? O(n)

    // note that our search, insert, delete operations do not need to change.

    // IDEA 1:
    // store rank in each node n in the tree T
    
        // rank(T, k): search for n such that n.key = k, return n.rank -> O(log(n))
        // select(T, r): search for n such that n.rank = r, return n.key -> O(log(n))

    // note that with this idea, our search, insert, and delete operations will have to change to update the rank of each node whenever we insert and delete!
    // kind of tedious

    // IDEA 2:
    // store the size of the subtree rooted at each node n in the tree T
    // how is size related to rank? 
    // define RELATIVE-RANK, rank(n, k) as rank of key k relative to the keys in the tree rooted at node n

        // rank(T, k): 1 + number of keys in T than are less than k
        // rank(n, n.key) = 1 + size(n.left)

        // we can use this to form an O(log(n)) algorithm for rank and select!

    //  rank(T, k) in O(log(n)):
    // to find the rank of k in T, we can do a binary search for k in T and keep track of the rank as we go down the tree.

    // 1. base case: if k == n.key, return 1 + size(n.left)
    // 2. if k < n.key, return rank(n.left, k)
    // 3. if k > n.key, return 1 + size(n.left) + rank(n.right, k)

    //  select(T, r) in O(log(n)):
    // to find the key with rank r in T, we also do a binary search! this time, we traverse the tree and compare the rank of the current node to r. in our recursion, we will have to change the value of r as we go down the tree. it will make more sense when we see the algo:

    // 1. base case: if r == size(n.left) + 1, return n.key
    // 2. if r < (size.nleft) + 1, return select(n.left, r)
    // 3. if r > (size.nleft) + 1, return select(n.right, r - 1 - size(n.left))

    // now everything is in O(log(n))
    return 0;
}

int union_of_AVLs(){
    // so far we have taken a look at the following operations on AVLs:
    // 1. search
    // 2. insert
    // 3. delete
    // 4. rank
    // 5. select

    // now we will explore returning the union, intersections, and difference of AVL trees
    
    // UNION OF AVL TREES
    // suppose we have two AVL trees G and L
    // size(G) = n, size(L) = m, and n <= m

    // simple approach for union:
    // just add all the nodes of G to L
    // each insertion is O(log(m + n)), and we have n insertions
    // hence, the complexity of the union is O(n*log(m + n))

    // a better approach: divide and conquer

        // recap of divide and conquer: split the input into smaller pieces and solve the problem on each piece, then combine the results

        // some eg: merge sort, quick sort, binary search in array, etc.

    // we can use divide and conquer to find the union of two AVL trees
        // split G into smaller trees
        // split L into smaller trees
        // build unions of G and L
        // merge results from union of G and L

    // lets see how we can SPLIT an AVL tree
        // suppose tree L has key k at its root node
        // split G into two trees: G<k and G>k, both balanced
        // split(T, k): returns (T<k, T>k)

    // example
    //           25
    //         /    \
    //       14       30
    //      /  \     / 
    //    12   17   27
    // say we want to split at 16
    // we want {12, 14} and {17, 25, 27, 30} as the result
    // we split the left subtree into (L, R) = ({12, 14}, {17})
    // T<k is {12, 14}, the left the above split
    // T>k is join({17}, 25, {27, 30})

    // so our split(T, k) algorithm will be as follows:
    
    // if T == null:
    //    return (null, null)
    // if k == T.key:
    //    return (T.left, T.right)

    // if k < T.key:
    //    (L, R) = split(T.left, k)
    //    R' = join(R, T.key, T.right)
    //    return (L, R')

    // if k > T.key:
    //    (L, R) = split(T.right, k)
    //    L' = join(T.left, t.key, L)
    //    return (L', R)

    // let's understand this recursion a bit better:
        // our bases cases are fairly simple, we just return the left and right subtrees when we find the key or pairs of  NULLs when we reach a null node

        // when the k < T.key, that means the split needs to happen in the left subtree.  but the right part of the split in the left subtree also needs to be joined with the stuff from the parent node. specifically, the parent node itself and the right subtree of the parent node.

        // for visualization, see output.pdf
            // you can see the blue nodes are the left split. the red nodes are the righ split WITHIN the subtree. they need to be joined with all the white nodes.

    new_tex(
        "\\begin{mypar}\n"
        "\\textbf{splitting an AVL tree}\n\n"
        "let's split the AVL tree at 16\n\n"
        "\\begin{forest}\n"
        "for tree={circle,draw,minimum size=2em,edge={-latex}, calign=edge midpoint}\n"
        "[25\n"
        "    [14, fill=blue, opacity=0.5\n"
        "        [12, fill=blue, opacity=0.5]\n"
        "        [17, fill=red, opacity=0.5]\n"
        "    ]\n"
        "    [30\n"
        "        [27]\n"
        "       [ ,phantom]\n"
        "    ]\n"
        "]\n"
        "\\end{forest}\n"
        "\\end{mypar}"
    );


    // now lets see how we can JOIN two AVL trees
    // join(G, k, L): returns a new AVL tree with root k and subtrees G and L/ k is the root of L

    // join(G, k, L):
        // note that, G <= k <= L

    // NULL cases 
    // if G == null:
    //    return insert(L, k)
    // if L == null: 
    //    return insert(G, k)

    // NO BALANCE CASE 
    // if |height(G) - height(L)| <= 1:
    //    return new AVL tree with root k, left G, right L

    // BALANCE CASE 
    // if height(G) > height(L) + 1: 
        // insert k and L into G 

    // if height(L) > height(G) + 1: 
        // insert k and G into L

    // note that when we insert the trees, we don't just insert all the nodes of L into G or vice versa. we do it in a more efficient way!

    // inserting G into L:
    // in this case height(L) > height(G) + 1

        // in L, keep going right to find the node p, which satisfies:
            // 1.) p is still too tall: height(p) > height(G) + 1
            // 2.) p.right is just right: height(p.right) <= height(G) + 1
        // create a new node q with key k, left child p.right, and right child G. this node becomes p's new right child
        // rebalance p from upwards as needed


    // inserting L into G:
    // similiarly, in this case, height(G) > height(L) + 1

        // in G, keep going left until we find a node p such that:
            // 1.) height(p) > height(L) + 1
            // 2.) height(p.right) <= height(L) + 1

        // create a new tree q with node k, left child L, and right child p.right. then set q to be p's right child.
        // rebalanced p from upwards as needed

    // let's understand, why does this result in a balanced tree?
    
    // lets look at an example for intuition:

    // suppose we have two AVL trees G and L

    // L:
    //          25
    //        /    \
    //      14      26

    // G:
    //           37
    //        /      \
    //      33        40
    //     /  \      /  \
    //   32   34    38   50
    //  /       \          \
    // 31       35          60
    //            \
    //            36

    // suppose our k value is 30. we want to insert L into G

    // we traverse G to find the node p = 33.
    // then we create the following node:

    //          30
    //        /     \
    //      25       32
    //     /  \      /  
    //   14    26  31 

    // then we set this to be the left child of p = 33.

    //                  37
    //              /       \
    //            33         40
    //           /   \      /  \
    //         30    34    38   50
    //        /   \    \          \
    //      25     32   36         60
    //     /  \    /
    //   14   26  31

    // we can see the above tree is balanced.
    // in general, there are 4 cases of joining AVL trees.
    // it will be easier to understand with a diagram, so run this code and see the output.pdf file in this directory

    // TODO: complete hand drawn diagrams for this and upload to the figures directory

    add_tex_output(
        "\n\n\\textbf{here are the 4 cases for joining AVL trees}\n\n"
        "\\includegraphics[width=0.5\\textwidth]{figures/avl_join1.png}\n"
        "\\includegraphics[width=0.5\\textwidth]{figures/avl_join2.png}\n"
        "\\includegraphics[width=0.5\\textwidth]{figures/avl_join3.png}\n"
        "\\includegraphics[width=0.5\\textwidth]{figures/avl_join4.png}\n"
    );
    
    return 0;
}

int weighted_balance_trees() {
    // another way to balance trees is to use WEIGHTED BALANCE TREES. 
    // before we were using AVLs, which balanced the tree based on the height of the tree

    // in a weighted balance tree, we balance the tree based on the number of nodes in the tree, i.e the size

    // idea: at every node n,
        // 1/3 <= [size(n.left) + 1] / [size(n.right) + 1] <= 3

        // =>
            // (1/3) * [size(n.right) + 1] <= size(n.left) + 1 <= 3 * [size(n.right) + 1]

        // i.e the size of the left subtree + 1 is between 1/3 and 3 times the size of the right subtree + 1

    // or we can simplify this by saying that weight(n) = size(n) + 1, hence:

        // 1/3 <= weight(n.left) / weight(n.right) <= 3

    // equivalently,
        // weight(n.left) <= 3 * weight(n.right)
        // weight(n.right) <= 3 * weight(n.left)

    // we can use this to balance the tree. just keep track of the size with a size field.

    // we will want to do rotations again, as with AVL trees!

    return 0;
}