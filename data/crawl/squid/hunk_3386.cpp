     /* initial setup */
     hash = hash_create((HASHCMP *) strcmp, 7921, hash_string);
     if (NULL == hash) {
-        fprintf(stderr, "digest_pw_auth: cannot create hash table\n");
+        fprintf(stderr, "digest_file_auth: cannot create hash table\n");
         exit(1);
     }
     f = fopen(passwordFile, "r");
