                      name, "digest", noncemaxuses,
                      name, "digest", (int) noncemaxduration,
                      name, "digest", (int) nonceGCInterval);
    storeAppendPrintf(entry, "%s digest utf8 %s\n", name, utf8 ? "on" : "off");
    return true;
}

