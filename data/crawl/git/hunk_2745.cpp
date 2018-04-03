 	xdemitconf_t xecfg;
 	xdemitcb_t ecb;
 	mmfile_t minus, plus;
+	int ret;
 
 	if (read_mmfile(&minus, file1) || read_mmfile(&plus, file2))
-		return 1;
+		return -1;
 
 	printf("--- a/%s\n+++ b/%s\n", label1, label2);
 	fflush(stdout);
