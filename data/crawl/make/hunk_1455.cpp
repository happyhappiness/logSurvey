 	if (dir->contents == 0)
 	  printf ("# %s: could not be stat'd.\n", dir->name);
 	else if (dir->contents->files == 0)
+#ifdef VMS
+	  printf ("# %s (device %d, inode [%d,%d,%d]): could not be opened.\n",
+		  dir->name, dir->contents->dev,
+		  dir->contents->ino[0], dir->contents->ino[1],
+		  dir->contents->ino[2]);
+#else
 	  printf ("# %s (device %d, inode %d): could not be opened.\n",
 		  dir->name, dir->contents->dev, dir->contents->ino);
+#endif
 	else
 	  {
 	    register unsigned int f = 0, im = 0;
