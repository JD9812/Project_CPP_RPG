#ifndef JD_ARCHER_H
#define JD_ARCHER_H
#include "characterTpl.h"

namespace JD {

	template<typename Weapon_t>
	class Archer : public characterTpl<seneca::SuperHealth>
	{
		int m_baseDefense{};
		int m_baseAttack{};
		Weapon_t m_weapon{};

	public:
		Archer(const std::string name, int healthMax, int baseAttack, int baseDefense, Weapon_t weapon);
		~Archer() = default;

		int getAttackAmnt() const override;
		int getDefenseAmnt() const override;

		Character* clone() const override;
		void attack(Character* enemy) override;
		void takeDamage(int dmg) override;

	};

	template<typename Weapon_t>
	Archer<Weapon_t>::Archer(const std::string name, int healthMax, int baseAttack, int baseDefense, Weapon_t weapon)
		: characterTpl<JD::SuperHealth>(name, healthMax), m_baseDefense{ baseDefense }, m_baseAttack{ baseAttack }, m_weapon{ weapon }
	{
	}

	template<typename Weapon_t>
	int Archer<Weapon_t>::getAttackAmnt() const {
		return 1.3 * m_baseAttack;
	}

	template<typename Weapon_t>
	int Archer<Weapon_t>::getDefenseAmnt() const {
		return 1.2 * m_baseAttack;
	}

	template<typename Weapon_t>
	Character* Archer<Weapon_t>::clone() const {
		return new Archer(*this);
	}

	template<typename Weapon_t>
	void Archer<Weapon_t>::attack(Character* enemy) {
		int damage = 0;

		if (enemy)
		{
			std::cout << getName() << " is attacking " << enemy->getName() << std::endl;

			damage = getAttackAmnt();

			std::cout << "Archer deals " << damage << " ranged damage!" << std::endl;

			enemy->takeDamage(damage);
		}
	}

	template<typename Weapon_t>
	void Archer<Weapon_t>::takeDamage(int dmg) {

		std::cout << getName() << " is attacked for " << dmg << std::endl;
		std::cout << "\tArcher has a defense of " << getDefenseAmnt() << ". Reducing damage received" << std::endl;

		dmg -= getDefenseAmnt();

		if (dmg < 0)
		{
			dmg = 0;
		}

		characterTpl<seneca::SuperHealth>::takeDamage(dmg);
	}
}


#endif