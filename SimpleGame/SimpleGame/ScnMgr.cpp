#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"

#include "stdafx.h"
#include "ScnMgr.h"
#include "Renderer.h"
#include "Object.h"
#define MAX_OBJECT 500

ScnMgr::ScnMgr() {
	m_renderer = new Renderer(500, 500);
	if (m_renderer->IsInitialized())
	{
		std::cout << "Renderer could not be initialized.. \n";
	}

	for (int i = 0; i < MAX_OBJECT; ++i)
		m_object[i] = NULL;

	for (int i = 0; i < MAX_OBJECT; ++i)
		m_TestIdxArray[i] = AddObject(i-250, i-250, 1, 1+i/10, 1, 1, 0.002*i, 0.002*i, 0.002*i, 1);
}

ScnMgr::~ScnMgr() {
	delete m_renderer;
	m_renderer = NULL;
}

void ScnMgr::RenderScene() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.0f, 0.3f, 0.3f, 1.0f);

		// Renderer Test
		for(int i=0; i<MAX_OBJECT; ++i) {
			if (m_object[i] == NULL)
				break;

			float x, y, z = .0f;
			float sx, sy, sz = 0.f;
			float r, g, b, a = 0.f;

			m_object[m_TestIdxArray[i]]->GetLocation(&x, &y, &z);
			m_object[m_TestIdxArray[i]]->GetSize(&sx, &sy, &sz);
			m_object[m_TestIdxArray[i]]->GetColor(&r, &g, &b, &a);

			m_renderer->DrawSolidRect(x, y, z, sx, r, g, b, a);
		}
}

int ScnMgr::AddObject(float x, float y, float z, float sx, float sy, float sz, float r, float g, float b, float a) {
	//Search empty slot
	int idx = -1;
	for (int i = 0; i < MAX_OBJECT; ++i) {
		if (m_object[i] == NULL) {
			idx = i;
			break;
		}
	}
	if (idx == -1) {
		std::cout << "no more remaining object" << std::endl;
		return -1;
	}

	m_object[idx] = new Object();
	m_object[idx]->SetColor(r, g, b, a);
	m_object[idx]->SetSize(sx, sy, sz);
	m_object[idx]->SetLocation(x, y, z);

	return idx;
}
void ScnMgr::DeleteObject(int idx) {
	if (idx < 0) {
		std::cout << "Negative idx does not allowed." << std::endl;
	}

	if (idx >= MAX_OBJECT) {
		std::cout << "Requested idx exceeds MAX_OBJECT count. "<< idx << std::endl;
	}

	if (m_object[idx] != NULL) {
		delete m_object[idx];
		m_object[idx] = NULL;
	}
}