 	fclose(fp);
 
 	if (finish_command(&cp) && !ignore_cp_exit_code)
-		die("'git status --porcelain' failed in submodule %s", path);
+		die("'git status --porcelain=2' failed in submodule %s", path);
 
 	strbuf_release(&buf);
 	return dirty_submodule;