                 if (t->zero)
                     entry->append("0", 1);
 
-                if (t->width)
-                    storeAppendPrintf(entry, "%d", (int) t->width);
+                if (t->widthMin >= 0)
+                    storeAppendPrintf(entry, "%d", t->widthMin);
 
-                if (t->precision)
-                    storeAppendPrintf(entry, ".%d", (int) t->precision);
+                if (t->widthMax >= 0)
+                    storeAppendPrintf(entry, ".%d", t->widthMax);
 
                 if (arg)
                     storeAppendPrintf(entry, "{%s}", arg);
