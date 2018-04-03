{
    int i;
    storeAppendPrintf(dumpEntry, "Active file descriptors:\n");
    storeAppendPrintf(dumpEntry, "%-4s %-6s %-4s %-7s* %-7s* %-21s %s\n",
                      "File",
                      "Type",
                      "Tout",
                      "Nread",
                      "Nwrite",
                      "Remote Address",
                      "Description");
    storeAppendPrintf(dumpEntry, "---- ------ ---- -------- -------- --------------------- ------------------------------\n");

    for (i = 0; i < Squid_MaxFD; i++) {
        fd_table[i].dumpStats(*dumpEntry, i);