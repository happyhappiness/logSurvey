 #else
 extern void _db_print();
 #endif
+extern void xassert(const char *, const char *, int);
 
 /* packs, then prints an object using debug() */
 extern void debugObj(int section, int level, const char *label, void *obj, ObjPackMethod pm);
