 		return;
 
 	fputs(tag, stdout);
-	write_name_quoted("", 0, ent->name + offset, line_terminator, stdout);
-	putchar(line_terminator);
+	write_name_quoted(ent->name + offset, stdout, line_terminator);
 }
 
 static void show_other_files(struct dir_struct *dir)
