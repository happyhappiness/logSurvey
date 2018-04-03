 	storeAppendPrintf(sentry, "FS Block Size %d Bytes\n",
 	    SD->fs.blksize);
 	SD->statfs(SD, sentry);
+	if (SD->repl) {
+	    storeAppendPrintf(sentry, "Removal policy: %s\n", SD->repl->_type);
+	    if (SD->repl->Stats)
+		SD->repl->Stats(SD->repl, sentry);
+	}
     }
 }
 
