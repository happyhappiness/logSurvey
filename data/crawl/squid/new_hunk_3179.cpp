
    if ((p = getpwnam(username)) == NULL) {
        /* Returns an error if user does not exist in the /etc/passwd */
        fprintf(stderr, "ERROR: User does not exist '%s'\n", username);
        return 0;
    } else {
        /* Verify if the this is the primary user group */
