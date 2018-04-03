                     break;
                 }
 
-                storeAppend(entry, "%", 1);
+                entry->append("%", 1);
 
                 switch (t->quote) {
 
                 case LOG_QUOTE_QUOTES:
-                    storeAppend(entry, "\"", 1);
+                    entry->append("\"", 1);
                     break;
 
                 case LOG_QUOTE_BRAKETS:
-                    storeAppend(entry, "[", 1);
+                    entry->append("[", 1);
                     break;
 
                 case LOG_QUOTE_URL:
-                    storeAppend(entry, "#", 1);
+                    entry->append("#", 1);
                     break;
 
                 case LOG_QUOTE_RAW:
-                    storeAppend(entry, "'", 1);
+                    entry->append("'", 1);
                     break;
 
                 case LOG_QUOTE_NONE:
                     break;
                 }
 
                 if (t->left)
-                    storeAppend(entry, "-", 1);
+                    entry->append("-", 1);
 
                 if (t->zero)
-                    storeAppend(entry, "0", 1);
+                    entry->append("0", 1);
 
                 if (t->width)
                     storeAppendPrintf(entry, "%d", (int) t->width);
