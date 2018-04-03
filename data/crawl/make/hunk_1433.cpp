 		  dir->contents->ino[0], dir->contents->ino[1],
 		  dir->contents->ino[2]);
 #else
-	  printf ("# %s (device %d, inode %d): could not be opened.\n",
-		  dir->name, dir->contents->dev, dir->contents->ino);
+	  printf ("# %s (device %ld, inode %ld): could not be opened.\n",
+		  dir->name, (long int) dir->contents->dev,
+		  (long int) dir->contents->ino);
 #endif
 #endif /* WIN32 */
 	else
