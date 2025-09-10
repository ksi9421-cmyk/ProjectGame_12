#include "item.h"
#include "Player.h"

void PotionHealAmount::use(Player* target)
{
	target->heal(healAmount);
	subcount(1);
	std::cout << " [Potion]" << getName() << "at used " << healAmount << "heal.\n";
}
