 
             if (fmt->width) {
                 if (fmt->left)
-                    memBufPrintf(&mb, "%-*s", (int) fmt->width, out);
+                    mb.Printf("%-*s", (int) fmt->width, out);
                 else
-                    memBufPrintf(&mb, "%*s", (int) fmt->width, out);
+                    mb.Printf("%*s", (int) fmt->width, out);
             } else
-                memBufAppend(&mb, out, strlen(out));
+                mb.append(out, strlen(out));
         } else {
-            memBufAppend(&mb, "-", 1);
+            mb.append("-", 1);
         }
 
         if (fmt->space)
-            memBufAppend(&mb, " ", 1);
+            mb.append(" ", 1);
 
         sb.clean();
 
