        dbuf[x] = '\0';
        x++;
        fputs(dbuf, stdout);
//    debug("printfx", "DATA: %s", dbuf);
        memset(dbuf, '\0', strlen(dbuf));
    } else {
        /* FAIL */
        snprintf(dbuf, sz, "%s: local_printfx(%s) FAILURE: %zd\n", prog, dbuf, x);
        fputs(dbuf, stderr);
    }

    /* stdout needs to be flushed for it to work with Squid */
