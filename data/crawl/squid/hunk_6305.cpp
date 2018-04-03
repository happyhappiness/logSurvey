 	hid->count--;
 	return;
     }
-    fatal("hash_remove_link: could not find entry");
+    assert(0);
 }
 
 /*