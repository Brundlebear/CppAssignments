#pragma once
#ifndef ESSAY

#include "GradedActivity.h"
#include <iostream>

class Essay : public GradedActivity
{
private:
	int grammarPoints;
	int	spellingPoints;
	int lengthPoints;
	int contentPoints;

public:
	//Constructor
	Essay() {
		grammarPoints = 0;
		spellingPoints = 0;
		lengthPoints = 0;
		contentPoints = 0;
	};

	//Mutators
	void setGrammar(int g);
	void setSpelling(int s);
	void setLength(int l);
	void setContent(int c);

	//Accessors
	int getGrammar() const {
		return grammarPoints;
	}
	int getSpelling() const {
		return spellingPoints;
	}
	int getLength() const {
		return lengthPoints;
	}
	int getContent() const {
		return contentPoints;
	}

	virtual int getScore();
	virtual char getLetterScore();


};



#endif // !ESSAY
