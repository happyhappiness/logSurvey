 	fatalf("Unknown cache_dir type '%s'\n", type_str);
     }
     allocate_new_swapdir(swap);
-    sd = swap->swapDirs + swap->n_configured;
-    sd->type = storefs_list[fs].typestr;
-    /* defaults in case fs implementation fails to set these */
-    sd->max_objsize = -1;
-    sd->fs.blksize = 1024;
+    swap->swapDirs[swap->n_configured] = SwapDir::Factory(storefs_list[fs]);
+    sd = swap->swapDirs[swap->n_configured];
     /* parse the FS parameters and options */
-    storefs_list[fs].parsefunc(sd, swap->n_configured, path_str);
-    swap->n_configured++;
+    sd->parse(swap->n_configured, path_str);
+    ++swap->n_configured;
     /* Update the max object size */
     update_maxobjsize();
 }
