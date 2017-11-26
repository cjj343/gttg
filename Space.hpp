#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>
class Space
{
private:
	Space *top;
	Space *right;
	Space *bottom;
	Space *left;
	int row;
	int col;
public:
	Space();
	Space(Space *, Space *, Space *, Space *, int, int);
	virtual void printGraphic() = 0;
	virtual void positionCharacter() = 0;
	virtual void revealSpace() = 0;
	virtual bool getAccess() = 0;
	virtual bool getType() = 0;
	virtual char getDesignator() = 0;
	virtual ~Space();
	friend class Map;
};
#endif

