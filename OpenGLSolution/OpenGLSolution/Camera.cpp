#include "Camera.h"









Camera::~Camera()
{
}

glm::mat4 Camera::GetViewMatrix()
{
	
		glm::vec3 pos = m_transform.GetPos();
		return glm::lookAt(pos, pos + m_front, m_worldUp);
	
}
