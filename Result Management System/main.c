#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

void goto_x_y(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
struct student
{
	char result[20];
	char name[50];
	char roll[20];
	float m1;
	float m2;
	float m3;
	float m4;
	float m5;
	float total;
	float percentage;
	char year[5];
	char schoolname[100];
} s;
void addrecords();
void individual();
void all();
void modifyrecords();
void deleterecords();
int password_check();
void aboutus();
int main()
{
	int i;
	char choice;

	system("cls");

	printf("\n\n\n\n\n");
	for (i = 0; i <= 100; i++)
		printf("*");
	printf("\n\t\t\t*\t  Welcome to The Program          *");
	printf("\n\t\t\t*\t\t***MENU***                *");
	printf("\n\t\t\t*\t1. Add data                       *");
	printf("\n\t\t\t*\t2. Display the individual Report  *");
	printf("\n\t\t\t*\t3. Display the overall Report     *");
	printf("\n\t\t\t*\t4. Edit Record                    *");
	printf("\n\t\t\t*\t5. Delete Record!!!               *");
	printf("\n\t\t\t*\t6. About us                       *");
	printf("\n\t\t\t*\t7. Exit                           *\n");
	fflush(stdin);
	for (i = 0; i <= 100; i++)
		printf("*");
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\tEnter your choice:");
	choice = getch();
	switch (choice)
	{
	case '1':
		addrecords();
		main();
		break;
	case '2':
		individual();
		getch();
		main();
		break;
	case '3':
		all();
		getch();
		main();
		break;
	case '4':
		modifyrecords();
		getch();
		main();
		break;
	case '5':
		deleterecords();
		getch();
		main();
		break;
	case '6':
		aboutus();
		main();
		break;
	case '7':
		system("cls");
		exit(0);
		break;
	default:
		printf("\nPlease select the proper option as indicated from 1 to 7");
		getch();
		main();
	}
}
void addrecords()
{
	system("cls");
	int i, f;
	char chkwrd;
	FILE *fptr;
	char test;
	i = password_check();
	if (i == 0)
	{
		printf("\n\n\n\n\n\n\t\tTHE PASSWORD YOU ENTERED IS INCORRECT....TRY AGAIN FOR IT OR IF YOU WANT TO GO TO MAIN MENU PRESS ESC KEY");
		chkwrd = getch();
		if (chkwrd == 27)
			main();
		addrecords();
	}
	if ((fptr = fopen("data.dat", "ab+")) == NULL)
		exit(0);
	do
	{
		printf("\n\n\nEnter the name of the college");
		scanf("%[^\n]", s.schoolname);
		system("cls");
		goto_x_y(0, 0);
		printf("Full Name of the student:\t");
		printf("Roll no: ");
		goto_x_y(0, 5);
		printf("Enter the marks\n");
		printf("Mathematics\tPhysics\t\tChemistry\t\tEnglish\t\tNepali");
		goto_x_y(0, 1);
		fflush(stdin);
		scanf("%[^\n]", s.name);
		goto_x_y(25, 1);
		fflush(stdin);
		scanf("%s", s.roll);
		goto_x_y(3, 7);
		fflush(stdin);
		scanf("%f", &s.m1);
		goto_x_y(17, 7);
		fflush(stdin);
		scanf("%f", &s.m2);
		goto_x_y(34, 7);
		fflush(stdin);
		scanf("%f", &s.m3);
		goto_x_y(56, 7);
		fflush(stdin);
		scanf("%f", &s.m4);
		goto_x_y(73, 7);
		fflush(stdin);
		scanf("%f", &s.m5);
		if (s.m1 > 100 || s.m1 < 0 || s.m2 > 100 || s.m2 < 0 || s.m3 > 100 || s.m3 < 0 || s.m4 > 100 || s.m5 < 0 || s.m4 < 0 || s.m5 > 100)
		{
			printf("\n\n\n\t\t\t\t\tInvalid Data Entered!!!!!");
			getch();
			main();
		}
		s.total = (s.m1 + s.m2 + s.m3 + s.m4 + s.m5);
		s.percentage = s.total / 5.0;
		if (s.percentage >= 75)
			strcpy(s.result, "Distinction");
		if (s.percentage < 75 && s.percentage >= 60)
			strcpy(s.result, "First Division");
		if (s.percentage < 60 && s.percentage >= 50)
			strcpy(s.result, "Second Division");
		if (s.percentage < 50 && s.percentage >= 40)
			strcpy(s.result, "Pass");
		if (s.percentage < 32)
			strcpy(s.result, "Fail");
		if (s.m1 < 32 || s.m2 < 32 || s.m3 < 32 || s.m4 < 32 || s.m5 < 32)
			strcpy(s.result, "Fail");
		fwrite(&s, sizeof(s), 1, fptr);
		fflush(stdin);
		printf("press Esc to go to the main menu");
		goto_x_y(10, 16);
		printf("Press any other key to continue adding.....");
		test = getch();
	} while (test != 27); // ASCII value of Esc key is 27
	fclose(fptr);
}
void individual()
{
	char rollno[10];
	FILE *fptr;
	int a = 1, i;
	if ((fptr = fopen("data.dat", "rb")) == NULL)
		exit(0);
	system("cls");
	printf("Enter the roll number of the student to see his report card:");
	scanf("%s", rollno);
	while (fread(&s, sizeof(s), 1, fptr) == 1)
	{
		if (strcmp(s.roll, rollno) == 0)
		{
			system("cls");
			printf("\t\t\t\t  RESULT MANAGEMENT SYSTEM");
			printf("\n\n");
			printf("\n\t\t\t\tMARK SHEET");
			printf("\n\n");
			printf("Name of student: %s\nSymbol No: %s\nGrade 12\nSchool: %s\n", s.name, s.roll, s.schoolname);
			for (i = 0; i <= 70; i++)
				printf("\xcd");
			printf("\nSubject\t     Full Mark\t\t  Pass Mark\t    Obtained Mark\n");
			for (i = 0; i <= 70; i++)
				printf("\xcd");
			printf("\nENGLISH\t\t100\t\t\t35\t\t%2.f\n", s.m4);
			printf("NEPALI\t\t100\t\t\t35\t\t%2.f\n", s.m5);
			printf("PHYSICS\t\t100\t\t\t35\t\t%2.f\n", s.m2);
			printf("CHEMISTRY\t100\t\t\t35\t\t%2.f\n", s.m3);
			printf("MATHEMATICS\t100\t\t\t35\t\t%2.f\n", s.m1);
			for (i = 0; i <= 70; i++)
				printf("\xcd");
			printf("\n\t\t\t\t\t\tTotal: %.f\n", s.total);
			for (i = 0; i <= 70; i++)
				printf("\xcd");
			printf("\n\t\t\t\t\t\tPercentage: %f", s.percentage);
			printf("\n\t\t\t\t\t\tResult: %s", s.result);

			a = 0;
		}
	}
	if (a == 1)
		printf("Data Not Found!!!");
	fclose(fptr);
	getch();
}
void all()
{
	int i;
	FILE *fptr;
	if ((fptr = fopen("data.dat", "rb")) == NULL)
		exit(0);
	system("cls");
	printf("\nRoll No.  Name\t\tMaths.\tPhys.\tChem.\tNep\tEng\tTotal\tPcnt.  Result\n");
	for (i = 0; i <= 95; i++)
		printf("\xcd");
	while (fread(&s, sizeof(s), 1, fptr) == 1)
	{
		printf("\n%s\t%s\t\t%.f\t%.f\t%.f\t%.f\t%.f\t%.f\t%.f\%", s.roll, s.name, s.m1, s.m2, s.m3, s.m5, s.m4, s.total, s.percentage);
		printf("\t%s", s.result);
	}
	fclose(fptr);
}
void modifyrecords()
{
	system("cls");
	FILE *fptr;
	char roll[20];
	int i;
	char chkwrd;
	i = password_check();
	if (i == 0)
	{
		printf("\n\n\n\n\n\n\t\tTHE PASSWORD YOU ENTERED IS INCORRECT....TRY AGAIN FOR IT OR IF YOU WANT TO GO TO MAIN MENU PRESS ESC KEY");
		chkwrd = getch();
		if (chkwrd == 27)
			main();
		modifyrecords();
	}
	long int size = sizeof(s);
	if ((fptr = fopen("data.dat", "rb+")) == NULL)
	{
		printf("The Source file does not exist");
		fclose(fptr);
		exit(0);
	}
	else
	{
		int a = 1;
		system("cls");
		printf("ENTER THE ROLL NO OF THE STUDENT TO MODIFY HIS REPORT:");
		scanf("%s", roll);
		fflush(stdin);
		while (fread(&s, sizeof(s), 1, fptr) == 1)
		{
			if (strcmp(s.roll, roll) == 0)
			{
				system("cls");
				goto_x_y(0, 0);
				printf("New Full Name of the student:");
				goto_x_y(0, 3);
				printf("Enter New marks: \n");
				printf("Mathematics\tPhysics\t\tChemistry\t\tEnglish\t\tNepali");
				goto_x_y(0, 1);
				scanf("%[^\n]", s.name);
				goto_x_y(3, 5);
				scanf("%f", &s.m1);
				goto_x_y(17, 5);
				scanf("%f", &s.m2);
				goto_x_y(34, 5);
				scanf("%f", &s.m3);
				goto_x_y(56, 5);
				scanf("%f", &s.m4);
				goto_x_y(73, 5);
				scanf("%f", &s.m5);
				s.total = s.m1 + s.m2 + s.m3 + s.m4 + s.m5;
				s.percentage = s.total / 5.0;
				if (s.percentage >= 75)
					strcpy(s.result, "Distinction");
				if (s.percentage < 75 && s.percentage >= 60)
					strcpy(s.result, "First Division");
				if (s.percentage < 60 && s.percentage >= 50)
					strcpy(s.result, "second Division");
				if (s.percentage < 50 && s.percentage >= 40)
					strcpy(s.result, "Third Division");
				if (s.percentage < 32)
					strcpy(s.result, "Fail...Better Luck Next time.");
				if (s.m1 < 32 || s.m2 < 32 || s.m3 < 32 || s.m4 < 32 || s.m5 < 32)
					strcpy(s.result, "Fail");
				fseek(fptr, -size, SEEK_CUR);
				fwrite(&s, sizeof(s), 1, fptr);
				fclose(fptr);
				printf("The data has been succesfully updated...\nPress any key to exit..");
				a = 0;
			} // end of if
		}	  // end of while
		if (a == 1)
			printf("The data does not exist");
	}
}
void deleterecords()
{
	system("cls");
	FILE *fptr;
	FILE *temp;
	char roll[20];
	int a = 1;
	int i;
	char chkwrd;
	i = password_check();
	if (i == 0)
	{
		printf("\n\n\n\n\n\n\t\tTHE PASSWORD YOU ENTERED IS INCORRECT....TRY AGAIN FOR IT OR IF YOU WANT TO GO TO MAIN MENU PRESS ESC KEY");
		chkwrd = getch();
		if (chkwrd == 27)
			main();
		deleterecords();
	}
	if ((fptr = fopen("data.dat", "rb")) == NULL)
		exit(0);
	if ((temp = fopen("TEMP.dat", "wb")) == NULL)
		exit(0);
	system("cls");
	printf("\n     **********************************************************");
	printf("\n     *********************DELETE RECORDS****************************");
	printf("\n       *******************************************************\n");
	printf("Enter the corresponding roll.no to delete his/her data: \n");
	scanf("%s", roll);
	while (fread(&s, sizeof(s), 1, fptr) == 1)
	{
		if (strcmp(s.roll, roll) == 0)
		{
			printf("Data Deleted Sucessfully!!!");
			a = 0;
			continue;
		}
		else
			fwrite(&s, sizeof(s), 1, temp);
	}
	if (a == 1)
		printf("\n Data Not Found!!!");
	fclose(fptr);
	fclose(temp);
	remove("data.dat");
	rename("TEMP.dat", "data.dat");
}
int password_check()
{
	system("cls");
	char pass[25];
	char default_pass[25] = "password";
	int i = 0;
	printf("\n\t\t\tENTER YOUR PASSWORD TO LOGIN: ");
	pass[i] = getch();
	while (pass[i] != '\r')
	{
		if (pass[i] == '\b')
		{
			printf("\b \b");
			i--;
		}
		else
		{
			printf("*");
			i++;
		}
		pass[i] = getch();
	}
	pass[i] = '\0';
	i = 0;
	if (strcmp(pass, default_pass) == 0)
		return 1;
	else
		return 0;
}
void aboutus()
{
	system("cls");
	int i;
	printf("\n\n\n\n\n");
	for (i = 0; i <= 100; i++)
		printf("*");
	printf("\n\t\tThis mini project was designed by Student of 2020/BCE\n");
	printf("\t\tSandesh Sapkota(BE2020ce61)\n");
	printf("\t\t\n");
	printf("\t\t");
	printf("\t\t\n");
	for (i = 0; i <= 100; i++)
		printf("*");
	goto_x_y(45, 19);
	printf("press any key to continue....");

	getch();
}
