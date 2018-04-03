   return result;
 }
 
-/* Try to interpret LINE (a null-terminated string) as a variable definition.
-
-   ORIGIN may be o_file, o_override, o_env, o_env_override,
-   or o_command specifying that the variable definition comes
-   from a makefile, an override directive, the environment with
-   or without the -e switch, or the command line.
-
-   See the comments for parse_variable_definition().
-
-   If LINE was recognized as a variable definition, a pointer to its `struct
-   variable' is returned.  If LINE is not a variable definition, NULL is
-   returned.  */
+/* Given a variable, a value, and a flavor, define the variable.
+   See the try_variable_definition() function for details on the parameters. */
 
 struct variable *
-try_variable_definition (flocp, line, origin, target_var)
+do_variable_definition (flocp, varname, value, origin, flavor, target_var)
      const struct floc *flocp;
-     char *line;
+     const char *varname;
+     char *value;
      enum variable_origin origin;
+     enum variable_flavor flavor;
      int target_var;
 {
-  register int c;
-  register char *p = line;
-  register char *beg;
-  register char *end;
-  enum { f_bogus,
-         f_simple, f_recursive, f_append, f_conditional } flavor = f_bogus;
-  char *name, *expanded_name, *value=0, *alloc_value=NULL;
+  char *p, *alloc_value = NULL;
   struct variable *v;
   int append = 0;
 
-  while (1)
-    {
-      c = *p++;
-      if (c == '\0' || c == '#')
-	return 0;
-      if (c == '=')
-	{
-	  end = p - 1;
-	  flavor = f_recursive;
-	  break;
-	}
-      else if (c == ':')
-	if (*p == '=')
-	  {
-	    end = p++ - 1;
-	    flavor = f_simple;
-	    break;
-	  }
-	else
-	  /* A colon other than := is a rule line, not a variable defn.  */
-	  return 0;
-      else if (c == '+' && *p == '=')
-	{
-	  end = p++ - 1;
-	  flavor = f_append;
-	  break;
-	}
-      else if (c == '?' && *p == '=')
-        {
-          end = p++ - 1;
-          flavor = f_conditional;
-          break;
-        }
-      else if (c == '$')
-	{
-	  /* This might begin a variable expansion reference.  Make sure we
-	     don't misrecognize chars inside the reference as =, := or +=.  */
-	  char closeparen;
-	  int count;
-	  c = *p++;
-	  if (c == '(')
-	    closeparen = ')';
-	  else if (c == '{')
-	    closeparen = '}';
-	  else
-	    continue;		/* Nope.  */
-
-	  /* P now points past the opening paren or brace.
-	     Count parens or braces until it is matched.  */
-	  count = 0;
-	  for (; *p != '\0'; ++p)
-	    {
-	      if (*p == c)
-		++count;
-	      else if (*p == closeparen && --count < 0)
-		{
-		  ++p;
-		  break;
-		}
-	    }
-	}
-    }
-
-  beg = next_token (line);
-  while (end > beg && isblank ((unsigned char)end[-1]))
-    --end;
-  p = next_token (p);
-
-  /* Expand the name, so "$(foo)bar = baz" works.  */
-  name = (char *) alloca (end - beg + 1);
-  bcopy (beg, name, end - beg);
-  name[end - beg] = '\0';
-  expanded_name = allocated_variable_expand (name);
-
-  if (expanded_name[0] == '\0')
-    fatal (flocp, _("empty variable name"));
-
   /* Calculate the variable's new value in VALUE.  */
 
   switch (flavor)
     {
+    default:
     case f_bogus:
       /* Should not be possible.  */
       abort ();
