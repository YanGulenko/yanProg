#include <iostream>
#include <stdio.h>
#include <math.h>
#include <fstream>
#include <string.h>
#include <windows.h>
using namespace std;
int Lenght(const char s[])
{
	int L = 0;
	while (s[L++]);
	return (L - 1);
}
int main()
{
	setlocale(0, "");
	char abc[] = "abcdefghijklmnopqrstuvwxyz";
	char key[] = "key";
	char word[] = "programm";
	int key_num[10] = { 0 };
	int word_num[10] = { 0 };
	int word_num_new[10] = { 0 };
	int k = 0;
	int w = 0;
	system("cls");
	//translate the word and key in the numeric equivalent
	while (k <= Lenght(key))
	{
		for (int i = 0; i<26; i++)
		{
			//putting letters in the numeric code to key_num
			if (key[k] == abc[i])
			{
				key_num[k] = i;
			}
		}

		k++;
	}
	while (w <= Lenght(word))
	{
		for (int i = 0; i<25; i++)
		{
			//putting letters in the numeric code to word_num
			if (word[w] == abc[i])
			{
				word_num[w] = i;
			}
		}

		w++;
	}

	w = 0;
	k = 0;
	while (w<Lenght(word))
	{
		//declared in word_num_new the sum of the numbers from word and key
		word_num_new[w] = key_num[k] + word_num[w];
		//implement the cycles to encrypt
		if (word_num_new[w]>26)
		{
			word_num_new[w] -= 26;
		}

		w++;
		k++;
		if (k >= Lenght(key))
		{
			k = 0;
		}

	}
	//conclusion the data obtained with the translation of numbers into letters again
	cout << "\nThe encryption method of the Vigenere";
	cout << "\nThe original word: " << word;
	cout << "\nUsed key: " << key;
	cout << "\nThe result of encryption: ";
	w = 0;
	while (w<Lenght(word))
	{
		cout << abc[word_num_new[w]];
		w++;
	}
	//dushiruum the word
	w = 0;
	k = 0;
	int t, m;
	while (w<Lenght(word))
	{
		t = word_num_new[w];
		m = key_num[k];
		t -= m;
		//subtract codes key codes from an encrypted message, modulo 26
		if (t<0)
		{
			word_num_new[w] += 26 - key_num[k];
		}
		else
		{
			word_num_new[w] -= key_num[k];
		}

		w++;
		k++;
		if (k >= Lenght(key))
		{
			k = 0;
		}
	}
	cout << "\nDecryption :";
	//the output encrypted message
	w = 0;
	while (w<Lenght(word))
	{
		cout << abc[word_num_new[w]];
		w++;
	}
	cout << "\n\n";
	system("pause");
	return 0;
}