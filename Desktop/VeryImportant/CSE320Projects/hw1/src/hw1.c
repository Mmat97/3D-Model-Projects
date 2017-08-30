#include "hw1.h"
#include "info.h"



// For your helper functions (you may add additional files also)
// DO NOT define a main function here!



char shifting(int length, int n, char orgLetter,char** argv) {
	if(orgLetter>='a' && orgLetter<='z'){//97-122
		orgLetter=orgLetter-32;
	}
	char temp=0;
	const char *arrC2 = *(argv+2);
	if(*(arrC2+1) == 'e'){
	for(int i=0;i<length;i++){
		//n+indexmod(arraylength)
		//Note: not changing Alphabet array
			temp=*(Alphabet+((n+i)%length));
		if(*(Alphabet+i)==orgLetter){
			return temp;
		}
		else
			temp= orgLetter;
		}
	}





		if(*(arrC2+1) == 'd'){
				for(int i=0;i<length;i++){
					if(i<n && n!=0){
						temp=*(Alphabet+(length)-n+i);
						if(*(Alphabet+i)==orgLetter){

							return temp;
						}

					}else if(i>=n || n==0){
						temp=*(Alphabet+((i-n)%length));
						if(*(Alphabet+i)==orgLetter){
							return temp;
						}
					}

					else
						temp= orgLetter;
					}
		}
		return temp;
}

int getN(const char *nArg){
	//variables used to add digits of n together
	char l2=0;
	int x=0;
	int y=0;
	l2=*(nArg+y);
	while(l2 != '\0'){
		x=x*10;
		x=x+l2-48;
		y=y+1;
		l2=*(nArg+y);
	}
	return x;
}

void encryption(FILE *in, FILE *out,char** argv, int argc){
	const char *inf = *(argv+3);
	const char *outf = *(argv+4);
   	in = fopen(inf, "r");//r for read
	out = fopen(outf, "w");//w to write in outfile
	//special value
	if(*(inf+0) == '-'){
		in = stdin;
	}
	if(*(outf+0) == '-'){
		out = stdout;
	}
	const char *arrC = *(argv+1);//same as argv[1]
    const char *arrC2 = *(argv+2);
    if(*(arrC+0) == '-'
        && *(arrC+1) == 's'
        && *(arrC2+0)=='-'
        &&*(arrC2+1) == 'e'
       ) {
	int alength=0;
	int m=0;
	const char *nAr = *(argv+5);//parse the chars
	m=getN(nAr);
	alength=getAlphabetLength();
	char fromIn=0;//from infile
	char outLetter=0;//letter for outfile
//Encryption
	int k=0;
	while(fromIn!=EOF){
		fromIn=fgetc(in);
		if(fromIn>='a' && fromIn<='z'){
				fromIn=fromIn-32;
			}
		k++;
		outLetter=fromIn;

//for each letter in infile, search entire alphabet array
		for(int q=0;q<alength;q++){
			if(fromIn==*(Alphabet+q)){
				outLetter=shifting(alength, m, fromIn, argv);
			}
		}

		if(fromIn==EOF){
			printf("\n");
			#ifdef INFO
				info1(' ');
				info3(m);
				if(*(inf+0) == '-'){
				info4("STDIN");
				}else{
				info4(inf);
				}

				if(*(outf+0) == '-'){
				info5("STDOUT");
				}else{
				info5(outf);
				}
				info6("encryption");
			#endif
			break;
		}
		fputc(outLetter,out);



	}
}
else

	return;
}





void decryption(FILE *in1, FILE *out1,char** argv, int argc){
	const char *inf = *(argv+3);
	const char *outf = *(argv+4);
	in1 = fopen(inf, "r");//r for read
	out1 = fopen(outf, "w");//w to write in outfile
	//special value
	if(*(inf+0) == '-'){
		in1 = stdin;
	}
		if(*(outf+0) == '-'){
		out1 = stdout;
	}
		const char *arrC = *(argv+1);//same as argv[1]
    const char *arrC2 = *(argv+2);
    if(*(arrC+0) == '-'
        && *(arrC+1) == 's'
        && *(arrC2+0)=='-'
        &&*(arrC2+1) == 'd'
       ){
       	int alength1=0;
		int m1=0;
		const char *nAr = *(argv+5);//parse the chars
		m1=getN(nAr);
		alength1=getAlphabetLength();
		char fromIn1=0;//from infile
		char outLetter1=0;//letter for outfile
		//Decryption
		int k1=0;
	while(fromIn1!=EOF){
		fromIn1=fgetc(in1);
		if(fromIn1>='a' && fromIn1<='z'){
				fromIn1=fromIn1-32;
			}
		k1++;
		outLetter1=fromIn1;

//for each letter in infile, search entire alphabet array
		for(int q=0;q<alength1;q++){
			if(fromIn1==*(Alphabet+q)){
				outLetter1=shifting(alength1, m1, fromIn1, argv);
			}
		}

		if(fromIn1==EOF){
			printf("\n");
			#ifdef INFO
			info1(' ');
			info3(m1);
			if(*(inf+0) == '-'){
				info4("STDIN");
			}else{
			info4(inf);
			}

			if(*(outf+0) == '-'){
				info5("STDOUT");
			}else{
				info5(outf);
			}
			info6("decryption");
			#endif
			break;
		}
		fputc(outLetter1,out1);

	}
}
else

	return;
}

void tutneseE(FILE *in2, FILE *out2,char** argv, int argc){
const char *inf = *(argv+3);
	const char *outf = *(argv+4);
	in2 = fopen(inf, "r");//r for read
	out2 = fopen(outf, "w");//w to write in outfile
	//special value
	if(*(inf+0) == '-'){
		in2 = stdin;
	}
		if(*(outf+0) == '-'){
		out2 = stdout;
	}
	const char *arrC = *(argv+1);//same as argv[1]
    const char *arrC2 = *(argv+2);
    if(*(arrC+0) == '-'
        && *(arrC+1) == 't'
        && *(arrC2+0)=='-'
        &&*(arrC2+1) == 'e'
       ){

			int tutLength=0;
			char letterIn=0;//from infile
			tutLength=getTutneseLength();
			while(letterIn!=EOF){
				letterIn=fgetc(in2);
				//b/////////*(*Tutnese+1)
				//////(((((*(Tutnese+b)  ))))(string)
				int z=0;
				for(int index=0;index<tutLength;index++){
					if(letterIn==**(&*(Tutnese+index)+0)){
						fputs(*(Tutnese+index),out2);
						z++;
					}
					else if(letterIn==' '){
						fputs(" ",out2);
					}else if(index==tutLength-1 && z<1){
						fputc(letterIn,out2);
					}
				}




				if(letterIn==EOF){
					break;

				}
			}
    }else{
    	return;
    }

}










int getAlphabetLength(){
//Find Alphabet length
	char a=0;
	int alphab=0;
	int b=0;
	a=*(Alphabet+b);
	while(a != '\0') {
		a=*(Alphabet+b);
		b=b+1;
	}
	alphab=b-1;
	return alphab;
}

int getTutneseLength(){
	int b = 0;
	int tut=0;
	while (*(Tutnese+b) != NULL) {
    b++;
	}
	tut=b-1;
	return tut;
}


/////DINFO MACRO
///////////////////////////////////////fread substitute on fgetc
//info mapper
//reference section pg 18/21
//just that











char validargs(int argc, char** argv, FILE** in, FILE** out) {

//FILE **(pointer-pointer-file)

//initialize return byte
	char ret = 0;
//variables used for changing the return byte bits
	char mask1 = 0x80;
	char mask2 = 0x40;
	char mask3 = 0xBF;
	char mask4 = 0x20;
	char mask5 = 0xDF;
//arrC points to second string and arrC2...
	const char *arrC = *(argv+1);//same as argv[1]
	const char *arrC2 = *(argv+2);
	const char *infile = *(argv+3);
	const char *outfile = *(argv+4);
	if (*(arrC+0) == '-'&& *(arrC+1) == 'h'){
		ret = ret | mask1;
		USAGE(EXIT_SUCCESS);
	}
	*in = fopen(infile, "r");
	*out = fopen(outfile, "w");
	if(*(infile+0) == '-'){
		*in = stdin;
	}
	if(*(outfile+0) == '-'){
		*out = stdout;
	}



	const char *nArg = *(argv+5);//parse the chars
	int n=0;
//variables used to measure Alphabet array length
	int alphabetLength=0;
	int result=0;
	result=result+0;















//check only for valid combinations
	if(*(arrC+0) != '-'
		||(*(arrC+1) != 's' && *(arrC+1) != 't' && *(arrC+1) != 'h')
	  || *(arrC2+0)!='-'
	  ||(*(arrC2+1) != 'e' && *(arrC2+1) != 'd')
	|| infile==NULL
	|| outfile==NULL
	|| argc>6
	||*in==NULL) {
		ret=0;
		return ret;

	}
	else{
//checking dashes and flags(they are characters in each array in argv)


//Find n
//defualt 320 for last 5 bits
	 if(*(arrC+1) == 't'){
		alphabetLength=getAlphabetLength();
		result=320%alphabetLength;
//change last 5 bits to match the result
//add result to ret ;
		ret=ret+result;
	}else if(nArg!=NULL && *(arrC+1) != 't'){
		n=getN(nArg);
		alphabetLength=getAlphabetLength();
		result=n%alphabetLength;

//change last 5 bits to match the result
//add result to ret ;
		ret=ret+result;


	}













	if (*(arrC+0) == '-' && *(arrC+1) == 's'){
		ret = ret | mask2;


	}
	if (*(arrC+0) == '-'&& *(arrC+1) == 't'){
		ret = ret & mask3;

	}



	if (*(arrC2+0) == '-'&& *(arrC2+1) == 'd'){
		ret = ret | mask4;
		return ret;


	}
	if (*(arrC2+0) == '-'&& *(arrC2+1) == 'e'){
		ret = ret & mask5;
		return ret;
	}






}
















//code to be gotten in main()
	return ret;

}
















