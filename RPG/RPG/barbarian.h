#ifndef JD_BARBARIAN_H
#define JD_BARBARIAN_H
#include "characterTpl.h"


namespace JD {

	template<typename T, typename Ability_t, typename Weapon_t>
	class Barbarian : public characterTpl<T>
	{
		int m_baseDefense{};
		int m_baseAttack{};
		Ability_t m_ability{};
		Weapon_t m_weapon[2]{};

	public:
		Barbarian(const std::string name, int healthMax, int baseAttack, int baseDefense, Weapon_t primaryWeapon, Weapon_t secondaryWeapon);
		~Barbarian() = default;

		int getAttackAmnt() const override;
		int getDefenseAmnt() const override;

		Character* clone() const override;
		void attack(Character* enemy) override;
		void takeDamage(int dmg) override;

	};

	template<typename T, typename Ability_t, typename Weapon_t>
	Barbarian<T, Ability_t, Weapon_t>::Barbarian(const std::string name, int healthMax,
		int baseAttack, int baseDefense, Weapon_t primaryWeapon, Weapon_t secondaryWeapon)
		: characterTpl<T>(name, healthMax), m_baseDefense{ baseDefense }, m_baseAttack{ baseAttack }
	{
		m_weapon[0] = primaryWeapon;
		m_weapon[1] = secondaryWeapon;
	}

	template<typename T, typename Ability_t, typename Weapon_t>
	int Barbarian<T, Ability_t, Weapon_t>::getAttackAmnt() const {

		return m_baseAttack + (static_cast<double>(m_weapon[0]) / 2) + (static_cast<double>(m_weapon[1]) / 2);
	}

	template<typename T, typename Ability_t, typename Weapon_t>
	int Barbarian<T, Ability_t, Weapon_t>::getDefenseAmnt() const {
		return m_baseDefense;
	}

	template<typename T, typename Ability_t, typename Weapon_t>
	Character* Barbarian<T, Ability_t, Weapon_t>::clone() const {
		return new Barbarian(*this);
	}

	template<typename T, typename Ability_t, typename Weapon_t>
	void Barbarian<T, Ability_t, Weapon_t>::attack(Character* enemy) {

		int damage = 0;

		if (enemy)
		{
			std::cout << this->getName() << " is attacking " << enemy->getName() << std::endl;

			m_ability.useAbility(this);

			damage = getAttackAmnt();

			m_ability.transformDamageDealt(damage);

			std::cout << "Barbarian deals " << damage << " melee damage!" << std::endl;

			enemy->takeDamage(damage);
		}

	}

	template<typename T, typename Ability_t, typename Weapon_t>
	void Barbarian<T, Ability_t, Weapon_t>::takeDamage(int dmg) {

		std::cout << this->getName() << " is attacked for " << dmg << std::endl;
		std::cout << "\tBarbarian has a defense of " << getDefenseAmnt() << ". Reducing damage received" << std::endl;

		dmg -= getDefenseAmnt();

		if (dmg < 0)
		{
			dmg = 0;
		}

		m_ability.transformDamageReceived(dmg);

		characterTpl<T>::takeDamage(dmg);

	}

}

#endif