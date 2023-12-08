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

void initializeClothes(struct CLOTHES* costume);
void displayClothes(const struct CLOTHES* costume);

int main() {
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

void initializeClothes(struct CLOTHES* costume) {
	printf("���� �̸��� �Է��ϼ���: ");
	char temp[100];
	scanf_s("%s", temp, (int)sizeof(temp));
	costume->name = (char*)malloc((strlen(temp) + 1) * sizeof(char));
	strcpy_s(costume->name, strlen(temp) + 1, temp);

	printf("���� ������ �Է��ϼ��� (1. ����  2. ����  3. �ƿ��� ): ");
	scanf_s("%d", &costume->type);

	if (costume->type == 1) {
		costume->top = costume->name;
	}
	else if (costume->type == 2) {
		costume->bottom = costume->name;
	}
	else if (costume->type == 3) {
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