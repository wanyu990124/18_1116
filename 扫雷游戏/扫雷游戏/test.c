#include<stdio.h>
#include<stdlib.h>

#define MAX_ROW 10
#define MAX_COL 10
#define DEFAULT_MINE_COUNT 10

int Menu() {
	printf("=================");
	printf("1.��ʼ��Ϸ\n");
	printf("0.�˳���Ϸ\n");
	printf("=================");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

void Init(char show_map[MAX_ROW + 2][MAX_COL + 2], char mine_map[MAX_ROW + 2][MAX_COL + 2]) {
	for (int row = 0; row < MAX_ROW + 2; ++row) {
		for (int col = 0; col < MAX_COL + 2; ++col) {
			show_map[row][col] = '*';
		}
	}
	for (int row = 0; row < MAX_ROW + 2; ++row) {
		for (int col = 0; col < MAX_COL + 2; ++col) {
			mine_map[row][col] = '0';
		}
	}
	int mine_count = DEFAULT_MINE_COUNT;
	while (mine_count > 0) {
		int row = rand() % 10 + 1;
		int col = rand() % 10 + 1;
		--mine_count;
	}
}

void DisplayMap() {

}

void Game() {
	char show_map[MAX_ROW + 2][MAX_COL + 2];
	char mine_map[MAX_ROW + 2][MAX_COL + 2];
	int blank_cnt = 0;
	Init(show_map,mine_map);
	DisplayMap(show_map);
	while (1) {
		int row, col;
		printf("����������:");
		scanf("%d %d", &row, &col);
		if (row <= 0 || row > MAX_ROW || col <= 0 || col > MAX_COL) {
			printf("�������벻�Ϸ�,����������!\n");
			continue;
		}
		if (mine_map == '1') {
			printf("��Ϸ����!\n");
			DisplayMap(mine_map);
			break;
		}
		++blank_cnt;
		if (blank_cnt == MAX_ROW * MAX_COL - DEFAULT_MINE_COUNT) {
			printf("ɨ�׳ɹ�!\n");
			DisplayMap(mine_map);
			break;
		}
		UpdateShowMap();
		DisplayMap(show_map);
}

void Start() {
	while (1) {
		int choice = Menu();
		if (choice == 0) {
			break;
		}
		Game();
	}
}

int main() {

	system("pause");
	return 0;
}