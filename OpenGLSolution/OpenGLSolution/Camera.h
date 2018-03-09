#pragma once
#include "TransformNode.h"
#include <vector>

const GLfloat YAW = -90.f;
const GLfloat PITCH		   = 0.0f;
const GLfloat SPEED		   = 6.0f;
const GLfloat SENSITIVITY  = 0.25f;
const GLfloat ZOOM		   = 45.0f;
class Camera
{
	enum Cam_Movement
	{
		FORWARD,
		BACKWARD,
		LEFT,
		RIGHT
	};

private:
	TransformNode m_transform;
	glm::vec3 m_worldUp;
	glm::vec3 m_up;
	glm::vec3 m_front;
	glm::vec3 m_right;
	GLfloat m_yaw;
	GLfloat m_pitch;
	GLfloat m_movementSpeed;
	GLfloat m_mouseSensitivity;
	GLfloat m_zoom;
	void UpdateCamVectors();
public:
	Camera(glm::vec3 pos, glm::vec3 up, GLfloat yaw, GLfloat pitch);
	Camera() {};
	
	~Camera();

	glm::mat4 GetViewMatrix();
	void ProcessKeyboard(Cam_Movement dir, GLfloat deltaTime);
	//{
	//	GLfloat velocity = this->m_movementSpeed * deltaTime;
	//	glm::vec3 newPos = m_transform.GetPos();
	//	if (FORWARD == dir){
	//		newPos += (this->m_front * velocity);
	//		this->m_transform.SetPos(newPos);
	//	}
	//	if (BACKWARD == dir) {
	//		newPos -= (this->m_front * velocity);
	//		this->m_transform.SetPos(newPos);
	//	}
	//	if (LEFT == dir) {
	//		newPos -= (this->m_right * velocity);
	//		this->m_transform.SetPos(newPos);
	//	}
	//	if (RIGHT == dir) {
	//		newPos += (this->m_right * velocity);
	//		this->m_transform.SetPos(newPos);
	//	}

	//}

	void ProcessMouseMovement(GLfloat xOffset, GLfloat yOffset, GLboolean constrainPitch);
	//{
	//	xOffset *= this->m_mouseSensitivity;
	//	yOffset *= this->m_mouseSensitivity;

	//	this->m_yaw		+= xOffset;
	//	this->m_pitch   += yOffset;

	//	if (constrainPitch)
	//	{
	//		if(this->m_pitch > 89.0f)
	//		{ 
	//			this-> m_pitch = 89.0f;
	//		}
	//		if (this->m_pitch < - 89.0f)
	//		{
	//			this->m_pitch = -89.0f;
	//		}
	//	}
	//	this->UpdateCamVectors();
	//}
	void ProcessMouseScroll(GLfloat yOffset);
	/*{
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

	}*/
	GLfloat GetZoom() { return this->m_zoom; };

	
	
};

