// 5
typedef long long int li;

// if b is positive the answer is positive
// if b is negative the answer is negative
li mod(li a, li b) { return (b + (a % b)) % b; }