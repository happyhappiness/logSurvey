 		else
 		  ++f;
 #ifdef WINDOWS32
-            printf ("# %s (key %s, mtime %d): ",
+            printf (_("# %s (key %s, mtime %d): "),
                     dir->name, dir->contents->path_key, dir->contents->mtime);
 #else  /* WINDOWS32 */
 #ifdef VMS
-	    printf ("# %s (device %d, inode [%d,%d,%d]): ",
+	    printf (_("# %s (device %d, inode [%d,%d,%d]): "),
 		    dir->name, dir->contents->dev,
 			dir->contents->ino[0], dir->contents->ino[1],
 			dir->contents->ino[2]);
 #else
-	    printf ("# %s (device %ld, inode %ld): ",
+	    printf (_("# %s (device %ld, inode %ld): "),
 		    dir->name,
                     (long)dir->contents->dev, (long)dir->contents->ino);
 #endif
 #endif /* WINDOWS32 */
 	    if (f == 0)
-	      fputs ("No", stdout);
+	      fputs (_("No"), stdout);
 	    else
 	      printf ("%u", f);
-	    fputs (" files, ", stdout);
+	    fputs (_(" files, "), stdout);
 	    if (im == 0)
-	      fputs ("no", stdout);
+	      fputs (_("no"), stdout);
 	    else
 	      printf ("%u", im);
-	    fputs (" impossibilities", stdout);
+	    fputs (_(" impossibilities"), stdout);
 	    if (dir->contents->dirstream == 0)
 	      puts (".");
 	    else
-	      puts (" so far.");
+	      puts (_(" so far."));
 	    files += f;
 	    impossible += im;
 	  }
