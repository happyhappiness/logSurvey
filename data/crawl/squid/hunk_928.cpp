         if (isSet(flag) && flag != SC_OTHER) {
 
             /* print option name */
-            p->Printf((pcount ? ", " SQUIDSTRINGPH : SQUIDSTRINGPH),
+            p->appendf((pcount ? ", " SQUIDSTRINGPH : SQUIDSTRINGPH),
                          SQUIDSTRINGPRINT(ScFieldsInfo[flag].name));
 
             /* handle options with values */
 
             if (flag == SC_MAX_AGE)
-                p->Printf("=%d", (int) max_age);
+                p->appendf("=%d", (int) max_age);
 
             if (flag == SC_CONTENT)
-                p->Printf("=\"" SQUIDSTRINGPH "\"", SQUIDSTRINGPRINT(content_));
+                p->appendf("=\"" SQUIDSTRINGPH "\"", SQUIDSTRINGPRINT(content_));
 
             ++pcount;
         }
     }
 
     if (hasTarget())
-        p->Printf(";" SQUIDSTRINGPH, SQUIDSTRINGPRINT(target));
+        p->appendf(";" SQUIDSTRINGPH, SQUIDSTRINGPRINT(target));
 }
 
 void
