#ifndef ANT_H_ /* Include guard */
#define ANT_H_

class ant
{
protected:
	int age;
	int max_age;
	int x;
	int y;
	int food_level;	  // current food level
	int food_maximum; // maximum food that can eat the ant

public:
	ant();
	~ant();

	void endTurn();

	
	bool endFood();
	bool ageMax();

};

#endif // ANT_H_