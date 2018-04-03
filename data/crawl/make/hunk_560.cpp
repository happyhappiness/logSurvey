 {
   puts (_("\n# Variables\n"));
 
-  print_variable_set (&global_variable_set, "");
+  print_variable_set (&global_variable_set, "", 0);
 
   puts (_("\n# Pattern-specific Variable Values"));
 
