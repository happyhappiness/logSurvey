    xfree(list);
#else

    storeAppendPrintf(sentry,"NETDB support not compiled into this Squid cache.\n");
#endif
}

