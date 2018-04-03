        (void) fflush(p);

        if (pclose(p) == 0)
            SEND_OK("");
        else
            SEND_ERR("");
    }				/* while (1) */
    return 0;
}
