#include "Player.h"
#include "Item.h"
#include "Bag.h"

int main() {
    
    Player hero("용사", 100, 200, 20);
    hero.printStatus();

    
    Bag bag;

    // 아이템 추가
    bag.addItem(std::make_unique<Weapon>("강철검", 300, "현재 공격력의 20% 증가", 0)); // damage는 0, 20%는 use()에서 계산
    bag.addItem(std::make_unique<Armor>("전설의 갑옷", 500, "최대 HP 30% 증가", 0.3f));
    bag.addItem(std::make_unique<Potion>("상처약", 50, "고정 100 회복", 100));
    bag.addItem(std::make_unique<Potion>("엘릭서", 120, "최대 HP 50% 회복", 0.5f));

    std::cout << "\n=== 가방 아이템 목록 ===\n";

    std::cout << "\n=== 아이템 사용 ===\n";

    // 무기 장착 (현재 공격력의 20% 증가)
    bag.useAt(0, hero);
    hero.printStatus();

    // 아머 장착 (최대 HP 30% 증가)
    bag.useAt(1, hero);
    hero.printStatus();

    // 포션 사용 (고정 100 회복)
    hero.heal(-150); // HP 깎기 (테스트용)
    hero.printStatus();
    bag.useAt(2, hero);
    hero.printStatus();

    // 포션 사용 (최대 HP 50% 회복)
    hero.heal(-180); // HP 더 깎기
    hero.printStatus();
    bag.useAt(3, hero);
    hero.printStatus();

    return 0;
}
