#else
SQUIDCEXTERN void _db_print();
#endif

/* packs, then prints an object using debug() */
SQUIDCEXTERN void debugObj(int section, int level, const char *label, void *obj, ObjPackMethod pm);
