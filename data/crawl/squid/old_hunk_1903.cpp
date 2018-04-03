        snprintf(from, MAXPATHLEN, "%s.%d", path, i - 1);
        snprintf(to, MAXPATHLEN, "%s.%d", path, i);
#if _SQUID_OS2_ || _SQUID_WINDOWS_
        remove(to);
#endif
        rename(from, to);
    }
    if (rotate_count > 0) {
        snprintf(to, MAXPATHLEN, "%s.%d", path, 0);
#if _SQUID_OS2_ || _SQUID_WINDOWS_
        remove(to);
#endif
        rename(path, to);
    }
}

