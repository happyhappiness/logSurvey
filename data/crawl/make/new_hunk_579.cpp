expand_deps (struct file *f)
{
  struct dep *d;
  struct dep **dp;
  const char *file_stem = f->stem;
  int initialized = 0;

  f->updating = 0;

  /* Walk through the dependencies.  For any dependency that needs 2nd
     expansion, expand it then insert the result into the list.  */
  dp = &f->deps;
  d = f->deps;
  while (d != 0)
    {
      char *p;
      struct dep *new, *next;
      char *name = (char *)d->name;

      if (! d->name || ! d->need_2nd_expansion)
        {
          /* This one is all set already.  */
          dp = &d->next;
          d = d->next;
          continue;
        }

      /* If it's from a static pattern rule, convert the patterns into
         "$*" so they'll expand properly.  */
      if (d->staticpattern)
        {
          char *o;
          d->name = o = variable_expand ("");
          o = subst_expand (o, name, "%", "$*", 1, 2, 0);
          *o = '\0';
          free (name);
          d->name = name = xstrdup (d->name);
          d->staticpattern = 0;
        }

      /* We're going to do second expansion so initialize file variables for
         the file. Since the stem for static pattern rules comes from
         individual dep lines, we will temporarily set f->stem to d->stem.  */
      if (!initialized)
        {
          initialize_file_variables (f, 0);
          initialized = 1;
        }

      if (d->stem != 0)
        f->stem = d->stem;

      set_file_variables (f);

      p = variable_expand_for_file (d->name, f);

      if (d->stem != 0)
        f->stem = file_stem;

      /* At this point we don't need the name anymore: free it.  */
      free (name);

      /* Parse the prerequisites and enter them into the file database.  */
      new = enter_prereqs (split_prereqs (p), d->stem);

      /* If there were no prereqs here (blank!) then throw this one out.  */
      if (new == 0)
        {
          *dp = d->next;
          free_dep (d);
          d = *dp;
          continue;
        }

      /* Add newly parsed prerequisites.  */
      next = d->next;
      *dp = new;
      for (dp = &new->next, d = new->next; d != 0; dp = &d->next, d = d->next)
        ;
      *dp = next;
      d = *dp;
    }
}

/* Reset the updating flag.  */

static void
reset_updating (const void *item)
{
  struct file *f = (struct file *) item;
  f->updating = 0;
}

/* For each dependency of each file, make the `struct dep' point
