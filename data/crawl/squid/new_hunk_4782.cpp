
extern void clientAccessCheck(void *);

/* see debug.c for info on context-based debugging */
SQUIDCEXTERN Ctx ctx_enter(const char *descr);
SQUIDCEXTERN void ctx_exit(Ctx ctx);
