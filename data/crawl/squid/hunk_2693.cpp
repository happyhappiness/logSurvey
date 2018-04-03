             fprintf(stderr, "is followed to the top (e.g. if the group is a member of a group)\n");
             fprintf(stderr, "Group membership is determined with non AD servers through the users memberuid (assuming\n");
             fprintf(stderr, "PosixGroup) or primary group membership (assuming PosixAccount)\n");
+            fprintf(stderr, "The ldap server list can be:\n");
+            fprintf(stderr, "server - In this case server can be used for all Kerberos domains\n");
+            fprintf(stderr, "server@  - In this case server can be used for all Kerberos domains\n");
+            fprintf(stderr, "server@domain  - In this case server can be used for Kerberos domain domain\n");
+            fprintf(stderr, "server1a@domain1:server1b@domain1:server2@domain2:server3@:server4 - A list is build with a colon as seperator\n");
             clean_args(&margs);
             exit(0);
         default:
