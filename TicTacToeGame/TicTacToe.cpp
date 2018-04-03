#include<iostream>
#include "TicTacToe.h"

using namespace std;

//Players 
char ttX = 'X';//player1
char ttO = 'O';//player2
char ttPlr = ttX;//current player

//Is play
bool ttOver = false;

//board reference
char *TicTacToe::board[3][3];

TicTacToe::TicTacToe()
{
}

//Main game entry point
void TicTacToe::ttPlay()
{
	ttHelp();
	ttClear();
	ttDraw();
	while (true) {
		ttInput();
		ttDraw();
		ttWinRules();
		ttMod();
	}

	cin.get();
}

void TicTacToe::ttHelp()
{
	char flag='\0';
	
	system("CLS");

	cout << "\t This is a modern console based TicTacToe game \n"
		<< "\t Use the numbers your number pad for placing markers on the board \n"
		<< "\t\t\t  1|2|3 \n\t\t\t  4|5|6 \n\t\t\t  7|8|9 \n"
		<< "\t Enter 'C' to clear board \n"
		<< "\t Enter 'H' for this helpful notice \n"
	<< "\t Enter 'N' to close program\n";

	cout << "PLAY >>"; cin >> flag;
	
	if (flag == 'N' || flag == 'n') exit(0);
}

void TicTacToe::ttInput()
{
	//Variable to hold user input
	char ttUsr;

	if (!ttOver) {
		//Check and display whose turn it is to play
		cout << "\t    Player( " << ttPlr << " )'s turn!!\n" << endl;
	}
	//Code and Coordinate input 
	cout << "cod||>>> "; cin >> ttUsr;

	/*

	1,2,3,
	4,5,6,
	7,8,9,

	*/
	//Coordinates for players
	switch (ttUsr) {
	case '1':
		if (board[0][0] == &ttX || board[0][0] == &ttO)cout << "Point Taken!" << endl;
		else board[0][0] = &ttPlr;
		break;
	case '2':
		if (board[0][1] == &ttX || board[0][1] == &ttO)cout << "Point Taken!" << endl;
		else board[0][1] = &ttPlr;
		break;
	case '3':
		if (board[0][2] == &ttX || board[0][2] == &ttO)cout << "Point Taken!" << endl;
		else board[0][2] = &ttPlr;
		break;
	case '4':
		if (board[1][0] == &ttX || board[1][0] == &ttO)cout << "Point Taken!" << endl;
		else board[1][0] = &ttPlr;
		break;
	case '5':
		if (board[1][1] == &ttX || board[1][1] == &ttO)cout << "Point Taken!" << endl;
		else board[1][1] = &ttPlr;
		break;
	case '6':
		if (board[1][2] == &ttX || board[1][2] == &ttO)cout << "Point Taken!" << endl;
		else board[1][2] = &ttPlr;
		break;
	case '7':
		if (board[2][0] == &ttX || board[2][0] == &ttO)cout << "Point Taken!" << endl;
		else board[2][0] = &ttPlr;
		break;
	case '8':
		if (board[2][1] == &ttX || board[2][1] == &ttO)cout << "Point Taken!" << endl;
		else board[2][1] = &ttPlr;
		break;
	case '9':
		if (board[2][2] == &ttX || board[2][2] == &ttO)cout << "Point Taken!" << endl;
		else board[2][2] = &ttPlr;
		break;
	case 'C':
	case 'c':
		ttClear();
		ttOver = false;
		break;
	case 'H':
	case 'h':
		ttHelp();
		ttOver = false;
		break;
	case 'N':
	case 'n':
		exit(0);
	default:
		break;
	}

}

void TicTacToe::ttClear()
{
	char cl = '_';
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = &cl;
		}
	}
}

void TicTacToe::ttDraw()
{

	system("CLS");
	cout << "\t\t**TICTACTOE** \n" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "\t\t  ";
		for (int j = 0; j < 3; j++) {
			cout << "|" << board[i][j] << "|";
		}
		cout << endl;
		cout << "\t\t  _________\n" << endl;
	}
}

void TicTacToe::ttMod()
{
	if (ttPlr == ttX)ttPlr = ttO; else ttPlr = ttX;
}

void wintt(char pl) {
	ttOver = true;
	system("CLS");
	cout << "\n\n\t PLAYER (" << pl << ") WINS!!\n\t Enter 'c' to clear board" << endl;
}

void TicTacToe::ttWinRules()
{
	/*

	00,01,02,
	10,11,12,
	20,21,22,

	*/

	//TODO: FIX THIS**

	for (int i = 0; i < 3; i++)
	{
		if ((board[i][0] == &ttPlr) && (board[i][1] == &ttPlr) && (board[i][2] == &ttPlr))wintt(ttPlr);
		else if ((board[0][i] == &ttPlr) && (board[1][i] == &ttPlr) && (board[2][i] == &ttPlr))wintt(ttPlr);

		if ((board[0][0] == &ttPlr) && (board[1][1] == &ttPlr) && (board[2][2] == &ttPlr))wintt(ttPlr);
		if ((board[0][2] == &ttPlr) && (board[1][1] == &ttPlr) && (board[2][0] == &ttPlr))wintt(ttPlr);
	}


	/*
	/*

	//For player(x)//
	//hor
	if ((board[0][0] == ttPlr) && (board[0][1] == ttPlr) && (board[0][2] == ttPlr)) {
	cout << " Player( " << ttPlr << " ) wins!\n Enter 'c' to clear board" << endl;
	ttIsPlaying = false;
	}
	else if ((board[1][0] == ttPlr) && (board[1][1] == ttPlr )&& (board[1][2] == ttPlr)) {
	cout << " Player( " << ttPlr << " ) wins!\n Enter 'c' to clear board" << endl;
	ttIsPlaying = false;
	}
	else if ((board[2][0] == ttPlr) && (board[2][1] == ttPlr) && (board[2][2]==ttPlr) ) {
	cout << " Player( " << ttPlr << " ) wins!\n Enter 'c' to clear board" << endl;
	ttIsPlaying = false;
	}
	//ver
	else if ((board[0][1]==ttPlr) && (board[1][1] ==ttPlr) &&(board[2][1] ==ttPlr)) {
	cout << " Player( " << ttPlr << " ) wins!\n Enter 'c' to clear board" << endl;
	ttIsPlaying = false;
	}
	else if ((board[0][2]==ttPlr) && (board[1][2] ==ttPlr) &&(board[2][2] ==ttPlr)) {
	cout << " Player( " << ttPlr << " ) wins!\n Enter 'c' to clear board" << endl;
	ttIsPlaying = false;
	}
	else if ((board[0][0]==ttPlr) && (board[1][0] ==ttPlr) &&(board[2][0] ==ttPlr)) {
	cout << " Player( " << ttPlr << " ) wins!\n Enter 'c' to clear board" << endl;
	ttIsPlaying = false;
	}
	//dia
	else if ((board[0][0]==ttPlr) && (board[1][1] ==ttPlr) &&(board[2][2] ==ttPlr)) {
	cout << " Player( " << ttPlr << " ) wins!\n Enter 'c' to clear board" << endl;
	ttIsPlaying = false;
	}
	else if ((board[0][2]==ttPlr) && (board[1][1] ==ttPlr) &&(board[2][0] ==ttPlr)) {
	cout << " Player( " << ttPlr << " ) wins!\n Enter 'c' to clear board" << endl;
	ttIsPlaying = false;
	}







//For player(o)	//
//hor
if ((board[0][0] == ttO) && (board[0][1] == ttO) && (board[0][2] == ttO)) {
cout << " Player( " << ttO << " ) wins!\n Enter 'c' to clear board" << endl;
ttIsPlaying = false;
}
else if ((board[1][0] == ttO) && (board[1][1] == ttO) && (board[1][2] == ttO)) {
cout << " Player( " << ttO << " ) wins!\n Enter 'c' to clear board" << endl;
ttIsPlaying = false;
}
else if ((board[2][0] == ttO) && (board[2][1] == ttO) && (board[2][2] == ttO)) {
cout << " Player( " << ttO << " ) wins!\n Enter 'c' to clear board" << endl;
ttIsPlaying = false;
}
//ver
else if ((board[0][0] == ttO) && (board[1][0] == ttO) && (board[2][0] == ttO)) {
cout << " Player( " << ttO << " ) wins!\n Enter 'c' to clear board" << endl;
ttIsPlaying = false;
}
else if ((board[0][1] == ttO) && (board[1][1] == ttO) && (board[2][1] == ttO)) {
cout << " Player( " << ttO << " ) wins!\n Enter 'c' to clear board" << endl;
ttIsPlaying = false;
}
else if ((board[0][2] == ttO) && (board[1][2] == ttO) && (board[2][2] == ttO)) {
cout << " Player( " << ttO << " ) wins!\n Enter 'c' to clear board" << endl;
ttIsPlaying = false;
}
//dia
else if ((board[0][0] == ttO) && (board[1][1] == ttO) && (board[2][2] == ttO)) {
cout << " Player( " << ttO << " ) wins!\n Enter 'c' to clear board" << endl;
ttIsPlaying = false;
}
else if ((board[0][2] == ttO) && (board[1][1] == ttO) && (board[2][0] == ttO)) {
cout << " Player( " << ttO << " ) wins!\n Enter 'c' to clear board" << endl;
ttIsPlaying = false;
}

*/


}


TicTacToe::~TicTacToe()
{
}
