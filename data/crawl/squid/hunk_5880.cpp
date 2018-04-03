  * -f fail-over to another DC if DC connection fails.
  * domain\controller ...
  */
+char *my_program_name = NULL;
+
+void
+usage()
+{
+    fprintf(stderr,
+	"%s usage:\n"
+	"%s [-b] [-f] domain\\controller [domain\\controller ...]\n"
+	"-b, if specified, enables load-balancing among controllers\n"
+	"-f, if specified, enables failover among controllers\n\n"
+	"You MUST specify at least one Domain Controller.\n"
+	"You can use either \\ or / as separator between the domain name \n"
+	"\tand the controller name\n"
+	,my_program_name
+	,my_program_name);
+}
+
+
 void
 process_options(int argc, char *argv[])
 {