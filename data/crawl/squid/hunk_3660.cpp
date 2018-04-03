 #if HAVE_WINSOCK2_H
 #include <winsock2.h>
 #endif
-main() {
+int main(int argc, char **argv) {
 	FILE *fp = fopen("conftestval", "w");
 	fprintf (fp, "%d\n", FD_SETSIZE);
-	exit(0);
+	return 0;
 }
-],
-DEFAULT_FD_SETSIZE=`cat conftestval`,
-DEFAULT_FD_SETSIZE=256,
-DEFAULT_FD_SETSIZE=256)
+]])],[DEFAULT_FD_SETSIZE=`cat conftestval`],[DEFAULT_FD_SETSIZE=256],[DEFAULT_FD_SETSIZE=256])
 AC_MSG_RESULT($DEFAULT_FD_SETSIZE)
 AC_DEFINE_UNQUOTED(DEFAULT_FD_SETSIZE, $DEFAULT_FD_SETSIZE, [Default FD_SETSIZE value])
 
