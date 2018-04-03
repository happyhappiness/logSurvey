 		    dwTotalCount++;
 		}
 	    }
-        } else {
+	} else {
 	    result = 0;
-            fprintf(stderr, "%s NetUserGetGroups() failed.'\n", myname);
-        }
+	    fprintf(stderr, "%s NetUserGetGroups() failed.'\n", myname);
+	}
     } else {
 	fprintf(stderr, "%s Can't find DC for local domain '%s'\n", myname, machinedomain);
     }
     /*
      * Free the allocated memory.
      */
     if (pSrvBuf != NULL)
-        NetApiBufferFree(pSrvBuf);
+	NetApiBufferFree(pSrvBuf);
     if (pUsrBuf != NULL)
-        NetApiBufferFree(pUsrBuf);
+	NetApiBufferFree(pUsrBuf);
     if ((UsrDCptr != NULL) && (UsrDCptr != LclDCptr))
-        NetApiBufferFree((LPVOID) UsrDCptr);
+	NetApiBufferFree((LPVOID) UsrDCptr);
     if (LclDCptr != NULL)
-        NetApiBufferFree((LPVOID) LclDCptr);
+	NetApiBufferFree((LPVOID) LclDCptr);
     return result;
 }
 
 static void
 usage(char *program)
 {
-    fprintf(stderr,"Usage: %s [-D domain][-G][-P][-c][-d][-h]\n"
-	    	" -D    default user Domain\n"
-	    	" -G    enable Domain Global group mode\n"
-	    	" -P    use ONLY PDCs for group validation\n"
-	    	" -c    use case insensitive compare\n"
-	    	" -d    enable debugging\n"
-		" -h    this message\n",
-		program);
+    fprintf(stderr, "Usage: %s [-D domain][-G][-P][-c][-d][-h]\n"
+	" -D    default user Domain\n"
+	" -G    enable Domain Global group mode\n"
+	" -P    use ONLY PDCs for group validation\n"
+	" -c    use case insensitive compare\n"
+	" -d    enable debugging\n"
+	" -h    this message\n",
+	program);
 }
 
 void
