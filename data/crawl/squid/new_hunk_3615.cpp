
SQUIDCEXTERN void _db_print(const char *,...) PRINTF_FORMAT_ARG1;

/* packs, then prints an object using debugs() */
SQUIDCEXTERN void debugObj(int section, int level, const char *label, void *obj, ObjPackMethod pm);

/* disk.c */
