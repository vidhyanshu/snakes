#include<iostream>
#include<stdlib.h>//
#include<time.h>//time
#include<conio.h>//_kbhit() and _getch()
#include<windows.h>// sleep() function
using namespace std;
int score=0;
char input;

int y_orignal,x_orignal;
bool gameover = 0;
enum direction { stop=0, LEFT, RIGHT, UP ,DOWN};
direction dir;

class draw
{
	private:
		int x_snake,y_snake,x_food,y_food;
		char space[25][50];
	public:
		void boundary()  
		{
				for(int i=1;i<=23;i++)
			{
				for(int j=1;j<=48;j++)
				{
					space[i][j]=' ';
				}
				
			}// prints the inner space
			
			for(int i=1;i<=24;i++)
			{
				space[i][0]='#';
				space[i][49]='#';
		
			}// vertical boundry
			
			
			cout<<endl;
			for(int j=1;j<49;j++)
			{
				space[0][j]='#';
				space[24][j]='#';
			}// horizontal boundary
		}
		void display()
		{
			for(int i=0;i<=24;i++)
			{
				for(int j=0;j<=49;j++)
				{
					cout<<space[i][j];
				}
				cout<<endl;
			}
		}// prints the complete graph
		void initialize_snake()
		{
			
			x_snake=rand()%23+1;
			y_snake = rand()%48+1;
				 
			
		}//inititalizes the initital posititon of the snake 
		void initialize_food()
		{
			rand:
			x_food =  rand()%23+1;
			y_food = rand()%48+1;
			if(x_snake==x_food && y_snake==y_food)
			 {
			 	goto rand;
			}
			
		}//initializes the position of food
		void take_input()
		{
			if(_kbhit()) // _kbhit() lies in conio.h it returns true or false keyboard hit
		{
				switch(_getch()) // _getch() gets the charecter
			{
				case 'a':
					dir= LEFT;
					break;
				case 'd':
					dir= RIGHT;
					break;
				case 'w':
					dir= UP;
					break;
				case 's':
					dir= DOWN;
					break;
				default :
					break;
			}
		}
		// it desides the direction of the head
		
			
		}
		void action()
		{
			x_orignal=x_snake;
				y_orignal=y_snake;
				//saves the orignal positions so we can change the orignal positions to blanks
			switch(dir)
			{
				
				case LEFT:
					y_snake--;
					break;
				case RIGHT:
					y_snake++;
					break;
				case UP:
					x_snake--;
					break;
				case DOWN:
					x_snake++;
					break;
				default :
					break;
				
					
			 }			
			 // takes the movement 
			 if(x_snake==x_food && y_snake==y_food)
			 {
			 	score+=10;
				  //when the head reaches the food position score increases
			 	rand:
			x_food =  rand()%23+1;
			y_food = rand()%48+1;
			if(x_snake==x_food && y_snake==y_food)
			 {
			 	goto rand; //makes sure that head and food are not in the same place
			 }
		}
			 if(space[x_snake][y_snake]=='#')
			 {
			 	gameover=1; 
				 exit(0); // when wall hitted gameover is true
			 }
				 
		}
		void body()
		{
			space[x_snake][y_snake]='@';
			space[x_orignal][y_orignal]=' ';
			space[x_food][y_food]='f';
		}
		
};

int main()
{
	srand  (time(0));
	draw obj;
	obj.boundary();
	obj.initialize_snake();
	obj.initialize_food();
	obj.body();
	obj.display();
	while(!gameover)
	{	
		obj.take_input();
		obj.action();
			system("cls");
		obj.body();
		obj.display();
		Sleep(20);
		// check this out whats the problem
		cout<<"\nscore : "<<score;
		
	
	}
	
	
	return 0;
}
