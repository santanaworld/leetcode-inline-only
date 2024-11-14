#include <iostream>

void print_int(int a, int b) {
	a = a / 4;
	b = b / 4;
	printf("[%d, %d] ", a, b);

}


int main()
{
	
	const char* message = "Hey there";

	

	int nums[] = { 2,7,11,15 };
	int numsSize = 16; // multiply size x 4
	int target = 9;
	int sum = 0;
	
	
	__asm {
		xor eax, eax	// init registers 
		xor ebx, ebx
		xor ecx, ecx
		xor edx, edx


		check :

			movzx eax, dword ptr[nums + ebx]   // outer array;  eax = first iterator, uses ebx as counter
			movzx edx, dword ptr[nums + ecx]	// inner array; edx = second iterator, uses ecx as counter

			add edx, eax	// sum of the two numbers

			cmp edx, target // check if it is equal to target number
			je found // if yes, then jump and print, else continue loop

			iter :
				add ecx, 4 // inc ecx
				cmp ecx, numsSize // check if ecx is equal to current length
				jne check // if not -> new iteration

				xor ecx, ecx // else, clean ecx 
				add ebx, 4 // and new outer iteration
				jmp check // new outer loop

		found :

			//movzx edx, dword ptr[nums + ecx] // edx gets messed up because of addition above, rewrite into register

			cmp ecx, ebx // make sure they are not the same element
			je iter // if it is the case, return to iteration

			push ecx
			push ebx // push positions to print
			call print_int
			pop ecx
			pop ebx


	}
	

	return 0;
}



