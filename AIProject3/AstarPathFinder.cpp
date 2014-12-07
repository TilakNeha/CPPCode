/*
 * AstarPathFinder.cpp
 *
 *  Created on: Dec 2, 2014
 *      Author: ntilak
 */

#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
using namespace std;

#define SIZE 60

static int grid[SIZE][SIZE];
static int topography_map[SIZE][SIZE];
static int closed[SIZE][SIZE]; // map of closed (tried-out) nodes
static int open[SIZE][SIZE]; // map of open (not-yet-tried) nodes
static int dir_map[SIZE][SIZE]; // map of directions
// The legal directions of moving-
static int dx[8]={1, 1, 0, -1, -1, -1, 0, 1};
static int dy[8]={0, 1, 1, 1, 0, -1, -1, -1};
int nodecount  = 0;
int routecost = 0;
int accurate = 1;
class Node {
private:
	int row;
    int col;
    int cost;
    int priority;
public:
    Node(int r, int c, int ct, int pr) {
    	  row =r; col = c; cost = ct; priority = pr;
    }
	int getCol() const {
		return col;
	}

	int getCost() const {
		return cost;
	}

	int getPriority() const {
		return priority;
	}

	int getRow() const {
		return row;
	}

    void findCost(int dir) {
    	// Cost of moving up, down, right, left : 10
    	// Cost of moving diagonally : 14
    	cost += (dir%2==0?10:14);
    	//Add the cost of moving up and down.
    	// Penalize for moving uphill and reward for moving downhill.
    	int diff = topography_map[row][col] - topography_map[row - dx[dir]][col - dy[dir]];
    	cost+=diff;
        //cost = 0; // This is for checking greedy behavior.
    }

    int findHeuristic(int xdest, int ydest) {
    	   static int xd, yd, d;
           xd=xdest-row;
           yd=ydest-col;

           // Euclidian Distance
           d=static_cast<int>((sqrt(xd*xd+yd*yd)) * 10);
           // Manhattan Distance 
             d = static_cast<int>((abs(xd) + abs(yd)) * 10);
           return d;
    }

    void updatePriority(int xDest, int yDest) {
    	priority=cost+ findHeuristic(xDest, yDest); //A*
    	//priority=cost; //Greedy
    }
};

// Overload < operator for priority queue.
bool operator<(const Node& n1, const Node& n2)
{
  return n1.getPriority() > n2.getPriority();
}

string findPath( const int & xStart, const int & yStart,
                 const int & xFinish, const int & yFinish )
{
    static priority_queue<Node> pq[2]; // list of open (not-yet-tried) nodes
    static int pqi; // pq index
    static Node* n0;
    static Node* m0;
    static int i, j, x, y, xdx, ydy;
    static char c;
    pqi=0;

    // reset the node maps
    for(y=0;y<SIZE;y++)
    {
        for(x=0;x<SIZE;x++)
        {
            closed[x][y]=0;
            open[x][y]=0;
        }
    }

    // create the start node and push into list of open nodes
    n0=new Node(xStart, yStart, 0, 0);
    n0->updatePriority(xFinish, yFinish);
    pq[pqi].push(*n0);
    nodecount++;
    // A* search
    while(!pq[pqi].empty())
    {
        // get the current node w/ the highest priority
        // from the list of open nodes
        n0=new Node( pq[pqi].top().getRow(), pq[pqi].top().getCol(),
                     pq[pqi].top().getCost(), pq[pqi].top().getPriority());

        x=n0->getRow(); y=n0->getCol();
        int temp1 = pq[pqi].top().getCost();
        pq[pqi].pop(); // remove the node from the open list
        open[x][y]=0;
        // mark it on the closed nodes map
        closed[x][y]=1;

        // Stop searching when the goal state is reached

        if(x==xFinish && y==yFinish)
        {
        	routecost = temp1;
            // generate the path from finish to start
            // by following the directions
            string path="";
            while(!(x==xStart && y==yStart))
            {
                j=dir_map[x][y];
                c='0'+(j+4)%8;
                path=c+path;
                x+=dx[j];
                y+=dy[j];
            }

            // garbage collection
            delete n0;
            // empty the leftover nodes
            while(!pq[pqi].empty()) pq[pqi].pop();
            return path;
        }

        // generate moves (child nodes) in all possible directions
        for(i=0;i<8;i++)
        {
            xdx=x+dx[i]; ydy=y+dy[i];

            if(!(xdx<0 || xdx>SIZE-1 || ydy<0 || ydy>SIZE-1 || grid[xdx][ydy]==1
                || closed[xdx][ydy]==1))
            {
                // generate a child node
                m0=new Node( xdx, ydy, n0->getCost(),
                             n0->getPriority());
                m0->findCost(i);
                m0->updatePriority(xFinish, yFinish);

                // if it is not in the open list then add into that
                if(open[xdx][ydy]==0)
                {
                    open[xdx][ydy]=m0->getPriority();
                    pq[pqi].push(*m0);
                    nodecount++;
                    // mark its parent node direction
                    dir_map[xdx][ydy]=(i+8/2)%8;
                }
                else if(open[xdx][ydy]>m0->getPriority())
                {
                    // update the priority info
                    open[xdx][ydy]=m0->getPriority();
                    // update the parent direction info
                    dir_map[xdx][ydy]=(i+4)%8;

                    // replace the node
                    // by emptying one pq to the other one
                    // except the node to be replaced will be ignored
                    // and the new node will be pushed in instead
                    while(!(pq[pqi].top().getRow()==xdx &&
                           pq[pqi].top().getCol()==ydy))
                    {
                        pq[1-pqi].push(pq[pqi].top());
                        pq[pqi].pop();
                    }
                    pq[pqi].pop(); // remove the wanted node

                    // empty the larger size pq to the smaller one
                    if(pq[pqi].size()>pq[1-pqi].size()) pqi=1-pqi;
                    while(!pq[pqi].empty())
                    {
                        pq[1-pqi].push(pq[pqi].top());
                        pq[pqi].pop();
                    }
                    pqi=1-pqi;
                    pq[pqi].push(*m0); // add the better node instead
                }
                else delete m0; // garbage collection
            }
        }
        delete n0; // garbage collection
    }
    return ""; // no route found
}

int main() {
	//srand(time(NULL));

	// create empty map
    // Randomly add elevation to each cell of the map.
    for(int y=0;y<SIZE;y++) {
        for(int x=0;x<SIZE;x++) {
        	grid[x][y]=0;
        	topography_map[x][y] = rand() % 10;
        }
    }

    
    // Add obstacles in the grid. in a X pattern.
    for (int i = 15; i< SIZE - 15; i ++) {
    	grid[i][i] = 1;
        grid[i][i+1] = 1;
    	grid[i][SIZE-i] = 1;
        grid[i][SIZE-i+1]= 1;
    }


    // Randomly select start and finish locations
    int xA, yA, xB = 0, yB = 0;

     xA = 3;
     yA = 4;
     xB = 55;
     yB = 49;
    //xA = rand() % SIZE;
    //yA = rand() % SIZE;
    //xB = rand() % SIZE;
    //yB = rand() % SIZE;
    cout<<"Map Size (X,Y): "<<SIZE<<","<<SIZE<<endl;
    cout<<"Start: "<<xA<<","<<yA<<endl;
    cout<<"Finish: "<<xB<<","<<yB<<endl;
    string route=findPath(xA, yA, xB, yB);
 
    // follow the route on the map and display it
        if(route.length()>0)
        {
            int j; char c;
            int x=xA;
            int y=yA;
            grid[x][y]=2;
            for(unsigned int i=0;i<route.length();i++)
            {
                c =route.at(i);
                j=atoi(&c);
                x=x+dx[j];
                y=y+dy[j];
                grid[x][y]=3;
            }
            grid[x][y]=4;

            // display the map with the route
            for(int y=0;y<SIZE;y++)
            {
                for(int x=0;x<SIZE;x++)
                    if(grid[x][y]==0)
                        cout<<".";
                    else if(grid[x][y]==1)
                        cout<<"O"; //obstacle
                    else if(grid[x][y]==2)
                        cout<<"S"; //start
                    else if(grid[x][y]==3) {
                        cout<<"R"; //route
                    }
                    else if(grid[x][y]==4)
                        cout<<"F"; //finish
                cout<<endl;
            }
        }
        cout << endl << "Space taken by all " << nodecount << " nodes created is " << (sizeof(Node) * nodecount) << " bytes." << endl;
        cout << "Cost of reaching the destination is " << routecost << endl;
        cout << "Route length = " << route.length() << endl;

     return 0;
}
