#include <stdio.h>
#define clothes_num 3

void a(char* ptr, char clothes[][clothes_num]) {
	*ptr = clothes;
}

int main() {
	char clothes[clothes_num][256];
	int clothes_type[clothes_num];
	char clothes_top[clothes_num][256];
	char clothes_bottom[clothes_num][256];
	char clothes_outer[clothes_num][256];
	char* a = clothes_top;

	for (int i = 0; i < clothes_num; i++) {
		printf("���� ���� �� 10���� ���ʷ� �Է����ּ��� (���� ����) : ");
		scanf_s("%s", clothes[i], (int)sizeof(clothes[i]));
	}

	for (int i = 0; i < clothes_num; i++) {
		printf("%s <- �� ���� ������ �Է��ϼ��� (���� = 1, ���� = 2, �ƿ��� = 3) : ", clothes[i]);
		scanf_s("%d", &clothes_type[i]);
		
	}

	for (int i = 0; i < clothes_num; i++) {
		if (clothes_type[i] == 1) {
			a(&clothes_top, clothes[i]);
			printf("%s", clothes_top[i]);
		}
	}


	// �迭 Ȯ�ο�
	/*for (int i = 0; i < clothes_num; i++) {
		printf("%s\t", clothes[i]);
		printf("%d\n", clothes_type[i]);
	}*/

}