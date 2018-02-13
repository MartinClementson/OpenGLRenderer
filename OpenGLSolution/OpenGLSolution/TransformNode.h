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
	glm::mat4 GetTransformMatrix()const { return m_transform; };
	
	const glm::vec3 GetPos() const { return m_pos; };
	void SetPos(glm::vec3 newPos) { m_pos = newPos; };

	const glm::vec3 GetRot() const { return m_rot; };
	void SetRot(glm::vec3 newRot) { m_rot = newRot; };

	const glm::vec3 GetScale() const { return m_scale; };
	void SetScale(glm::vec3 newScale) { m_scale = newScale; };
private:
	glm::vec3 m_pos, m_rot, m_scale;
	glm::mat4 m_transform;

	bool m_nodeDirty = false;


};

