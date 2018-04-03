     return xcalloc(1, mp->obj_size);
 }
 
-void *
-memPoolGetObj(MemPool *mp)
-{
-    void *obj = memPoolGetObj2(mp);
-    /*printf("memPoolGetObj: %p :  %d -> %d , %d >= %d\n", obj, mp->static_stack->count, mp->dynamic_stack->count, mp->alloc_count, mp->free_count);*/
-    return obj;
-}
-
 /*
  * return object to the pool; put on the corresponding stack or free if
  * corresponding stack is full
