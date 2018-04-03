                   (unsigned long)temp.timestamp, (unsigned long)temp.lastref,
                   (unsigned long)temp.expires, (unsigned long)temp.lastmod, temp.flags, temp.refcount );
     } else {
-        snprintf( timeb, sizeof(timeb), "%08lx %08lx %08lx %08lx %04x %5hu ", (unsigned long)-1, (unsigned long)-1, (unsigned long)-1, (unsigned long)-1, 0, 0 );
+        unsigned long ul = -1;  // Match type of StoreMetaTLV fields
+        unsigned short hu = 0;  // Match type of StoreMetaTLV refcount fields
+        snprintf( timeb, sizeof(timeb), "%08lx %08lx %08lx %08lx %04x %5d ", ul, ul, ul, ul, 0, hu);
     }
 
     // make sure that there is just one printf()
