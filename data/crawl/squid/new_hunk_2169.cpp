    storeAppendPrintf(dumpEntry, "---- ------ ---- -------- -------- --------------------- ------------------------------\n");
#endif

    for (i = 0; i < Squid_MaxFD; ++i) {
        fd_table[i].dumpStats(*dumpEntry, i);
    }
}
