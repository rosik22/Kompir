#!/usr/bin/env python3

def printMaze(maze):
    ans = [ [ 0 for j in range(20) ] for i in range(10) ]
    for i in range(10):
        for j in range(20):
            if maze[i][j] == 1:
                ans[i][j] = "#"
            elif maze[i][j] == 0:
                ans[i][j] = " "
            elif maze[i][j] == 2:
                ans[i][j] = "."
    ans[3][16] = "G"      
    for i in range(len(ans)):
            for j in range(len(ans[i])):
                print(ans[i][j], end=' ')
            print()
    
def solveMaze(x,y,maze):
    maze[3][16] = "G"
    check = False
    while(check == False):
        


if __name__ == '__main__':
    maze = [[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1],
            [1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1],
            [1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1],
            [1,0,0,0,0,0,0,0,1,0,1,0,1,0,1,1,0,1,0,1],
            [1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,1,0,1,0,1],
            [1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0,1],
            [1,0,1,0,1,1,1,0,1,1,1,1,1,0,1,1,0,1,0,1],
            [1,0,1,0,1,0,1,0,1,0,0,0,0,0,1,1,0,1,0,1],
            [1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1],
            [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]]
    
    solveMaze(3,3,maze)
    printMaze(maze)