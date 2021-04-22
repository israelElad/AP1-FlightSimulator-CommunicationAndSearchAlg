from socket import *

# Define matrixes
m1 = [[0, 9, 5, 1, 0, 3,-1, 5, 2, 0],
      [7, 6, 4, 2, 6, 3, 8, 9, 1,-1],
      [9, 7, 4,-1, 3, 5,-1, 9, 2, 9],
      [9, 6, 9, 2, 6, 8, 6, 7, 1, 9],
      [6, 9, 3, 0,-1, 9, 3, 8, 6, 5],
      [7, 5, 1, 1, 6, 5, 5, 4, 4, 6],
      [3, 3, 3, 2, 5, 8, 9, 1, 3, 0],
      [-1, 9, 8, 3,-1, 9, 0, 1, 5,8],
      [6, 0, 3, 8, 2, 8, 1, 9, 2, 6],
      [5, 7, 8, 7, 8, 3, 4, 8, 4, 0]]

m2 = [[0, 2, 7, 6, 4, 6, 3, 6, 6, 7],
      [4, 0, 9, 6, 7,-1, 5, 9, 7, 8],
      [3, 1, 3, 2, 9, 2, 4, 1, 9, 7],
      [9, 4,-1, 4, 9, 5, 9, 2,-1, 6],
      [9, 4, 5, 8, 9, 3, 8, 4, 2, 6],
      [1, 7, 6, 3, 8, 3, 4, 0, 6, 3],
      [9, 5, 7, 7,-1, 6, 2, 8,-1, 0],
      [4, 7, 3,-1, 5, 3, 1, 1, 8, 5],
      [6, 8, 0, 2, 2, 7, 7, 7, 8, 3],
      [-1, 7, 7, 7, 3, 5, 3, 6, 3,0]]

m3 = [[0, 6, 9, 1, 5, 2, 3, 7, 5, 0],
      [0,-1, 9,-1, 3,-1, 7, 9, 6, 6],
      [0, 6, 1, 8, 1, 5, 1, 3, 0, 4],
      [6, 7, 9, 3, 7, 2, 5, 1, 0, 9],
      [2,-1, 9,-1, 0, 0, 0, 6,-1, 7],
      [2, 0, 1, 3, 7, 3, 9, 8, 7, 8],
      [2, 1, 5,-1, 4, 1, 3,-1, 3, 2],
      [7, 4, 2, 6, 4, 1, 8, 3, 9, 6],
      [0,-1, 8, 0, 3, 3, 4, 3, 1, 0],
      [-1, 2, 0, 6, 3, 5, 8, 5, 3,0]]

# Define & connect sockets to server
s1 = socket(AF_INET, SOCK_STREAM)
s2 = socket(AF_INET, SOCK_STREAM)
s3 = socket(AF_INET, SOCK_STREAM)
s1.connect(('127.0.0.1', 5400))
s2.connect(('127.0.0.1', 5400))
s3.connect(('127.0.0.1', 5400))

# Send matrixes
for i in range(10):
      s1.send((",".join(map(str,m1[i])) + "\n").encode())
      s2.send((",".join(map(str,m1[i])) + "\n").encode())
      s3.send((",".join(map(str,m1[i])) + "\n").encode())

# Send start
s1.send(("0,0" + "\n").encode())
s2.send(("0,0" + "\n").encode())
s3.send(("0,0" + "\n").encode())
# Send goal
s1.send(("9,9" + "\n").encode())
s2.send(("9,9" + "\n").encode())
s3.send(("9,9" + "\n").encode())
# Send end
s1.send(("end" + "\n").encode())
s2.send(("end" + "\n").encode())
s3.send(("end" + "\n").encode())

# Print solutions
print(s1.recv(1024))
print(s2.recv(1024))
print(s3.recv(1024))