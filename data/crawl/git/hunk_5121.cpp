 					i++;
 			}
 		}
-		write_message(msgbuf, defmsg);
-		fprintf(stderr, "Automatic %s failed.%s\n",
-			me, help_msg());
-		rerere(allow_rerere_auto);
-		exit(1);
 	}
-	write_message(msgbuf, defmsg);
-	fprintf(stderr, "Finished one %s.\n", me);
+
+	return !clean;
 }
 
 static int do_pick_commit(void)
