#include<iostream>
#include<string>
using namespace std;
char matrix[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row, column;
char token='x';
bool tie=false;
string p1="";
string p2="";
void first()
{
    cout<< "    |     |     \n";
    cout<< " "<<matrix[0][0]<<"  |  "<<matrix[0][1]<< "  |  "<<matrix[0][2]<<"  \n";
    cout<< "____|_____|____ \n";
    cout<< "    |     |     \n";
    cout<< " "<<matrix[1][0]<<"  |  "<<matrix[1][1]<< "  |  "<<matrix[1][2]<<"  \n";
    cout<< "____|_____|____ \n";
    cout<< "    |     |     \n";
    cout<< " "<<matrix[2][0]<<"  |  "<< matrix[2][1]<< "  |  "<<matrix[2][2]<<"  \n";
    cout<< "    |     |     \n";
}
void second()
{
    int element;
    if (token=='x')
    {
        cout<<p1<<"\nplay your turn: ";
        cin>>element;
    }
    else if (token=='0')
    {
        cout<<p2<<"\nplay your turn: ";
        cin>>element;
    }
    if (element<1 || element>9)
    {
        cout<<"\nInvalid input!!!";
        second();
        return;
    }
    row=(element - 1)/3;
    column=(element-1)%3;
    if (matrix[row][column]!='x' && matrix[row][column]!='0')
    {
        matrix[row][column]=token;
        if (token=='x')
            token='0';
        else
            token='x';
    }
    else
    {
        cout<<"\nCell already occupied!";
        second();
    }
}
bool third()
{
    for (int i=0; i<3; i++)
    {
        if (matrix[i][0]==matrix[i][1] && matrix[i][0]==matrix[i][2] || matrix[0][i]==matrix[1][i] && matrix[0][i]==matrix[2][i])
            return true;
    }

    if (matrix[0][0]==matrix[1][1] && matrix[1][1]==matrix[2][2] || matrix[0][2]==matrix[1][1] && matrix[1][1]==matrix[2][0])
        return true;
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            if (matrix[i][j]!='x' && matrix[i][j]!='0')
            {
                return false;
            }
        }
    }
    tie=true;
    return true;
}
int main()
{
	char playAgain;
    do 
	{
    cout<<"Enter the name of first player: ";
    getline(cin, p1);
    cout<<"\nEnter the name of second player: ";
    getline(cin, p2);
    cout<<"\nPlayer 1 plays first: ";
    cout<<"\nPlayer 2 plays second: \n";
    while(!third())
    {
        first();
        second();
    }
    if (token=='0' && !tie)
    {
        cout<<p1<<" wins!! \n"<<endl;
    }
    else if (token=='x' && !tie)
    {
        cout<<p2<<" wins!! \n"<<endl;
    }
    else
    {
        cout<<"\n Game Draw!! ";
    }
    cout<<"Do you want to play again? (Y/N): ";
    cin>>playAgain;
    cin.ignore(); 
    } while (playAgain=='Y' || playAgain=='y');
    return 0;
}
