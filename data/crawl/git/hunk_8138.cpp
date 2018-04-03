 	fputc('\n', rpt);
 
 	fputs("fatal: ", rpt);
-	vfprintf(rpt, err, params);
+	fputs(err, rpt);
 	fputc('\n', rpt);
 
 	fputc('\n', rpt);
