#include <stdio.h>
#include <stdlib.h>

void PrintClothes(const num, char** ptr) {  // ���� �����ͷ� �ּ��� �ּҸ� �޾ƿ�
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
	printf("�Է��� ������ �� ������ �Է����ּ���: ");
	scanf_s("%d", &top);

	printf("�Է��� ������ �� ������ �Է����ּ���: ");
	scanf_s("%d", &bottom);

	printf("�Է��� �ƿ����� �� ������ �Է����ּ���: ");
	scanf_s("%d", &outer);

	int ArrSize = top + bottom + outer;

	char** clothes = (char**)malloc(sizeof(char*) * ArrSize);  //������ �迭(����������)�� ���� ũ�⿡ ���� ���� �����Ҵ���.
	int* clothes_type = (int*)malloc(sizeof(int) * ArrSize);
	char** clothes_top = (char**)malloc(sizeof(char*) * top);
	char** clothes_bottom = (char**)malloc(sizeof(char*) * bottom);
	char ** clothes_outer = (char**)malloc(sizeof(char*) * outer);

	if (clothes == NULL) {  // ������ �ݺ� �Լ�ȭ �ʿ�! -> ����� ������ ����
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


	for (int i = 0; i < ArrSize; i++) {  //������ �迭(����������)�� �� �� �� ũ�⿡ ���� ���� �����Ҵ���.
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
		printf("���� ���� �� %d���� ���ʷ� �Է����ּ��� (���� ����) : ", ArrSize);
		scanf_s("%s", clothes[i], 20);  // sizeof(clothes[i]) == �������� ũ�⸦ �˷��ִ� ��. ���� ���� �߻� �ذ���??
	}

	for (int i = 0; i < ArrSize; i++) { 
		printf("%s <- �� ���� ������ �Է��ϼ��� (���� = 1, ���� = 2, �ƿ��� = 3) : ", clothes[i]);
		scanf_s("%d", &clothes_type[i]);
	}



	 // ���� ������ ���� ������ �迭�� ���� �־���
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

	printf("���� :\n");  // ���� ���� �ʵ��� �з��Ͽ� �����
	PrintClothes(top, clothes_top);
	
	printf("\n���� :\n");
	PrintClothes(bottom, clothes_bottom);

	printf("\n�ƿ��� :\n");
	PrintClothes(outer, clothes_outer);

	free(clothes);
	free(clothes_type);
	free(clothes_top);
	free(clothes_bottom);
	free(clothes_outer);
	return 0;
}