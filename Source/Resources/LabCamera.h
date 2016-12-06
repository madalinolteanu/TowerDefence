#pragma once
#include <include/glm.h>
#include <include/math.h>

namespace Laborator
{
	class Camera
	{
	public:
		Camera()
		{
			position = glm::vec3(0, 2, 5);
			forward = glm::vec3(0, 0, -1);
			up = glm::vec3(0, 1, 0);
			right = glm::vec3(1, 0, 0);
			distanceToTarget = 2;
		}

		Camera(const glm::vec3 &position, const glm::vec3 &center, const glm::vec3 &up)
		{
			Set(position, center, up);
		}

		~Camera()
		{ }

		// Update camera
		void Set(const glm::vec3 &position, const glm::vec3 &center, const glm::vec3 &up)
		{
			this->position = position;
			forward = glm::normalize(center - position);
			right = glm::cross(forward, up);
			this->up = glm::cross(right, forward);
		}

		void MoveForward(float distance)
		{
			glm::vec3 dir = glm::normalize(glm::vec3(forward.x, 0, forward.z));
		}

		void TranslateForward(float distance)
		{
			glm::vec3 dir = glm::normalize(glm::vec3(forward.x, 0, forward.z));
			glm::normalize(forward);
			position += distance * dir;
		}

		void TranslateToTarget(float distance)
		{
			position = position + glm::normalize(forward) * distance;
		}

		void TranslateRight(float distance)
		{

			glm::vec3 dir = glm::normalize(right);
			position += distance*dir;

		}

		void RotateFirstPerson_OX(float angle)
		{
			glm::vec3 new_forward = glm::rotate(glm::mat4(1), angle, right)*glm::vec4(forward, 1);
			forward = glm::normalize(new_forward);
			up = glm::normalize(glm::cross(right, forward));
		}

		void RotateFirstPerson_OY(float angle)
		{
			glm::vec4 new_forward = glm::rotate(glm::mat4(1), angle, glm::vec3(0, 1, 0))*glm::vec4(forward, 1);
			forward = glm::normalize(new_forward);
			glm::vec4 new_right = glm::rotate(glm::mat4(1), angle, glm::vec3(0, 1, 0))*glm::vec4(right, 1);
			right = glm::normalize(new_right);
			up = glm::cross(right, forward);
		}

		void RotateFirstPerson_OZ(float angle)
		{
		}

		void RotateThirdPerson_OX(float angle)
		{
			TranslateToTarget(distanceToTarget);
			RotateFirstPerson_OX(angle);
			TranslateToTarget(-distanceToTarget);
		}

		void RotateThirdPerson_OY(float angle)
		{
			TranslateToTarget(distanceToTarget);
			RotateFirstPerson_OY(angle);
			TranslateToTarget(-distanceToTarget);
		}

		void RotateThirdPerson_OZ(float angle)
		{
			TranslateToTarget(-distanceToTarget);
			RotateFirstPerson_OZ(angle);
			TranslateToTarget(-distanceToTarget);
		}

		glm::mat4 GetViewMatrix()
		{
			// Returns the View Matrix
			return glm::lookAt(position, position + forward, up);
		}

		glm::vec3 GetTargetPosition()
		{
			return position + forward * distanceToTarget;
		}

	public:
		float distanceToTarget;
		glm::vec3 position;
		glm::vec3 forward;
		glm::vec3 right;
		glm::vec3 up;
	};
}