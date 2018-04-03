    if (!ldapServer)
        ldapServer = (char *) "localhost";

    if (!userbasedn || !passattr) {
        fprintf(stderr, "Usage: " PROGRAM_NAME " -b basedn -f filter [options] ldap_server_name\n\n");
        fprintf(stderr, "\t-A password attribute(REQUIRED)\t\tUser attribute that contains the password\n");
        fprintf(stderr, "\t-l password realm delimiter(REQUIRED)\tCharater(s) that devides the password attribute\n\t\t\t\t\t\tin realm and password tokens, default ':' realm:password\n");
        fprintf(stderr, "\t-b basedn (REQUIRED)\t\t\tbase dn under where to search for users\n");
        fprintf(stderr, "\t-e Encrypted passwords(REQUIRED)\tPassword are stored encrypted using HHA1\n");
        fprintf(stderr, "\t-F filter\t\t\t\tuser search filter pattern. %%s = login\n");
