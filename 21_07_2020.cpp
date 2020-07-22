// CHALLENGE 1

// A small frog wants to get to the other side of a river. The frog is initially located on one bank of the river (position 0) and wants to get to the opposite bank (position X+1). Leaves fall from a tree onto the surface of the river.

// You are given an array A consisting of N integers representing the falling leaves. A[K] represents the position where one leaf falls at time K, measured in seconds.

// The goal is to find the earliest time when the frog can jump to the other side of the river. The frog can cross only when leaves appear at every position across the river from 1 to X (that is, we want to find the earliest moment when all the positions from 1 to X are covered by leaves). You may assume that the speed of the current in the river is negligibly small, i.e. the leaves do not change their positions once they fall in the river.

// For example, you are given integer X = 5 and array A such that:

//   A[0] = 1
//   A[1] = 3
//   A[2] = 1
//   A[3] = 4
//   A[4] = 2
//   A[5] = 3
//   A[6] = 5
//   A[7] = 4
// In second 6, a leaf falls into position 5. This is the earliest time when leaves appear in every position across the river.

// Write a function:

// class Solution { public int solution(int X, int[] A); }

// that, given a non-empty array A consisting of N integers and integer X, returns the earliest time when the frog can jump to the other side of the river.

// If the frog is never able to jump to the other side of the river, the function should return −1.

// For example, given X = 5 and array A such that:

//   A[0] = 1
//   A[1] = 3
//   A[2] = 1
//   A[3] = 4
//   A[4] = 2
//   A[5] = 3
//   A[6] = 5
//   A[7] = 4
// the function should return 6, as explained above.

// Write an efficient algorithm for the following assumptions:

// N and X are integers within the range [1..100,000];
// each element of array A is an integer within the range [1..X].

// I have no record of the solution of this challenge. Although it was achieved with a 100% performance and correctness score.





// CHALLENGE 2

// A non-empty array A consisting of N integers is given. Array A represents numbers on a tape.

// Any integer P, such that 0 < P < N, splits this tape into two non-empty parts: A[0], A[1], ..., A[P − 1] and A[P], A[P + 1], ..., A[N − 1].

// The difference between the two parts is the value of: |(A[0] + A[1] + ... + A[P − 1]) − (A[P] + A[P + 1] + ... + A[N − 1])|

// In other words, it is the absolute difference between the sum of the first part and the sum of the second part.

// For example, consider array A such that:

//   A[0] = 3
//   A[1] = 1
//   A[2] = 2
//   A[3] = 4
//   A[4] = 3
// We can split this tape in four places:

// P = 1, difference = |3 − 10| = 7
// P = 2, difference = |4 − 9| = 5
// P = 3, difference = |6 − 7| = 1
// P = 4, difference = |10 − 3| = 7
// Write a function:

// class Solution { public int solution(int[] A); }

// that, given a non-empty array A of N integers, returns the minimal difference that can be achieved.

// For example, given:

//   A[0] = 3
//   A[1] = 1
//   A[2] = 2
//   A[3] = 4
//   A[4] = 3
// the function should return 1, as explained above.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [2..100,000];
// each element of array A is an integer within the range [−1,000..1,000].

// I have no record of the solution of this challenge. Although it was achieved with a 100% performance and correctness score.