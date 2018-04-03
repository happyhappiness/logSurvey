        dbuf[x] = '\0';
        x++;
        fputs(dbuf, stdout);
	*(dbuf) = '\0';
    } else {
        /* FAIL */
        debug("local_printfx() FAILURE: %zd\n", x);
    }

