                         sslpath);
                 exit(1);
             } else {
-                sslinit++;
+                ++sslinit;
             }
             if ((ld = ldapssl_init(ldapServer, port, 1)) == NULL) {
                 fprintf(stderr, "\nUnable to connect to SSL LDAP server: %s port:%d\n",
