                 }
             }
 
-            if (fmt->width) {
+            // enforce width limits if configured
+            const bool haveMaxWidth = fmt->precision && !doint && !dooff;
+            if (haveMaxWidth || fmt->width) {
+                const int minWidth = fmt->width ?
+                                     static_cast<int>(fmt->width) : 0;
+                const int maxWidth = haveMaxWidth ?
+                                     static_cast<int>(fmt->precision) : strlen(out);
+
                 if (fmt->left)
-                    mb.Printf("%-*s", (int) fmt->width, out);
+                    mb.Printf("%-*.*s", minWidth, maxWidth, out);
                 else
-                    mb.Printf("%*s", (int) fmt->width, out);
+                    mb.Printf("%*.*s", minWidth, maxWidth, out);
             } else
                 mb.append(out, strlen(out));
         } else {
