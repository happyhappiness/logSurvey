SQUIDCEXTERN void _db_init(const char *logfile, const char *options);
SQUIDCEXTERN void _db_rotate_log(void);

/* packs, then prints an object using debugs() */
SQUIDCEXTERN void debugObj(int section, int level, const char *label, void *obj, ObjPackMethod pm);

