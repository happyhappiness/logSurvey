 
     gettimeofday(&now, NULL);
     if (now.tv_sec != last_t) {
-        tm = localtime(&now.tv_sec);
+        tm = localtime((time_t *)&now.tv_sec);
         strftime(buf, 127, "%Y/%m/%d %H:%M:%S", tm);
         last_t = now.tv_sec;
     }
     return buf;
 }
 
-// AYJ: this looks like a duplicate of the lib/gethostname function */
 char *gethost_name(void) {
-  char      hostname[MAXHOSTNAMELEN];
+  char      hostname[sysconf(_SC_HOST_NAME_MAX)];
   struct addrinfo *hres=NULL, *hres_list;
   int rc,count;
 
-  rc = gethostname(hostname,MAXHOSTNAMELEN);
+  rc = gethostname(hostname,sysconf(_SC_HOST_NAME_MAX));
   if (rc)
     {
       fprintf(stderr, "%s| %s: error while resolving hostname '%s'\n", LogTime(), PROGRAM, hostname);
