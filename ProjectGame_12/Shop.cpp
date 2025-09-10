#include "Shop.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Shop::Shop()
{
    Itemlist.push_back({ "HP 100 ���� ����",10, EItemType::HealAmount }); // �������� �Ǹ� ����Ʈ
    Itemlist.push_back({ "HP 50% ���� ����",20, EItemType::HealRatio });
    Itemlist.push_back({ "���ݷ� ���� ����",80, EItemType::EWeapon });
    Itemlist.push_back({ "�ִ�ü�� ���� ����",80, EItemType::EArmor });
}

void Shop::buyItem(Player* player)
{
    int index; // �� ��ȣ

    while (true) // �� ��ų� �߸��� ��ȣ �Է��ϸ� ������ while�� ���
    {
        // �� ���� �÷��̾� ��� ��� (�׻� �� �ٸ�)
        cout << "\n�÷��̾� ���� ���: " << Gold::getinstance().getAmount() << " Gold" << endl;

        // ���� ��� ���
        cout << "===== ž�� ���� =====" << endl;
        for (int i = 0; i < (int)Itemlist.size(); ++i) // ����â���� �ǸŸ�� 1�������ؼ� ����â ���
        {
            cout << i + 1 << ". " << Itemlist[i].name
                << " - " << Itemlist[i].price << " Gold" << endl; // 1. �� - ���� ���
        }
        cout << "0. ���� ������" << endl;
        cout << "==================" << endl;

        cout << "������ ��ȣ�� �Է��ϼ���.: ";
        cin >> index;

        if (index == 0)
        {
            cout << "������ �����ϴ�." << endl;
            break;
        }

        if (index < 1 || index >(int)Itemlist.size())
        {
            cout << "�߸��� �Է°��Դϴ�." << endl;
            continue;
        }

        ShopItem selectItem = Itemlist[index - 1]; // 0���� �����ϴϱ� -1 ���༭ 1���� �����ϰ� ����

        if (Gold::getinstance().spend(selectItem.price))
        {
            cout << selectItem.name << "�� �����Ͽ����ϴ�." << endl;

            
            auto item = player->getBag()->getItem(selectItem.type);
            if (item)
            {
                item->addCount(1);
            }
            
           

        }
    }

    // �ݺ����� ���ư��� �� �� ��尡 ���ŵǸ鼭 ���� ȭ�� �ٽ� ���
}

