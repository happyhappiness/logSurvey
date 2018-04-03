   if (debug_flag)
     db_level = DB_ALL;
 
-  if (!db_flags)
-    return;
+  if (db_flags)
+    for (pp=db_flags->list; *pp; ++pp)
+      {
+        const char *p = *pp;
 
-  for (pp=db_flags->list; *pp; ++pp)
-    {
-      const char *p = *pp;
+        while (1)
+          {
+            switch (tolower (p[0]))
+              {
+              case 'a':
+                db_level |= DB_ALL;
+                break;
+              case 'b':
+                db_level |= DB_BASIC;
+                break;
+              case 'i':
+                db_level |= DB_BASIC | DB_IMPLICIT;
+                break;
+              case 'j':
+                db_level |= DB_JOBS;
+                break;
+              case 'm':
+                db_level |= DB_BASIC | DB_MAKEFILES;
+                break;
+              case 'v':
+                db_level |= DB_BASIC | DB_VERBOSE;
+                break;
+              default:
+                fatal (NILF, _("unknown debug level specification '%s'"), p);
+              }
 
-      while (1)
-        {
-          switch (tolower (p[0]))
-            {
-            case 'a':
-              db_level |= DB_ALL;
-              break;
-            case 'b':
-              db_level |= DB_BASIC;
-              break;
-            case 'i':
-              db_level |= DB_BASIC | DB_IMPLICIT;
-              break;
-            case 'j':
-              db_level |= DB_JOBS;
-              break;
-            case 'm':
-              db_level |= DB_BASIC | DB_MAKEFILES;
-              break;
-            case 'v':
-              db_level |= DB_BASIC | DB_VERBOSE;
-              break;
-            default:
-              fatal (NILF, _("unknown debug level specification '%s'"), p);
-            }
+            while (*(++p) != '\0')
+              if (*p == ',' || *p == ' ')
+                break;
 
-          while (*(++p) != '\0')
-            if (*p == ',' || *p == ' ')
+            if (*p == '\0')
               break;
+          }
+      }
 
-          if (*p == '\0')
-            break;
-
-          ++p;
-        }
-    }
+  if (db_level)
+    verify_flag = 1;
 }
 
 static void
