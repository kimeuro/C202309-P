#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void bodyinformation(struct BODY* p_body_info);
void fatcalculator(struct BODY* p_body_info);
void initializeClothes(struct CLOTHES* costume);
void displayClothes(const struct CLOTHES* costume);

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



    return 0;
}



void bodyinformation(struct BODY* p_body_info) {
    printf("��ü ������ ���� �Է��� ���� �����ϰڽ��ϴ�.\n");
    printf("Ű�� �Է����ּ���: ");
    scanf_s("%f", &p_body_info->height);
    printf("�����Ը� �Է����ּ���: ");
    scanf_s("%f", &p_body_info->weight);
    printf("\n0.Ư¡ ����(���) 1. ��ü�ߴ��� 2. ��ü�ߴ��� 3. ��ü�� 4. ��ü�� 5. ��ü�� 6. �ɰ��� ��ü��\n");
    printf("ü���� Ư¡�� �ֳ���?: ");
    scanf_s("%d", &p_body_info->bodybalance);
}

void fatcalculator(struct BODY* p_body_info) {
    float BMI = p_body_info->height / (p_body_info->weight) * (p_body_info->weight);
    char bodymass[5][10] = { "��ü��", "����ü��", "��ü��", "��", "����" };
    int bodymassindex;
    if (BMI < 18.5) {
        bodymassindex = 0;
    }
    else if (BMI > 18.5 && BMI < 22.9) {
        bodymassindex = 1;
    }
    else if (BMI > 23 && BMI < 24.9) {
        bodymassindex = 2;
    }
    else if (BMI > 25 && BMI < 39.9) {
        bodymassindex = 3;
    }
    else {
        bodymassindex = 4;
    }
    p_body_info->bmi = bodymassindex;
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

void displayClothes(const struct CLOTHES* costume) {
    char color_list[10][10] = { "���", "������", "������", "��Ȳ��", "�����", "�ʷϻ�", "�Ķ���", "����", "�����", "��������" };
    char fit_list[3][20] = { "������", "��������", "������" };

    printf("�̸�: %s\n", costume->name);
    if (costume->type == 1) {
        printf("����: ����\n");
    }
    else if (costume->type == 2) {
        printf("����: ����\n");
    }
    else if (costume->type == 3) {
        printf("����: �ƿ���\n");
    }
    printf("��: %s\n", color_list[costume->color]);
    printf("��: %s\n", fit_list[costume->fit]);
}