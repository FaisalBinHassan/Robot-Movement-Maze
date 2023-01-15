// Simple Counter(Right/Left) Algorthim -> Code
// Libraries 
#include "graphics.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Global 2d maze layout matrix [1] = Black, [0] = White, [2] = Grey(Final Destination)
int Maze_Matrix[11][11] = { 
        {0,0,1,1,1,1,1,1,1,1,1}, 
        {1,0,0,0,0,0,0,0,0,0,1},  
        {1,0,1,1,1,1,0,1,1,0,1},  
        {1,0,1,1,1,1,0,1,1,0,1},  
        {1,0,0,1,1,1,0,0,0,0,1}, 
        {1,1,0,1,1,1,0,1,1,0,1},  
        {1,0,0,1,1,1,0,1,1,0,1}, 
        {1,0,0,1,1,1,0,1,1,0,1}, 
        {1,0,0,0,0,0,0,0,0,0,1}, 
        {1,1,1,1,1,1,1,1,0,0,2}, 
        {1,1,1,1,1,1,1,1,1,1,1}, };

// Drawing the maze pattern through the 2d array
void Pattern() {

    // Window size
    setWindowSize(495,495);

    // Draw the pattern in the background, and initiate block size
    background();
    const int squareSize = 45 ;
    const int width = 20 ;
    const int height = 20 ;
    
    // Draw the Maze, think of drawing squares like chess, but with the maze matrix layout!
    for ( int row = 0 ; row < height ; row++ ) {
        for ( int column = 0 ; column < width ; column++ ) {
            
            // Draw the square at the [i][j] plot being [Black]
            if ( Maze_Matrix[row][column] == 1 )
            {
                background();
                setColour(black) ;
                fillRect(column * squareSize, row * squareSize, squareSize, squareSize) ;

            }

            // Draw the square at the [i][j] plot being [White] ( so no background transparent), only [Black] borders
            else if ( Maze_Matrix[row][column] == 0)
            {
                background();
                setColour(black);
                drawRect(column * squareSize, row * squareSize, squareSize, squareSize);
            }
            // Draw the square at the [i][j] plot being [Grey]
            else
            {
                background();
                setColour(gray) ;
                fillRect(column * squareSize, row * squareSize, squareSize, squareSize) ;
            }
        }        
    }

}

// Struct having x and y coordinates of the robot, and direction of the robot [East,West,South,North].
struct robot
{
    int x;
    int y;
    char direction[100];
};

// Function called if the robot should be drawn NOW!
// Draw the robot as a polygen shape...
void DrawingRobot(struct robot *Robot){
    
    // Everything except the pattern of the mze should be drawn in the foreground layer...
    foreground();

    // Clear past robot drawing, we are drawing a new robot 
    clear();

    // Draw the robot facing the West side.
    if ( strcmp((Robot->direction),"West") == 0 ) 
    {
        // The polygen(Robot) is drawn by taking the x/y coordinate of the robot and fitting it to the square formation
        int x_west[] = {((Robot->y)*45)+45,((Robot->y)*45)+45,((Robot->y)*45)+0};
        int y_west[] = {((Robot->x)*45)+0,((Robot->x)*45)+45,((Robot->x)*45)+23};
        
        // Both x and y arrays should be colored red and filled to the polygen function.
        setColour(red);
        fillPolygon(3,x_west,y_west);
        sleep(150);
    }
    // Draw the robot facing the East side.
    else if ( strcmp((Robot->direction),"East") == 0 ) 
    {
        // The polygen(Robot) is drawn by taking the x/y coordinate of the robot and fitting it to the square formation
        int x_east[] = {((Robot->y)*45)+0,((Robot->y)*45)+0,((Robot->y)*45)+45};
        int y_east[] = {((Robot->x)*45)+0,((Robot->x)*45)+45,((Robot->x)*45)+23};
        
        // Both x and y arrays should be colored red and filled to the polygen function.
        setColour(red);
        fillPolygon(3,x_east,y_east);
        sleep(150);
    }
    // Draw the robot facing the South side.
    else if ( strcmp((Robot->direction),"South") == 0 ) 
    {
        // The polygen(Robot) is drawn by taking the x/y coordinate of the robot and fitting it to the square formation
        int x_south[] = {((Robot->y)*45)+0,((Robot->y)*45)+45,((Robot->y)*45)+23};
        int y_south[] = {((Robot->x)*45)+0,((Robot->x)*45)+0,((Robot->x)*45)+45};
        
        // Both x and y arrays should be colored red and filled to the polygen function.
        setColour(red);
        fillPolygon(3,x_south,y_south);
        sleep(150);
    }
    // Draw the robot facing the North side.
    else if ( strcmp((Robot->direction),"North") == 0 ) 
    {
        // The polygen(Robot) is drawn by taking the x/y coordinate of the robot and fitting it to the square formation
        int x_north[] = {((Robot->y)*45)+0,((Robot->y)*45)+45,((Robot->y)*45)+23};
        int y_north[] = {((Robot->x)*45)+45,((Robot->x)*45)+45,((Robot->x)*45)+0};
        
        // Both x and y arrays should be colored red and filled to the polygen function.
        setColour(red);
        fillPolygon(3,x_north,y_north);
        sleep(150);
    }
}

// Move the robot (staying still in same place - sqaure) to the left position.
void Left(struct robot *Robot)
{
    // The robot should always be drawn in the 2nd layer.
    foreground();
    clear();
    sleep(150); 

    // The robot initial direction should move left toward the South if it was in -> West
    if ( strcmp((Robot->direction),"West") == 0 ) 
    {
        // Change direction to South and draw the robot to it's new direction
        strcpy(Robot->direction , "South");
        DrawingRobot(Robot);
    }
    // The robot initial direction should move left toward the North if it was in -> East
    else if ( strcmp((Robot->direction),"East") == 0 ) 
    {
        // Change direction to North and draw the robot to it's new direction
        strcpy(Robot->direction , "North");
        DrawingRobot(Robot);
    }
    // The robot initial direction should move left toward the East if it was in -> South
    else if ( strcmp((Robot->direction),"South") == 0 ) 
    {
        // Change direction to East and draw the robot to it's new direction
        strcpy(Robot->direction , "East");
        DrawingRobot(Robot);
    }
    // The robot initial direction should move left toward the West if it was in -> North
    else if ( strcmp((Robot->direction),"North") == 0 ) 
    {
        // Change direction to West and draw the robot to it's new direction
        strcpy(Robot->direction , "West");
        DrawingRobot(Robot);
    }
}

// Move the robot (staying still in same place - sqaure) to the Right position.
void Right(struct robot *Robot)
{
    // The robot should always be drawn in the 2nd layer.
    foreground();
    clear();
    sleep(150);

    // The robot initial direction should move left toward the North if it was in -> West
    if ( strcmp((Robot->direction),"West") == 0 ) 
    {
        // Change direction to North and draw the robot to it's new direction
        strcpy(Robot->direction , "North");
        DrawingRobot(Robot);
    }
    // The robot initial direction should move left toward the South if it was in -> East
    else if ( strcmp((Robot->direction),"East") == 0 ) 
    {
        // Change direction to South and draw the robot to it's new direction
        strcpy(Robot->direction , "South");
        DrawingRobot(Robot);
    }
    // The robot initial direction should move left toward the West if it was in -> South
    else if ( strcmp((Robot->direction),"South") == 0 ) 
    {
        // Change direction to West and draw the robot to it's new direction
        strcpy(Robot->direction , "West");
        DrawingRobot(Robot);
    }
    // The robot initial direction should move left toward the East if it was in -> North
    else if ( strcmp((Robot->direction),"North") == 0 ) 
    {
        // Change direction to East and draw the robot to it's new direction
        strcpy(Robot->direction , "East");
        DrawingRobot(Robot);
    }
}

// Check the robot if it landed in the direction - (Grey Square)
int At_Marker(struct robot *Robot)
{
    // Check if the robot is at value 2 in the matrix - Grey Square
    if (  Maze_Matrix[(Robot->x)][Robot->y] == 2 )
    {
        return 1;
    }
    else{
        return 0;
    }
}

// Check if the robot position with it's initial direction CAN/CAN'T move forward...
int CanMoveForward(struct robot *Robot)
{
    // Initial robot direction is West
    if ( strcmp((Robot->direction),"West") == 0 ) 
    {
        // MOVE if the West direction of the current robot direction is 2(destination) or 0(white movable square) then move!
        if ( Maze_Matrix[(Robot->x)][Robot->y-1] == 0 ||  Maze_Matrix[(Robot->x)][Robot->y-1] == 2 )
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }
    // Initial robot direction is East
    if ( strcmp((Robot->direction),"East") == 0 ) 
    {
        // MOVE if the East direction of the current robot direction is 2(destination) or 0(white movable square) then move!
        if ( Maze_Matrix[(Robot->x)][Robot->y+1] == 0 ||  Maze_Matrix[(Robot->x)][Robot->y+1] == 2 ) 
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }
    // Initial robot direction is South
    if ( strcmp((Robot->direction),"South") == 0  ) 
    {
        // MOVE if the South direction of the current robot direction is 2(destination) or 0(white movable square) then move!
        if ( Maze_Matrix[(Robot->x)+1][Robot->y] == 0 ||  Maze_Matrix[(Robot->x)+1][Robot->y] == 2 ) 
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }
    // Initial robot direction is North
    if ( strcmp((Robot->direction),"North") == 0 ) 
    {
        // MOVE if the North direction of the current robot direction is 2(destination) or 0(white movable square) then move!
        if ( Maze_Matrix[(Robot->x)-1][Robot->y] == 0 ||  Maze_Matrix[(Robot->x)-1][Robot->y] == 2 )
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }
    return 0;
}

// Move the robot forward, with whatever it's direction.
void Forward(struct robot *Robot)
{
    //Left - Move the robot towards left, so decrement the (y)
    if ( strcmp((Robot->direction),"West") == 0 ) 
    {
        Robot->y -= 1;
        DrawingRobot(Robot);
    }
    //Right - Move the robot towards Right, so increment the (y)
    if ( strcmp((Robot->direction),"East") == 0 ) 
    {
        Robot->y += 1;
        DrawingRobot(Robot);
    }
    //Down - Move the robot towards Down, so increment the (x)
    if ( strcmp((Robot->direction),"South") == 0 ) 
    {
        Robot->x += 1;
        DrawingRobot(Robot);
    }
    //Up - Move the robot towards Up, so decrement the (x)
    if ( strcmp((Robot->direction),"North") == 0 ) 
    {
        Robot->x -= 1;
        DrawingRobot(Robot);
    }
}


int main(void) {
    
    // Draw the initial Robot in the 2nd layer, above the background(pattern)
    foreground();

    // 1st thing to start the program is to draw the maze pattern
    Pattern();
    
    // Assign the structure done, and point it to a reference value
    struct robot *robotnPtr, arobot;
    robotnPtr = &arobot;  
    
    // Initialise the first x,y coorfinates and direction of the robot, and Draw it..
    robotnPtr->x=0;
    robotnPtr->y=0;
    strcpy(robotnPtr->direction , "East");
    DrawingRobot(robotnPtr);

    // Algorithm made to move the robot RIGHT (first) then (LEFT) and towards this loop...
    // The robot should move with this procedure with making sure it not moving after it got to the marker nor into the black squares
    int counter = 2;
    while ( !At_Marker(robotnPtr) )
    {
        // The robot should move forward until it stops by a black square, if stopped at the marker then EXIT program...
        while ( CanMoveForward(robotnPtr) )
        {
            Forward(robotnPtr);
            if ( At_Marker(robotnPtr) )
                exit(0);
        }
        
        // Move left after it being through a right. Counter being even, and then increment...
        if (counter % 2 )
        {
            Left(robotnPtr);
            counter++; 
        }
        else
        {
            Right(robotnPtr);
            counter++; 
        }
    }
}