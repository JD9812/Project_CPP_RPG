#ifndef JD_CHARACTER_H
#define JD_CHARACTER_H
#include <iostream>
#include <iomanip>
#include <string>

namespace JD
{
	// Playable character.
	class Character
	{
		std::string m_name{};

	public:

		// Initializes character
		Character(const char* name) : m_name{ name } {}

		// Get's characters name
		const std::string& getName() const { return m_name; }

		// True if character is alive
		bool isAlive() const { return getHealth() > 0; }

		// Gets base attack
		virtual int getAttackAmnt() const = 0;

		// Gets base defense
		virtual int getDefenseAmnt() const = 0;

		// Gets the current health
		virtual int getHealth() const = 0;

		// Sets health to parameter
		virtual void setHealth(int health) = 0;

		// Gests max health
		virtual int getHealthMax() const = 0;

		// Sets max health to parameter
		virtual void setHealthMax(int health) = 0;

		// Creates a copy of the character.
		virtual Character* clone() const = 0;

		// Attacks enemy character. Use avilities and weapon modifiers.
		virtual void attack(Character* enemy) = 0;

		// Takes damage. May use defense or abilities modifiers.
		virtual void takeDamage(int dmg) = 0;
		virtual ~Character() = default;

		// Overloads << operator to print character info.
		friend std::ostream& operator<<(std::ostream& out, const Character& c)
		{
			out.setf(std::ios::left);
			out << std::setw(20) << c.m_name << "  ";
			out.unsetf(std::ios::left);

			int health = 100 * c.getHealth() / c.getHealthMax();
			out << "  Health: " << std::setw(3) << health << "% ";
			out << '(' << std::setw(4) << c.getHealth() << '/'
				<< std::setw(4) << c.getHealthMax() << ')';
			out << "  Attack: " << std::setw(4) << c.getAttackAmnt();
			out << "  Defense: " << std::setw(4) << c.getDefenseAmnt();
			return out;
		}
	};
}

#endif