extern void _db_print();
#endif

/* packs, then prints an object using debug() */
extern void debugObj(int section, int level, const char *label, void *obj, ObjPackMethod pm);


extern int file_open(const char *path, int mode, FOCB *, void *callback_data, void *tag);
extern void file_close(int fd);
