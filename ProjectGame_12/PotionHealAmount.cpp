#include "item.h"
#include "Player.h"

void PotionHealAmount::use(Player* target)
{
	target->heal(healAmount);
	std::cout << getName() << "at used " << healAmount << "heal.\n";
}
