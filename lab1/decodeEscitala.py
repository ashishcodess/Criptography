import numpy as np

def readFile(filePath):
    content = ''
    with open(filePath, 'r') as file:
        if file.mode == 'r':
            content = file.read()
        file.close()
        return content

content = readFile('download.escitala')
   
n = 10 # Pre-allocate matrix
matrix = [[]]
matrix[0][0] = 'a'
matrix[0][1]= 'b'
print(matrix[0][0])
a = len(content)