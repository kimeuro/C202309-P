#include <stdio.h>
#include <stdlib.h>
#define clothes_num 10  // 동적 메모리 할당을 통해 가진 옷의 수를 입력하는 것 구현 필요

void PrintClothes(const num, char** ptr) {  // 이중 포인터로 주소의 주소를 받아옴
	for (int i = 0; i < num; i++) {
		printf("%s ", ptr[i]);
	}
}

int main() {
	char clothes[clothes_num][256];
	int clothes_type[clothes_num];
	char* clothes_top[clothes_num] = {NULL,};
	char* clothes_bottom[clothes_num] = {NULL,};
	char* clothes_outer[clothes_num] = {NULL,};

	for (int i = 0; i < clothes_num; i++) {
		printf("현재 가진 옷 10개를 차례로 입력해주세요 (띄어쓰기 없이) : ");
		scanf_s("%s", clothes[i], (int)sizeof(clothes[i]));
	}

	for (int i = 0; i < clothes_num; i++) { 
		printf("%s <- 이 옷의 종류를 입력하세요 (상의 = 1, 하의 = 2, 아우터 = 3) : ", clothes[i]);
		scanf_s("%d", &clothes_type[i]);
	}
	 // 옷의 종류에 따라 포인터 배열에 각각 넣어줌
	int i = 0;
	for (int j = 0; j < clothes_num; j++) {
		if (clothes_type[j] == 1) {
			clothes_top[i] = clothes[j];
			i++;
		}
	}

	i = 0;
	for (int j = 0; j < clothes_num; j++) {
		if (clothes_type[j] == 2) {
			clothes_bottom[i] = clothes[j];
			i++;
		}
	}
	i = 0;
	for (int j = 0; j < clothes_num; j++) {
		if (clothes_type[j] == 3) {
			clothes_outer[i] = clothes[j];
			i++;
		}
	}

	printf("상의 :\n");  // 현재 가진 옷들을 분류하여 출력함
	PrintClothes(clothes_num, clothes_top);
	
	printf("\n하의 :\n");
	PrintClothes(clothes_num, clothes_bottom);

	printf("\n아우터 :\n");
	PrintClothes(clothes_num, clothes_outer);

	return 0;
}