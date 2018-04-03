             fprintf(stderr, "[%4.4s]   %-50.50s  %s\n", addrstr, hexstr, charstr);
         }
     }
+
+   if (0) { //temporary hack to keep the linker happy
+     uc(NULL);
+     lc(NULL);
+     hex_dump(NULL,0);
+   }
+    
 }
 
 #endif /* _SQUID_LIBNTLMAUTH_SUPPORT_BITS_CCI */
