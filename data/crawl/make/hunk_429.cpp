     return 1;
   }
 
-  open ("SAVEDOS" . $default_output_stack_level . "out", ">&STDOUT")
-        || &error ("ado: $! duping STDOUT\n", 1);
-  open ("SAVEDOS" . $default_output_stack_level . "err", ">&STDERR")
-        || &error ("ado: $! duping STDERR\n", 1);
+  my $dup = undef;
+  open($dup, '>&', STDOUT) or error("ado: $! duping STDOUT\n", 1);
+  push @OUTSTACK, $dup;
 
-  open (STDOUT, "> " . $filename)
-        || &error ("ado: $filename: $!\n", 1);
-  open (STDERR, ">&STDOUT")
-        || &error ("ado: $filename: $!\n", 1);
+  open($dup, '>&', STDERR) or error("ado: $! duping STDERR\n", 1);
+  push @ERRSTACK, $dup;
 
-  $default_output_stack_level++;
+  open(STDOUT, '>', $filename) or error("ado: $filename: $!\n", 1);
+  open(STDERR, ">&STDOUT") or error("ado: $filename: $!\n", 1);
 }
 
 # close the current stdout/stderr, and restore the previous ones from
