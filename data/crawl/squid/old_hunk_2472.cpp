
    struct stat swap_sb;
    if (::stat(path, &swap_sb) < 0) {
        debugs (47, 1, "Creating Rock db directory: " << path);
#ifdef _SQUID_MSWIN_
        const int res = mkdir(path);
#else
        const int res = mkdir(path, 0700);
#endif
        if (res != 0) {
            debugs(47,0, "Failed to create Rock db dir " << path <<
                ": " << xstrerror());
            fatal("Rock Store db creation error");
		}
