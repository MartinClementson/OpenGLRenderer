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
	glm::vec3 m_yaw;
	glm::vec3 m_pitch;
	glm::vec3 m_front;
	GLfloat m_movementSpeed;
	GLfloat m_mouseSensitivity;
	GLfloat m_zoom;
	void UpdateCamVectors();
public:
	Camera(glm::vec3 pos = glm::vec3(0.0f,0.0f,0.0f), glm::vec3 up = glm::vec3(0.0f,1.0f,0.0f),GLfloat yaw = YAW,GLfloat pitch = PITCH): m_front(glm::vec3(0.0f,0.0f,-1,0f)), m_movementSpeed(SPEED), m_mouseSensitivity(SENSITIVITY), m_zoom(ZOOM);
	
	
	~Camera();

	glm::mat4 GetViewMatrix();

	void ProcessKeyboard(Cam_Movement dir, GLfloat deltaTime)
	{
		GLfloat velocity = this -> m_movementSpeed * deltaTime
	}
	
};

