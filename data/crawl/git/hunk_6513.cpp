 			 */
 			sprintf(temp->mode, "%06o", one->mode);
 		}
-		return;
+		return temp;
 	}
 	else {
 		if (diff_populate_filespec(one, 0))
 			die("cannot read data blob for %s", one->path);
 		prep_temp_blob(temp, one->data, one->size,
 			       one->sha1, one->mode);
 	}
-}
-
-static void remove_tempfile(void)
-{
-	int i;
-
-	for (i = 0; i < 2; i++)
-		if (diff_temp[i].name == diff_temp[i].tmp_path) {
-			unlink(diff_temp[i].name);
-			diff_temp[i].name = NULL;
-		}
-}
-
-static void remove_tempfile_on_signal(int signo)
-{
-	remove_tempfile();
-	signal(SIGINT, SIG_DFL);
-	raise(signo);
+	return temp;
 }
 
 /* An external diff command takes:
