#include <stdio.h>
#include <stdlib.h>
#define clothes_num 10  // ���� �޸� �Ҵ��� ���� ���� ���� ���� �Է��ϴ� �� ���� �ʿ�

void PrintClothes(const num, char** ptr) {  // ���� �����ͷ� �ּ��� �ּҸ� �޾ƿ�
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
		printf("���� ���� �� 10���� ���ʷ� �Է����ּ��� (���� ����) : ");
		scanf_s("%s", clothes[i], (int)sizeof(clothes[i]));
	}

	for (int i = 0; i < clothes_num; i++) { 
		printf("%s <- �� ���� ������ �Է��ϼ��� (���� = 1, ���� = 2, �ƿ��� = 3) : ", clothes[i]);
		scanf_s("%d", &clothes_type[i]);
	}
	 // ���� ������ ���� ������ �迭�� ���� �־���
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

	printf("���� :\n");  // ���� ���� �ʵ��� �з��Ͽ� �����
	PrintClothes(clothes_num, clothes_top);
	
	printf("\n���� :\n");
	PrintClothes(clothes_num, clothes_bottom);

	printf("\n�ƿ��� :\n");
	PrintClothes(clothes_num, clothes_outer);

	return 0;
}