#include "TowerDefence.h"

#include <vector>
#include <string>
#include <iostream>
#include <Resources\DrawObjects\DrawObjects.h>

#include <Core/Engine.h>

using namespace std;

TowerDefence::TowerDefence() {
}

TowerDefence::~TowerDefence() {
}

void TowerDefence::Init() {
	renderCameraTarget = false;

	camera = new Laborator::Camera();
	camera->Set(glm::vec3(0, 3, 5.0f), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0));
	resolution = window->GetResolution();

	miniMapCamera = new Laborator::Camera();
	miniMapCamera->Set(glm::vec3(0, 30, 0), glm::vec3(0, 1, 0), glm::vec3(1, 0, 0));


	projectionMatrix = glm::perspective(RADIANS(60), window->props.aspectRatio, 0.01f, 200.0f);
	projectionMiniMapMatrix = glm::perspective(RADIANS(60), window->props.aspectRatio, 0.01f, 200.0f);
}

void TowerDefence::FrameStart() {
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);
}

void TowerDefence::Update(float deltaTimeSeconds) {
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 1, 0));
		modelMatrix = glm::rotate(modelMatrix, RADIANS(45.0f), glm::vec3(0, 1, 0));

		// Attention! The RenderMesh function overrides the usual RenderMesh that we used until now
		// It uses the viewMatrix from Laborator::Camera instance and the local projectionMatrix
		RenderMesh(meshes["box"], shaders["VertexNormal"], modelMatrix);
	}

	DrawObjects *drawObjects = new DrawObjects();
	drawObjects->drawObjects();
}

void TowerDefence::FrameEnd() {
	glViewport(0, 0, resolution.x, resolution.y);
	DrawCoordinatSystem(camera->GetViewMatrix(), projectionMatrix);
	glViewport(0, 0, resolution.x / 5, resolution.y / 5);
	DrawCoordinatSystem(miniMapCamera->GetViewMatrix(), projectionMiniMapMatrix);
}

void TowerDefence::RenderMesh(Mesh * mesh, Shader * shader, const glm::mat4 & modelMatrix) {
	if (!mesh || !shader || !shader->program)
		return;

	// render an object using the specified shader and the specified position
	shader->Use();
	glUniformMatrix4fv(shader->loc_view_matrix, 1, GL_FALSE, glm::value_ptr(camera->GetViewMatrix()));
	glUniformMatrix4fv(shader->loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
	glUniformMatrix4fv(shader->loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

	mesh->Render();
}

void TowerDefence::RenderMeshMiniMap(Mesh * mesh, Shader * shader, const glm::mat4 & modelMatrix) {
	if (!mesh || !shader)
		return;

	// render an object using the specified shader and the specified position
	shader->Use();
	glUniformMatrix4fv(shader->loc_view_matrix, 1, false, glm::value_ptr(miniMapCamera->GetViewMatrix()));
	glUniformMatrix4fv(shader->loc_projection_matrix, 1, false, glm::value_ptr(projectionMatrix));
	glUniformMatrix4fv(shader->loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

	mesh->Render();
}

// Documentation for the input functions can be found in: "/Source/Core/Window/InputController.h" or
// https://github.com/UPB-Graphics/Framework-EGC/blob/master/Source/Core/Window/InputController.h

void TowerDefence::OnInputUpdate(float deltaTime, int mods) {
	// move the camera only if MOUSE_RIGHT button is pressed
	// de verificat vieti la player
	if (window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
	{
		float cameraSpeed = 2.0f;

		if (window->KeyHold(GLFW_KEY_W)) {
			// TODO : translate the camera forward
			camera->TranslateForward(cameraSpeed*deltaTime);
		}

		if (window->KeyHold(GLFW_KEY_A)) {
			// TODO : translate the camera to the left
			camera->TranslateRight(-cameraSpeed*deltaTime);
		}

		if (window->KeyHold(GLFW_KEY_S)) {
			// TODO : translate the camera backwards
			camera->TranslateForward(-cameraSpeed*deltaTime);
		}

		if (window->KeyHold(GLFW_KEY_D)) {
			// TODO : translate the camera to the right
			camera->TranslateRight(cameraSpeed*deltaTime);
		}
	}
}

void TowerDefence::OnKeyPress(int key, int mods) {
	// add key press event
	if (key == GLFW_KEY_T)
	{
		renderCameraTarget = !renderCameraTarget;
	}
}

void TowerDefence::OnKeyRelease(int key, int mods) {
	// add key release event
}

void TowerDefence::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) {
	// de verificat vietile la player
	if (window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
	{
		float sensivityOX = 0.001f;
		float sensivityOY = 0.001f;

		if (window->GetSpecialKeyState() == 0) {
			camera->RotateThirdPerson_OX(-sensivityOX * deltaY);
			camera->RotateThirdPerson_OY(-sensivityOY * deltaX);
		}

		// de setat unghi la player
		//player->setAngle(-deltaX * 0.001f + player->getAngle());
	}
}

void TowerDefence::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) {
	// add mouse button press event
}

void TowerDefence::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) {
	// add mouse button release event
}

void TowerDefence::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) {
}

void TowerDefence::OnWindowResize(int width, int height) {
}
