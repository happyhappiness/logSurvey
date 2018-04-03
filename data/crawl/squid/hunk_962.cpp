     if (strlen(line) > 1024) {
         html = new MemBuf();
         html->init();
-        html->Printf("<tr><td colspan=\"5\">%s</td></tr>\n", line);
+        html->appendf("<tr><td colspan=\"5\">%s</td></tr>\n", line);
         return html;
     }
 
