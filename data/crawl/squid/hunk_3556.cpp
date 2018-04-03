         break;
 
     case 'w':
-
         if (Config.adminEmail)
             mb.Printf("%s", Config.adminEmail);
-        else
+        else if (!url_presentable)
             p = "[unknown]";
-
         break;
 
     case 'W':
+        if (url_presentable) break;
         if (Config.adminEmail && Config.onoff.emailErrData)
             Dump(&mb);
-
         break;
 
     case 'z':
+        if (url_presentable) break;
         if (dnsError.size() > 0)
             p = dnsError.termedBuf();
         else
             p = "[unknown]";
-
         break;
 
     case 'Z':
+        if (url_presentable) break;
         if (err_msg)
             p = err_msg;
         else
             p = "[unknown]";
-
         break;
 
     case '%':
         p = "%";
-
         break;
 
     default:
         mb.Printf("%%%c", token);
-
         do_quote = 0;
-
         break;
     }
 
