#include "Shop.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Shop::Shop()
{
    Itemlist.push_back({ "고정 체력포션",10 }); // 상점에서 판매 리스트
    Itemlist.push_back({ "50%회복 체력포션",20 });
    Itemlist.push_back({ "탑 관리자의 검",80 });
    Itemlist.push_back({ "탑 관리자의 갑옷",80 });
}

void Shop::buyItem(Gold& playerGold)
{
    int index; // 템 번호

    while (true) // 템 사거나 잘못된 번호 입력하면 끝나서 while문 사용
    {
        // 맨 위에 플레이어 골드 출력 (항상 한 줄만)
        cout << "\n플레이어 현재 골드: " << playerGold.getAmount() << " Gold" << endl;

        // 상점 목록 출력
        cout << "===== 탑의 상점 =====" << endl;
        for (int i = 0; i < (int)Itemlist.size(); ++i) // 상점창에서 판매목록 1번부터해서 상점창 출력
        {
            cout << i + 1 << ". " << Itemlist[i].name
                << " - " << Itemlist[i].price << " Gold" << endl; // 1. 템 - 가격 골드
        }
        cout << "0. 상점 나가기" << endl;
        cout << "==================" << endl;

        cout << "구매할 번호를 입력하세요.: ";
        cin >> index;

        if (index == 0)
        {
            cout << "상점을 나갑니다." << endl;
            break;
        }

        if (index < 1 || index >(int)Itemlist.size())
        {
            cout << "똑바로 고르세요." << endl;
            continue;
        }

        ShopItem selectItem = Itemlist[index - 1]; // 0부터 시작하니까 -1 해줘서 1부터 시작하게 해줌

        if (playerGold.spend(selectItem.price))
        {
            cout << selectItem.name << "을 구매하셨습니다." << endl;
            
        }
        else
        {
            cout << "골드가 부족합니다. 다시 선택하세요." << endl;
        }

        // 반복문이 돌아가면 맨 위 골드가 갱신되면서 상점 화면 다시 출력
    }
}
