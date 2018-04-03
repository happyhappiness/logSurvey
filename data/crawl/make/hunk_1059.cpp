   o = variable_buffer_output (o,  result ? "1" : "", result);
   return o;
 }
-
-
-
-/*
- This is an experimental conditional function.
-
- Syntax:
-
-    $(if condition, true-part, false-part)
-
- This is fully not consistent with make's syntax, but more in line
- with `normal' programming languages.
-
- Semantics:
-
- - CONDITION is false iff it evaluates to an empty string.  White
- space before and after condition are stripped before evaluation.
-
- - If CONDITION is true, then TRUE-PART is evaluated, otherwise
- FALSE-PART is evaluated.  Because only one of the two PARTs is
- evaluated, you can use $(if ) to create side-effects with the
- $(shell ) function
-
- */
-static char *
-func_if (char* o, char **argv, char *funcname)
-{
-  char *begp = argv[0];
-  char *endp = argv[1]-2;
-  char *expansion =0;
-  int result = 0;
-
-  strip_whitespace (&begp, &endp);
-  if(begp <= endp)
-    expansion = expand_argument (begp, endp + 1);
-
-  result = expansion
-    ? strlen (expansion)
-    : 0;
-
-  result = !result;
-  free (expansion);
-
-  expansion = expand_argument (argv[1 + result], argv[2+result] -1);
-  o = variable_buffer_output (o, expansion, strlen (expansion));
-
-  return o;
-}
 #endif
 
 
