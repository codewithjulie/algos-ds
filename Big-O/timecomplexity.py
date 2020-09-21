# Time complexity

'''Algorithms have a sequence of steps to be performed to reach a goal

Each algorithm takes some time to complete the steps

1. We coud measure by time (before and after the algorithm)
2. Limitation of this would be every machine is different and basically there's no precision in timing

Instead we can 
Second option is to count the number of operations in the algorithm

Third, best, is to abstract the number of operations, focusing on the dominantly growing factor in relation to the input
'''

'''
x = 0   #constant // c1
n = 10  #constant // c2
for y in range(n): #n * c3
  x = x + y  #  n * c4
  print(x)   #  n * c5
# T(n) = c1 + c2 + n*c3 + n*c4 + n*c5 =
# = n * (c3+c4+c5) + (c1 + c2) = 
# = n * a + b =
# = O(n) (Big-O)
'''

x = 0   #constant // c1
n = 10  #constant // c2
for y in range(n): # n * c3
  for z in range(n):# n * n *c4
    x = z + y  #  n * n *c5
    print(x)   #  n * n * c6

#T(n) = c1 + c2 + n * c3 + n*n * c4 + n*n * c5 + n*n * c6 = 
# = n*n(c5+c6+c4) + n(c3) + (c1+c2) =
# = n*n* a + n * b + c =
# = O(n*n)

Big O - worse case
Big Omega - best case,  Ω
Theta -  Θ or ϴ, average case