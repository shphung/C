/*
 * Name: Steven Phung
 * Project: #2
 * Due: November 15th, 2018
 * Course: cs-2560-01-f18
 *
 */
#pragma once
#include <vector>
#include "Question.h"

using namespace std;

class Player {
	private:
		int playerID;
		vector<Question *> questionsRight;
		vector<Question *> questionsWrong;
		vector<int> correct;
		vector<int> incorrect;

	public:
		void setPlayerID(int num);
		void gotRight(Question que, int num);
		void gotWrong(Question que, int num);
		void resetPlayer();

		int getPlayerID() const;
		int getRightSize() const;
		int getWrongSize() const;
		vector<Question *> getRight() const;
		vector<Question *> getWrong() const;
		vector<int> getCorrect() const;
};
