 
     printf("<TABLE BORDER=\"0\" CELLPADDING=\"10\" CELLSPACING=\"1\">\n");
 
-    printf("<TR><TH ALIGN=\"left\">Cache Host:</TH><TD><INPUT NAME=\"host\" ");
 
-    printf("size=\"30\" VALUE=\"%s\"></TD></TR>\n", host);
+    fp = fopen("cachemgr.conf", "r");
+
+    if (fp == NULL)
+        fp = fopen(DEFAULT_CACHEMGR_CONFIG, "r");
+
+    if (fp != NULL) {
+        int servers = 0;
+        char config_line[BUFSIZ];
+
+        while (fgets(config_line, BUFSIZ, fp)) {
+            char *server, *comment;
+            strtok(config_line, "\r\n");
+
+            if (config_line[0] == '#')
+                continue;
+
+            if (config_line[0] == '\0')
+                continue;
+
+            if ((server = strtok(config_line, " \t")) == NULL)
+                continue;
+
+            if (strchr(server, '*') || strchr(server, '[') || strchr(server, '?')) {
+                need_host = -1;
+                continue;
+            }
+
+            comment = strtok(NULL, "");
+
+            if (comment)
+                while (*comment == ' ' || *comment == '\t')
+                    comment++;
+
+            if (!comment || !*comment)
+                comment = server;
+
+            if (!servers) {
+                printf("<TR><TH ALIGN=\"left\">Cache Server:</TH><TD><SELECT NAME=\"server\">\n");
+            }
+
+            printf("<OPTION VALUE=\"%s\"%s>%s</OPTION>\n", server, (servers || *host) ? "" : " SELECTED", comment);
+            servers++;
+        }
+
+        if (servers) {
+            if (need_host == 1 && !*host)
+                need_host = 0;
+
+            if (need_host)
+                printf("<OPTION VALUE=\"\"%s>Other</OPTION>\n", (*host) ? " SELECTED" : "");
+
+            printf("</SELECT></TR>\n");
+        }
+
+        fclose(fp);
+    }
+
+    if (need_host) {
+        if (need_host == 1 && !*host)
+            host = "localhost";
+
+        printf("<TR><TH ALIGN=\"left\">Cache Host:</TH><TD><INPUT NAME=\"host\" ");
 
-    printf("<TR><TH ALIGN=\"left\">Cache Port:</TH><TD><INPUT NAME=\"port\" ");
+        printf("size=\"30\" VALUE=\"%s\"></TD></TR>\n", host);
 
-    printf("size=\"30\" VALUE=\"%d\"></TD></TR>\n", port);
+        printf("<TR><TH ALIGN=\"left\">Cache Port:</TH><TD><INPUT NAME=\"port\" ");
+
+        printf("size=\"30\" VALUE=\"%d\"></TD></TR>\n", port);
+    }
 
     printf("<TR><TH ALIGN=\"left\">Manager name:</TH><TD><INPUT NAME=\"user_name\" ");
 
