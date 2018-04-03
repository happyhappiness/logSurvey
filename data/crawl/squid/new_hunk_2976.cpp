        fputs(dbuf, stderr);
        memset(dbuf, '\0', strlen(dbuf));
    } else {
        snprintf(bbuf, sz, "%s: local_debugx(%s) FAILURE: %zd\n", prog, dbuf, x);
        fputs(bbuf, stderr);
    }
}
*/

/* local_printfx() -
 *
