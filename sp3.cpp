#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	srand(time(0));
	long long n;
	long long x = 8;
	long long array[x];
	cout<<"Сгенерированный массив"<<endl;
	for (int i = 0; i < x; i++)
	{
		array[i] = rand() % 9 + 1;
		cout<<array[i]<<" ";
	}
	cout<<endl;
	cout<< "Введите количство позиций смещения"<<endl;
	cin>>n;
	long long *ptr_array = &array[0];
	if (n<=1)
	{
		cout<< "Не верное число"<<endl;
		return -1;
	}
	asm(
		"mov %[n], %%rcx\n\t"
		"mov $1, %%rdx\n\t"
                "mov %[ptr_array], %%rbx\n\t"
		"inc %%rcx\n\t"
		"loop_start:\n\t"
		"mov $8, %%rax\n\t"
		"less:\n\t"
		"push (%%rbx)\n\t"
		"add $8, %%rbx\n\t"
		"push (%%rbx)\n\t"
		"add $-8, %%rbx\n\t"
		"pop (%%rbx)\n\t"
		"add $8, %%rbx\n\t"
		"pop (%%rbx)\n\t"
		"dec %%rax\n\t"
		"cmp %%rax, %%rdx\n\t"
		"jne less\n\t"
		"dec %%rcx\n\t"
		"add $-56, %%rbx\n\t"
		"cmp %%rcx, %%rdx\n\t"
		"jne loop_start\n\t"
		"end_asm:\n\t"
		:
		:[ptr_array]"m"(ptr_array), [n]"m"(n)
		:"%rax", "%rbx", "%rcx", "%rdx"
	);
	cout<<endl<<"--------------------------------"<<endl;
	cout<<"Итоговая матрица"<<endl;
	for (int i = 0; i < x; i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
	return 0;
}
