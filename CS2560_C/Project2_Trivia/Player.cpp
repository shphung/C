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
#include "Player.h"
#include "Question.h"
//Sets player number
void Player::setPlayerID(int num) {
	playerID = num;
}

//Pushes correct questions onto vector
void Player::gotRight(Question que, int num) {
	questionsRight.push_back(&que);
	correct.push_back(num);
}

//Pushes wrong questions onto vector
void Player::gotWrong(Question que, int num) {
	questionsWrong.push_back(&que);
	incorrect.push_back(num);
}

//Returns player number
int Player::getPlayerID() const {
	return playerID;
}

//Returns questionsRight size
int Player::getRightSize() const {
	return questionsRight.size();
}

//Returns questionsWrong size
int Player::getWrongSize() const {
	return questionsWrong.size();
}

//Returns vector of questionsRight
vector<Question *> Player::getRight() const {
	return questionsRight;
}

//Returns vector of questionsWrong
vector<Question *> Player::getWrong() const {
	return questionsWrong;
}

//Returns vector of question numbers
vector<int> Player::getCorrect() const {
	return correct;
}

//Clears all vectors, keeps player number
void Player::resetPlayer() {
	questionsRight.clear();
	questionsWrong.clear();
	correct.clear();
	incorrect.clear();
}
