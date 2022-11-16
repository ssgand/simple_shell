#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int v;
	
	v = execve(argv[1], argv, NULL);
	if (v == -1)
		perror("Error");
	return (0);
}
