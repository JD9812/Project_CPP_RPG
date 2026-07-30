#include <string>
#include <iostream>

#include "archer.h"
#include "barbarian.h"
#include "rogue.h"

#include "abilities.h"
#include "weapons.h"

#include "health.h"

#include "guild.h"
#include "team.h"

using namespace JD;

int main()
{
	JD::Rogue<JD::SuperHealth, JD::Heal, JD::Fireball> rog1("Vex Nightblade", 120, 26, 8);
	JD::Archer<JD::Bow> arch1("Lyra Windshot", 130, 24, 9, JD::Bow{120});
	JD::Barbarian<double, JD::Bersek, JD::Axe> bar1("Rurik Ironfist", 150, 30, 12, JD::Axe{150}, JD::Axe{150});

	std::cout << "Welcome to RPG Coliseum!" << std::endl;
	std::cout << "Select character" << std::endl;

	std::cout << "1. " << rog1 << std::endl;
	std::cout << "2. " << arch1 << std::endl;
	std::cout << "3. " << bar1 << std::endl;
	



	return 0;
}
