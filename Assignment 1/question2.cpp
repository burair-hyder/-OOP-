# include <iostream>
using namespace std;

class Robot;
class Ball;
class Goal;
class Robot{
	private:
	string name;
	int hits;
	
	
	public:
		
		Robot(){
			
		}
		Robot(string namep){
			name = namep;
			
			
			
		}
		
		void hitball(int &ballX, int &ballY,const string &direction){
			
			if (direction == "up"){
				ballY++;
			}
			else if (direction == "down"){
				ballY--;
			}
			else if (direction =="right"){
				ballX++;
			}
			else if (direction == "left"){
				ballX--;
			}
			else{
				cout <<"Invalid Direction!"<<endl;
			}
			hits++;
		
		}
		
		int get_hits(){
			return hits;
		}
		
		
		
		
		
};

class Ball{
	private:
		int x;
		int y;
		
		
	public:
		Ball(int xp,int yp){
			x =xp;
			y=  yp;
		}
		Ball(){
			
		}
		
		int getX(){
			return x;
		}
		
		int getY(){
			return y;
		}
		
		
		void move(int dx, int dy){
			x= dx;
			y = dy;
		}
		
		
		int* getPosition(){
			static int arr[2];
			arr[0] = x;
			arr[1] = y;
			return arr;
		}
		
		
		
		
		
		
};

class Goal{
	int gx;
	int gy;
	
	public:
		Goal(){
			gx= 3;
			gy =3;
			
		}
	
		int isGoalReacher(int ballX, int ballY){
			if (ballX == gx && ballY==gy){
				return 1;
			}
			else{
				return 0;
			}
		}
};


class Team{
	public:
	string teamName;
	Robot *player;
	
	Team(string name,Robot *R1){
		teamName = name;
		player =R1;
		
	}
	Team(){
		
	}
	
};

class Game{

	Team teamOne;
	Team teamTwo;
	Ball ball;
	
	int x;
	int y;
	Goal goal;
	
	public:
		string direction;
		Game(Team T1,Team T2,Ball ballp,Goal goalp){
			teamOne = T1;
			teamTwo = T2;
			ball = ballp;
			goal = goalp;	
			x=0;
			y=0;
		}
		
			void play(Team *team){
				team->player->hitball(x,y,direction);
				ball.move(x,y);
				
			
			
		}
		void startGame(){
			

			 x= ball.getX();
			 y= ball.getY();
			 	int i=1;
			while(!goal.isGoalReacher(x,y)){
					cout <<"Team 1 youR turn:";
					cout <<"Enter direction";
					cin >>direction;
					play(&teamTwo);
				}
				
				x=0;
				y=0;
			while(!goal.isGoalReacher(x,y)){
				
					cout <<"Team 2 youR turn:";
					cout <<"Enter direction";
					cin >>direction;
					play(&teamOne);
				
					
					
				}
				
			
			
		}
		
		
		void declarWinner(){
			int a= teamOne.player->get_hits();
			int b = teamTwo.player->get_hits();
			
			if (a<b){
				cout <<teamOne.teamName<<" Wines!!"<<endl;
			}
			else{
				cout <<teamTwo.teamName<<" Wines!!"<<endl;
			}
		}
		
	
		
		
};

int main() {
	string name1=  "RObotOne";
	string name2 = "RObotTwo";
    Robot r1(name1), r2(name2);
    Team team1("Team A",&r1);
    Team team2("Team B", &r2);
    Ball ball(0, 0);
    Goal goal;
    

    Game game(team1, team2, ball, goal);

    game.startGame();
    
    if (team1.player->get_hits()<team2.player->get_hits()){
    	cout <<"team1";
	}
	else{
		cout<<"team2";
	}

    return 0;
}
