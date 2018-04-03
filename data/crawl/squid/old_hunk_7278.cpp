    FD_ENTRY *fde = &fd_table[fd];
    xstrncpy(fde->desc, s, FD_DESC_SZ);
}
