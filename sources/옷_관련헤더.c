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

void bodyinformation(struct BODY* p_body_info) {
    printf("��ü ������ ���� �Է��� ���� �����ϰڽ��ϴ�.\n");
    printf("Ű(m)�� �Է����ּ���(ex: 173cm = 1.73m): ");
    scanf_s("%f", &p_body_info->height);
    printf("�����Ը� �Է����ּ���: ");
    scanf_s("%f", &p_body_info->weight);
    printf("\n0.Ư¡ ����(���) 1. ��ü�ߴ��� 2. ��ü�ߴ��� 3. ��ü�� 4. ��ü�� 5. �ɰ��� ��ü��\n");
    printf("ü���� Ư¡�� �ֳ���?: ");
    scanf_s("%d", &p_body_info->bodybalance);
}

void fatcalculator(struct BODY* p_body_info) {
    float BMI = (p_body_info->weight) / ((p_body_info->height) * (p_body_info->height));  //�� ���� ����
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

void displayClothes(const struct CLOTHES* costume) {
    char color_list[10][10] = { "���", "������", "������", "��Ȳ��", "�����", "�ʷϻ�", "�Ķ���", "����", "�����", "��������" };
    char fit_list[3][20] = { "������", "��������", "������" };

    printf("�̸�: %s\n", costume->name);
    if (costume->type == 0) {
        printf("����: ����\n");
    }
    else if (costume->type == 1) {
        printf("����: ����\n");
    }
    else if (costume->type == 2) {
        printf("����: �ƿ���\n");
    }
    printf("��: %s\n", color_list[costume->color]);
    printf("��: %s\n", fit_list[costume->fit]);
}


void recommendClothesBMI0(struct BODY* p_body_info, struct CLOTHES* costume) {
    if (p_body_info->bodybalance == 5) {
        if (costume->fit == 2) {
            printf("%s ", costume->name);
        }
    }

    else {
        if (costume->fit == 2) {
            printf("%s ", costume->name);
        }
    }
}

void recommendClothesBMI12(struct BODY* p_body_info, struct CLOTHES* costume) {
    if (p_body_info->bodybalance == 0) {
        if (costume->fit == 0 || costume->fit == 1 || costume->fit == 2) {
            printf("%s ", costume->name);
        }
    }
    else if (p_body_info->bodybalance == 1) {
        if (costume->fit == 0) {
            printf("%s ", costume->name);
        }
    }
    else if (p_body_info->bodybalance == 2) {
        if (costume->fit == 0) {
            printf("%s ", costume->name);
        }
    }
}

void recommendClothesBMI34(struct BODY* p_body_info, struct CLOTHES* costume) {
    if (p_body_info->bodybalance == 3) {
        if (costume->fit == 2) {
            printf("%s ", costume->name);
        }
    }
}