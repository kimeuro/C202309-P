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
    printf("신체 정보에 대한 입력을 먼저 시작하겠습니다.\n");
    printf("키(m)를 입력해주세요(ex: 173cm = 1.73m): ");
    scanf_s("%f", &p_body_info->height);
    printf("몸무게를 입력해주세요: ");
    scanf_s("%f", &p_body_info->weight);
    printf("\n0.특징 없음(평범) 1. 상체발달형 2. 하체발달형 3. 상체비만 4. 하체비만 5. 심각형 저체중\n");
    printf("체형에 특징이 있나요?: ");
    scanf_s("%d", &p_body_info->bodybalance);
}

void fatcalculator(struct BODY* p_body_info) {
    float BMI = (p_body_info->weight) / ((p_body_info->height) * (p_body_info->height));  //식 오류 변경
    char bodymass[5][10] = { "저체충", "정상체중", "과체중", "비만", "고도비만" };
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
    char color_list[10][10] = { "흰색", "검정색", "빨간색", "주황색", "노란색", "초록색", "파란색", "남색", "보라색", "베이지색" };
    char fit_list[3][20] = { "슬림핏", "정사이즈", "오버핏" };

    printf("이름: %s\n", costume->name);
    if (costume->type == 0) {
        printf("종류: 상의\n");
    }
    else if (costume->type == 1) {
        printf("종류: 하의\n");
    }
    else if (costume->type == 2) {
        printf("종류: 아우터\n");
    }
    printf("색: %s\n", color_list[costume->color]);
    printf("핏: %s\n", fit_list[costume->fit]);
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