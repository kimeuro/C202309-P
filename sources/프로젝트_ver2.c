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
    printf("몇 개의 옷을 입력할 것인가요?: ");
    scanf_s("%d", &numClothes);

    struct CLOTHES* clothes = (struct CLOTHES*)malloc(numClothes * sizeof(struct CLOTHES));

    if (clothes == NULL) {
        return 1;
    }

    for (int i = 0; i < numClothes; i++) {
        printf("\n%d번 옷의 정보 입력을 시작할게요\n", i + 1);
        initializeClothes(&clothes[i]);
    }

    printf("\n옷의 정보를 보여드릴게요\n");
    for (int i = 0; i < numClothes; i++) {
        printf("\n%d번 옷\n", i + 1);
        displayClothes(&clothes[i]);
    }



    return 0;
}



void bodyinformation(struct BODY* p_body_info) {
    printf("신체 정보에 대한 입력을 먼저 시작하겠습니다.\n");
    printf("키를 입력해주세요: ");
    scanf_s("%f", &p_body_info->height);
    printf("몸무게를 입력해주세요: ");
    scanf_s("%f", &p_body_info->weight);
    printf("\n0.특징 없음(평범) 1. 상체발달형 2. 하체발달형 3. 상체비만 4. 하체비만 5. 저체중 6. 심각형 저체중\n");
    printf("체형에 특징이 있나요?: ");
    scanf_s("%d", &p_body_info->bodybalance);
}

void fatcalculator(struct BODY* p_body_info) {
    float BMI = p_body_info->height / (p_body_info->weight) * (p_body_info->weight);
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

void initializeClothes(struct CLOTHES* costume) {
    printf("옷의 이름을 입력하세요: ");
    char temp[100];
    scanf_s("%s", temp, (int)sizeof(temp));
    costume->name = (char*)malloc((strlen(temp) + 1) * sizeof(char));
    strcpy_s(costume->name, strlen(temp) + 1, temp);

    printf("옷의 종류를 입력하세요 (0. 상의  1. 하의  2. 아우터 ): ");
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
        printf("잘못된 입력 입니다. 프로그램이 종료됩니다. ");
        return 1;
    }
    printf("\n0.흰색 1. 검정색 2. 빨간색 3. 주황색 4. 노란색 5. 초록색 6. 파란색 7. 남색 8. 보라색 9. 베이지색\n");
    printf("옷의 주요 색은 무슨 색인가요?: ");
    scanf_s("%d", &costume->color);

    printf("\n0. 슬림핏 1. 정사이즈 2. 오버핏\n");
    printf("옷의 핏은 어떤가요?: ");
    scanf_s("%d", &costume->fit);
}

void displayClothes(const struct CLOTHES* costume) {
    char color_list[10][10] = { "흰색", "검정색", "빨간색", "주황색", "노란색", "초록색", "파란색", "남색", "보라색", "베이지색" };
    char fit_list[3][20] = { "슬림핏", "정사이즈", "오버핏" };

    printf("이름: %s\n", costume->name);
    if (costume->type == 1) {
        printf("종류: 상의\n");
    }
    else if (costume->type == 2) {
        printf("종류: 하의\n");
    }
    else if (costume->type == 3) {
        printf("종류: 아우터\n");
    }
    printf("색: %s\n", color_list[costume->color]);
    printf("핏: %s\n", fit_list[costume->fit]);
}