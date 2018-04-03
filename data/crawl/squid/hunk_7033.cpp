 {
     LOCAL_ARRAY(char, logmsg, MAX_URL << 1);
     int dirn;
-    if (e->swap_file_number < 0)
-	fatal_dump("storeDirSwapLog: swap_file_number < 0");
+    assert(e->swap_file_number >= 0);
     dirn = e->swap_file_number >> SWAP_DIR_SHIFT;
     assert(dirn < Config.cacheSwap.n_configured);
     assert(!BIT_TEST(e->flag, KEY_PRIVATE));