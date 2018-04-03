     FILE *f;
 
     if (!(f = fopen(filename, "r"))) {
-        fprintf(stderr, PROGRAM_NAME " ERROR: Can not read secret file %s\n", filename);
+        fprintf(stderr, PROGRAM_NAME ": ERROR: Can not read secret file %s\n", filename);
         return 1;
     }
     if (!fgets(buf, sizeof(buf) - 1, f)) {
-        fprintf(stderr, PROGRAM_NAME " ERROR: Secret file %s is empty\n", filename);
+        fprintf(stderr, PROGRAM_NAME ": ERROR: Secret file %s is empty\n", filename);
         fclose(f);
         return 1;
     }
