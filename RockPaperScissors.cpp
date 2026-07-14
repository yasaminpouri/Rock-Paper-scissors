#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void sowMenu()
{
	cout<<"s=stone"<<endl<<"p=paper"<<endl<<"c=scissors"<<endl;
}

char getPlayerChoice()
{
	char userchoice;
	cout<<"Enter your choice: "<<endl;
	cin>>userchoice;
	
	while(userchoice!='s'&&
	   userchoice!='p'&&
	   userchoice!='c')
	   {
	   	 cout<<"Enter your choice!"<<endl;
	   	 cin>>userchoice;
	   }
	   return userchoice;
}

char getComputerChoice()
{
	int randomnumber = rand() % 3 + 1;
	char computerchoice;
	if(randomnumber == 1)
	computerchoice = 's';
	else if(randomnumber == 2)
	computerchoice = 'p';
	else
	computerchoice = 'c';
	
	cout<<endl;
	return computerchoice;
}
void showComputerChoice(char choice)
{
	char computerchoice;
	
	if(computerchoice == 's')
	cout<<"Computerchoice : "<<"stone";
	if(computerchoice == 'p')
	cout<<"Computerchoice : "<<"paper";
	if(computerchoice == 'c')
	cout<<"Computerchoice : "<<"scissors";
	cout<<endl; 
}
void showPlayerChoice(char userchoice)
{
	if(userchoice == 's')
	cout<<"Userchoice : stone";
	if(userchoice == 'p')
	cout<<"Userchoice : paper";
	if(userchoice == 'c')
	cout<<"Userchoice : scissors";
	cout<<endl;
}
int showRoundResult(char userchoice,char computerchoice)
{
	if(computerchoice == userchoice)
	{
	cout<<"Tie!"<<endl;
	return 0;
	}

	else if((userchoice == 's' && computerchoice == 'p')||
	(userchoice == 'p' && computerchoice == 'c')||
	(userchoice == 'c' && computerchoice == 's'))
    {
	cout<<"Computer win!"<<endl;
	return 1;
	}

	else
	{
	cout<<"You win!"<<endl;
	return 2;
	}

}
void showFinalWinner(int userScore,int computerScore)
{
	if(userScore == 3)
	cout<<"You win!!!"<<endl;
	else
	cout<<"Computer wins!!!"<<endl;
	cout<<endl<<endl;
}

int main()
{
	srand(time(0));
	sowMenu();
	char playagain;
	do
	{	
    int userScore=0;
    int computerScore=0;
    int tieScore=0;
    while( userScore < 3 && computerScore < 3)
    {
    	
	char computerchoice;
	char userchoice;
	
	userchoice = getPlayerChoice();
	
	computerchoice = getComputerChoice();

	showComputerChoice(computerchoice);
	
    showPlayerChoice(userchoice);
    
    int result = showRoundResult(userchoice,computerchoice);
    {
    	if(result == 1)
    		++computerScore;
		else if(result == 2)
			++userScore;
		else
			++tieScore;
	}
	
    }
    
    showFinalWinner(userScore,computerScore);
	
	cout<<"===== final score ===="<<endl;
	cout<<"Computer : "<<computerScore<<endl;
	cout<<"User : "<<userScore<<endl;
	cout<<"Tie : "<<tieScore<<endl;
	
	cout<<"play again ?(y/n)"<<endl;
	cin>>playagain;
	
    }while(playagain == 'y' || playagain == 'Y');
}