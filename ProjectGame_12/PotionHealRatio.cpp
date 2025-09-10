#include "item.h"
#include "Player.h"

void PotionHealRatio::use(Player* target)
{
	int healValue = static_cast<int>(target->getHealth() * healRatio);
	target->heal(healValue);
	std::cout << "[elixirr]" << getName() << "at used max hp " << (healRatio * 50) << "% heal.(+" << healValue << ")\n";
}
