extern void _db_print();
#endif


extern int file_open(const char *path, int mode, FOCB *, void *callback_data, void *tag);
extern void file_close(int fd);
