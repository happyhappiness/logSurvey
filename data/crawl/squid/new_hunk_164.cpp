        }
    }
#endif

    if (Config.readAheadGap <= 0) {
        fatalf("read_ahead_gap must be greater than 0 bytes");
    }
}

/** Parse a line containing an obsolete directive.
