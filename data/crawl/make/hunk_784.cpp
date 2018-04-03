 	}
 	status= sys$qiow (0, chan, IO$_SETMODE|IO$M_CTRLYAST,&iosb,0,0,
 		astHandler,0,0,0,0,0);
-	if (status==SS$_ILLIOFUNC) {
+	if (status==SS$_NORMAL)
+		status= iosb.status;
+        if (status==SS$_ILLIOFUNC || status==SS$_NOPRIV) {
 		sys$dassgn(chan);
 #ifdef	CTRLY_ENABLED_ANYWAY
 		fprintf (stderr,
