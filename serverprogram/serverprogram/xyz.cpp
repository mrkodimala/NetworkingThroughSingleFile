/*#include<stdio.h>
#include<Windows.h>
int main()
{
	FILE *clientfile, *serverfile;
	clientfile = fopen("f:\client.bin", "rb+");
	serverfile = fopen("f:\server1.bin", "wb");
	printf("%d\t%d\n", serverfile, clientfile);
	int server_flag;
	int server_read_flag;
	int client_flag;
	int client_read_flag;
	char buffer[1024];
	int buffer_offset = 0;
	int q = 1;
	while (1)
	{
		fseek(serverfile, 0, SEEK_SET);
		server_flag = 1;
		fwrite(&server_flag, sizeof(int), 1, serverfile);
		fclose(serverfile);
		serverfile = fopen("f:\server.bin", "wb+");
		printf("%d", ftell(serverfile));
		printf("Waiting for connection....\n");
		Sleep(1000);
		while (1)
		{
			//Sleep(1000);
			client_flag = '0';
			buffer_offset = 0;
			fseek(clientfile, 0, SEEK_SET);
			fread(&client_flag, sizeof(int), 1, clientfile);
			fread(&client_read_flag, sizeof(int), 1, clientfile);
			if (client_flag == 1)
			{
				if (q == 1)
				{
					printf("Client Connected");
					q++;
				}
				if (client_read_flag == 1)
				{
					char ch = ' ';
					fseek(clientfile, 10, SEEK_SET);
					while (ch != '\0')
					{
						fread(&ch, sizeof(char), 1, clientfile);
						buffer[buffer_offset++] = ch;
					}
					buffer[buffer_offset] = '\0';
					//fseek(clientfile, 4, SEEK_SET);
					//int q = 0;
					//fwrite(&q, sizeof(int), 1, clientfile);
					printf("Client:%s\n", buffer);
					printf("Enter Some Text:");
					gets_s(buffer);
					fseek(serverfile, 10, SEEK_SET);
					fwrite(&buffer, sizeof(buffer), 1, serverfile);
					server_read_flag = 1;
					fseek(serverfile, 4, SEEK_SET);
					fwrite(&server_read_flag, sizeof(int), 1, serverfile);
				}
			}
		}
	}
	fseek(serverfile, 0, SEEK_SET);
	int i = 0;
	fwrite(&i, sizeof(int), 1, serverfile);
	_fcloseall();
	getchar();
	return 0;
}*/