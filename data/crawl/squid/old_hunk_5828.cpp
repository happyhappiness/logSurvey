	debug(3, 1) ("cache_dir '%s' new Q2 value '%d'\n", diskdinfo->magic2);
}

struct cache_dir_option options[] =
{
#if NOT_YET
    {"L1", storeDiskdDirParseL1},
    {"L2", storeDiskdDirParseL2},
#endif
    {"Q1", storeDiskdDirParseQ1},
    {"Q2", storeDiskdDirParseQ2},
    {NULL, NULL}
};

