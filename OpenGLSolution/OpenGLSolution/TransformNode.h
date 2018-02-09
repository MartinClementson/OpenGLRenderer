#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class TransformNode
{
public:
	TransformNode();
	~TransformNode();
	void Translate(glm::vec3 translate);
	void Rotate(glm::vec3 axis, float angle);
	void Scale(glm::vec3 scale);
	bool GetDirtyState() { return m_nodeDirty; };
	void Update();
private:
	glm::vec3 m_pos, m_rot, m_scale;
	glm::mat4 m_transform;

	bool m_nodeDirty = false;


};

