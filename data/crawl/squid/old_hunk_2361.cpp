    }

    /* giving up if failed */
    if (!loaded())
        fatal("failed to find or read error text file.");

    return true;
}
