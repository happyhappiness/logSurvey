        logfilePrintf(logfile, " [%s] [%s]\n", ereq, erep);
        safe_free(ereq);
        safe_free(erep);
    } else {
        logfilePrintf(logfile, "\n");
    }

}

#if ICAP_CLIENT
