  * Print formatted message of func() to stderr if MODE_DEBUG is set.
  *
  */
-void debug(char *func, const char *msg,...) {
-  char prog[MAXLEN], dbuf[MAXLEN], cbuf[MAXLEN];
-  size_t sz, x;
-  va_list ap;
-  if (!(conf.mode & MODE_DEBUG))
-    return;
+void debug(char *func, const char *msg,...)
+{
+    char prog[MAXLEN], dbuf[MAXLEN], cbuf[MAXLEN];
+    size_t sz, x;
+    va_list ap;
+    if (!(conf.mode & MODE_DEBUG))
+        return;
 
-  if (conf.program[0] == '\0')
-    strcpy(prog, DEFAULT_PROGRAM_NAME);
-  else
-    strncpy(prog, conf.program, sizeof(prog));
-  if ((func == NULL) || (msg == NULL) || (strlen(prog) > 256)) {
-    /* FAIL */
-    snprintf(dbuf, sizeof(dbuf), "%s: debug() EPIC FAILURE.\n", prog);
-    fputs(dbuf, stderr);
-    return;
-  }
-  sz = sizeof(dbuf);
-  strncpy(cbuf, prog, sizeof(cbuf));
-  strcat(cbuf, ": [DB] ");
-  strncat(cbuf, func, sizeof(cbuf));
-  strcat(cbuf, "() - ");
-  va_start(ap, msg);
-  x = vsnprintf(dbuf, sz, msg, ap);
-  va_end(ap);
-  if (x > 0) {
-    strncat(cbuf, dbuf, x);
-    fputs(cbuf, stderr);
-    memset(dbuf, '\0', strlen(dbuf));
-  }
-  else {
-    /* FAIL */
-    snprintf(dbuf, sz, "%s: debug(%s) FAILURE: %zd\n", prog, dbuf, x);
-    fputs(dbuf, stderr);
-  }
+    if (conf.program[0] == '\0')
+        strcpy(prog, DEFAULT_PROGRAM_NAME);
+    else
+        strncpy(prog, conf.program, sizeof(prog));
+    if ((func == NULL) || (msg == NULL) || (strlen(prog) > 256)) {
+        /* FAIL */
+        snprintf(dbuf, sizeof(dbuf), "%s: debug() EPIC FAILURE.\n", prog);
+        fputs(dbuf, stderr);
+        return;
+    }
+    sz = sizeof(dbuf);
+    strncpy(cbuf, prog, sizeof(cbuf));
+    strcat(cbuf, ": [DB] ");
+    strncat(cbuf, func, sizeof(cbuf));
+    strcat(cbuf, "() - ");
+    va_start(ap, msg);
+    x = vsnprintf(dbuf, sz, msg, ap);
+    va_end(ap);
+    if (x > 0) {
+        strncat(cbuf, dbuf, x);
+        fputs(cbuf, stderr);
+        memset(dbuf, '\0', strlen(dbuf));
+    } else {
+        /* FAIL */
+        snprintf(dbuf, sz, "%s: debug(%s) FAILURE: %zd\n", prog, dbuf, x);
+        fputs(dbuf, stderr);
+    }
 }
 
 /* debugx() -
  *
  * Print formatted message to stderr if MODE_DEBUG is set, without preformatting.
  *
  */
-void debugx(const char *msg,...) {
-  char prog[MAXLEN], dbuf[MAXLEN];
-  size_t sz, x;
-  va_list ap;
-  if (!(conf.mode & MODE_DEBUG))
-    return;
+void debugx(const char *msg,...)
+{
+    char prog[MAXLEN], dbuf[MAXLEN];
+    size_t sz, x;
+    va_list ap;
+    if (!(conf.mode & MODE_DEBUG))
+        return;
 
-  if (conf.program[0] == '\0')
-    strcpy(prog, DEFAULT_PROGRAM_NAME);
-  else
-    strncpy(prog, conf.program, sizeof(prog));
-  if ((msg == NULL) || (strlen(prog) > 256)) {
-    /* FAIL */
-    snprintf(dbuf, sizeof(dbuf), "%s: debugx() EPIC FAILURE.\n", prog);
-    fputs(dbuf, stderr);
-    return;
-  }
-  sz = sizeof(dbuf);
-  va_start(ap, msg);
-  x = vsnprintf(dbuf, sz, msg, ap);
-  va_end(ap);
-  if (x > 0) {
-    fputs(dbuf, stderr);
-    memset(dbuf, '\0', strlen(dbuf));
-  }
-  else {
-    /* FAIL */
-    snprintf(dbuf, sz, "%s: debug(%s) FAILURE: %zd\n", prog, dbuf, x);
-    fputs(dbuf, stderr);
-  }
+    if (conf.program[0] == '\0')
+        strcpy(prog, DEFAULT_PROGRAM_NAME);
+    else
+        strncpy(prog, conf.program, sizeof(prog));
+    if ((msg == NULL) || (strlen(prog) > 256)) {
+        /* FAIL */
+        snprintf(dbuf, sizeof(dbuf), "%s: debugx() EPIC FAILURE.\n", prog);
+        fputs(dbuf, stderr);
+        return;
+    }
+    sz = sizeof(dbuf);
+    va_start(ap, msg);
+    x = vsnprintf(dbuf, sz, msg, ap);
+    va_end(ap);
+    if (x > 0) {
+        fputs(dbuf, stderr);
+        memset(dbuf, '\0', strlen(dbuf));
+    } else {
+        /* FAIL */
+        snprintf(dbuf, sz, "%s: debug(%s) FAILURE: %zd\n", prog, dbuf, x);
+        fputs(dbuf, stderr);
+    }
 }
 
 /* printfx() -
  *
  * Print formatted message to stderr AND stdout, without preformatting.
  *
  */
-void printfx(const char *msg,...) {
-  char prog[MAXLEN], dbuf[MAXLEN];
-  size_t sz, x;
-  va_list ap;
+void printfx(const char *msg,...)
+{
+    char prog[MAXLEN], dbuf[MAXLEN];
+    size_t sz, x;
+    va_list ap;
 
-  if (conf.program[0] == '\0')
-    strcpy(prog, DEFAULT_PROGRAM_NAME);
-  else
-    strncpy(prog, conf.program, sizeof(prog));
+    if (conf.program[0] == '\0')
+        strcpy(prog, DEFAULT_PROGRAM_NAME);
+    else
+        strncpy(prog, conf.program, sizeof(prog));
 
-  if ((msg == NULL) || (strlen(prog) > 256)) {
-    /* FAIL */
-    snprintf(dbuf, sizeof(dbuf), "%s: printfx() EPIC FAILURE.\n", prog);
-    fputs(dbuf, stderr);
-    return;
-  }
-  sz = sizeof(dbuf);
-  va_start(ap, msg);
-  x = vsnprintf(dbuf, sz, msg, ap);
-  va_end(ap);
-  if (x > 0) {
-    dbuf[x] = '\0';
-    x++;
-    fputs(dbuf, stdout);
+    if ((msg == NULL) || (strlen(prog) > 256)) {
+        /* FAIL */
+        snprintf(dbuf, sizeof(dbuf), "%s: printfx() EPIC FAILURE.\n", prog);
+        fputs(dbuf, stderr);
+        return;
+    }
+    sz = sizeof(dbuf);
+    va_start(ap, msg);
+    x = vsnprintf(dbuf, sz, msg, ap);
+    va_end(ap);
+    if (x > 0) {
+        dbuf[x] = '\0';
+        x++;
+        fputs(dbuf, stdout);
 //    debug("printfx", "DATA: %s", dbuf);
-    memset(dbuf, '\0', strlen(dbuf));
-  }
-  else {
-    /* FAIL */
-    snprintf(dbuf, sz, "%s: printfx(%s) FAILURE: %zd\n", prog, dbuf, x);
-    fputs(dbuf, stderr);
-  }
+        memset(dbuf, '\0', strlen(dbuf));
+    } else {
+        /* FAIL */
+        snprintf(dbuf, sz, "%s: printfx(%s) FAILURE: %zd\n", prog, dbuf, x);
+        fputs(dbuf, stderr);
+    }
 
-  /* stdout needs to be flushed for it to work with Squid */
-  fflush(stdout);
+    /* stdout needs to be flushed for it to work with Squid */
+    fflush(stdout);
 }
 
 /*
