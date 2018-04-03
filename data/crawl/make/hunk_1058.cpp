   return o;
 }
 
+/*
+  $(if condition,true-part[,false-part])
+
+  CONDITION is false iff it evaluates to an empty string.  White
+  space before and after condition are stripped before evaluation.
+
+  If CONDITION is true, then TRUE-PART is evaluated, otherwise FALSE-PART is
+  evaluated (if it exists).  Because only one of the two PARTs is evaluated,
+  you can use $(if ...) to create side-effects (with $(shell ...), for
+  example).
+*/
+
+static char *
+func_if (o, argv, funcname)
+     char *o;
+     char **argv;
+     const char *funcname;
+{
+  char *begp = argv[0];
+  char *endp = argv[1]-1;
+  int result = 0;
+
+  /* Find the result of the condition: if we have a value, and it's not
+     empty, the condition is true.  If we don't have a value, or it's the
+     empty string, then it's false.  */
+
+  strip_whitespace (&begp, &endp);
+
+  if (begp < endp)
+    {
+      char *expansion = expand_argument (begp, endp);
+
+      result = strlen (expansion);
+      free (expansion);
+    }
+
+  /* If the result is true (1) we want to eval the first argument, and if
+     it's false (0) we want to eval the second.  If the argument doesn't
+     exist we do nothing, otherwise expand it and add to the buffer.  */
+
+  argv += 1 + !result;
+
+  if (argv[0] != NULL && argv[1] != NULL)
+    {
+      char *expansion;
+      char **endp = argv+1;
+
+      /* If we're doing the else-clause, make sure we concatenate any
+         potential extra arguments into the last argument.  */
+      if (!result)
+        while (*endp && **endp != '\0')
+          ++endp;
+
+      expansion = expand_argument (*argv, *endp-1);
+
+      o = variable_buffer_output (o, expansion, strlen (expansion));
+      free (expansion);
+    }
+
+  return o;
+}
+
 static char *
 func_wildcard(o, argv, funcname)
      char *o;
