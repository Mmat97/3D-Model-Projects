#ifndef INFO_H
#define INFO_H
#include <stdlib.h>
#include <stdio.h>
#define info1(msg) printf("INFO: shifted alphabet: %c\n",msg);
#define info2(alphabet) printf("%c",alphabet);
#define info3(shiftint) printf("INFO: shift amount: %d\n",shiftint);
#define info4(inputfilename) printf("INFO: input file:%s\n" ,inputfilename);
#define info5(outputfilename) printf("INFO: output file:%s\n" ,outputfilename);
#define info6(operation) printf("INFO: operation: %s\n" ,operation);


#endif
