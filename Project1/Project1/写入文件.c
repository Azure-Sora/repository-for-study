#include<stdio.h>
//ª∆ÃÏ”Ë2022141461050
int main()
{
	FILE* write;
	FILE* read;
   char temp;
	write = fopen("C.txt", "a");
   read = fopen("A.txt", "r");
   temp = fgetc(read);
   while(temp != EOF)
   {
      fputc(temp, write);
      temp = fgetc(read);

   }
   fclose(read);
   read = fopen("B.txt", "r");
   temp = fgetc(read);
   while(temp != EOF)
   {
      fputc(temp, write);
      temp = fgetc(read);

   }
   fclose(read);
	fclose(write);
	return 0;
}
