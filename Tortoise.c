#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int eat(int rows,int columns,char (*array)[columns],char direct){
    int eatCount;
    int playerX;
    int playerY;
   
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < columns ; j++){
            if(array[i][j] == '@'){
                playerX = j;
                playerY = i;
            }
        }
    }
    //EAT DIRECTON DEFINE
    if(direct == 'N'){
        if(array[playerY-1][playerX] == '*'){
            array[playerY-1][playerX] = '_';
            eatCount = 1;
        }
        else{
            printf("THERE IS NO FOOD!\n");
            eatCount = 0;  
        }
    }    
    else if(direct == 'S'){
        if(array[playerY+1][playerX] == '*'){
            array[playerY+1][playerX] = '_';
            eatCount = 1;
        }
        else{
            printf("THERE IS NO FOOD!\n");
            eatCount = 0;  
        }
    }    
    else if(direct == 'W'){
        if(array[playerY][playerX-1] == '*'){
            array[playerY][playerX-1] = '_';
            eatCount = 1;
        }
        else{
            printf("THERE IS NO FOOD!\n");
            eatCount = 0;  
        }
    }    
    else if(direct == 'E'){
        if(array[playerY][playerX+1] == '*'){
            array[playerY][playerX+1] = '_';
            eatCount = 1;
        }
        else{
            printf("THERE IS NO FOOD!\n");
            eatCount = 0;  
        }
    } 
    else{
        printf("YOU COMMAND CANT BE HAPPEN!\n");
    }
    return eatCount;
}


int move(int rows,int columns,char (*array)[columns],char direct){
    int playerX;
    int playerY;
    int moveCount;
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < columns ; j++){
            if(array[i][j] == '@'){
                playerX = j;
                playerY = i;
            }
        }
    }
    //PLAYER CONTROL DEFINE
    if(direct == 'N'){
        if(array[playerY-1][playerX] == '0'){
            array[playerY][playerX] = '_';
            moveCount = 2;
        }
        else{
            if(playerY > 0 && array[playerY-1][playerX] == '_'){
                array[playerY][playerX] = '_';
                playerY--;
                array[playerY][playerX] = '@';
                moveCount = 1;
            }
            else{
                printf("PLAYER CANT MOVE THERE!\n");
                moveCount = 0;  
            }
        }
    }
    else if(direct == 'S'){
        if(array[playerY+1][playerX] == '0'){
            array[playerY][playerX] = '_';
            moveCount = 2;
        }
        else{
            if(playerY < columns-1 && array[playerY+1][playerX] == '_'){
                array[playerY][playerX] = '_';
                playerY++;
                array[playerY][playerX] = '@';
                moveCount = 1;
            }
            else{
                printf("PLAYER CANT MOVE THERE!\n");
                moveCount = 0;  
            }  
        }
    }
    else if(direct == 'E'){
        if(array[playerY][playerX+1] == '0'){
            array[playerY][playerX] = '_';
            moveCount = 2;
        }
        else{
            if(playerX < columns-1 && array[playerY][playerX+1] == '_'){
                array[playerY][playerX] = '_';
                playerX++;
                array[playerY][playerX] = '@';
                moveCount = 1;
            }
            else{
                printf("PLAYER CANT MOVE THERE!\n");
                moveCount = 0;  
            }
        }
    }
    else if(direct == 'W'){
        if(array[playerY][playerX-1] == '0'){
            array[playerY][playerX] = '_';
            moveCount = 2;
        }
        else{
            if(playerX > 0 && array[playerY][playerX-1] == '_'){
                array[playerY][playerX] = '_';
                playerX--;
                array[playerY][playerX] = '@';
                moveCount = 1;
            }
            else{
                printf("PLAYER CANT MOVE THERE!\n");
                moveCount = 0;  
            }
        }
    }
    else{
        printf("YOU COMMAND CANT BE HAPPEN!\n");
    }
    return moveCount;
}
// Function to print a two-dimensional array
void print_array(int rows,int columns,int timeLine,int energy,char (*array)[columns]){
  // Seed the random number generator with the current time
    srand(time(0)); 
    if(timeLine == 1){
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                array[i][j] = '_';
            }
        }
        // Generate random starting location for the player
        int player_row = rand() % rows;
        int player_col = rand() % columns;
        // Set the player on the board
        array[player_row][player_col] = '@';
        //MulberriesCordinate
        for(int i = 0 ; i < ceil(0.15 * (rows * columns)) ; i++)
	    {
		    int cordinateX = rand() %rows;
    	    int cordinateY = rand() %columns;
    	    if(array[cordinateX][cordinateY] == '_')
		    {
			    array[cordinateX][cordinateY] = '*';
		    }
		    else
		    {
	            i--;
		    }
	    }
	    //PitsCordinate
        for(int i = 0 ; i < ceil(0.05 * (rows * columns)) ; i++)
	    {
		    int cordinateX = rand() %rows;
    	    int cordinateY = rand() %columns;
    	
    	    if(array[cordinateX][cordinateY] == '_')
		    {
			    array[cordinateX][cordinateY] = '0';
		    }
		
		    else
		    {
			    i--;
		    }
	    }
    }
  //Print board
  printf("Time = %d Energy level: %d \n\n",timeLine,energy);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      printf("%c ", array[i][j]);
    }
    printf("\n");
  }
}
int main(void){
  // Initialize the board with empty spaces
  int size;
  int game = 0;
  int count = 1;
  int timeLine = 1;
  int energy = 30;
  printf("Welcome to the Tortoise Game.\nPlease specify the size of the board: ");
  scanf("%d",&size);
  int number = size;
  printf("\n");
  char board[number][number];
  // Print the board with the player
  while (game != 1){
    if(count == 1){
        print_array(number,number,timeLine,energy,board);
        int food_remaining = 0;
        for (int i = 0; i < number; i++) {
            for (int j = 0; j < number; j++) {
                if (board[i][j] == '*') {
                    food_remaining = 1;
                }
            }
        }
        if(food_remaining == 0){
            printf("CONGRAGULATIONS, YOU WON :-)");
            return 0;
        }
    }
    if(energy <= 0){
        printf("YOU LOST :-(\nTHE GAME IS OVER!");
        game = 1;
    }
    char command;
    char direction;
    if(energy > 0){
        printf("Enter a command (M/E): ");
        scanf("%s",&command);
        if(command == 'M'){
        //Move the character
            printf("Enter a direction (N/S/E/W): ");
            scanf("%s",&direction);
            count = move(number,number,board,direction);
            if(count == 1){
                energy -= 10;
                timeLine++;
            }
            else if(count == 2){
                energy -= 10;
                timeLine++;
                print_array(number,number,timeLine,energy,board);
                printf("YOU LOST :-(\nTHE GAME IS OVER!\n");
                game = 1;
            }
        }
        else if(command == 'E'){
        //Eat the food
            printf("Enter a direction (N/S/E/W): ");
            scanf("%s",&direction);
            count = eat(number,number,board,direction);
            if(count == 1){
                energy += 10;
                timeLine++;
            }
        }
        else{
            printf("YOU COMMAND CANT BE HAPPEN!\n");
        }
    }
  }
  return 0;
}