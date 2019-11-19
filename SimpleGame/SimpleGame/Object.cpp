#include "stdafx.h"
#include "Object.h"


Object::Object()
{
}


Object::~Object()
{
}

void Object::SetSize(float sx, float sy, float sz) {
	this->sx = sx;
	this->sy = sy;
	this->sz = sz;
}
void Object::SetLocation(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}
void Object::SetColor(float r, float g, float b, float a) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

void Object::GetSize(float* sx, float* sy, float* sz) {
	*sx = this->sx;
	*sy = this->sy;
	*sz = this->sz;
};
void Object::GetLocation(float* x, float* y, float* z) { 
	*x = this->x;
	*y = this->y;
	*z = this->z;
};
void Object::GetColor(float* r, float* g, float* b, float* a) {
	*r = this->r;
	*g = this->g;
	*b = this->b;
	*a = this->a;
};
