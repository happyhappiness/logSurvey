    if (atexit(WIN32_Exit) != 0)
        return 1;

    return 0;
}

#endif
