#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char* argv[])
{
	//main�����ĵ�һ������Ĭ���ǿ�ִ���ļ�����
	//�ڶ���������ʼ�ǽ��յ��Ĳ�����
	if (argc == 3) {
		//��ȡ�ļ�������
		char data;
		FILE* fp = fopen(argv[2], "r");

		if (!fp) {
			printf("�����ļ���ȡʧ��\n");
			return -1;

		}

		//�Բ��������ж�
		if (!strcmp(argv[1], "-c")) {
			//�ַ���
			char ch;
			int num = 0;
			ch = fgetc(fp);
			while (ch != EOF) {
				ch = fgetc(fp);
				num++;
			}
			printf("�ַ�����%d\n", num);
		}

		//�Բ��������ж�
		else if (!strcmp(argv[1], "-w")) {
			//������
			int w = 0;
			char a = fgetc(fp);
			while (a != EOF) {
				if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')) {
					while ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
						a = fgetc(fp);
					w++;
					a = fgetc(fp);
				}
				else
					a = fgetc(fp);
			}
			printf("��������%d\n", w);
		}
		
		else {
			printf("���󣺲���������Χ��\n");
			printf("���������-c��-w\n");
		}
		int n = fclose(fp);
	}
	else {
		printf("�������в�������Ҫ3��\n");
		printf("�÷���wc.exe [parameter] [input_file_name]\n");

	}
	system("pause");
	return 0;
}