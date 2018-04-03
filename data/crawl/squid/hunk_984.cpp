                                      fmt->widthMax : strlen(out);
 
                 if (fmt->left)
-                    mb.Printf("%-*.*s", minWidth, maxWidth, out);
+                    mb.appendf("%-*.*s", minWidth, maxWidth, out);
                 else
-                    mb.Printf("%*.*s", minWidth, maxWidth, out);
+                    mb.appendf("%*.*s", minWidth, maxWidth, out);
             } else
                 mb.append(out, strlen(out));
         } else {
