 		  ++im;
 		else
 		  ++f;
+#ifdef VMS
+	    printf ("# %s (device %d, inode [%d,%d,%d]): ",
+		    dir->name, dir->contents->dev,
+			dir->contents->ino[0], dir->contents->ino[1],
+			dir->contents->ino[2]);
+#else
 	    printf ("# %s (device %d, inode %d): ",
 		    dir->name, dir->contents->dev, dir->contents->ino);
+#endif
 	    if (f == 0)
 	      fputs ("No", stdout);
 	    else
