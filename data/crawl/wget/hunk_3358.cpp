     }
   else if (status == 0)
     {
-      fprintf (stderr, "Invalid command `%s'\n", opt);
+      fprintf (stderr, _("%s: Invalid --execute command `%s'\n"),
+	       exec_name, opt);
       exit (2);
     }
 }
 
 /* Generic helper functions, for use with `commands'. */
 
-static int myatoi PARAMS ((const char *s));
+#define CMP1(p, c0) (TOLOWER((p)[0]) == (c0) && (p)[1] == '\0')
+
+#define CMP2(p, c0, c1) (TOLOWER((p)[0]) == (c0)	\
+			 && TOLOWER((p)[1]) == (c1)	\
+			 && (p)[2] == '\0')
+
+#define CMP3(p, c0, c1, c2) (TOLOWER((p)[0]) == (c0)	\
+		     && TOLOWER((p)[1]) == (c1)		\
+		     && TOLOWER((p)[2]) == (c2)		\
+		     && (p)[3] == '\0')
+
 
 /* Store the boolean value from VAL to CLOSURE.  COM is ignored,
    except for error messages.  */
