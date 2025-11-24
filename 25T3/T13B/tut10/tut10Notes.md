# Tutorial 10 25T3 T13B Missed Exercises

Most of the notes are  similar if not the same as the tutorial notes on the course website it is best to double check there if unsure about anything in these exercises

## Suppose you are given an array $A$ of size $n$, and you would like to find the largest $k$ elements $(k \leq n)$. For example, if given the array $A = [7,4,2,5,9]$ and the value $k=3$, the largest $k$ values are 9,5,7

## A simple way to solve this problem is to sort the array in increasing order, and then the largest k elements would be the last k elements of the sorted array. What is the worst-case time complexity of this approach?

O(nlogn) it takes at least nlogn to sort the array which would dominate.

## Come up with a more efficient method that uses a heap. What is the worst-case time complexity of this method?

- Obvious approach
    
    Insert into a max heap then delete the elements, but this is O(nlogn) inserts and O(klogn) deletes not faster.
    
- Faster approach
    
    Use a min heap, insert k elements then insert one more and delete then insert then delete.
    
    This is O(nlogk) as the heap always contains at most k+1 elements and insertion and deletion is therefore logk

# Alien Poetry

It's the year 2521, and space exploration has uncovered an alien language (which just so happens to use the same letters as English 😉️)! A team of linguists has found that these aliens loved poetry, and that two words are said to rhyme with degree k if the last k letters of each word are identical. For example, the words `GOODRA` and `QUOLODRA` rhyme with degree 4, as the last 4 letters of these words are identical. These words also rhyme with degree 1, 2 and 3.

To help investigate this poetry and write some of your own, you would like to devise a method to find the number of words that rhyme with a given word with degree k.

For example, suppose the words of the language are `ARON`, `AGGRON`, `SQUARON`, `RONA`, `LAVARON` and `UDON`. Then:

- The number of words that rhyme with `SQUARON` with degree 2 is 4 (the words are `ARON`, `AGGRON`, `LAVARON` and `UDON`)
- The number of words that rhyme with `SQUARON` with degree 3 is 3 (the words are `ARON`, `AGGRON` and `LAVARON`)
- The number of words that rhyme with `SQUARON` with degree 4 is 2 (the words are `ARON` and `LAVARON`)
- The number of words that rhyme with `SQUARON` with degree 5 is 0.

Can you come up with a method to efficiently answer queries like the ones above? Suppose you are allowed to preprocess the words of the language before answering any queries.

## Hint

Think about different ways of storing in a trie.

## Answer

Store in reverse order and traverse the last k letters then count the number of finishing nodes in the subtrie

## Is this efficient?

No, because you still need to go through an entire subtrie 

## What should you do instead

- Store the number of ending nodes as you go, this can easily be done by adding to each node as you insert a new word. e.g. if there are 3 ending nodes in a subtree, store that at the node, this can easily be maintained by updating as you go  back up each time you add a new word, then you just need to check that number which is O(k)
- Now only need to go down to that node return the count - 1 because the current word is already stored in the trie too.
- O(k) time complexity where k is the degree.