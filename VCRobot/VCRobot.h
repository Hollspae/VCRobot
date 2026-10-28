#pragma once
#include <SFML/Graphics.hpp>


namespace VCRobotLib {

	class VCRobot {
	public:

		VCRobot(float x, float y, float rotation);

		void Draw(bool visible);
		void Show();
		void Hide();

		void MoveForward();
		void MoveBackward();

		void SetStepSize(float step);
		void GetStepSize();

		void TurnLeft(float angle);
		void TurnRight(float angle);
		void Rotate(float angle);

		void CleaningOn();
		void CleaningOff();

		sf::Vector2f GetPosition();
		void GetRotation();
		void IsCleanOn();
		void CanMoveForward();
		void CanMoveBackward();

	};
}
