#pragma once
class MovableObject
{
protected: 
	int xPosition;
	int yPosition;

public:
	MovableObject();
	MovableObject(int _xPosition, int _yPosition);
	~MovableObject();

	void SetPosition(int x, int y);
	virtual void Display();
};

