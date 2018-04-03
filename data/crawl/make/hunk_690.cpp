 $makefile = "GNUmakefile";
 
 open(MAKEFILE,"> $makefile");
-
 print MAKEFILE "FIRST: ; \@echo It chose GNUmakefile\n";
-
 close(MAKEFILE);
 
 # DOS/WIN32 platforms preserve case, but Makefile is the same file as makefile.
 # Just test what we can here (avoid Makefile versus makefile test).
-#
-if ($port_type eq 'UNIX')
-{
+
+if ($port_type eq 'UNIX') {
   # Create another makefile called "makefile"
   open(MAKEFILE,"> makefile");
-
   print MAKEFILE "SECOND: ; \@echo It chose makefile\n";
-
   close(MAKEFILE);
 }
 
-
 # Create another makefile called "Makefile"
 open(MAKEFILE,"> Makefile");
-
 print MAKEFILE "THIRD: ; \@echo It chose Makefile\n";
-
 close(MAKEFILE);
 
 
 &run_make_with_options("","",&get_logfile);
-
-# Create the answer to what should be produced by this Makefile
-$answer = "It chose GNUmakefile\n";
-
-# COMPARE RESULTS
-
-&compare_output($answer,&get_logfile(1)) || &error("abort");
+&compare_output("It chose GNUmakefile\n",&get_logfile(1));
 unlink $makefile;
 
-# DOS/WIN32 platforms preserve case, but Makefile is the same file as makefile.
-# Just test what we can here (avoid Makefile versus makefile test).
-#
-if ($port_type eq 'UNIX')
-{
-  $answer = "It chose makefile\n";
-
+if ($port_type eq 'UNIX') {
   &run_make_with_options("","",&get_logfile);
-
-  &compare_output($answer,&get_logfile(1)) || &error("abort");
+  &compare_output("It chose makefile\n",&get_logfile(1));
   unlink "makefile";
 }
 
-$answer = "It chose Makefile\n";
-
 &run_make_with_options("","",&get_logfile);
-
-&compare_output($answer,&get_logfile(1)) || &error("abort");
+&compare_output("It chose Makefile\n",&get_logfile(1));
 unlink "Makefile";
