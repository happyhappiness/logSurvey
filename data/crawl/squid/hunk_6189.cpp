 #include <arpa/inet.h>
 main ()
 {
+	FILE *fp;
 	struct in_addr in;
 	in.s_addr = inet_addr("1.2.3.4");
-        fprintf (fopen("conftestval", "w"), "%s\n", inet_ntoa(in));
+	fp = fopen("conftestval", "w"); 
+	fprintf (fp, "%s\n", inet_ntoa(in));
 	exit(0);
 }
 
 EOF
-if { (eval echo configure:4583: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest && (./conftest; exit) 2>/dev/null
+if { (eval echo configure:4596: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest && (./conftest; exit) 2>/dev/null
 then
   INET_NTOA_RESULT=`cat conftestval`
 else
