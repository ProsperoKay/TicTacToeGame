#pragma once
class TicTacToe
{
public:

	//Contr
	TicTacToe();

	//Main game entry point
	static void ttPlay();

	//Destr
	~TicTacToe();

private:

	//Help when you need it 
	static void ttHelp();

	//Input system for player
	static void ttInput();
	 
	//Clear gaming board 
	static void ttClear();

	//Draw gaming board including player point 
	static void ttDraw();

	//Toggle player modes
	static void ttMod();

	//Check scores and reset game or terminate
	static void ttWinRules();

	//Board dat content
	static char board[3][3];

};

