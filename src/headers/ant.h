#ifndef ANT_H_ /* Include guard */
#define ANT_H_

class ant
{
protected:
	int age;
	int max_age;
	int x;
	int y;
	int food_consumed;
	int food_needed;

public:
	ant();
	~ant();
};

#endif // ANT_H_