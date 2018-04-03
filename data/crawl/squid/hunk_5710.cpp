 usage()
 {
     fprintf(stderr,
-	"%s usage:\n%s [-b] [-f] domain\\controller [domain\\controller ...]\n-b, if specified, enables load-balancing among controllers\n-f, if specified, enables failover among controllers (DEPRECATED and always active)\n-l, if specified, changes behavior on domain controller failyures to\tlast-ditch\n\nYou MUST specify at least one Domain Controller.\nYou can use either \\ or / as separator between the domain name \n\tand the controller name\n",
+	"%s usage:\n%s [-b] [-f] [-d] domain\\controller [domain\\controller ...]\n-b, if specified, enables load-balancing among controllers\n-f, if specified, enables failover among controllers (DEPRECATED and always active)\n-l, if specified, changes behavior on domain controller failyures to\tlast-ditch.-d enables debugging statements if DEBUG was defined at build-time.\n\nYou MUST specify at least one Domain Controller.\nYou can use either \\ or / as separator between the domain name \n\tand the controller name\n",
 	my_program_name, my_program_name);
 }
 
+char debug_enabled=0;
 
 void
 process_options(int argc, char *argv[])
 {
     int opt, j, had_error = 0;
     dc *new_dc = NULL, *last_dc = NULL;
-    while (-1 != (opt = getopt(argc, argv, "bfl"))) {
+    while (-1 != (opt = getopt(argc, argv, "bfld"))) {
 	switch (opt) {
 	case 'b':
 	    load_balance = 1;
