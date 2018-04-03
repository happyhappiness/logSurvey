 		    path, xstrerror());
 		fatal(tmp_error_buf);
 	    }
-	    debug(20, 1, "storeInit: Created swap directory %s\n", path);
+	    debug(20, 1, "storeVerifySwapDirs: Created swap directory %s\n", path);
 	    directory_created = 1;
 	}
 	if (clean) {
-	    debug(20, 1, "storeInit: Zapping all objects on disk storage.\n");
+	    debug(20, 1, "storeVerifySwapDirs: Zapping all objects on disk storage.\n");
 	    /* This could be dangerous, second copy of cache can destroy
 	     * the existing swap files of the previous cache. We may
 	     * use rc file do it. */
 	    cmdbuf = xcalloc(1, BUFSIZ);
 	    sprintf(cmdbuf, "cd %s; /bin/rm -rf log [0-9][0-9]", path);
-	    debug(20, 1, "storeInit: Running '%s'\n", cmdbuf);
+	    debug(20, 1, "storeVerifySwapDirs: Running '%s'\n", cmdbuf);
 	    system(cmdbuf);	/* XXX should avoid system(3) */
 	    xfree(cmdbuf);
 	}
