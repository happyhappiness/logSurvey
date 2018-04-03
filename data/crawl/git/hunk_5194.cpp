 		return;
 
 	fputs(tag, stdout);
-	write_name_quoted(ent->name + offset, stdout, line_terminator);
+	write_name(ent->name, ent->len);
 }
 
 static void show_other_files(struct dir_struct *dir)
