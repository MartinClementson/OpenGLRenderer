#include "TransformNode.h"



TransformNode::TransformNode()
{
	m_transform = glm::mat4(1.0);
}


TransformNode::~TransformNode()
{
}

void TransformNode::Translate(glm::vec3 translate)
{
	m_transform = glm::translate(m_transform, translate);
	m_nodeDirty = true;
}

void TransformNode::Rotate(glm::vec3 axis, float angle)
{
	m_transform = glm::rotate(m_transform, angle,axis);
	m_nodeDirty = true;
}

void TransformNode::Scale(glm::vec3 scale)
{
	m_transform = glm::scale(m_transform, scale);
	m_nodeDirty = true;
}

void TransformNode::Update()
{

	GLint transLocation = 0;
	glUniformMatrix4fv(transLocation, 1, GL_FALSE, glm::value_ptr(m_transform));
	m_nodeDirty = false;
}
