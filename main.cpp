#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    cout<<"----------------------Guessing Game-------------------------"<<endl<<endl<<endl;
    int Rno,guess;
    cout<<"Lets play a game\n Guess the number I am thinking: "<<endl;
    srand(time(0));
    Rno=(rand()%10)+1;
    int tries=0;
    while(true)
    {
        cin>>guess;
        if(guess==Rno)
        {
            cout<<"Bravo !!!. You guessed the number correctly in "<<tries<<" tries "<<endl;
            tries++;


            break;
        }
        else if(guess<Rno)
        {
            cout<<"Higher"<<endl;
            tries++;
        }
        else if(guess>Rno)
    {
            cout<<"Lower"<<endl;
            tries++;
    }
            else
                cout<<"Wrong choice" ;
    }

    return 0;
}
