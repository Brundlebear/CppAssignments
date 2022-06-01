#pragma once
#ifndef GRADED_ACTIVITY


class GradedActivity
{
protected:
	double score;
public:
	GradedActivity() {
		score = 0.0;
	};
	GradedActivity(double s) {
		score = s;
	};

	void setScore(double s) {
		score = s;
	};
	
	virtual int getScore() const {
		return score;
	};
	virtual char getLetterScore() const;
};

#endif // !GRADED_ACTIVITY
