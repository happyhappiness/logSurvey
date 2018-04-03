#if HAVE_PRCTL && defined(PR_SET_KEEPCAPS) && HAVE_SYS_CAPABILITY_H

    if (prctl(PR_SET_KEEPCAPS, 1, 0, 0, 0)) {
        IPInterceptor.StopTransparency("capability setting has failed.");
    }
#endif
}
