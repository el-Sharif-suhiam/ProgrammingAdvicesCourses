// First-Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>

using namespace std;

enum enGameOption {stone = 1, paper, scissor};
enum enWinnerResult {draw = 0, player, computer };
struct stGameResult {
    short playerScore; 
    short computerScore;
    short drawScore; 
    short rounds;
};
short RoundsNumber() {
    short rounds = 1;
    do {
        cout << "How Many rounds do want to play from 1 to 10? \n";
        cin >> rounds;
    } while (rounds < 1 || rounds > 10);
    return rounds;
}


int RandomNumber(int from, int to) {

    int randomNum = rand() % (to - from + 1) + from;

    return randomNum;
}

enGameOption ComOption() {
    return (enGameOption)RandomNumber(1, 3);
  
}

enGameOption PlayerOption() {
    short option;
    do {
        cout << "Your Choice: [1]:Stone, [2]:Paper, [3]Scissors ? ";
        cin >> option;
    } while (option < 1 || option > 3);
    return (enGameOption)option;
   
}

string OptionName(enGameOption option) {
    switch (option)
    {
    case stone:
        return "Stone";
        break;
    case paper:
        return "Paper";
        break;
    case scissor:
        return "Scissor";
        break;
    default:
        break;
    }
}
enWinnerResult RoundResult(enGameOption Com, enGameOption Player) {
    
    if (Com == Player) {
        return enWinnerResult::draw;
    }

    if (Com == enGameOption::stone && Player == enGameOption::scissor) {
        return enWinnerResult::computer;
    }
    else if (Com == enGameOption::paper && Player == enGameOption::stone) {
        return enWinnerResult::computer;
    }
    else if (Com == enGameOption::scissor && Player == enGameOption::paper) {
        return enWinnerResult::computer;
    }
    
    return enWinnerResult::player;

}

string WinnerName(enWinnerResult result) {
    switch (result)
    {
    case draw:
        return "[No Winner]";
        break;
    case player:
        return "[The Player Won]";
        break;
    case computer:
        return "[The Computer Won]";
        break;
    default:
        break;
    }
}
void FinalResult(stGameResult GameResult) {
    cout << "\n\n";
    cout << "\t\t _______________________________________________________\n\n";
    cout << "\t\t\t\t +++ Game Over ++ \n\n";
    cout << "\t\t _______________________________________________________\n\n";
    cout << "\t\t ___________________ [ Game Results ] __________________\n\n";
    cout << "\t\t Game Rounds        : " << GameResult.rounds << "\n";
    cout << "\t\t Player win Times   : " << GameResult.playerScore << "\n";
    cout << "\t\t Computer win Times : " << GameResult.computerScore << "\n";
    cout << "\t\t Draw Times         : " << GameResult.drawScore << "\n";

    string winnerName = "No Winner";
    if (GameResult.playerScore > GameResult.computerScore) {
        winnerName = "The Player";
        system("color 20");
    }
    else if (GameResult.playerScore < GameResult.computerScore) {
        winnerName = "The Computer";
        system("color 40");
    }
    else {
        system("color 60");
    }
    cout << "\t\t Final Winner : " << winnerName << "\n\n";
    cout << "\t\t _______________________________________________________\n\n";
}

void PlayGame() {
    stGameResult GameResult;
    GameResult.rounds = RoundsNumber();
    GameResult.playerScore = 0, GameResult.computerScore = 0, GameResult.drawScore = 0;
    for (short i = 1; i <= GameResult.rounds; i++) {
        cout << "\n\nRound [" << i << "] begins: \n\n";
        enGameOption Player = PlayerOption();
        enGameOption Com = ComOption();
        cout << "\n____________Round [" << i << "] ________________ \n\n";
        cout << "Player Choice   : " << OptionName(Player) << "\n";
        cout << "Computer Choice : " << OptionName(Com) << "\n";
        cout << "Round Winner    : " << WinnerName(RoundResult(Com, Player)) << "\n";

        if (RoundResult(Com, Player) == enWinnerResult::player) {
            system("color 20");
            GameResult.playerScore++;
        }
        else if (RoundResult(Com, Player) == enWinnerResult::computer) {
            system("color 40");
            cout << "\a";
            GameResult.computerScore++;
        }
        else {
            system("color 60");
            GameResult.drawScore++;
        }


    }
    FinalResult(GameResult);
}
void StartGame() {
    char WantPlay = 'Y';

    do {
        system("cls");
        system("color 07");
        PlayGame();
        cout << "\t\t Do you want to play again ? 'Y' for yes / 'N' for No \n\n";
        cout << "\t\t";
        cin >> WantPlay;

    } while (WantPlay == 'Y' || WantPlay == 'y');

}

int main()
{
    srand((unsigned)time(NULL));
    StartGame();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
