            fprintf(stderr, "WARNING: remove '%s' failure: %s\n", to, xstrerror());
        }
#endif
        if (rename(from, to) < 0 && errno != ENOENT) {
            fprintf(stderr, "WARNING: rename '%s' to '%s' failure: %s\n", from, to, xstrerror());
        }
    }
    if (rotate_count > 0) {