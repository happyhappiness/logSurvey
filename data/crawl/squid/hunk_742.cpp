     /* construct the table row from parts. */
     html = new MemBuf();
     html->init();
-    html->Printf("<tr class=\"entry\">"
+    html->appendf("<tr class=\"entry\">"
                  "<td class=\"icon\"><a href=\"%s%s\">%s</a></td>"
                  "<td class=\"filename\"><a href=\"%s%s\">%s</a></td>"
                  "<td class=\"date\">%s</td>"
