#include "item.h"
#include "Player.h"

void PotionHealRatio::use(Player* target)
{
	int healValue = static_cast<int>(target->getmaxHP() * healRatio);
	target->heal(healValue);
	subcount(1);
	std::cout << "[elixirr]" << getName() << "at used max hp " << (healRatio * 100) << "% heal.(+" << healValue << ")\n";
}
