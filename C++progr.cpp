#include<conio.h>
#include<iostream>
#include<windows.h>

using namespace std;

void gotoxy(int xpos, int ypos)
{
COORD scrn;

HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);

scrn.X = xpos; scrn.Y = ypos;

SetConsoleCursorPosition(hOuput, scrn);
}
struct books
{
char fio[20];
char book[30];
int year;
int tyr;
};
int main()
{
setlocale(0, "");
int q;
void create();
void view();
void dyap();
void sort();
void izd();
system("cls");
do
{
cout << " --------------  MENU  --------------------------\n";
cout << "=================================================\n";
cout << "      1- Enter info" << endl;
cout << "      2- Output info " << endl;
cout << "      3- Output books for the range of years" << endl;
cout << "      4- sorting in order of decreasing edition" << endl;
cout << "      5- Sorting a books of author in increasing order of year of publication" << endl;
cout << "      6- quit" << endl;
cout << "      choose & enter" << endl;
cin >> q;
switch (q)
{
case 1: create(); break;
case 2: view(); break;
case 3: dyap(); break;
case 4: sort(); break;
case 5: izd(); break;
}
} while (q != 6);
return 0;
}
void create()
{
system("cls");
FILE *in;
int n, i = 0;
char name[20];
cout << "enter name FILE: ";
cin >> name;
in = fopen(name, "w");
cout << "\nenter info:\n";
cout << "\nenter number of books: ";
cin >> n;

fprintf(in, "%d\n", n);
books *kn;
kn = new books[n];
system("cls");
cout << "don't enter "space"!, use _\n";
int y = 2, x = 0;
while (i<n + 2)
{
gotoxy(0, y); cout << "----------------------------------------------------------------------";
y = y + 2;
i++;
}
int j = 0;
y = 3;
while (j<2 * (n + 1))
{
gotoxy(3, y); cout << "|";//! 2
y = y + 1;
j++;
}
j = 0; y = 3;
while (j<2 * (n + 1))
{
gotoxy(21, y); cout << "|";
y = y + 1;
j++;
}
j = 0; y = 3;
while (j<2 * (n + 1))
{
gotoxy(50, y); cout << "|";//40!
y = y + 1;
j++;
}
j = 0; y = 3;
while (j<2 * (n + 1))
{
gotoxy(57, y); cout << "|";//49!
y = y + 1;
j++;
}
j = 0; y = 3;
while (j<2 * (n + 1))
{
gotoxy(69, y); cout << "|";//60!
y = y + 1;
j++;
}
i = 0;
x = 0;
y = 3;
int k = 0;
//ввод данных в таблицу

while (i<n)
{

gotoxy(1, 3); cout << "№";
gotoxy(x + 1, y + 2); cout << k +1;
gotoxy(4, 3); cout << "FIO";//!3
gotoxy(22, 3); cout << "Name";
gotoxy(51, 3); cout << "Year";
gotoxy(58, 3); cout << "Edition";
gotoxy(4, y + 2); scanf("%f%*с", &kn[i].fio); gets(kn[i].fio);//!3
gotoxy(22, y + 2); gets(kn[i].book);
gotoxy(51, y + 2); cin >> kn[i].year;
gotoxy(58, y + 2); cin >> kn[i].tyr;

y = y + 2;
fprintf(in, "%s %s %d %d\n", kn[i].fio, kn[i].book, kn[i].year, kn[i].tyr);
i++;
k++;
}

fclose(in);
delete kn;
cout << "\n\nwriting succesfull FILE\n" << endl;
_getche();
system("cls");
}

void view()
{
system("cls");
FILE *in;
char name[20];
int i, n;
cout << "\nenter output file-name FILE: \n";
cin >> name;
system("cls");
in = fopen(name, "r");
fscanf(in, "%d\n", &n);
books *kn;
kn = new books[n];
for (i = 0; i<n; i++)
{
	fscanf(in, "%s %s %d %d\n", &kn[i].fio, &kn[i].book, &kn[i].year, &kn[i].tyr);
}
int x = 0, y = 3;
int j = 0;
y = 3;
j = 0;
y = 3;
while (j<2 * (n + 1))
{
gotoxy(3, y); cout << "|";
y = y + 1;
j++;
}
j = 0; y = 3;
while (j<2 * (n + 1))
{
gotoxy(21, y); cout << "|";
y = y + 1;
j++;
}
j = 0; y = 3;
while (j<2 * (n + 1))
{
	gotoxy(50, y); cout << "|";//40!
	y = y + 1;
	j++;
}
j = 0; y = 3;
while (j<2 * (n + 1))
{
	gotoxy(57, y); cout << "|";//49!
	y = y + 1;
	j++;
}
j = 0; y = 3;
while (j<2 * (n + 1))
{
	gotoxy(69, y); cout << "|";//60!
	y = y + 1;
	j++;
}
i = 0;
x = 0;
y = 3;
int k = 0;
while (i<n)
{

gotoxy(1, 3); cout << "№";
gotoxy(x + 1, y + 2); cout << k + 1;
gotoxy(4, 3); cout << "FIO";
gotoxy(22, 3); cout << "Name";
gotoxy(51, 3); cout << "Year";
gotoxy(58, 3); cout << "Edition";
gotoxy(4, y + 2); cout << kn[i].fio;
gotoxy(22, y + 2); cout << kn[i].book;
gotoxy(51, y + 2); cout << kn[i].year;
gotoxy(58, y + 2); cout << kn[i].tyr;
y = y + 2;
i++;
k++;
}
i = 0; y = 2;
while (i<n + 2)
{
gotoxy(0, y); cout << "----------------------------------------------------------------------";
y = y + 2;
i++;
}
delete kn;
_getche();
fclose(in);
system("cls");
}
void dyap()
{
system("cls");
FILE *in, *out;
char name_in[20], name_out[20];
char book[20];
int i, n;
int k = 0, j;
int y1, y2;
cout << "\nenter input file-name FILE: \n";
cin >> name_in;
cout << "enter output file-name FILE: \n";
cin >> name_out;
system("cls");
in = fopen(name_in, "r");
out = fopen(name_out, "w");
fscanf(in, "%d\n", &n);
books *kn;
kn = new books[n];
for (i = 0; i<n; i++)
{
	fscanf(in, "%s %s %d %d\n", &kn[i].fio, &kn[i].book, &kn[i].year, &kn[i].tyr);
}

cout << "Enter years:\n";
cout << "From: ";
cin >> y1;
cout << "To: ";
cin >> y2;
int m=0;
j = 0;
for (i = 0; i < n; i++)
{

if ((kn[i].year >= y1) && (kn[i].year <= y2))
{
strcpy(kn[j].fio, kn[i].fio);
strcpy(kn[j].book, kn[i].book);
kn[j].year=kn[i].year;
kn[j].tyr=kn[i].tyr;
j++;
m++;
}
}
k = m;
fprintf(out, "%d\n", k);
system("cls");
int x = 0, y = 3;
j = 0;
y = 3;
j = 0;
y = 3;
while (j<2 * (k + 1))
{
gotoxy(3, y); cout << "|";
y = y + 1;
j++;
}
j = 0; y = 3;
while (j<2 * (k + 1))
{
gotoxy(21, y); cout << "|";
y = y + 1;
j++;
}
j = 0; y = 3;
while (j<2 * (k + 1))
{
	gotoxy(50, y); cout << "|";//40!
	y = y + 1;
	j++;
}
j = 0; y = 3;
while (j<2 * (k + 1))
{
	gotoxy(57, y); cout << "|";//49!
	y = y + 1;
	j++;
}
j = 0; y = 3;
while (j<2 * (k + 1))
{
	gotoxy(69, y); cout << "|";//60!
	y = y + 1;
	j++;
}
i = 0;
j = 0;
x = 0;
y = 3;
int q = 0;
while (j<m)
{
gotoxy(1, 3); cout << "№";
gotoxy(x + 1, y + 2); cout << q + 1;
gotoxy(4, 3); cout << "FIO";
gotoxy(22, 3); cout << "Name";
gotoxy(51, 3); cout << "Year";
gotoxy(58, 3); cout << "Edition";
gotoxy(4, y + 2); cout << kn[j].fio;
gotoxy(22, y + 2); cout << kn[j].book;
gotoxy(51, y + 2); cout << kn[j].year;
gotoxy(58, y + 2); cout << kn[j].tyr;
y = y + 2;
fprintf(out, "%s %s %d %d\n", kn[i].fio, kn[i].book, kn[i].year, kn[i].tyr);
q++;
j++;
}
i = 0; y = 2;
while (i<k + 2)
{
gotoxy(0, y); cout << "----------------------------------------------------------------------";
y = y + 2;
i++;
}
delete kn;
fclose(in);
fclose(out);
cout << "\n\nwriting succesfull FILE\n" << endl;
_getche();
system("cls");
}

void sort()
{
system("cls");
FILE *in, *out;
char name_in[20], name_out[20];
char book[20];
int i, n;
int k = 0, j;
int y1, y2;
cout << "\nEnter input file-name FILE: \n";
cin >> name_in;
cout << "Enter output file-name FILE: \n";
cin >> name_out;
system("cls");
in = fopen(name_in, "r");
out = fopen(name_out, "w");
fscanf(in, "%d\n", &n);
books *kn;
kn = new books[n];
books swap;
for (i = 0; i<n; i++)
{
	fscanf(in, "%s %s %d %d\n", &kn[i].fio, &kn[i].book, &kn[i].year, &kn[i].tyr);
}

int m = 0;
j = 0;
for (i = 0; i < n; i++)
{
for (j = 0; j < n;j++)
{
if (kn[i].tyr>kn[j].tyr)
{
strcpy(swap.fio, kn[i].fio);
strcpy(swap.book, kn[i].book);
swap.year = kn[i].year;
swap.tyr = kn[i].tyr;

strcpy(kn[i].fio, kn[j].fio);
strcpy(kn[i].book, kn[j].book);
kn[i].year = kn[j].year;
kn[i].tyr = kn[j].tyr;

strcpy(kn[j].fio, swap.fio);
strcpy(kn[j].book, swap.book);
kn[j].year = swap.year;
kn[j].tyr = swap.tyr;
}
}
}
k = n;
fprintf(out, "%d\n", k);
system("cls");
int x = 0, y = 3;
j = 0;
y = 3;
j = 0;
y = 3;
while (j<2 * (k + 1))
{
gotoxy(3, y); cout << "|";
y = y + 1;
j++;
}
j = 0; y = 3;
while (j<2 * (k + 1))
{
gotoxy(21, y); cout << "|";
y = y + 1;
j++;
}
j = 0; y = 3;
while (j<2 * (k + 1))
{
	gotoxy(50, y); cout << "|";//40!
	y = y + 1;
	j++;
}
j = 0; y = 3;
while (j<2 * (n + 1))
{
	gotoxy(57, y); cout << "|";//49!
	y = y + 1;
	j++;
}
j = 0; y = 3;
while (j<2 * (n + 1))
{
	gotoxy(69, y); cout << "|";//60!
	y = y + 1;
	j++;
}
i = 0;
j = 0;
x = 0;
y = 3;
int q = 0;
while (i<n)
{
gotoxy(1, 3); cout << "№";
gotoxy(x + 1, y + 2); cout << q + 1;
gotoxy(4, 3); cout << "FIO";
gotoxy(22, 3); cout << "Name";
gotoxy(51, 3); cout << "Year";
gotoxy(58, 3); cout << "Editio";
gotoxy(4, y + 2); cout << kn[i].fio;
gotoxy(22, y + 2); cout << kn[i].book;
gotoxy(51, y + 2); cout << kn[i].year;
gotoxy(58, y + 2); cout << kn[i].tyr;
y = y + 2;
fprintf(out, "%s %s %d %d\n", kn[i].fio, kn[i].book, kn[i].year, kn[i].tyr);
q++;
i++;
}
i = 0; y = 2;
while (i<k + 2)
{
gotoxy(0, y); cout << "----------------------------------------------------------------------";
y = y + 2;
i++;
}
delete kn;
fclose(in);
fclose(out);
cout << "\n\nwriting succesfull FILE\n" << endl;
_getche();
system("cls");
}

void izd()
{
system("cls");
FILE *in, *out;
char name_in[20], name_out[20];
char book[20];
int i, n;
int k = 0, j;
int y1, y2;
cout << "\nEnter input file-name FILE: \n";
cin >> name_in;
cout << "Enter output file-name FILE: \n";
cin >> name_out;
system("cls");
in = fopen(name_in, "r");
out = fopen(name_out, "w");
fscanf(in, "%d\n", &n);
books *kn;
kn = new books[n];
books swap;
for (i = 0; i<n; i++)
{
	fscanf(in, "%s %s %d %d\n", &kn[i].fio, &kn[i].book, &kn[i].year, &kn[i].tyr);
}
char fam[20];
cout << "Enter FIO of author\n";
cout << "don't enter "space", use_\n";
scanf("%f%*с", &fam); gets(fam);
j = 0;
for (i = 0; i < n; i++)
{
	if (strcmp(kn[i].fio, fam) == 0)
	{
		strcpy(kn[j].fio, kn[i].fio);
		strcpy(kn[j].book, kn[i].book);
		kn[j].year = kn[i].year;
		kn[j].tyr = kn[i].tyr;
		j++;
		k++;
	}

}

fprintf(out, "%d\n", k);

for (i = 0; i < k; i++)
{
	for (j = 0; j < k; j++)
	{
		if (kn[i].year < kn[j].year)
		{
			strcpy(swap.fio, kn[i].fio);
			strcpy(swap.book, kn[i].book);
			swap.year = kn[i].year;
			swap.tyr = kn[i].tyr;

			strcpy(kn[i].fio, kn[j].fio);
			strcpy(kn[i].book, kn[j].book);
			kn[i].year = kn[j].year;
			kn[i].tyr = kn[j].tyr;

			strcpy(kn[j].fio, swap.fio);
			strcpy(kn[j].book, swap.book);
			kn[j].year = swap.year;
			kn[j].tyr = swap.tyr;
		}
	}
}
system("cls");
int x = 0, y = 3;
j = 0;
y = 3;
j = 0;
y = 3;
while (j<2 * (k + 1))
{
gotoxy(3, y); cout << "|";
y = y + 1;
j++;
}
j = 0; y = 3;
while (j<2 * (k + 1))
{
gotoxy(21, y); cout << "|";
y = y + 1;
j++;
}
j = 0; y = 3;
while (j<2 * (k + 1))
{
	gotoxy(50, y); cout << "|";//40!
	y = y + 1;
	j++;
}
j = 0; y = 3;
while (j<2 * (k + 1))
{
	gotoxy(57, y); cout << "|";//49!
	y = y + 1;
	j++;
}
j = 0; y = 3;
while (j<2 * (k + 1))
{
	gotoxy(69, y); cout << "|";//60!
	y = y + 1;
	j++;
}
i = 0;
j = 0;
x = 0;
y = 3;
int q = 0;
while (i<k)
{
gotoxy(1, 3); cout << "№";
gotoxy(x + 1, y + 2); cout << q + 1;
gotoxy(4, 3); cout << "FIO";
gotoxy(22, 3); cout << "Name";
gotoxy(51, 3); cout << "Year";
gotoxy(58, 3); cout << "Edition";
gotoxy(4, y + 2); cout << kn[i].fio;
gotoxy(22, y + 2); cout << kn[i].book;
gotoxy(51, y + 2); cout << kn[i].year;
gotoxy(58, y + 2); cout << kn[i].tyr;
y = y + 2;
fprintf(out, "%s %s %d %d\n", kn[i].fio, kn[i].book, kn[i].year, kn[i].tyr);
q++;
i++;
}
i = 0; y = 2;
while (i<k + 2)
{
gotoxy(0, y); cout << "----------------------------------------------------------------------";
y = y + 2;
i++;
}
delete kn;
fclose(in);
fclose(out);
cout << "\n\nwriting succesfull FILE\n" << endl;
_getche();
system("cls");
}