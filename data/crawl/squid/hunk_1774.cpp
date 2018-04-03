     fprintf(stderr, "           to authenticate all users\n");
     fprintf(stderr, " -o        Do not perform account mgmt (account expiration etc)\n");
     fprintf(stderr, " -1        Only one user authentication per PAM connection\n");
+    fprintf(stderr, " -r        Detect and remove Negotiate/NTLM realm from username\n");
 }
 
 int
