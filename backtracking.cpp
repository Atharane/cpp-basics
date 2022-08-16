#include <bits/stdc++.h>
using namespace std;

void printMaze(vector<vector<int>> maze)
{
    for (int i = 0; i < maze.size(); i++)
    {
        for (int j = 0; j < maze[0].size(); j++)
        {
            if (maze[i][j])
            {
                if (maze[i][j] == 2)                
                    printf("\033[0;32m"); // Set the text color to green
                
                cout << "◼ ";
                printf("\033[0m"); // Resets the text color
            }
            else
                cout << "□ ";
        }
        cout << endl;
    }
}

bool isBlocked(vector<vector<int>> maze, int rowIdx, int colIdx)
{
    if (rowIdx >= maze.size() || colIdx >= maze[0].size() || rowIdx < 0 || colIdx < 0)
        return true;

    return maze[rowIdx][colIdx];
}

bool solveMaze(vector<vector<int>> maze, int startRow, int startCol)
{
    // invalid starting state
    if (isBlocked(maze, startRow, startCol))
        return false;

    // base case
    if (startRow == maze.size() - 1 && startCol == maze[0].size() - 1)
    {
        maze[startRow][startCol] = 2;
        printMaze(maze);
        return true;
    }

    // mark the current cell as visited
    maze[startRow][startCol] = 2;

    // move up
    if (solveMaze(maze, startRow - 1, startCol)) 
        return true;
    
    // move down
    if (solveMaze(maze, startRow + 1, startCol))
        return true;

    // move left
    if (solveMaze(maze, startRow, startCol - 1))
        return true;
    
    // move right
    if (solveMaze(maze, startRow, startCol + 1))
        return true;

    // unmark the current cell as visited & backtrack
    maze[startRow][startCol] = 0;
    return false;
}

void printSudoku(int arr[][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (arr[i][j])
                cout << arr[i][j] << " ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}

bool solveSudoku(int arr[][9], int startRow, int startCol)
{
    // invalid starting state
    if (arr[row][col])
        ;

    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < count; j++)
        {
            if (arr[i][j])
                continue;

            
                for (size_t k = 1; value <= 9; k++)
                {
                    if (isValid(arr, i, j, k))
                    {
                        arr[i][j] = k;
                        if (solveSudoku(arr, i, j))
                            return true;
                        arr[i][j] = 0;
                    }
                }
                return false;
            
        }
        
    }
        

    // base case
    if (startRow == maze.size() - 1 && startCol == maze[0].size() - 1)
    {
        maze[startRow][startCol] = 2;
        printMaze(maze);
        return true;
    }

    // mark the current cell as visited
    maze[startRow][startCol] = 2;

    // move up
    if (solveMaze(maze, startRow - 1, startCol)) 
        return true;
    
    // move down
    if (solveMaze(maze, startRow + 1, startCol))
        return true;

    // move left
    if (solveMaze(maze, startRow, startCol - 1))
        return true;
    
    // move right
    if (solveMaze(maze, startRow, startCol + 1))
        return true;

    // unmark the current cell as visited & backtrack
    maze[startRow][startCol] = 0;
    return false;
}

int main()
{
    vector<vector<int>> maze = {
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0}};

    // printMaze(maze);
    // cout << endl;
    // solveMaze(maze, 0, 0);

    int sudokuArr[][9] = {
        { 2, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 6, 2, 0, 0 },
        { 0, 0, 1, 0, 0, 0, 0, 7, 0 },
        { 0, 0, 6, 0, 0, 8, 0, 0, 0 },
        { 3, 0, 0, 0, 9, 0, 0, 0, 7 },
        { 0, 0, 0, 6, 0, 0, 4, 0, 0 },
        { 0, 4, 0, 0, 0, 0, 8, 0, 0 },
        { 0, 0, 5, 2, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 3 },
    };

    printSudoku(sudokuArr);
    
    return 0;
}