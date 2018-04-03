 		  ++im;
 		else
 		  ++f;
+#ifdef WIN32
+            printf ("# %s (key %s, mtime %d): ",
+                    dir->name, dir->contents->path_key, dir->contents->mtime);
+#else  /* WIN32 */
 #ifdef VMS
 	    printf ("# %s (device %d, inode [%d,%d,%d]): ",
 		    dir->name, dir->contents->dev,
