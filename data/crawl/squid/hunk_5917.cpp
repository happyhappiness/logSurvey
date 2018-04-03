 }
 
 static void
-xmemFree(memitem *item)
+xmemFree(memitem * item)
 {
     extern MemPool *StringPool;
     assert(item && item->pool);
     if (StringPool == item->pool)
-        return memStringFree(item->pool, item->my_ptr, item->size);
+	return memStringFree(item->pool, item->my_ptr, item->size);
     else
-        return memFree(item->pool, item->my_ptr);
+	return memFree(item->pool, item->my_ptr);
 }
 
-void my_free(char *file, int line, void *ptr)
+void 
+my_free(char *file, int line, void *ptr)
 {
 #if 0
-fprintf(stderr,"{%s:%d:%p",file,line,ptr);
+    fprintf(stderr, "{%s:%d:%p", file, line, ptr);
 #endif
-free(ptr);
-#if 0 
-fprintf(stderr,"}\n");
+    free(ptr);
+#if 0
+    fprintf(stderr, "}\n");
 #endif
 }
