#include "Shop.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Shop::Shop()
{
    Itemlist.push_back({ "���� ü������",10 }); // �������� �Ǹ� ����Ʈ
    Itemlist.push_back({ "50%ȸ�� ü������",20 });
    Itemlist.push_back({ "ž �������� ��",80 });
    Itemlist.push_back({ "ž �������� ����",80 });
}

void Shop::buyItem(Gold& playerGold)
{
    int index; // �� ��ȣ

    while (true) // �� ��ų� �߸��� ��ȣ �Է��ϸ� ������ while�� ���
    {
        // �� ���� �÷��̾� ��� ��� (�׻� �� �ٸ�)
        cout << "\n�÷��̾� ���� ���: " << playerGold.getAmount() << " Gold" << endl;

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
            cout << "�ȹٷ� ��������." << endl;
            continue;
        }

        ShopItem selectItem = Itemlist[index - 1]; // 0���� �����ϴϱ� -1 ���༭ 1���� �����ϰ� ����

        if (playerGold.spend(selectItem.price))
        {
            cout << selectItem.name << "�� �����ϼ̽��ϴ�." << endl;
            playerGold.add();
        }
        else
        {
            cout << "��尡 �����մϴ�. �ٽ� �����ϼ���." << endl;
        }

        // �ݺ����� ���ư��� �� �� ��尡 ���ŵǸ鼭 ���� ȭ�� �ٽ� ���
    }
}
