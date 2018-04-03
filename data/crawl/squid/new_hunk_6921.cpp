#define UINTEGER    (ASN_APPLICATION | 7)
#define DEBUG
#ifdef DEBUG
#define ERROR(string)	fprintf(stderr,"%s(%d): ERROR %s\n",__FILE__, __LINE__, string);
#else
#define ERROR(string)
#endif
