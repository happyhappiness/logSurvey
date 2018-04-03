         usage(program_name);
         exit(1);
     }
-    FH = fopen(filename, "r");
+    FILE *FH = fopen(filename, "r");
+    if (!FH) {
+        fprintf(stderr, "%s: FATAL: Unable to open file '%s': %s", program_name, filename, xstrerror());
+        exit(1);
+    }
     current_entry = load_dict(FH);
 
     while (fgets(line, HELPER_INPUT_BUFFER, stdin)) {
