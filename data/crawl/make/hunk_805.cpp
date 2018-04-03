 	    }
 	}
     }
+  v->flavor = flavor;
 
   beg = next_token (line);
   while (end > beg && isblank ((unsigned char)end[-1]))
     --end;
   p = next_token (p);
+  v->value = p;
 
   /* Expand the name, so "$(foo)bar = baz" works.  */
   name = (char *) alloca (end - beg + 1);
   bcopy (beg, name, end - beg);
   name[end - beg] = '\0';
-  expanded_name = allocated_variable_expand (name);
+  v->name = allocated_variable_expand (name);
+
+  if (v->name[0] == '\0')
+    fatal (&v->fileinfo, _("empty variable name"));
+
+  return v;
+}
+
+/* Try to interpret LINE (a null-terminated string) as a variable definition.
 
-  if (expanded_name[0] == '\0')
-    fatal (flocp, _("empty variable name"));
+   ORIGIN may be o_file, o_override, o_env, o_env_override,
+   or o_command specifying that the variable definition comes
+   from a makefile, an override directive, the environment with
+   or without the -e switch, or the command line.
 
-  v = do_variable_definition (flocp, expanded_name, p,
-                              origin, flavor, target_var);
+   See the comments for parse_variable_definition().
 
-  free (expanded_name);
+   If LINE was recognized as a variable definition, a pointer to its `struct
+   variable' is returned.  If LINE is not a variable definition, NULL is
+   returned.  */
 
-  return v;
+struct variable *
+try_variable_definition (const struct floc *flocp, char *line,
+                         enum variable_origin origin, int target_var)
+{
+  struct variable v;
+  struct variable *vp;
+
+  if (flocp != 0)
+    v.fileinfo = *flocp;
+  else
+    v.fileinfo.filenm = 0;
+
+  if (!parse_variable_definition (&v, line))
+    return 0;
+
+  vp = do_variable_definition (flocp, v.name, v.value,
+                               origin, v.flavor, target_var);
+
+  free (v.name);
+
+  return vp;
 }
 
 /* Print information for variable V, prefixing it with PREFIX.  */
