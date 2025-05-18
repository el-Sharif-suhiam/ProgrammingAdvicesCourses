// MathGame project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

enum enDifficultyLevel { easy = 1, med , hard, mix };
enum enOpType { add =1, sub , multiply, divide, mixType };

struct stQuestion {
    int FirstNumber = 0;
    int SecondNumber = 0;
    enDifficultyLevel QuestionLevel;
    enOpType OperationType;
    int RightAnswer = 0;
    int PlayerAnwer = 0;
    bool AnswerResult = false;
};

struct stQuizz {
    stQuestion QuestionList[100];
    short NumberOfQuestions;
    enDifficultyLevel Difficulty;
    enOpType OpType;
    short RightAnswers = 0;
    short WrongAnsers = 0;
    bool isPass = false;
};

void ChangeSecreenColor(bool result) {
    if (result) {
        system("color 2F");
    }
    else {
        system("color 4F");
        cout << "\a";
    }
};

string QuestionsLevelName(enDifficultyLevel level) {
    string QuestionLevel[4] = { "Easy", "Mid", "Hard", "Mix" };
    return QuestionLevel[level - 1];
}


string OpTypeSympol(enOpType op) {
    switch (op)
    {
    case add:
        return "+";
    case sub:
        return "-";
    case multiply:
        return "*";
    case divide:
        return "/";
    default:
        return "Mix";
        
    }
}

void RestScreen() {
    system("cls");
    system("color 0F");
}


short QuestionsNumber() {
    short rounds = 1;
    do {
        cout << "How Many Questions do want to answer from 1 to 30? \n";
        cin >> rounds;
    } while (rounds < 1 || rounds > 30);
    return rounds;
}

enDifficultyLevel GameLevel() {
    short level =1;
    do {
        cout << "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
        cin >> level;
    } while (level < 1 || level > 4);
    return (enDifficultyLevel)level;

}


enOpType OperationsType() {
    short op = 1;
    do {
        cout << "Enter Questions Type [1] Add, [2] Sub, [3] Multiply, [4] divide, [5] mix ? ";
        cin >> op;
    } while (op < 1 || op > 5);
    return (enOpType)op;

}
int RandomNumber(int from, int to) {

    int randomNum = rand() % (to - from + 1) + from;

    return randomNum;
}

int SimpleCalculater(int FirstNum, int SecondNum, enOpType OpType) {
    switch (OpType)
    {
    case add:
        return FirstNum + SecondNum;
        break;
    case sub:
        return FirstNum - SecondNum;

        break;
    case multiply:
        return FirstNum * SecondNum;

        break;
    case divide:
        return FirstNum / SecondNum;
    default:
        return FirstNum + SecondNum;

    }
}

enOpType GenrateRandomOpType() {
    int op = RandomNumber(1, 4);
    return (enOpType)op;
}
stQuestion GenrateQuestion(enDifficultyLevel level, enOpType OpType) {
    stQuestion Question;
    if (level == enDifficultyLevel::mix) {
        level = (enDifficultyLevel)RandomNumber(1, 3);
    };

    if (OpType == enOpType::mixType) {
        OpType = GenrateRandomOpType();
    }

    switch (level)
    {
    case easy:
        Question.FirstNumber = RandomNumber(1, 10);
        Question.SecondNumber = RandomNumber(1, 10);
        Question.OperationType = OpType;
        Question.QuestionLevel = level;
        Question.RightAnswer = SimpleCalculater(Question.FirstNumber, Question.SecondNumber, Question.OperationType);
        break;
    case med:
        Question.FirstNumber = RandomNumber(10, 50);
        Question.SecondNumber = RandomNumber(10, 50);
        Question.OperationType = OpType;
        Question.QuestionLevel = level;
        Question.RightAnswer = SimpleCalculater(Question.FirstNumber, Question.SecondNumber, Question.OperationType);

        break;
    case hard:
        Question.FirstNumber = RandomNumber(51, 200);
        Question.SecondNumber = RandomNumber(51, 200);
        Question.OperationType = OpType;
        Question.QuestionLevel = level;
        Question.RightAnswer = SimpleCalculater(Question.FirstNumber, Question.SecondNumber, Question.OperationType);
        break;
    }

    return Question;

}

void GenrateQuizzQuestions(stQuizz& Quizz) {
    for (int Question = 0; Question < Quizz.NumberOfQuestions; Question++) {
        Quizz.QuestionList[Question] = GenrateQuestion(Quizz.Difficulty, Quizz.OpType);
    }
}

int ReadQuestionAnswer() {
    int answer = 0;
    cin >> answer;
    return answer;
}


void PrintQustion(stQuizz &Quizz, int QuestionNumber){
    cout << "\n";
    cout << Quizz.QuestionList[QuestionNumber].FirstNumber << "\n";
    cout << Quizz.QuestionList[QuestionNumber].SecondNumber << " ";
    cout << OpTypeSympol(Quizz.QuestionList[QuestionNumber].OperationType) << "\n\n";
    cout << "__________\n";

}

void CorrectTheQuestionAnswer(stQuizz& Quizz, int QuestionNumber) {

    if (Quizz.QuestionList[QuestionNumber].RightAnswer == Quizz.QuestionList[QuestionNumber].PlayerAnwer) {
        Quizz.QuestionList[QuestionNumber].AnswerResult = true;

        Quizz.RightAnswers++;
        cout << "Right Answer :-) \n";
    }
    else {
        cout << "Wrong Answer :-( \n";
        cout << "The Right Answer is : ";
        cout << Quizz.QuestionList[QuestionNumber].RightAnswer << "\n";
        Quizz.WrongAnsers++;
    }
}
void GenrateQuizz(stQuizz& Quizz) {
    for (int Questions = 0; Questions < Quizz.NumberOfQuestions; Questions++) {
        cout << "\n\nQuestion [" << Questions << "/" << Quizz.NumberOfQuestions << "]\n\n";
        PrintQustion(Quizz, Questions);
        Quizz.QuestionList[Questions].PlayerAnwer = ReadQuestionAnswer();
        CorrectTheQuestionAnswer(Quizz, Questions);
        ChangeSecreenColor(Quizz.QuestionList[Questions].AnswerResult);
    }

}


bool isPass(stQuizz Quizz) {
    if (Quizz.RightAnswers >= Quizz.WrongAnsers) {
        return true;
    }
    else {
        return false;
    }
}
void FinalResult(stQuizz &Quizz) {

    string result = "Pass :-)";
    Quizz.isPass = isPass(Quizz);
    if (Quizz.isPass) {
        ChangeSecreenColor(Quizz.isPass);
        
    }
    else{
        result = "Fail :-(";
        ChangeSecreenColor(Quizz.isPass);
    }
   

    cout << "\n\n\n";
    cout << "_______________________________________________________\n\n";
    cout << "\t Final Result is " << result << "\n\n";
    cout << "_______________________________________________________\n\n";
    cout << "Number of Questions : " << Quizz.NumberOfQuestions<< "\n";
    cout << "Questions Level   : " << QuestionsLevelName(Quizz.Difficulty) << "\n";
    cout << "OperationType   : " << OpTypeSympol(Quizz.OpType) << "\n";

    cout << "Number of Right Answers: " << Quizz.RightAnswers << "\n";
    cout << "Number of Wrong Answers: " << Quizz.WrongAnsers << "\n\n";

    cout << "_______________________________________________________\n\n";
}

void PlayGame() {
    stQuizz Quizz;
    Quizz.NumberOfQuestions = QuestionsNumber();
    Quizz.RightAnswers = 0, Quizz.WrongAnsers = 0;
    Quizz.Difficulty = GameLevel();
    Quizz.OpType = OperationsType();

    GenrateQuizzQuestions(Quizz);
    GenrateQuizz(Quizz);
    FinalResult(Quizz);
}
void StartGame() {
    char WantPlay = 'Y';

    do {
        RestScreen();
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
    return 0;
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
