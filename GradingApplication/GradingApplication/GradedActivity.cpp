#include <iostream>
#include "GradedActivity.h"

//define GetLetterScore function

char GradedActivity::getLetterScore() const{

	char letterGrade;

	if (score > 89) {
		letterGrade = 'A';
	}
	else if (score >79)	{
		letterGrade = 'B';
	}
	else if(score >69) {
		letterGrade = 'C';
	}
	else if(score > 59) {
		letterGrade = 'D';
	}
	else {
		letterGrade = 'F';
	}

	return letterGrade;
};
