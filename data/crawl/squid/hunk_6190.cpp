 #include <sys/types.h>
 #endif
 main() {
-	fprintf (fopen("conftestval", "w"), "%d\n", FD_SETSIZE);
+	FILE *fp = fopen("conftestval", "w");
+	fprintf (fp, "%d\n", FD_SETSIZE);
 	exit(0);
 }
 ],
