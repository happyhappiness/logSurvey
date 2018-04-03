     }
     FILE *FH = fopen(filename, "r");
     if (!FH) {
-        fprintf(stderr, "%s: FATAL: Unable to open file '%s': %s", program_name, filename, xstrerror());
+        int xerrno = errno;
+        fprintf(stderr, "%s: FATAL: Unable to open file '%s': %s", program_name, filename, xstrerr(xerrno));
         exit(1);
     }
     current_entry = load_dict(FH);
