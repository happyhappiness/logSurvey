 #endif
 
 /* Local functions */
-static int client_comm_connect();
-static void usage();
+static int client_comm_connect(int sock, char *dest_host, u_short dest_port);
+static void usage(char *progname);
 
-static void usage(progname)
-     char *progname;
+static void
+usage(char *progname)
 {
     fprintf(stderr, "\
 Usage: %s [-rs] [-i IMS_time] [-h host] [-p port] [-m method] url\n\
