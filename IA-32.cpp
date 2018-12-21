#include <iostream>

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Error! Missing parameter!" << std::endl;
		return 1;
	}

	char* string = argv[1];
	int result = 0;

	_asm
	{
		mov eax, 0 // assigns eax = 0
		mov ebx, 10 // assigns ebx = 10
		mov ecx, string // assigns ecx = string
		for_loop: // loop name
			mul ebx // eax = eax * ebx
			mov dl, byte ptr[ecx] // assigns dl = byte ptr[ecx]
			cmp dl, 0 // if dl = 0
			jz exit_loop // jump out of loop if zero
			sub dl, '0' // edx = dl - '0'
			add eax, edx // eax = eax + edx
			inc ecx // ecx++
		jmp for_loop // jump back to loop
		exit_loop: // exit loop
		div ebx // eax = eax / ebx
		mov result, eax // assigns result = eax
	}

	std::cout << result << std::endl;
}
