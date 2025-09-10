#include "item.h"
#include "Player.h"

void PotionHealRatio::use(Player* target)
{
	int healValue = static_cast<int>(target->getmaxHP() * healRatio);
	target->heal(healValue);
	std::cout << getName() << "at used max hp " << (healRatio*100) << "% heal.(+" << healValue << ")\n";
}
