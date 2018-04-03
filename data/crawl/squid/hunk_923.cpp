         if (isSet(flag) && flag != CC_OTHER) {
 
             /* print option name for all options */
-            p->Printf((pcount ? ", %s": "%s") , CcAttrs[flag].name);
+            p->appendf((pcount ? ", %s": "%s") , CcAttrs[flag].name);
 
             /* for all options having values, "=value" after the name */
             switch (flag) {
             case CC_MAX_AGE:
-                p->Printf("=%d", (int) maxAge());
+                p->appendf("=%d", maxAge());
                 break;
             case CC_S_MAXAGE:
-                p->Printf("=%d", (int) sMaxAge());
+                p->appendf("=%d", sMaxAge());
                 break;
             case CC_MAX_STALE:
                 /* max-stale's value is optional.
                   If we didn't receive it, don't send it */
                 if (maxStale()!=MAX_STALE_ANY)
-                    p->Printf("=%d", (int) maxStale());
+                    p->appendf("=%d", maxStale());
                 break;
             case CC_MIN_FRESH:
-                p->Printf("=%d", (int) minFresh());
+                p->appendf("=%d", minFresh());
                 break;
             default:
                 /* do nothing, directive was already printed */
