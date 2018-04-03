       to the right helper. squid must keep session state
    */

    pipe(pkin);
    pipe(pkout);

    if  (( fpid = vfork()) < 0 ) {
        fprintf(stderr, "%s| %s: Failed first fork\n", LogTime(), PROGRAM);
