   for (p = file_id_list; p; p = p->next)
     if (p->ino == st.st_ino && p->dev == st.st_dev)
       {
-	FATAL_ERROR ((0, 0, _("%s: file list already read"),
-		      quotearg_colon (filename)));
+	ERROR ((0, 0, _("%s: file list already read"),
+		quotearg_colon (filename)));
+	return 1;
       }
   p = xmalloc (sizeof *p);
   p->next = file_id_list;
   p->ino = st.st_ino;
   p->dev = st.st_dev;
   file_id_list = p;
+  return 0;
 }
 
 enum read_file_list_state  /* Result of reading file name from the list file */
