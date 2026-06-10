#include<iostream>
#include<vector>
using namespace std;

/*
    PROBLEM:
    Given a maze represented by a 2D matrix where:
        1 = Open cell (can move through)
        0 = Blocked cell (cannot move through)

    A rat starts at the top-left corner (0,0) and needs to reach
    the bottom-right corner (n-1,m-1).

    The goal is to find and print all possible valid paths from
    the source to the destination.

    APPROACH (Backtracking):

    1. Start from cell (0,0).
    2. Maintain:
        - A 'path' vector to store the current path.
        - A 'visited' matrix to prevent revisiting cells and
          creating cycles.
    3. At each cell:
        - Add the current cell to the path.
        - Mark it as visited.
    4. If the destination cell is reached:
        - Print the path.
        - Backtrack to explore other possible paths.
    5. Explore all four possible directions:
        - Down
        - Up
        - Right
        - Left
       Only move if the next cell:
        - Lies within maze boundaries.
        - Contains a value of 1.
        - Has not been visited already.
    6. After exploring all valid moves:
        - Unmark the current cell as visited.
        - Remove it from the current path.
       This allows the cell to be reused in different paths.

    WHY BACKTRACKING?
    Backtracking is used because we need to explore every possible
    route from source to destination. After exploring one route,
    we undo our choices and try alternative paths.

    TIME COMPLEXITY:
    O(4^(N*M)) in the worst case, since each cell can potentially
    explore up to 4 directions.
*/

void printPath(vector<pair<int,int>>& path)
{
    cout << "Path FOUND: ";
    for(int i = 0; i < path.size(); i++)
    {
        cout << path[i].first << "," << path[i].second << "  ";
    }
        cout << endl;
}

bool isSafe(vector<vector<int>>& maze, vector<vector<bool>>& visited, int possibleX, int possibleY)
{
    if(possibleX >= 0 && possibleX < maze.size() && possibleY >= 0 && possibleY < maze[0].size() && maze[possibleX][possibleY] == 1 && !visited[possibleX][possibleY])
    {
        return true;
    }

    return false;
}

void helper(vector<vector<int>>& maze, vector<pair<int,int>>& path, vector<vector<bool>>& visited, int x, int y)
{
    path.push_back(pair<int,int>(x,y));
    visited[x][y] = true;

    if(x == maze.size() - 1 && y == maze[0].size() - 1)
    {
        printPath(path);
        path.pop_back();
        visited[x][y] = false;
        return;
    }
    
    if (isSafe(maze, visited, x+1, y))
    {
        helper(maze, path, visited, x + 1, y);
    }
    if (isSafe(maze, visited, x-1, y))
    {
        helper(maze, path, visited, x - 1, y);
    }
    if (isSafe(maze, visited, x, y+1))
    {
        helper(maze, path, visited, x, y + 1);
    }
    if (isSafe(maze, visited, x, y-1))
    {
        helper(maze, path, visited, x, y - 1);
    }

    visited[x][y] = false;
    path.pop_back();
}

void RatInAMaze(vector<vector<int>>& maze)
{
    vector<pair<int,int>> path;
    vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
    helper(maze, path, visited, 0, 0);
}

int main()
{
    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};
    RatInAMaze(maze);
    return 0;
}