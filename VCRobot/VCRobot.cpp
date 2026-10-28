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

void VCRobotLib::VCRobot::Draw(bool action)
{

}

int SetTextures(sf::Texture textureOn, sf::Texture textureOff) {

	if (textureOn.loadFromFile("images/robot_clean_on.png") && textureOn.loadFromFile("images/robot_clean_off.png")) {
		return true;
	}
	return false;
}