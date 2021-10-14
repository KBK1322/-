#include <iostream>
#include<time.h>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "¬ведите размерность массива:";
	cin >> n;
	int* mas = new int[n];
	unsigned rand_value = 11;
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		mas[i] = rand() % 10 - 5;
		cout << mas[i] << " ";

	}
	short three = 0;
	short five = 0;
	_asm {
		lea si, [mas]
		mov cx, len

		mov bl, 3
		mov dl, 0
		@@for:
		lodsb
			cbw
			idiv bl
			cmp ah, 0
			jz @@next
			inc dl
			@@next:
		loop @@for
			mov[three], dl

			lea si, [mas]
			mov cx, len
			mov bl, 5
			mov dl, 0
			@@for:
		lodsb
			cbw
			idiv bl
			cmp ah, 0
			jz @@next
			inc dl
			@@next:
		loop @@for
			mov[five], dl
	}
	cout << "three=" << three;
	cout << "five=" << five;
	delete[] mas;
}