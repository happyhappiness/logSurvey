 static std::stack<StoreEntry*> LateReleaseStack;
 MemAllocator *StoreEntry::pool = NULL;
 
-StorePointer Store::CurrentRoot = NULL;
-
-void
-Store::Root(Store * aRoot)
-{
-    CurrentRoot = aRoot;
-}
-
-void
-Store::Root(StorePointer aRoot)
-{
-    Root(aRoot.getRaw());
-}
-
 void
 Store::Stats(StoreEntry * output)
 {
     assert(output);
     Root().stat(*output);
 }
 
-void
-Store::create()
-{}
-
-void
-Store::diskFull()
-{}
-
-void
-Store::sync()
-{}
-
-void
-Store::unlink(StoreEntry &)
-{
-    fatal("Store::unlink on invalid Store\n");
-}
-
 void
 StoreEntry::makePublic()
 {
