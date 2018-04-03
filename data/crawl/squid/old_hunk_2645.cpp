    close(pkin[0]);
    close(pkout[1]);

    pipe(pnin);
    pipe(pnout);

    if  (( fpid = vfork()) < 0 ) {
        fprintf(stderr, "%s| %s: Failed second fork\n", LogTime(), PROGRAM);