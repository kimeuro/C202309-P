#include <stdio.h>
#include <stdlib.h>

void PrintClothes(const num, char** ptr) {  // 이중 포인터로 주소의 주소를 받아옴
	for (int i = 0; i < num; i++) {
		printf("%s ", ptr[i]);
	}
}

//struct People {
//	char name[12];
//	int age;
//	float height;
//	float weight;
//	char bodybalance[12];
//	char bodyweakness[12];
//};

int main() {
	int top, bottom, outer = 0;
	printf("입력할 상의의 총 갯수를 입력해주세요: ");
	scanf_s("%d", &top);

	printf("입력할 하의의 총 갯수를 입력해주세요: ");
	scanf_s("%d", &bottom);

	printf("입력할 아우터의 총 갯수를 입력해주세요: ");
	scanf_s("%d", &outer);

	int ArrSize = top + bottom + outer;

	char** clothes = (char**)malloc(sizeof(char*) * ArrSize);  //이차원 배열(이중포인터)의 행의 크기에 대한 값을 동적할당함.
	int* clothes_type = (int*)malloc(sizeof(int) * ArrSize);
	char** clothes_top = (char**)malloc(sizeof(char*) * top);
	char** clothes_bottom = (char**)malloc(sizeof(char*) * bottom);
	char ** clothes_outer = (char**)malloc(sizeof(char*) * outer);

	if (clothes == NULL) {  // 여러번 반복 함수화 필요! -> 현재는 구현에 집중
		return 1;
	}
	if (clothes_type == NULL) {
		return 1;
	}
	if (clothes_top == NULL) {
		return 1;
	}
	if (clothes_bottom == NULL) {
		return 1;
	}
	if (clothes_outer == NULL) {
		return 1;
	}


	for (int i = 0; i < ArrSize; i++) {  //이차원 배열(이중포인터)의 각 행 당 크기에 대한 값을 동적할당함.
		clothes[i] = (char*)malloc(20 * sizeof(char));
	}
	for (int i = 0; i < ArrSize; i++) {  
		clothes_top[i] = (char*)malloc(20 * sizeof(char));
	}
	for (int i = 0; i < ArrSize; i++) {  
		clothes_bottom[i] = (char*)malloc(20 * sizeof(char));
	}
	for (int i = 0; i < ArrSize; i++) { 
		clothes_outer[i] = (char*)malloc(20 * sizeof(char));
	}


	for (int i = 0; i < ArrSize; i++) {
		printf("현재 가진 옷 %d개를 차례로 입력해주세요 (띄어쓰기 없이) : ", ArrSize);
		scanf_s("%s", clothes[i], 20);  // sizeof(clothes[i]) == 포인터의 크기를 알려주는 것. 따라서 오류 발생 해결방법??
	}

	for (int i = 0; i < ArrSize; i++) { 
		printf("%s <- 이 옷의 종류를 입력하세요 (상의 = 1, 하의 = 2, 아우터 = 3) : ", clothes[i]);
		scanf_s("%d", &clothes_type[i]);
	}



	 // 옷의 종류에 따라 포인터 배열에 각각 넣어줌
	int i = 0;
	for (int j = 0; j < ArrSize; j++) {
		if (clothes_type[j] == 1) {
			clothes_top[i] = clothes[j];
			i++;
		}
	}

	i = 0;
	for (int j = 0; j < ArrSize; j++) {
		if (clothes_type[j] == 2) {
			clothes_bottom[i] = clothes[j];
			i++;
		}
	}
	i = 0;
	for (int j = 0; j < ArrSize; j++) {
		if (clothes_type[j] == 3) {
			clothes_outer[i] = clothes[j];
			i++;
		}
	}

	printf("상의 :\n");  // 현재 가진 옷들을 분류하여 출력함
	PrintClothes(top, clothes_top);
	
	printf("\n하의 :\n");
	PrintClothes(bottom, clothes_bottom);

	printf("\n아우터 :\n");
	PrintClothes(outer, clothes_outer);

	free(clothes);
	free(clothes_type);
	free(clothes_top);
	free(clothes_bottom);
	free(clothes_outer);
	return 0;
}