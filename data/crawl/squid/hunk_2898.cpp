 
 #define HELPER_INPUT_BUFFER	8196
 
-#define safe_free(x)    if (x) { free(x); x = NULL; }
-
 /* send OK result to Squid with a string parameter. */
 #define SEND_OK(x)	fprintf(stdout, "OK %s\n",x)
 
