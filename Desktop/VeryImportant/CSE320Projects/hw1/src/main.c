#include "hw1.h"

int main(int argc, char **argv) {

	FILE* in;//pointer to file
    FILE* out;
    char validret=0;

    //Use input and output files
    /* Note: create a variable to assign the result of validargs */
    validret=validargs(argc, argv, &in, &out);//&address of pointer(pointer of a pointer)
//bin/hw1 -s -e rsrc/plain.txt - 3
    encryption(in, out, argv, argc);
    decryption(in, out, argv, argc);
    tutneseE(in, out, argv, argc);


    //If the mode is non-zero, success, else...
	if(validret!=0){
        return EXIT_SUCCESS;
    }
    else{
        return EXIT_FAILURE;
    }
}

