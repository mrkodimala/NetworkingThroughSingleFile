#include<stdio.h>
#include<Windows.h>


struct SyncObject{
	int isOpen;
	int isWrite;
	int isRead;
	char unused[20];
};

struct Message{
	char message[1024];
};

int setServerStarted(char *filename)
{
	FILE *server;
	server = fopen(filename, "rb+");
	struct SyncObject s;
	s.isOpen = 1;
	s.isRead = 0;
	s.isWrite = 0;
	fseek(server, 0, SEEK_SET);
	fwrite(&s, sizeof(struct SyncObject), 1, server);
	fseek(server, 0, SEEK_SET);
	memset(&s, 0, sizeof(struct SyncObject));
	fread(&s, sizeof(struct SyncObject), 1, server);
	printf("sopen=%d\n", s.isOpen);
	fclose(server);
	return 1;
}

int checkIsClientStarted(char *filename)
{
	FILE *client;
	client = fopen(filename, "rb");
	struct SyncObject s;
	fseek(client, 1024, SEEK_SET);
	fread(&s, sizeof(struct SyncObject), 1, client);
	fclose(client);
	if (s.isOpen == 1)
		return 1;
	return 0;
}

int checkIsClientWrote(char *filename)
{
	FILE *client;
	client = fopen(filename, "rb");
	struct SyncObject s;
	fseek(client, 1024, SEEK_SET);
	fread(&s, sizeof(struct SyncObject), 1, client);
	fclose(client);
	if (s.isWrite == 1)
		return 1;
	return 0;
}

int setServerWrote(char *filename)
{
	FILE *server;
	server = fopen(filename, "r+b");
	struct SyncObject s;
	s.isOpen = 1;
	s.isRead = 0;
	s.isWrite = 1;
	fseek(server, 0, SEEK_SET);
	fwrite(&s, sizeof(struct SyncObject), 1, server);
	fclose(server);
	return 0;
}


struct Memory{
	char c[2048];
};


void ClearMemory(char *filename)
{
	FILE *file = fopen(filename, "wb");
	struct Memory m;
	memset(&m, 0, sizeof(m));
	fwrite(&m, sizeof(m), 1, file);
	fclose(file);
}

int main()
{
	char commonfile[200] = "f:\commonfile.bin";
	ClearMemory(commonfile);
	setServerStarted(commonfile);
	int Openflag;
	int Writeflag;
	int Readflag;
	int count = 0;
	getchar();
	printf("Waiting for connection....\n");
	
	while (1)
	{
		Sleep(1000);
		if (checkIsClientStarted(commonfile))
		{
			if (count == 0)
			{
				printf("Connected to the Client\n");
				count++;
			}
			if (checkIsClientWrote(commonfile))
			{
				struct Message msg;
				struct SyncObject s;
				FILE *file,*serverfile;
				file = fopen(commonfile, "r+b");
				fseek(file, 1024+32, SEEK_SET);
				fread(&msg, sizeof(struct Message), 1, file);
				s.isRead = 0;
				s.isWrite = 0;
				printf("Client:  %s   \n", msg.message);
				printf("Enter your message:");
				gets(msg.message);
				serverfile = fopen(commonfile, "r+b");
				fseek(serverfile, 32, SEEK_SET);
				fwrite(&msg, sizeof(struct SyncObject), 1, serverfile);
				fclose(serverfile);
				//getchar();
				setServerWrote(commonfile);
				Sleep(100);
				fseek(file, 1024, SEEK_SET);
				fwrite(&s, sizeof(struct SyncObject), 1, file);
				fclose(file);
			}
		}
	}
	getchar();
	return 0;
}