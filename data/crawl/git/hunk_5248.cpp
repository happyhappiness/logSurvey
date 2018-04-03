 		else if (s->nowarn)
 			; /* nothing */
 		else if (s->workdir_dirty)
-			printf("no changes added to commit (use \"git add\" and/or \"git commit -a\")\n");
+			printf("no changes added to commit%s\n",
+				advice_status_hints
+				? " (use \"git add\" and/or \"git commit -a\")" : "");
 		else if (s->untracked.nr)
-			printf("nothing added to commit but untracked files present (use \"git add\" to track)\n");
+			printf("nothing added to commit but untracked files present%s\n",
+				advice_status_hints
+				? " (use \"git add\" to track)" : "");
 		else if (s->is_initial)
-			printf("nothing to commit (create/copy files and use \"git add\" to track)\n");
+			printf("nothing to commit%s\n", advice_status_hints
+				? " (create/copy files and use \"git add\" to track)" : "");
 		else if (!s->show_untracked_files)
-			printf("nothing to commit (use -u to show untracked files)\n");
+			printf("nothing to commit%s\n", advice_status_hints
+				? " (use -u to show untracked files)" : "");
 		else
-			printf("nothing to commit (working directory clean)\n");
+			printf("nothing to commit%s\n", advice_status_hints
+				? " (working directory clean)" : "");
 	}
 }
 