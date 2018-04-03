 void
 usage()
 {
-    fprintf(stderr,
-            "%s usage:\n%s [-A|D UserGroup][-O DefaultDomain][-d]\n"
+    fprintf(stderr, "Usage:\n%s [-A|D UserGroup][-O DefaultDomain][-d]\n"
             "-A can specify a Windows Local Group name allowed to authenticate\n"
             "-D can specify a Windows Local Group name not allowed to authenticate\n"
             "-O can specify the default Domain against to authenticate\n"
             "-d enable debugging.\n"
             "-h this message\n\n",
-            my_program_name, my_program_name);
+            my_program_name);
 }
 
 void
 process_options(int argc, char *argv[])
 {
-    int opt, had_error = 0;
+    int opt;
     while (-1 != (opt = getopt(argc, argv, "dhA:D:O:"))) {
         switch (opt) {
         case 'A':
