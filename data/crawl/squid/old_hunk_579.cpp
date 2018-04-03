    close(pnin[0]);
    close(pnout[1]);

    FDKIN=fdopen(pkin[1],"w");
    FDKOUT=fdopen(pkout[0],"r");

    FDNIN=fdopen(pnin[1],"w");
    FDNOUT=fdopen(pnout[0],"r");

    if (!FDKIN || !FDKOUT || !FDNIN || !FDNOUT) {
        fprintf(stderr, "%s| %s: Could not assign streams for FDKIN/FDKOUT/FDNIN/FDNOUT\n", LogTime(), PROGRAM);
        return 1;
    }

