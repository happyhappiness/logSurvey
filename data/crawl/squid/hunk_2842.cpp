         p = errorPageName(type);
         break;
 
+    case 'D':
+        if (!allowRecursion)
+            p = "%D";  // if recursion is not allowed, do not convert
+#if USE_SSL
+        // currently only SSL error details implemented
+        else if (detail) {
+            const String &errDetail = detail->toString();
+            MemBuf *detail_mb  = ConvertText(errDetail.termedBuf(), false);
+            mb.append(detail_mb->content(), detail_mb->contentSize());
+            delete detail_mb;
+            do_quote = 0;
+        } else
+#endif
+            mb.Printf("[No Error Detail]");
+        break;
+
     case 'e':
         mb.Printf("%d", xerrno);
         break;
