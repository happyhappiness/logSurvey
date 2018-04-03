{
    kq = kqueue();
    if (kq < 0) {
	fatal("comm_select_init: Couldn't open kqueue fd!\n");
    }
    kqmax = getdtablesize();
    kqlst = xmalloc(sizeof(*kqlst) * kqmax);
