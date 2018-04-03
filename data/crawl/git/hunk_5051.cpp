 	} else {
 		if (!no_commit)
 			res = run_git_commit(defmsg);
-		if (!res)
-			fprintf(stderr, "Finished %s.\n", mebuf.buf);
 	}
 
 	strbuf_release(&mebuf);
