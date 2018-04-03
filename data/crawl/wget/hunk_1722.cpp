       char *tmp = strchr (type, ';');
       if (tmp)
         {
+#ifdef ENABLE_IRI
+          char *tmp2 = tmp + 1;
+#endif
+
           while (tmp > type && c_isspace (tmp[-1]))
             --tmp;
           *tmp = '\0';
+
+#ifdef ENABLE_IRI
+          if (opt.enable_iri && *tmp2 != '\0' &&
+              (tmp = strstr (tmp2, "charset=")) != NULL)
+            {
+              tmp += 8;
+              tmp2 = tmp;
+
+              while (*tmp2 && !c_isspace (*tmp2))
+                tmp2++;
+
+              if (tmp2 > tmp)
+                {
+                  *tmp2 = '\0';
+                  /* sXXXav : check given charset */
+                  logprintf (LOG_VERBOSE, "HTTP charset: `%s'\n", tmp);
+                }
+            }
+#endif
         }
     }
   hs->newloc = resp_header_strdup (resp, "Location");
