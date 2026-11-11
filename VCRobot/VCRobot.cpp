#include <SFML/Graphics.hpp>
#include "VCRobot.h"
#include <iostream>

VCRobotLib::VCRobot::VCRobot(float x, float y, float rotation)
	: posX(x)
	, posY(y)
	, angle(0.0f)
{
	rotation = std::fmod(rotation, 360.0f);
	if (rotation < 0.0f)
		rotation += 360.0f;
	angle = rotation;

	spriteOn.setPosition(posX, posY);
	spriteOff.setPosition(posX, posY);
	spriteOn.setRotation(angle);
	spriteOff.setRotation(angle);
}

VCRobotLib::VCRobot::~VCRobot()
{
}

bool VCRobotLib::VCRobot::SetTextures(const std::string& fileOn, const std::string& fileOff)
{
	if (!textureOn.loadFromFile(fileOn)) {
		return false;
	}

	if (!textureOff.loadFromFile(fileOff)) {
		return false;
	}

	spriteOn.setTexture(textureOn);
	spriteOff.setTexture(textureOff);

	sf::FloatRect boundsOn = spriteOn.getLocalBounds();
	sf::FloatRect boundsOff = spriteOff.getLocalBounds();
	spriteOn.setOrigin(boundsOn.width / 2.0f, boundsOn.height / 2.0f);
	spriteOff.setOrigin(boundsOff.width / 2.0f, boundsOff.height / 2.0f);

	return true;
}

void VCRobotLib::VCRobot::Draw(bool action)
{
	if (!action || !isVisible) return;

	sf::Sprite& activeSprite = isCleaning ? spriteOn : spriteOff;

	renderWindow->draw(activeSprite);
}

void VCRobotLib::VCRobot::Show()
{
	isVisible = true;
}

void VCRobotLib::VCRobot::Hide()
{
	isVisible = false;
}

void VCRobotLib::VCRobot::MoveForward()
{
}

void VCRobotLib::VCRobot::MoveBackward()
{
}

void VCRobotLib::VCRobot::CleaningOn()
{
	isCleaning = true;
}

void VCRobotLib::VCRobot::CleaningOff()
{
	isCleaning = false;
}

bool VCRobotLib::VCRobot::IsCleanOn() const
{
	return isCleaning;
}
