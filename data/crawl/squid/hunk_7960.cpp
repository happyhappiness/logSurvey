-/* $Id: debug.cc,v 1.4 1996/03/27 05:12:38 wessels Exp $ */
+/* $Id: debug.cc,v 1.5 1996/03/27 18:15:42 wessels Exp $ */
 
 #include "squid.h"
 
-extern int getLogfileRotateNumber _PARAMS((void));
-
-static char *_db_modules = 0;	/* colon separated list of modules to debug. */
-int _db_level = 0;
 char *_db_file = __FILE__;
 int _db_line = 0;
 
-extern char *mkrfc850();
-extern int unbuffered_logs;	/* main.c */
-
 int syslog_enable = 0;
 int stderr_enable = 0;
 FILE *debug_log = NULL;
 static char *debug_log_file = NULL;
 static time_t last_cached_curtime = 0;
 static char the_time[81];
 
+#define MAX_DEBUG_SECTIONS 50
+static int debugLevels[MAX_DEBUG_SECTIONS];
+
 #if defined(__STRICT_ANSI__)
-void _db_print(int level,...)
+void _db_print(int section,...)
 {
-    char *format;
     va_list args;
 #else
 void _db_print(va_alist)
      va_dcl
 {
-    char *format;
-    int level;
     va_list args;
+    int section;
 #endif
+    int level;
+    char *format = NULL;
     static char f[BUFSIZ];
     static char tmpbuf[BUFSIZ];
-    char *module = NULL;
     char *s = NULL;
 
     if (debug_log == NULL)
 	return;
 
 #if defined(__STRICT_ANSI__)
-    /* strict ANSI compliance requires the second arg to va_start - we don't */
-    va_start(args, level);
-    format = va_arg(args, char *);
+    va_start(args, section);
 #else
     va_start(args);
+    section = va_arg(args, int);
+#endif
     level = va_arg(args, int);
     format = va_arg(args, char *);
-#endif
 
-    /* Obtain module name from filename. */
-    if ((module = strrchr(_db_file, '/')) != NULL)
-	module++;
-    else
-	module = _db_file;
-
-    if (_db_level >= level) {
-	if (!_db_modules || strstr(_db_modules, module)) {
-	    /* don't compute the curtime too much */
-	    if (last_cached_curtime != cached_curtime) {
-		last_cached_curtime = cached_curtime;
-		the_time[0] = '\0';
-		s = mkhttpdlogtime(&cached_curtime);
-		strcpy(the_time, s);
-	    }
-	    sprintf(f, "[%s] %s:%d:\t %s", the_time, module, _db_line, format);
+    if (debugLevels[section] > level) {
+	va_end(args);
+	return;
+    }
+    /* don't compute the curtime too much */
+    if (last_cached_curtime != cached_curtime) {
+	last_cached_curtime = cached_curtime;
+	the_time[0] = '\0';
+	s = mkhttpdlogtime(&cached_curtime);
+	strcpy(the_time, s);
+    }
+    sprintf(f, "[%s] %s:%d:\t %s",
+	the_time,
+	_db_file,
+	_db_line,
+	format);
 
 #if HAVE_SYSLOG
-	    /* level 0 go to syslog */
-	    if ((level == 0) && syslog_enable) {
-		tmpbuf[0] = '\0';
-		vsprintf(tmpbuf, f, args);
-		syslog(LOG_ERR, tmpbuf);
-	    }
+    /* level 0 go to syslog */
+    if ((level == 0) && syslog_enable) {
+	tmpbuf[0] = '\0';
+	vsprintf(tmpbuf, f, args);
+	syslog(LOG_ERR, tmpbuf);
+    }
 #endif /* HAVE_SYSLOG */
-	    /* write to log file */
-	    vfprintf(debug_log, f, args);
-	    if (unbuffered_logs)
-		fflush(debug_log);
-
-	    /* if requested, dump it to stderr also */
-	    if (stderr_enable) {
-		vfprintf(stderr, f, args);
-		fflush(stderr);
-	    }
-	}
+    /* write to log file */
+    vfprintf(debug_log, f, args);
+    if (unbuffered_logs)
+	fflush(debug_log);
+
+    /* if requested, dump it to stderr also */
+    if (stderr_enable) {
+	vfprintf(stderr, f, args);
+	fflush(stderr);
     }
     va_end(args);
 }
 
-void _db_init(prefix, initial_level, logfile)
+static void debugArg(arg)
+	char *arg;
+{
+	int s = 0;
+	int l = 0;
+	int i;
+
+	if (!strncasecmp(arg, "ALL", 3)) {
+		s = -1;
+		arg += 4;
+	} else {
+		s = atoi(arg);
+		while (*arg && *arg++ != ',');
+	}
+	l = atoi (arg);
+
+	if (s >= 0) {
+		debugLevels[s] = l;
+		return;
+	}
+	for (i = 0; i < MAX_DEBUG_SECTIONS; i++)
+        	debugLevels[i] = l;
+}
+
+void _db_init(prefix, logfile)
      char *prefix;
-     int initial_level;
      char *logfile;
 {
-    char *db_level_str, db_buf[MAXPATHLEN];
+    int i;
+    char *p = NULL;
+    char *s = NULL;
 
-    sprintf(db_buf, "%s_debug_level", prefix);
-    if ((db_level_str = getenv(db_buf)) != NULL)
-	_db_level = atoi(db_level_str);
-    else
-	_db_level = initial_level;
+    for (i = 0; i < MAX_DEBUG_SECTIONS; i++)
+	debugLevels[i] = -1;
 
-    _db_modules = getenv("DHT_DEBUG_MODULES");
+    if ((p = getDebugOptions())) {
+	p = xstrdup(p);
+	for (s=strtok(p, w_space); s; s=strtok(NULL, w_space)) {
+	    debugArg(s);
+	}
+	xfree(p);
+    }
 
     /* open error logging file */
     if (logfile != NULL) {
