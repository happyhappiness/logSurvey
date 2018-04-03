        snprintf(to, MAXPATHLEN, "%s.%d", path, i);
#if _SQUID_OS2_ || _SQUID_WINDOWS_
        if (remove(to) < 0) {
            int xerrno = errno;
            fprintf(stderr, "WARNING: remove '%s' failure: %s\n", to, xstrerr(xerrno));
        }
#endif
        if (rename(from, to) < 0 && errno != ENOENT) {
            int xerrno = errno;
            fprintf(stderr, "WARNING: rename '%s' to '%s' failure: %s\n", from, to, xstrerr(xerrno));
        }
    }
    if (rotate_count > 0) {
        snprintf(to, MAXPATHLEN, "%s.%d", path, 0);
#if _SQUID_OS2_ || _SQUID_WINDOWS_
        if (remove(to) < 0) {
            int xerrno = errno;
            fprintf(stderr, "WARNING: remove '%s' failure: %s\n", to, xstrerr(xerrno));
        }
#endif
        if (rename(path, to) < 0 && errno != ENOENT) {
            int xerrno = errno;
            fprintf(stderr, "WARNING: rename %s to %s failure: %s\n", path, to, xstrerr(xerrno));
        }
    }
}
