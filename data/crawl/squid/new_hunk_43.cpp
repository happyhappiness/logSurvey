    if (!ldapServer)
        ldapServer = (char *) "localhost";

    if (!userbasedn || !passattr || (!*delimiter && !*frealm)) {
        fprintf(stderr, "Usage: " PROGRAM_NAME " -b basedn -F filter [options] ldap_server_name\n\n");
        fprintf(stderr, "\t-A password attribute(REQUIRED)\t\tUser attribute that contains the password\n");
        fprintf(stderr, "\t-l password realm delimiter(REQUIRED)\tCharacter(s) that divides the password attribute\n\t\t\t\t\t\tin realm and password tokens, default ':' realm:password, could be\n\t\t\t\t\t\tempty string if the password is alone in the password attribute\n");
        fprintf(stderr, "\t-r filtered realm\t\t\tonly honor Squid requests for this realm. Mandatory if the password is alone in\n\t\t\t\t\t\tthe password attribute, acting as the implicit realm\n");
        fprintf(stderr, "\t-b basedn (REQUIRED)\t\t\tbase dn under where to search for users\n");
        fprintf(stderr, "\t-e Encrypted passwords(REQUIRED)\tPassword are stored encrypted using HHA1\n");
        fprintf(stderr, "\t-F filter\t\t\t\tuser search filter pattern. %%s = login\n");
