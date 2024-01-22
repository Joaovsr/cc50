/***************************************************************************
 * fifteen.c
 *
 * CC50
 * Pset 3
 *
 * Implements The Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 ***************************************************************************/
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9


// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;


// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

// GOD MODE
void god_mode(void);

// possible movements
int possibilites[4];
int len = 0;
// blank space coordinates
int x, y = 0; 
// function to update possibilites
void check_possibilites();

int
main(int argc, char *argv[])
{
    // greet user with instructions
    greet();

    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: %s d\n", argv[0]);
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %d x %d and %d x %d, inclusive.\n",
         DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }
		
        // prompt for move
        int tile = 0;
		string input = get_string("Tile to move:");
		if(strcmp(input,"GOD")==0){
			god_mode();
			break;
		}else
			tile = atoi(input);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }

    // that's all folks
    return 0;
}


/*
 * Clears screen using ANSI escape sequences.
 */

void
clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}


/*
 * Greets player.
 */

void
greet(void)
{
    clear();
    printf("WELCOME TO THE GAME OF FIFTEEN\n");
    usleep(2000000);
}


/*
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */

void
init(void)
{
    // define a counter and populate the array
    int c = 1;
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++){
	    // fill the tiles in descending order
	    if (c == d * d)
	        c = 0;
	    
	    board[i][j] = c;
	    c++;
	}
    }
    
	srand((unsigned int)time(NULL));
    int difficulty = rand() % 81 + 20; 
	
	x = d - 1;
	y = d - 1;	
	check_possibilites();
	
	for (int i = 0; i < difficulty; i++){
		int r = rand() % len;
		int tile_to_move = possibilites[r];
		printf("%d ",move(tile_to_move));
	}
	
}


/* 
 * Prints the board in its current state.
 */

void
draw(void)
{
	clear();
    for (int i = 0; i < d; i++){
        for (int j=0; j < d; j++){
	    if (board[i][j] == 0)
	        printf("[_]");
	    else
		printf("%2d ", board[i][j]);
	}
	printf("\n");
    }
}


/* 
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */

bool
move(int tile)
{	
	// verify if is possible to make the move
	bool possible = false;
    for(int i=0; i<len; i++)
		if (possibilites[i] == tile)
			possible = true;

	// if not possible return false
	if (!possible)
		return false;
	
	int x_temp = 0;
	int y_temp = 0;
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++){
			if (board[i][j] == tile){
				board[i][j] = 0;
				x_temp = i;
				y_temp = j;
			}
		}
	}

	board[x][y] = tile;
	x = x_temp;
	y = y_temp;

	check_possibilites();
    return true;
}


/*
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */

bool
won(void)
{
    int n = 1;

	// check to see if last tile is blank and return false if it is not
	if(board[d-1][d-1] != 0)
		return false;

	// set up for loops to check if number are in ascending order beginning with 1
	for (int i = 0; i < d; i++){
		for (int j = 0; j < d; j++){
			// check last grid position first, if blank, return true
			if (i == d - 1 && j == d - 1)
				return true;

			// check the numbers on the rest of the tiles
			if (n != board[i][j])
				return false;
			n++;
		}
	}
	return true;
}

/*
 * Check possibilites and update the array possibilites
 */

void
check_possibilites(void){
	len = 0;
		
	if (x == 0)
		possibilites[len++] = board[1][y];
	else if (x == d-1)
		possibilites[len++] = board[x-1][y];
	else {
		possibilites[len++] = board[x-1][y];
		possibilites[len++] = board[x+1][y];
	}
		
	if (y == 0)
		possibilites[len++] = board[x][1];
	else if (y == d-1)
		possibilites[len++] = board[x][y-1];
	else {
		possibilites[len++] = board[x][y-1];
		possibilites[len++] = board[x][y+1];
	}
}

void 
god_mode(void){
	//int row = 0;
	while(true){
					
		int n = 1;
		for (int i = 0; i < d; i++){
			for (int j = 0; j < d; j++){
				// check the numbers on the rest of the tiles
				if (n != board[i][j]){
					//row = (n-1) / d;
					//printf("%d", row);
					//printf("%d", n);
					//get_int(" ");
					goto leave;
				}
				n++;

			}
		}
		
		leave:

		int a_len = 0;
		int a_poss[4];
		for (int i = 0; i < len; i++){
			if(possibilites[i] > n-1)
				a_poss[a_len++] = possibilites[i];
		}

		int r = rand() % a_len;
		int tile = a_poss[r];
		move(tile);

		// clear the screen
		clear();

		// draw the current state of the board
		draw();

		// check for win
		if (won())
		{
			printf("ftw!\n");
			break;
		}

		usleep(500);
	}
}

