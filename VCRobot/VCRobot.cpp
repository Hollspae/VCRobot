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

int main() {
	sf::Texture textureOn;

	if (textureOn.loadFromFile("images/robot_clean_on.png")) {
		std::cout << "all ok";
	}
}