#pragma once
#include "Renderer.h"
#include "Object.h"

#define MAX_OBJECT 1000

class ScnMgr {
	Renderer* m_renderer = NULL;
	Object* m_object[MAX_OBJECT];
	int m_TestIdxArray[MAX_OBJECT];
public:
	ScnMgr();
	~ScnMgr();

	void RenderScene();
	int AddObject(float x, float y, float z, float sx, float sy, float sz, float r, float g, float b, float a);
	void DeleteObject(int idx);
};