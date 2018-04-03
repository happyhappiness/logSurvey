 }
 #endif
 
-/* This might not be very useful, but the code was simple to
-  implement, I just had to do it.
+/* User-defined functions.  Expand the first argument as either a builtin
+   function or a make variable, in the context of the rest of the arguments
+   assigned to $1, $2, ... $N.  $0 is the name of the function.  */
 
-  Here goes anyway
-
-  Apply & User defined functions.
-
-  SYNTAX
-
-    $(apply funcname, arg1, arg2, .. )
-
-  SEMANTICS
-
-  You can specify a builtin function, for funcname, eg
-
-    f = addprefix
-    $(apply addprefix,a, b c d)
-
-  This will result in
-
-    ab ac ad
-
-  You can specify your own functions, eg
-
-    funcname=BODY
-
-  BODY contains $(1) .. $(N) as argument markers.
-  upon expansions the strings ARG1 .. ARGN are substituted for $(1) .. $(N)
-  into BODY
-
-  Because the funcname is computed as well you can combine this do some
-  funky things, eg
-
-    map=$(foreach a, $(2), $(apply $(1), $(a)))
-
-
-  LIMITATIONS.
-
-  Make has no support for nested lists (or tuples), so you can't do
-  stuff like (Haskell notation):
-
-    f :: (a,b) -> c                   -- type of F
-    map :: (a->b) -> [a] -> b         -- type of MAP
-
-    map f [(1,2), (2,3)]              -- map F over list containing (1,2) and (2,3)
-
-  to get
-
-    [f (1, 2), f (2, 3)]
-
-
-  If only we had nested lists and quotes, we could duplicate LISP in make by
-  transforming
-
-    $(a, b, c) <->  (a b c)
-    $(quote $(a, b, c)) <-> '(a b c)
-
-  (or something alike ;-) (We could have automatic integration of
-  GUILE and make :-)
-
-  [Actually -- why should this be a joke?  If we could somehow integrate the
-  rules and targets into a functional model make could be a lot cleaner in
-  concept. ]
-
-*/
 char *
 func_apply (o, argv, funcname)
      char *o;
      char **argv;
      const char *funcname;
 {
-  char *userfunc_name;
-  int func_len;
-  char *body = 0;
-  char *expanded_body = 0;
+  char *fname;
+  int flen;
+  char *body;
   int i;
   const struct function_table_entry *entry_p;
 
-  userfunc_name = argv[0];
-  while (isspace (*userfunc_name))
-    ++userfunc_name;
+  /* Applying nothing is a no-op.  */
+  if (*argv[0] == '\0')
+    return o;
 
-  entry_p = lookup_function (function_table, userfunc_name);
+  /* There is no way to define a variable with a space in the name, so strip
+     trailing whitespace as a favor to the user.  */
+
+  flen = strlen (argv[0]);
+  fname = argv[0] + flen - 1;
+  while (isspace (*fname))
+    --fname;
+  fname[1] = '\0';
+
+  flen = fname - argv[0] + 1;
+  fname = argv[0];
+
+  /* Are we invoking a builtin function?  */
+
+  entry_p = lookup_function (function_table, fname);
 
-  /* builtin function? */
   if (entry_p)
     {
-      for (i=0; argv[i+1]; i++)
+      for (i=0; argv[i+1]; ++i)
 	;
 
-      o = expand_builtin_function (o, i, argv + 1, entry_p);
-      return o;
+      return expand_builtin_function (o, i, argv + 1, entry_p);
     }
 
-  func_len = strlen (userfunc_name);
-  body = xmalloc (func_len + 4);
-  strcpy (body + 2, userfunc_name);
-  body [func_len+2]=')';
-  body [func_len+3]= 0;
-  body [1]='(';
-  body [0]='$';
+  /* No, so the first argument is the name of a variable to be expanded and
+     interpreted as a function.  Create the variable reference.  */
+  body = alloca (flen + 4);
+  body[0]='$';
+  body[1]='(';
+  strcpy (body + 2, fname);
+  body[flen+2]=')';
+  body[flen+3]= '\0';
+
+  /* Set up arguments $(1) .. $(N).  $(0) is the function name.  */
 
   push_new_variable_scope ();
 
-  /* set up arguments $(1) .. $(N) */
-  for (i=0; argv[i]; i++)
+  for (i=0; *argv; ++i, ++argv)
     {
-      char num[10];
-      struct variable* var;
+      char num[11];
+
       sprintf (num, "%d", i);
-      var = define_variable (num, strlen (num), argv[i], o_automatic, 0);
+      define_variable (num, strlen (num), *argv, o_automatic, 0);
     }
 
-  expanded_body =  allocated_variable_expand (body);
-  o = variable_buffer_output (o, expanded_body, strlen (expanded_body));
-  free (expanded_body);
+  /* Expand the body in the context of the arguments, adding the result to
+     the variable buffer.  */
+
+  o = variable_expand_string (o, body, flen+3);
+
   pop_variable_scope ();
 
-  free (body);
-  return o;
+  return o + strlen(o);
 }
 
 
-#define STRING_SIZE_TUPLE(s) (s), (sizeof(s)-1)
+#define STRING_SIZE_TUPLE(_s) (_s), (sizeof(_s)-1)
 
 /* Lookup table for builtin functions.
 
