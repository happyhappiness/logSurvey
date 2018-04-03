 	    str[x] = ' ';
 }
 
+#define ONE_SECOND (1)
+#define ONE_MINUTE (ONE_SECOND*60)
+#define ONE_HOUR (ONE_MINUTE*60)
+#define ONE_DAY (ONE_HOUR*24)
+#define ONE_WEEK (ONE_DAY*7)
+#define ONE_MONTH (ONE_DAY*30)
+#define ONE_YEAR (ONE_DAY*365)
+
+static char *
+describeTimeSince(time_t then)
+{
+    time_t delta = now - then;
+    static char buf[128];
+    static char buf2[128];
+    char *fmt = "%s ago";
+    buf[0] = '\0';
+    if (delta < 0) {
+	delta = (-delta);
+	fmt = "in %s";
+    }
+    if (delta < ONE_MINUTE)
+	sprintf(buf, "%ds", (int) (delta / ONE_SECOND));
+    else if (delta < ONE_HOUR)
+	sprintf(buf, "%dm", (int) (delta / ONE_MINUTE));
+    else if (delta < ONE_DAY)
+	sprintf(buf, "%dh", (int) (delta / ONE_HOUR));
+    else if (delta < ONE_WEEK)
+	sprintf(buf, "%dD", (int) (delta / ONE_DAY));
+    else if (delta < ONE_MONTH)
+	sprintf(buf, "%dW", (int) (delta / ONE_WEEK));
+    else if (delta < ONE_YEAR)
+	sprintf(buf, "%dM", (int) (delta / ONE_MONTH));
+    else
+	sprintf(buf, "%dY", (int) (delta / ONE_YEAR));
+    sprintf(buf2, fmt, buf);
+    return buf2;
+}
 
 static void
 parse_object(char *string)
 {
-    char *tmp_line = NULL;
+    char *tbuf = NULL;
+    char *store_status = NULL;
+    char *mem_status = NULL;
+    char *swap_status = NULL;
+    char *ping_status = NULL;
+    char *lock_count = NULL;
+    char *flags = NULL;
+    char *last_verified = NULL;
+    char *last_use = NULL;
+    char *last_modified = NULL;
+    char *expires = NULL;
+    char *refcount = NULL;
+    char *clients = NULL;
+    char *size = NULL;
     char *url = NULL;
-    char *token = NULL;
-    char *store_time = NULL;
-    char *last_ref = NULL;
-    char *ttl = NULL;
-    char *sto = NULL;
-    char *status = NULL;
-    char *obj_status = NULL;
-    char *w_space = " \t\n";
-    int obj_size;
-    int ref_cnt;
-
-    /* Use tmp_line as a temporary pointer to the input line */
-    tmp_line = string;
-
-    /* Parse out the url */
-    url = strtok(tmp_line, w_space);
-
-    if (!url)
-	return;
+
+    tbuf = xstrdup(string);
+
+    if ((store_status = strtok(tbuf, w_space)) == NULL)
+	goto parse_obj_done;
+    if ((mem_status = strtok(NULL, w_space)) == NULL)
+	goto parse_obj_done;
+    if ((swap_status = strtok(NULL, w_space)) == NULL)
+	goto parse_obj_done;
+    if ((ping_status = strtok(NULL, w_space)) == NULL)
+	goto parse_obj_done;
+    if ((lock_count = strtok(NULL, w_space)) == NULL)
+	goto parse_obj_done;
+    if ((flags = strtok(NULL, w_space)) == NULL)
+	goto parse_obj_done;
+    if ((last_verified = strtok(NULL, w_space)) == NULL)
+	goto parse_obj_done;
+    if ((last_use = strtok(NULL, w_space)) == NULL)
+	goto parse_obj_done;
+    if ((last_modified = strtok(NULL, w_space)) == NULL)
+	goto parse_obj_done;
+    if ((expires = strtok(NULL, w_space)) == NULL)
+	goto parse_obj_done;
+    if ((refcount = strtok(NULL, w_space)) == NULL)
+	goto parse_obj_done;
+    if ((clients = strtok(NULL, w_space)) == NULL)
+	goto parse_obj_done;
+    if ((size = strtok(NULL, w_space)) == NULL)
+	goto parse_obj_done;
+    if ((url = strtok(NULL, w_space)) == NULL)
+	goto parse_obj_done;
 
 #if !ALL_OBJECTS
     if (!strncmp(url, "cache_object", 12))
-	return;
+	goto parse_obj_done;
     if (!strncmp(url, "POST", 4))
-	return;
+	goto parse_obj_done;
 #endif
 
-    tmp_line = NULL;
-
-    token = strtok(tmp_line, w_space);
-    sscanf(token, "%d", &obj_size);
-
-    token = strtok(tmp_line, w_space);
-    store_time = xstrdup(token);
-
-    token = strtok(tmp_line, w_space);
-    obj_status = xstrdup(token);
-
-    token = strtok(tmp_line, w_space);
-    last_ref = xstrdup(token);
-
-    token = strtok(tmp_line, w_space);
-    ttl = xstrdup(token);
-
-    token = strtok(tmp_line, w_space);
-    /* Active */
-
-    token = strtok(tmp_line, w_space);
-    sscanf(token, "%d", &ref_cnt);
-
-    token = strtok(tmp_line, w_space);
-    sto = xstrdup(token);
-
-    token = strtok(tmp_line, w_space);
-    status = xstrdup(token);
-
-    printf("<LI>Cache: <A HREF=\"%s\">%s</A><BR>",
+    printf("<LI><A HREF=\"%s\">%s</A><BR>",
 	url, url);
-    printf("Size: %d bytes, TTL: %s ,<BR>",
-	obj_size, ttl);
-    printf("Stored: %s, %s ago, %s %s,<BR>",
-	sto, store_time, obj_status, status);
-    printf("Refs: %d, Referenced %s hh:mm:ss ago</LI>\n",
-	ref_cnt, last_ref);
-
-    free(ttl);
-    free(store_time);
-    free(last_ref);
-    free(sto);
-    free(status);
+    printf("Verified %s, ", describeTimeSince((time_t) atoi(last_verified + 3)));
+    printf("Used %s, ", describeTimeSince((time_t) atoi(last_use + 3)));
+    printf("Modified %s, ", describeTimeSince((time_t) atoi(last_modified + 3)));
+    printf("Expires %s,<BR>", describeTimeSince((time_t) atoi(expires + 3)));
+    printf("%d bytes, %d accesses, %d active clients,<BR>",
+	atoi(size),
+	atoi(refcount),
+	atoi(clients));
+    printf("%s, %s, %s, %s,<BR>",
+	store_status,
+	mem_status,
+	swap_status,
+	ping_status);
+    printf("%d Locks, Flags: %s\n",
+	atoi(lock_count),
+	flags);
+
+  parse_obj_done:
+    xfree(tbuf);
 }
 
 int
