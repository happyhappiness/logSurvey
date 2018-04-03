         max_size = size;
     }
 
-    parseOptions(1);
     /* Enforce maxobjsize being set to something */
-
     if (max_objsize == -1)
         fatal("COSS requires max-size to be set to something other than -1!\n");
 }
