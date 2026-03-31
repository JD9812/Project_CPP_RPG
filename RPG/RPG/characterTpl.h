#ifndef JD_CHARACTERTPL_H
#define JD_CHARACTERTPL_H

#include <string>
#include "character.h"

namespace JD {

	template<typename T>
	class characterTpl : public Character
	{
		int m_healthMax{};
		T m_health{};

	public:
		characterTpl() = default;

		characterTpl(std::string name, int maxHealth);

		void takeDamage(int dmg) override;

		int getHealth() const override;

		int getHealthMax() const override;

		void setHealth(int health) override;

		void setHealthMax(int health) override;

		~characterTpl() = default;
	};

	template<typename T>
	characterTpl<T>::characterTpl(std::string name, int maxHealth)
		: Character{ name.c_str() },
		m_healthMax{ maxHealth },
		m_health{}
	{
		m_health = maxHealth;
	}

	template<typename T>
	void characterTpl<T>::takeDamage(int dmg) {
		m_health -= dmg;

		if (m_health <= 0)
		{
			std::cout << this->getName() << " has been defeated\n";
		}
		else
		{
			std::cout << this->getName() << " took " << dmg << ", " << this->getHealth() << " remaining.\n";
		}
	}

	template<typename T>
	int characterTpl<T>::getHealth() const {
		return static_cast<int>(m_health);
	}

	template<typename T>
	int characterTpl<T>::getHealthMax() const {
		return m_healthMax;
	}

	template<typename T>
	void characterTpl<T>::setHealth(int health) {
		m_health = health;
	}

	template<typename T>
	void characterTpl<T>::setHealthMax(int health) {
		m_healthMax = health;
		m_health = static_cast<int>(health);
	}

}

#endif