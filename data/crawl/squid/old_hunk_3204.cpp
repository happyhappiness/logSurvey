        (void) fflush(p);

        if (pclose(p) == 0)
            (void) printf("OK\n");
        else
            (void) printf("ERR\n");

    }				/* while (1) */
    return 0;
}
