     }
 
     if (!ldapServer)
-	ldapServer = "localhost";
+	ldapServer = (char *)"localhost";
 
     if (!userbasedn || !passattr) {
 	fprintf(stderr, "Usage: " PROGRAM_NAME " -b basedn -f filter [options] ldap_server_name\n\n");
