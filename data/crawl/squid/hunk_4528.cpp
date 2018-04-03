  */
 char *my_program_name = NULL;
 
-void
-usage()
+static void
+usage(void)
 {
     fprintf(stderr,
 	"Usage: %s [-d] [-v] [-h]\n"
