#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char* argv[])
{
	//main函数的第一个参数默认是可执行文件本身，
	//第二个参数开始是接收到的参数。
	if (argc == 3) {
		//读取文件的内容
		char data;
		FILE* fp = fopen(argv[2], "r");

		if (!fp) {
			printf("错误：文件读取失败\n");
			return -1;

		}

		//对参数进行判断
		if (!strcmp(argv[1], "-c")) {
			//字符数
			char ch;
			int num = 0;
			ch = fgetc(fp);
			while (ch != EOF) {
				ch = fgetc(fp);
				num++;
			}
			printf("字符数：%d\n", num);
		}

		//对参数进行判断
		else if (!strcmp(argv[1], "-w")) {
			//单词数
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
			printf("单词数：%d\n", w);
		}
		
		else {
			printf("错误：参数超出范围！\n");
			printf("允许参数：-c，-w\n");
		}
		int n = fclose(fp);
	}
	else {
		printf("错误：运行参数必须要3个\n");
		printf("用法：wc.exe [parameter] [input_file_name]\n");

	}
	system("pause");
	return 0;
}