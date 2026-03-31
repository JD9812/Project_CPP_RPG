#ifndef JD_ROGUE_H
#define JD_ROGUE_H
#include "characterTpl.h"
#include "weapons.h"

namespace JD {

	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	class Rogue : public characterTpl<T>
	{
		int m_baseDefense{};
		int m_baseAttack{};
		FirstAbility_t m_firstAbility{};
		SecondAbility_t m_secondAbility{};
		seneca::Dagger m_weapon[2]{};

	public:
		Rogue(const std::string name, int healthMax, int baseAttack, int baseDefense);
		~Rogue() = default;

		int getAttackAmnt() const override;
		int getDefenseAmnt() const override;

		Character* clone() const override;
		void attack(Character* enemy) override;
		void takeDamage(int dmg) override;
	};

	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	Rogue<T, FirstAbility_t, SecondAbility_t>::Rogue(const std::string name, int healthMax, int baseAttack, int baseDefense)
		: characterTpl<T>(name, healthMax), m_baseDefense{ baseDefense }, m_baseAttack{ baseAttack }
	{
	}

	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	int Rogue<T, FirstAbility_t, SecondAbility_t>::getAttackAmnt() const {
		return m_baseAttack + (2 * static_cast<double>(m_weapon[0]));
	}

	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	int Rogue<T, FirstAbility_t, SecondAbility_t>::getDefenseAmnt() const {
		return m_baseDefense;
	}

	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	Character* Rogue<T, FirstAbility_t, SecondAbility_t>::clone() const {
		return new Rogue(*this);
	}

	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	void Rogue<T, FirstAbility_t, SecondAbility_t>::attack(Character* enemy) {
		int damage = 0;

		if (enemy)
		{
			std::cout << this->getName() << " is attacking " << enemy->getName() << std::endl;

			m_firstAbility.useAbility(this);
			m_secondAbility.useAbility(this);

			damage = getAttackAmnt();

			m_firstAbility.transformDamageDealt(damage);
			m_secondAbility.transformDamageDealt(damage);

			std::cout << "Rogue deals " << damage << " melee damage!" << std::endl;

			enemy->takeDamage(damage);
		}
	}

	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	void Rogue<T, FirstAbility_t, SecondAbility_t>::takeDamage(int dmg) {

		std::cout << this->getName() << " is attacked for " << dmg << std::endl;
		std::cout << "\tRogue has a defense of " << getDefenseAmnt() << ". Reducing damage received" << std::endl;

		dmg -= getDefenseAmnt();

		if (dmg < 0)
		{
			dmg = 0;
		}

		m_firstAbility.transformDamageReceived(dmg);
		m_secondAbility.transformDamageReceived(dmg);

		characterTpl<T>::takeDamage(dmg);

	}

}


#endif