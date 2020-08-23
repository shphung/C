/*
 * Name: Steven Phung
 * Project: #2
 * Due: November 15th, 2018
 * Course: cs-2560-01-f18
 *
 * Description:
 * 	Trivia game for multiple players. 10 total questions with 4 answers each.
 * 	Each round all players will be asked the same question. Total 5 rounds.
 * 	Print winner at the end, replay possible.
 */
#include "Question.h"

//Sets question
void Question::setQuestion(string quest) {
	question = quest;
}

//Sets multiple choice answer 1
void Question::setPossibleAnswer1(string answer1) {
	possibleAnswer1 = answer1;
}

//Sets multiple choice answer 2
void Question::setPossibleAnswer2(string answer2) {
	possibleAnswer2 = answer2;
}

//Sets multiple choice answer 3
void Question::setPossibleAnswer3(string answer3) {
	possibleAnswer3 = answer3;
}

//Sets multiple choice answer 4
void Question::setPossibleAnswer4(string answer4) {
	possibleAnswer4 = answer4;
}

//Sets the correct answer
void Question::setCorrectAnswer(int answer) {
	correctAnswer = answer;
}

//Returns question
string Question::getQuestion() const {
	return question;
}

//Returns multiple answer 1
string Question::getPossibleAnswer1() const {
	return possibleAnswer1;
}

//Returns multiple answer 2
string Question::getPossibleAnswer2() const {
	return possibleAnswer2;
}

//Returns multiple answer 3
string Question::getPossibleAnswer3() const {
	return possibleAnswer3;
}

//Returns multiple answer 4
string Question::getPossibleAnswer4() const {
	return possibleAnswer4;
}

//Returns correct answer
int Question::getCorrectAnswer() const {
	return correctAnswer;
}
