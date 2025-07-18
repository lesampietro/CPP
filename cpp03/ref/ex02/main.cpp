#include "Claptrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap fragtrap("Fraggy");
	ScavTrap scavtrap("Scavvy");
	ClapTrap claptrap("Clappy");
	claptrap.attack("target1");
	claptrap.takeDamage(3);
	claptrap.beRepaired(2);
	scavtrap.attack("target2");
	scavtrap.takeDamage(5);
	scavtrap.beRepaired(3);
	scavtrap.guardGate();
	fragtrap.attack("target3");
	fragtrap.takeDamage(5);
	fragtrap.beRepaired(3);
	fragtrap.highFivesGuys();
	return 0;
}
