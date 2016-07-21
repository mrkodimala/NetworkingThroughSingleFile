//clientfile = fopen("f:\client.bin", "w+");


/*//printf("%d\t%d\n", e1, e2);
printf("%d\t%d\n", serverfile, clientfile);
int server_flag, client_flag = 0;
int server_read_flag = 0, client_read_flag = 0;
char buffer[1024];
int buffer_offset = 0;
int connectedflag = 0;
while (1)
{
	char a;
	fseek(serverfile, 0, SEEK_SET);
	fread(&server_flag, sizeof(server_flag), 1, serverfile);
	printf("%d\n", ftell(serverfile));
	printf("%d", server_flag);
	if (server_flag != 1)
	{
		printf("Server not started to connect...");
		break;
	}
	else{
		if (connectedflag == 0)
		{
			printf("Connected to the server...");
			fseek(clientfile, 0, SEEK_SET);
			int i = 1;
			fwrite(&i, sizeof(int), 1, clientfile);
			getchar();
			connectedflag++;
		}
		printf("Enter the message\n");
		gets(buffer);
		int i = 1;
		fwrite(&i, sizeof(int), 1, clientfile);
		fseek(clientfile, 10, SEEK_SET);
		fwrite(&buffer, sizeof(buffer), 1, clientfile);
	}
}*/