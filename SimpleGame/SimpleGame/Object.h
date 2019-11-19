#pragma once

class Object
{
	float x, y, z;
	float sx, sy, sz;
	float r, g, b, a;
	// »ö Ãß°¡
public:
	Object();
	~Object();
	void SetSize(float, float, float);
	void SetLocation(float, float, float);
	void SetColor(float, float, float, float);

	void GetSize(float*, float*, float*);
	void GetLocation(float*, float*, float*);
	void GetColor(float*, float*, float*, float*);
};

