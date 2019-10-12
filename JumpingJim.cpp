//Program that solves Jumping Jim puzzle. Created for COP4400 project 3 by Ron Bakrac, 11/28/2018
//The original problem is always equal row and col length where the top left tile is the start and bottom right is the exit. 
//This program can easily be edited to choose any row/col length independently and any tile to be the start and exit (exitTile and startTile variables)
#include <iostream>    
#include <algorithm> 
#include <vector>
#include <fstream> 
#include <queue>
#include <stack>


struct node{
    int num;
    char direction;
    node(int n = -1, char d = 'x') : num(n), direction(d){}
};

std::vector<node*> bfs(const std::vector<std::vector <node*>> &adj, node *start, node *&exitnode, int exitTile);
void path(const std::vector<node*> &pred, node *target, int startTile, int exitTile, std::ofstream &f2);


int main()
{
    std::ifstream f1 ("input.txt");
    std::ofstream f2 ("output.txt");

    if(!f1.is_open() || !f2.is_open())
    {
        std::cout<<"Unable to open either input.txt or output.txt";
        return 0;
    }

    int rows, cols, val;
    f1 >> rows >> cols;

    int exitTile = rows*cols; //can be changed to whatever you want the exit tile to be. In this problem, it's always the last (assumes counting starts at 1 not 0)
    int startTile = 0;        //same concept as above. 

    std::vector<std::vector <int>> jump(rows, std::vector<int>(cols, 0));
    std::vector<std::vector <node*>> adj(exitTile);

    //creates 2D matrix of the input
    for(int i=0; i<rows; ++i)
    {
        for(int j=0; j<cols; ++j)
        {
            f1 >> val;
            jump[i][j] = val;
        }
    }


    //creates adjacency list of the input matrix. 2D vector of a struct 'node', node struct is just an ordered pair.
    //Checkes all 4 possible neighbor locations for every vertex (N,E,S,W). If valid location then added to adj list for specific vertex (index p) where node struct num=vertex num and char= direction traveled from P. 
    int p=0;
    for(int i=0; i<rows; ++i)
        for(int j=0; j<cols; ++j, ++p)
        {
            if(jump[i][j] <= 0)
                continue;

            if(i - jump[i][j] >= 0)
            {
                node *current = new node;
                current->direction='N';
                current->num = j+(cols*(i-jump[i][j]));
                adj[p].push_back(current);
            }

            if(j + jump[i][j] < cols)
            {
                node *current = new node;
                current->direction='E';
                current->num = (j+(cols*i))+jump[i][j];
                adj[p].push_back(current);
            }

            if(i + jump[i][j] < rows)
            {
                node *current = new node;
                current->direction='S';
                current->num = j+(cols*(i+jump[i][j]));
                adj[p].push_back(current);
            }
            
            if(j - jump[i][j] >= 0)
            {
                node *current = new node;
                current->direction='W';
                current->num = (j+(cols*i))-jump[i][j];
                adj[p].push_back(current);
            }

        }

    //exitnode will be updated to the correct exit node through bfs function (pass by reference). Even though I know exitnode is the last node, I don't know the direction taken to get to it.
    //There is no direction to get to the start and thus nothing gets printed for it so I am able to put in anything for direction on startnode. Start is always the first tile in this puzzle so num=0.
    //pred = predecessor array that will be printed by path function. 
    node *exitnode = new node();
    node *startnode = new node(startTile, 'x');
    std::vector<node*> pred = bfs(adj, startnode, exitnode, exitTile);

    path(pred, exitnode, startTile, exitTile, f2);

    f1.close();
    f2.close();

    std::cout<<"Successfully written to output.txt";

    return 0;

}


std::vector<node*> bfs(const std::vector<std::vector <node*>> &adj, node *start, node *&exitnode, int exitTile)
{
    node *current;
    std::queue<node*> Q;
    std::vector<node*> pred(exitTile, nullptr);
    Q.push(start);
    while(!Q.empty()) 
    {
      current = Q.front();
      Q.pop();

      //this will terminate bfs as soon as a path to the exit is found. The exit node must be saved (exitnode pointer is a reference for this reason) for print predecessor function (argument requirment)
      if(current->num == (exitTile-1))
      {
          exitnode = current;
          return pred;
      }

      //hard to read but it's right
      for(int j=0; j<adj[current->num].size(); ++j)
      {
        if(pred[adj[current->num][j]->num] == nullptr)
        {
          Q.push(adj[current->num][j]);
          pred[adj[current->num][j]->num] = current;
        }
      }

    }

    return pred;

}

//prints predecessor path
void path(const std::vector<node*> &pred, node *target, int startTile, int exitTile, std::ofstream &f2)
{
    std::stack<node*> S;
    node *current = target;

    //current is initially our exit, will have values of defualt constructor if wasn't found in bfs search (-1, 'x')
    if(current->num != exitTile-1)
    {
        f2 << "No path exists";
        return;
    }

    //go through pred array from exit to start, pushing all the nodes to a stack (otherwise would be reverse)
    while(current != nullptr && current->num != startTile) 
    {
        S.push(current);
        current = pred[current->num];
    }

    while(S.size() > 0) 
    {
        f2 << S.top()->direction << " ";
        S.pop();
    }
}