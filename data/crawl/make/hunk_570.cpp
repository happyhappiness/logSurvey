 		short int	status, count;
 		int	dvi;
 	} iosb;
+	unsigned short int loc_chan;
 
 	setupYAstTried++;
 
-	if (!chan) {
-		status= sys$assign(&inputDsc,&chan,0,0);
+	if (chan)
+          loc_chan= chan;
+	else {
+		status= sys$assign(&inputDsc,&loc_chan,0,0);
 		if (!(status&SS$_NORMAL)) {
 			lib$signal(status);
 			return;
 		}
 	}
-	status= sys$qiow (0, chan, IO$_SETMODE|IO$M_CTRLYAST,&iosb,0,0,
-		astHandler,0,0,0,0,0);
-	if (status==SS$_NORMAL)
-		status= iosb.status;
-        if (status==SS$_ILLIOFUNC || status==SS$_NOPRIV) {
-		sys$dassgn(chan);
-#ifdef	CTRLY_ENABLED_ANYWAY
-		fprintf (stderr,
-                         _("-warning, CTRL-Y will leave sub-process(es) around.\n"));
-#else
-		return;
-#endif
-	}
-	else if (!(status&SS$_NORMAL)) {
-		sys$dassgn(chan);
-		lib$signal(status);
+	status= sys$qiow (0, loc_chan, IO$_SETMODE|IO$M_CTRLYAST,&iosb,0,0,
+                          astYHandler,0,0,0,0,0);
+        if (status==SS$_NORMAL)
+          	status= iosb.status;
+	if (status!=SS$_NORMAL) {
+		if (!chan)
+			sys$dassgn(loc_chan);
+		if (status!=SS$_ILLIOFUNC && status!=SS$_NOPRIV)
+			lib$signal(status);
 		return;
 	}
 
