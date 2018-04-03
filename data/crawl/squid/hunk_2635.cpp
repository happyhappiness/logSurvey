     return Ipc::Mem::PageSize();
 }
 
-void
-MemStore::updateSize(int64_t eSize, int sign)
-{
-    // XXX: irrelevant, but Store parent forces us to implement this
-    fatal("MemStore::updateSize should not be called");
-}
-
 void
 MemStore::reference(StoreEntry &)
 {
