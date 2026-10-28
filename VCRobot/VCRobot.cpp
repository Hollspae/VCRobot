#include <SFML/Graphics.hpp>
#include "VCRobot.h"
#include <iostream>

VCRobotLib::VCRobot::VCRobot(float x, float y, float rotation)
{
	float angle = std::fmod(rotation, 360);
	while (angle >= 360.f) {
		rotation -= 360.f;
	};
	while (angle < 0) {
		rotation += 360.f;
	}
}

VCRobotLib::VCRobot::~VCRobot()
{
}
int SetTextures(sf::Texture textureOn, sf::Texture textureOff, sf::Sprite spriteOff, sf::Sprite spriteOn) {

	if (textureOn.loadFromFile("Images/robot_clean_on.png") && textureOff.loadFromFile("Images/robot_clean_off.png")) {
		spriteOn.setTexture(textureOn);
		spriteOff.setTexture(textureOff);
		return true;
	}
	return false;
}

void VCRobotLib::VCRobot::Draw(bool action)
{
	if (action) {
		
	};
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
