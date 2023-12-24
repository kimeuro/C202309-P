#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "��_�������.h"

struct CLOTHES {
    char* name;
    int type;
    char* top;
    char* bottom;
    char* outer;
    int color;
    int fit;
};

struct BODY {
    float height;
    float weight;
    int bodybalance;
    int bmi;
};

void initializeClothes(struct CLOTHES* costume);

int main() {
    struct BODY body_info;
    bodyinformation(&body_info);
    fatcalculator(&body_info);

    int numClothes;
    printf("�� ���� ���� �Է��� ���ΰ���?: ");
    scanf_s("%d", &numClothes);

    struct CLOTHES* clothes = (struct CLOTHES*)malloc(numClothes * sizeof(struct CLOTHES));

    if (clothes == NULL) {
        return 1;
    }

    for (int i = 0; i < numClothes; i++) {
        printf("\n%d�� ���� ���� �Է��� �����ҰԿ�\n", i + 1);
        initializeClothes(&clothes[i]);
    }

    printf("\n���� ������ �����帱�Կ�\n");
    for (int i = 0; i < numClothes; i++) {
        printf("\n%d�� ��\n", i + 1);
        displayClothes(&clothes[i]);
    }


    printf("\n������ ���� �ڵ� ��õ�մϴ�.\n");
    if (body_info.bmi == 0) {
        printf("\n# �������̽ó׿�. ��︮�� ���� ��õ�� �帱�Կ�.\n\n");
        for (int i = 0; i < numClothes; i++) {
            recommendClothesBMI0(&body_info, &clothes[i]);
        }
        printf("\n");
    }

    else if (body_info.bmi == 1 || body_info.bmi == 2) {
        printf("\n# ���� ü���̽ó׿�. ��︮�� ���� ��õ�ص帱�Կ�.\n\n");
        for (int i = 0; i < numClothes; i++) {
            recommendClothesBMI12(&body_info, &clothes[i]);
        }
        printf("\n");
    }

    else if (body_info.bmi == 3 || body_info.bmi == 4) {
        printf("\n# ��ü���̽ó׿�. ��︮�� ���� ��õ�ص帱�Կ�.\n\n");
        for (int i = 0; i < numClothes; i++) {
            recommendClothesBMI34(&body_info, &clothes[i]);
        }
        printf("\n");
    }


    printf("�� ��︮�� �� ������ �̷����ϴ�.\n");
    printf("*** ����-�Ķ���  �ʷϻ�-�Ķ���  ������-�Ķ���  �����-����  ������-����  ����-�������� ***\n\n");
    printf("���� ������ �������� ���� ���� ������ ����Ͽ� �ڵ� ����Ʈ�� �� ������!\n");


    int randomcolor = 0;
    int randomclothes = 0;
    char color_list[10][10] = { "���", "������", "������", "��Ȳ��", "�����", "�ʷϻ�", "�Ķ���", "����", "�����", "��������" };
    char clothes_list[3][10] = { "����", "����", "�ƿ���" };
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        randomcolor = rand() % 9;
    }
    for (int i = 0; i < 2; i++) {
        randomclothes = rand() % 2;
    }
    printf("\n### (����) >>> %s %s ���� �����?", color_list[randomcolor], clothes_list[randomclothes]);

    return 0;
}

void initializeClothes(struct CLOTHES* costume) {
    printf("���� �̸��� �Է��ϼ���: ");
    char temp[100];
    scanf_s("%s", temp, (int)sizeof(temp));
    costume->name = (char*)malloc((strlen(temp) + 1) * sizeof(char));
    strcpy_s(costume->name, strlen(temp) + 1, temp);

    printf("���� ������ �Է��ϼ��� (0. ����  1. ����  2. �ƿ��� ): ");
    scanf_s("%d", &costume->type);

    if (costume->type == 0) {
        costume->top = costume->name;
    }
    else if (costume->type == 1) {
        costume->bottom = costume->name;
    }
    else if (costume->type == 2) {
        costume->outer = costume->name;
    }
    else {
        printf("�߸��� �Է� �Դϴ�. ���α׷��� ����˴ϴ�. ");
        return 1;
    }
    printf("\n0.��� 1. ������ 2. ������ 3. ��Ȳ�� 4. ����� 5. �ʷϻ� 6. �Ķ��� 7. ���� 8. ����� 9. ��������\n");
    printf("���� �ֿ� ���� ���� ���ΰ���?: ");
    scanf_s("%d", &costume->color);

    printf("\n0. ������ 1. �������� 2. ������\n");
    printf("���� ���� �����?: ");
    scanf_s("%d", &costume->fit);
}