#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "옷_관련헤더.h"

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


    printf("\n정보를 토대로 코디를 추천합니다.\n");
    if (body_info.bmi == 0) {
        printf("\n# 저제충이시네요. 어울리는 옷을 추천해 드릴게요.\n\n");
        for (int i = 0; i < numClothes; i++) {
            recommendClothesBMI0(&body_info, &clothes[i]);
        }
        printf("\n");
    }

    else if (body_info.bmi == 1 || body_info.bmi == 2) {
        printf("\n# 정상 체중이시네요. 어울리는 옷을 추천해드릴게요.\n\n");
        for (int i = 0; i < numClothes; i++) {
            recommendClothesBMI12(&body_info, &clothes[i]);
        }
        printf("\n");
    }

    else if (body_info.bmi == 3 || body_info.bmi == 4) {
        printf("\n# 과체중이시네요. 어울리는 옷을 추천해드릴게요.\n\n");
        for (int i = 0; i < numClothes; i++) {
            recommendClothesBMI34(&body_info, &clothes[i]);
        }
        printf("\n");
    }


    printf("잘 어울리는 색 조합은 이렇습니다.\n");
    printf("*** 남색-파란색  초록색-파란색  빨간색-파란색  노란색-남색  검정색-모든색  남색-베이지색 ***\n\n");
    printf("위의 색들을 바탕으로 위에 없는 색들을 사용하여 코디에 포인트를 줘 보세요!\n");


    int randomcolor = 0;
    int randomclothes = 0;
    char color_list[10][10] = { "흰색", "검정색", "빨간색", "주황색", "노란색", "초록색", "파란색", "남색", "보라색", "베이지색" };
    char clothes_list[3][10] = { "상의", "하의", "아우터" };
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        randomcolor = rand() % 9;
    }
    for (int i = 0; i < 2; i++) {
        randomclothes = rand() % 2;
    }
    printf("\n### (광고) >>> %s %s 구매 어떠세요?", color_list[randomcolor], clothes_list[randomclothes]);

    return 0;
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