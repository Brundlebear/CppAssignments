#include "Essay.h"
#include <iostream>
using namespace std;

//Define Essay Functions

void Essay::setGrammar(int g) {
	if (g < 0 || g > 30) {
		cout << "\n\nInput is out of acceptable range" << endl;
	}
	else
	{
		grammarPoints = g;
	}
};


void Essay::setSpelling(int s) {
	if (s < 0 || s > 20) {
		cout << "\n\nInput is out of acceptable range" << endl;
	}
	else
	{
		spellingPoints = s;
	}
};


void Essay::setLength(int l) {
	if (l < 0 || l > 20) {
		cout << "\n\nInput is out of acceptable range" << endl;
	}
	else
	{
		lengthPoints = l;
	}
};


void Essay::setContent(int c) {
	if (c < 0 || c > 30) {
		cout << "\n\nInput is out of acceptable range" << endl;
	}
	else
	{
		contentPoints = c;
	}
};

int Essay::getScore() {
	return grammarPoints + spellingPoints + lengthPoints + contentPoints;
};

char Essay::getLetterScore() {
	score = getScore();

	return GradedActivity::getLetterScore();
};