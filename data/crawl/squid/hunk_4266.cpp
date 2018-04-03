                 printf("<PRE>\n");
             }
 
+            istate = isActions;
+            /* yes, fall through, we do not want to loose the first line */
+
+        case isActions:
+            if (strncmp(buf, "action:", 7) == 0) {
+                fputs(" ", stdout);
+                fputs(munge_action_line(buf + 7, req), stdout);
+                break;
+            }
+            if (parse_menu) {
+                printf("<UL>\n");
+            } else {
+                printf("<HR noshade size=\"1px\">\n");
+                printf("<PRE>\n");
+            }
+
             istate = isBody;
             /* yes, fall through, we do not want to loose the first line */
 
