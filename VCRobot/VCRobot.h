#pragma once
#include <SFML/Graphics.hpp>

namespace VCRobotLib {

	class VCRobot {
	public:
		VCRobot(float x, float y, float rotation);
		virtual ~VCRobot();

		void Draw(bool action);
		void Show();
		void Hide();

		void MoveForward();
		void MoveBackward();

		void SetStepSize(float);
		void GetStepSize() const;

		void TurnLeft(float);
		void TurnRight(float);
		void Rotate(float);

		void CleaningOn();
		void CleaningOff();
		bool isCleaning = false;
		bool isVisible = true;

		bool SetTextures(const std::string& fileOn, const std::string& fileOff);

		sf::Vector2f GetPosition() const;
		float GetRotation() const;
		bool IsCleanOn() const;

		bool CanMoveForward() const;
		bool CanMoveBackward() const;

		sf::Texture textureOn;
		sf::Texture textureOff;

		sf::Sprite spriteOn;
		sf::Sprite spriteOff;

		float posX;
		float posY;
		float angle;

		static void SetRenderWindow(sf::RenderWindow* window);
		static  sf::RenderWindow* renderWindow;

	};
}
