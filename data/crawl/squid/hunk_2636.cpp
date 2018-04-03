         fatal("COSS requires max-size to be set to something other than -1!\n");
 }
 
+void
+CossSwapDir::swappedOut(const StoreEntry &e)
+{
+    updateSize(e.swap_file_sz, 1);
+}
+
 void
 CossSwapDir::dump(StoreEntry &entry)const
 {
