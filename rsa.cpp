#include"stdafx.h"
#include<iostream>
#include<string>
#include<ctime>
#include<string.h>
#include<msclr\marshal.h>
#include<time.h>
#defineDEBUG
//test
usingnamespacemsclr::interop;
usingnamespace System;
usingnamespaceSystem::Numerics;
usingnamespacestd;

BigIntegerextended_euclid(BigIntegera, BigIntegerb, BigInteger  *x, BigInteger *y, BigInteger  *d)
//матричныйалгоритм
/* calculates a * *x + b * *y = gcd(a, b) = *d */

{

	BigInteger q, r, x1, x2, y1, y2;
	BigIntegerbufff;

	if (true == b.IsZero)
	{

		*d=a, *x= 1, *y= 0;

		return 0;

	}

	x2 = 1, x1 = 0, y2 = 0, y1 = 1;

	while (false == b.IsZero)
	{

		q =a/b, bufff= q *b, r =BigInteger::Subtract(a, bufff);
		bufff= q * x1, *x=BigInteger::Subtract(x2, bufff), bufff= q * y1, *y=BigInteger::Subtract(y2, bufff);

		a=b, b= r;
		x2 = x1, x1 = *x, y2 = y1, y1 = *y;

	}

	*d=a, *x= x2, *y= y2;
	return y2;
}

stringSystemToStl(String ^s)
{
	usingnamespaceRuntime::InteropServices;
	constchar* ptr = (constchar*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	Marshal::FreeHGlobal(IntPtr((void*)ptr));
	returnstring(ptr);
}

voidblock(strings, BigIntegerM, BigIntegerD, BigIntegerE)
{
	string symbol = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЬЫЪЭЮЯ";
	stringformat[33] = { "01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31","32","33" };
	stringshifr;
	stringstr; // буферцифровойзаписи
				// -- перевод сообщения в числовой вид---
	for (int j = 0; j <s.length(); j++) // циклстроки
		for (int g = 0; g <symbol.length(); g++)
		{
			if (s[j] == symbol[g])
			{
				str+= format[g];
				break;
			}
		}
	cout<<"Закодированноесообщение:";
	cout<<str<<endl;
	// -- шифрование сообщения --
	String^ str3 = gcnewString(str.c_str());
	BigInteger t = BigInteger::Parse(str3);
	BigInteger Z = BigInteger::ModPow(t, E, M);
	str3 = Z.ToString();
	string chars = SystemToStl(str3);
	shifr= chars;
	cout<<"Защифрованноесообщение: "<<shifr<<endl;
	// -- дешифрование --
	str.clear();
	str=shifr;
	str3 = gcnewString(str.c_str());
	BigInteger T = BigInteger::Parse(str3);
	//Console::WriteLine(T);
	BigInteger TEXT = BigInteger::ModPow(T, D, M);
	str3 = TEXT.ToString();
	chars =SystemToStl(str3);
	str.clear();
	cout<<"Исходное слово в цифрах:";
	Console::WriteLine(TEXT);

	stringbuf;
	string result;
	if (chars.length() != 16)
	{
		str+="0";
		str+= chars;
	}
	else
	{
		str= chars;
	}
	for (int j = 0; j <str.length();)
	{
		string block = str.substr(j, 2);
		for (int g = 0; g < 33; g++)
		{
			if (block == format[g])
			{
				buf+= symbol[g];
				break;
			}
		}
		j += 2;
		result +=buf;
		buf.clear();
	}
	cout<<"Расшифрованноесообщение: ";
	cout<< result <<endl;
}
unsignedlonglonggcd(unsignedlonglonga, unsignedlonglongb)
{	//алгоритм Евклида нахождения НОД
	if (b == 0) returna;
	returngcd(b, a % b);
}
voidmain()
{
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	srand(time(NULL));
	setlocale(LC_CTYPE, "rus"); // вызов функции настройки локали
	longlong p, q;
	cout<<"Введитепростое p:";
	cin>> p;
	cout<<"Введите простое число q:";
	cin>> q;
	cout<<"Введите исходный текст: ";
	string s;
	cin>> s;
	longlong m = p*q;
	cout<<"Модуль шифрования(m):"<< m <<endl;
	unsignedlonglong f = (p - 1)*(q - 1);
	cout<<"(p-1)*(q-1) (f):"<< f <<endl;
	srand((unsigned)time(0));
	longlong e;
	do e = rand() %9000 + 1000;
	while (e>f || gcd(f, e) != 1);
	cout<<"e:"<<e<<endl;
	BigInteger x, y, d;
	BigInteger ha = extended_euclid(f, e, &x, &y, &d);
	BigInteger D = BigInteger::Add(ha, f);
	cout<<"D:";
	Console::WriteLine(D);
	BigInteger F = (BigInteger)f;
	BigInteger M = (BigInteger)m;
	BigInteger E = (BigInteger)e;
	block(s, M, D, E);
	system("pause");
}
