/*
 * Name: Steven Phung
 * Project: #2
 * Due: November 15th, 2018
 * Course: cs-2560-01-f18
 *
 */
#pragma once
#include <string>

using namespace std;

class Question {
	private:
		string question;
		string possibleAnswer1;
		string possibleAnswer2;
		string possibleAnswer3;
		string possibleAnswer4;
		int correctAnswer;
	public:
		void setQuestion(string quest);
		void setPossibleAnswer1(string anwser1);
		void setPossibleAnswer2(string answer2);
		void setPossibleAnswer3(string answer3);
		void setPossibleAnswer4(string answer4);
		void setCorrectAnswer(int answer);

		string getQuestion() const;
		string getPossibleAnswer1() const;
		string getPossibleAnswer2() const;
		string getPossibleAnswer3() const;
		string getPossibleAnswer4() const;
		int getCorrectAnswer() const;
};

