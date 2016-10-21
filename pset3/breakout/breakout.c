//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);


int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);
    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);
    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);
    int wdthb = getWidth(paddle);
    int hghtb = getHeight(paddle);
    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);
    // number of bricks initially
    int bricks = COLS * ROWS;
    // number of lives initially
    int lives = LIVES;
    // number of points initially
    int points = 0;
    // keep playing until game over
    //ball speed
    double velocity_x = 2.0;//*drand48();
    double velocity_y = 3.0;
    //positioning ball
    double x_a = velocity_x;
    double y_a = velocity_y;
    double a = (getWidth(window) - getWidth(ball))/2;
    double b = (getHeight(window) - getHeight(ball))/2;
    setLocation(ball, a, b);
      
    while (lives > 0 && bricks > 0)
    {
        // TODO        
        if(points==10||points==25||points==40)
            {
                velocity_x = 0.001+velocity_x;
                velocity_y = 0.003+velocity_y;        
            }
        
        // paddle movement        
        GEvent event = getNextEvent(MOUSE_EVENT);
            if (event != NULL)
            {
                if (getEventType(event) == MOUSE_MOVED)
                {
                    double x = getX(event) - wdthb;
                    double y = 550;
                    
                    if (x<0) 
                        x=0;
                    setLocation(paddle, x, y);
                }
            } 
            move(ball, x_a, y_a);
            
            // bounce ball            
            if (getX(ball) + getWidth(ball) >= getWidth(window))
            {
                x_a = -velocity_x+cos(drand48());
            }
            
            else if (getX(ball) <= 0)
            {
                x_a = velocity_x+cos(drand48());
            }
            
            if (getY(ball) + getHeight(ball) >= getHeight(window))
            {
                lives--;
                setLocation(ball, a, b);
                
                while (true)
                {
                    GEvent evnt = getNextEvent(MOUSE_EVENT);
                    
                    if (evnt != NULL)
                        {
                            if (getEventType(evnt) == MOUSE_CLICKED)
                            {
                                move(ball, x_a, y_a);
                                break;
                            }
                        }
                }
            }
            
            else if (getY(ball) <= 0)
            {
                y_a = velocity_y-cos(drand48());
            }
            
            GObject object = detectCollision(window, ball);
            
            if (object==paddle)
            {
                y_a = -velocity_y-cos(drand48());
            }
            
            else if(object != NULL )
            {
                if (strcmp(getType(object), "GRect")==0)
                {
                    removeGWindow(window, object);
                    x_a = velocity_x-cos(drand48());
                    y_a = velocity_y-cos(drand48());
                    points++;
                    bricks--;
                }
                
                // update label
                char s[12];
                sprintf(s, "%i", points);
                setLabel(label, s);
                
                               
                // center label in window
                double x = (getWidth(window) - getWidth(label)) / 2;
                double y = (getHeight(window) - getHeight(label)) / 2;
                setLocation(label, x, y);
                
               
            }
            // linger before moving again
            pause(10);        
               
            
            
         
    } 
               
    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;    
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    // TODO
    GRect bricks[ROWS][COLS];
    int b=10;
    for (int i=0; i<ROWS; i++)
        {
        int a=2;
        for (int j=0; j<COLS; j++)
            {    
                bricks [i][j] = newGRect(a, b, 35, 5);
                if (i==0)
                {
                setColor(bricks[i][j], "YELLOW");
                setFilled(bricks[i][j], true);
                }
                if (i==1)
                {
                setColor(bricks[i][j], "GREEN");
                }
                if (i==2)
                {
                setColor(bricks[i][j], "BLUE");
                }
                if (i==3)
                {
                setColor(bricks[i][j], "ORANGE");
                }
                if (i==4)
                {
                setColor(bricks[i][j], "RED");;
                }
                
                setFilled(bricks[i][j], true);
                add(window, bricks[i][j]);
                a=a+40;               
            }
             b=b+10;
        }           
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    // TODO
    
    GOval ball = newGOval(0, 0, 20, 20);
    setColor(ball, "BLUE");
    setFilled(ball, true);
    add(window, ball);
    
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    // TODO
    double bw=100;
    GRect paddle = newGRect(150, 550, bw, 10);
    setColor(paddle, "BLACK");
    setFilled(paddle, true);
    add(window, paddle);
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    // TODO
     GLabel label = newGLabel("");
    setFont(label, "SansSerif-36");
    add(window, label);
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
