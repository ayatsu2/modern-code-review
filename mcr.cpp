#include <iostream>
using namespace std;
//judge if the game board is [win] status
bool isWin(char game[3][3]){
	bool win = false;
	
	//check the 3 horizontal conditions of winning
	
	if (game[0][0] == game[0][1] && game[0][1] == game[0][2] && game[0][0] != NULL) win = true;
	if (game[1][0] == game[1][1] && game[1][1] == game[1][2] && game[1][0] != NULL) win = true;
	if (game[2][0] == game[2][1] && game[2][1] == game[2][2] && game[2][0] != NULL) win = true;
	
	//check the 3 vertical conditions of winning
	
	if (game[0][0] == game[1][0] && game[1][0] == game[2][0] && game[0][0] != NULL) win = true;
	if (game[0][1] == game[1][1] && game[1][1] == game[2][1] && game[0][1] != NULL) win = true;
	if (game[0][2] == game[1][2] && game[1][2] == game[2][2] && game[0][2] != NULL) win = true;
	
	// 2 diagonal conditions
	
	if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && game[0][0] != NULL) win = true;
	if (game[0][2] == game[1][1] && game[1][1] == game[2][0] && game[0][2] != NULL) win = true;
	
	return win;
}

int main(){
	int i, j;
	
	// Tic-tac-toe
	char game[3][3] = {' '};
	game[0][0] = NULL;
	char player1 = 'X';
	char player2 = 'O';
	bool turn = true; // false for player 1's turn, true for player 2's turn. Player 1 first.
	
	cout << "X = Player 1" << endl << "O = Player 2" << endl;
	
    for (int n=0; n<9; n++){
		turn = !turn;  // use the not-operator to change true to false or false to true.
	       
	    //whether it's player1's turn or player 2'turn
		if (turn == false)
			cout << "Player 1: ";
		else
			cout << "Player 2: ";
		cout << "Which cell to mark? i:[1..3], j:[1..3]: "; 
	       
	       
	    //get the input of column num and row num
		cin >> i >> j;
	    
	    
	    //check out-of-bound error and prevent players from placing a move on an already taken slot.
	    while (i > 3 || i < 1 || j > 3 || j < 1 || game[i-1][j-1] != NULL){
			cout << "Illegal move. Please input again." << endl;
			cout << "Which cell to mark? i:[1..3], j:[1..3]: "; 
		    cin >> i >> j;
	    }    
	       
	    //change the game board status
		if (turn == false)
			game[i-1][j-1] = 'X';
		else 
			game[i-1][j-1] = 'O';
	       
	    //check if either one player wins the game
		if (isWin(game)){
		    if (turn)
		        cout << "Player 2 ";
		    else
		        cout << "Player 1 ";
			cout << "Win!" << endl;
			
			cout << "game status:" << endl;
			cout << game[0][0] << " " << game[0][1] << " " << game[0][2] << endl;
	        cout << game[1][0] << " " << game[1][1] << " " << game[1][2] << endl;
	        cout << game[2][0] << " " << game[2][1] << " " << game[2][2] << endl;
			break; // need to terminate the problem
		}
			
        //no winner
	    if (n == 9){
	        cout << "Tie!" << endl;
	    }
			
	    cout << "game status:" << endl;
	    cout << game[0][0] << " " << game[0][1] << " " << game[0][2] << endl;
	    cout << game[1][0] << " " << game[1][1] << " " << game[1][2] << endl;
	    cout << game[2][0] << " " << game[2][1] << " " << game[2][2] << endl;
	        
	        

	    
	}
	

	return 0;
}
