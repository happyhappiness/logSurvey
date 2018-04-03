         break;
 
     case 't':
-        mb.Printf("%s", mkhttpdlogtime(&squid_curtime));
+        mb.Printf("%s", Time::FormatHttpd(squid_curtime));
         break;
 
     case 'T':
