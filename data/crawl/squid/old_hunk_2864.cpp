        dbuf[x] = '\0';
        x++;
        fputs(dbuf, stdout);
        memset(dbuf, '\0', sizeof(dbuf));
    } else {
        /* FAIL */
        /*
                snprintf(bbuf, sz, "%s: local_printfx(%s) FAILURE: %zd\n", prog, dbuf, x);
                fputs(bbuf, stderr);
        */
        debug("local_printfx() FAILURE: %zd\n", x);
    }

