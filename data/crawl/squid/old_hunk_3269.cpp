    /* initial setup */
    hash = hash_create((HASHCMP *) strcmp, 7921, hash_string);
    if (NULL == hash) {
        fprintf(stderr, "ncsa_auth: cannot create hash table\n");
        exit(1);
    }
    f = fopen(passwdfile, "r");
    if (NULL == f) {
        fprintf(stderr, "%s: %s\n", passwdfile, xstrerror());
        exit(1);
    }
    while (fgets(buf, 8192, f) != NULL) {
