   if (snapped_deps)
     fatal (flocp, _("prerequisites cannot be defined in recipes"));
 
+  /* Determine if this is a pattern rule or not.  */
+  name = filenames->name;
+  implicit_percent = find_percent_cached (&name);
+
+  /* If there's a recipe, set up a struct for it.  */
   if (commands_idx > 0)
     {
       cmds = xmalloc (sizeof (struct commands));
