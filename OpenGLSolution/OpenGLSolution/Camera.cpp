#include "Camera.h"





void Camera::ProcessKeyboard(Camera::Cam_Movement dir, GLfloat deltaTime)
{
	GLfloat velocity = this->m_movementSpeed * deltaTime;
	glm::vec3 newPos = m_transform.GetPos();
	if (FORWARD == dir) {
		newPos += (this->m_front * velocity);
		this->m_transform.SetPos(newPos);
	}
	if (BACKWARD == dir) {
		newPos -= (this->m_front * velocity);
		this->m_transform.SetPos(newPos);
	}
	if (LEFT == dir) {
		newPos -= (this->m_right * velocity);
		this->m_transform.SetPos(newPos);
	}
	if (RIGHT == dir) {
		newPos += (this->m_right * velocity);
		this->m_transform.SetPos(newPos);
	}

}
void Camera::ProcessMouseMovement(GLfloat xOffset, GLfloat yOffset, GLboolean constrainPitch = true)
{
	xOffset *= this->m_mouseSensitivity;
	yOffset *= this->m_mouseSensitivity;

	this->m_yaw += xOffset;
	this->m_pitch += yOffset;

	if (constrainPitch)
	{
		if (this->m_pitch > 89.0f)
		{
			this->m_pitch = 89.0f;
		}
		if (this->m_pitch < -89.0f)
		{
			this->m_pitch = -89.0f;
		}
	}
	this->UpdateCamVectors();
}
void Camera::ProcessMouseScroll(GLfloat yOffset)
{
	if (this->m_zoom >= 1.0f && this->m_zoom <= 45.0f)
	{
		this->m_zoom -= yOffset;
	}
	if (this->m_zoom <= 1.0f)
	{
		this->m_zoom = 1.0f;
	}
	if (this->m_zoom >= 45.0f)
	{
		this->m_zoom = 45.0f;
	}

}
void Camera::UpdateCamVectors()
{
	glm::vec3 front;
	front.x = cos(glm::radians(this->m_yaw)) * cos(glm::radians(this->m_pitch));
	front.y = sin(glm::radians(this->m_pitch));
	front.z = sin(glm::radians(this->m_yaw)) * cos(glm::radians(this->m_pitch));

	this->m_front = glm::normalize(front);
	this->m_right = glm::normalize(glm::cross(this->m_front, this->m_worldUp));
	this->m_up	  = glm::normalize(glm::cross(this->m_right, this->m_front));
}



Camera::Camera(glm::vec3 pos = glm::vec3(0.0f, 0.0f, -3.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), GLfloat yaw = YAW, GLfloat pitch = PITCH) : m_front(glm::vec3(0.0f, 0.0f, -1.0f)), m_movementSpeed(SPEED), m_mouseSensitivity(SENSITIVITY), m_zoom(ZOOM)
{
	this->m_transform.SetPos(pos);
	this->m_worldUp = up;
	this->m_yaw = yaw;
	this->m_pitch = pitch;
	this->UpdateCamVectors();

}
Camera::~Camera()
{
}

glm::mat4 Camera::GetViewMatrix()
{
	
		glm::vec3 pos = m_transform.GetPos();
		return glm::lookAt(pos, pos + m_front, m_worldUp);
	
}
