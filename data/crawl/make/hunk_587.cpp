               free_dep_chain (f->deps);
 	      f->deps = 0;
 	    }
-          else if (this != 0)
-	    {
-	      /* Add the file's old deps and the new ones in THIS together.  */
-
-              if (f->deps != 0)
-                {
-                  struct dep **d_ptr = &f->deps;
-
-                  while ((*d_ptr)->next != 0)
-                    d_ptr = &(*d_ptr)->next;
-
-                  if (cmds != 0)
-                    {
-                      /* This is the rule with commands, so put its deps
-                         last. The rationale behind this is that $< expands to
-                         the first dep in the chain, and commands use $<
-                         expecting to get the dep that rule specifies.  However
-                         the second expansion algorithm reverses the order thus
-                         we need to make it last here.  */
-                      (*d_ptr)->next = this;
-                      /* This is a hack. I need a way to communicate to
-                         snap_deps() that the last dependency line in this
-                         file came with commands (so that logic in snap_deps()
-                         can put it in front and all this $< -logic works). I
-                         cannot simply rely on file->cmds being not 0 because
-                         of the cases like the following:
-
-                         foo: bar
-                         foo:
-                         ...
-
-                         I am going to temporarily "borrow" UPDATING member in
-                         `struct file' for this.   */
-                      f->updating = 1;
-                    }
-                  else
-                    {
-                      /* This is a rule without commands.  If we already have
-                         a rule with commands and prerequisites (see "hack"
-                         comment above), put these prereqs at the end but
-                         before prereqs from the rule with commands. This way
-                         everything appears in makefile order.  */
-                      if (f->updating)
-                        {
-                          this->next = *d_ptr;
-                          *d_ptr = this;
-                        }
-                      else
-                        (*d_ptr)->next = this;
-                    }
-                }
-              else
-                f->deps = this;
-	    }
 	}
       else
 	{
 	  /* Double-colon.  Make a new record even if there already is one.  */
 	  f = lookup_file (name);
 
-	  /* Check for both : and :: rules.  Check is_target so
-	     we don't lose on default suffix rules or makefiles.  */
+	  /* Check for both : and :: rules.  Check is_target so we don't lose
+	     on default suffix rules or makefiles.  */
 	  if (f != 0 && f->is_target && !f->double_colon)
 	    fatal (flocp,
                    _("target file `%s' has both : and :: entries"), f->name);
+
 	  f = enter_file (strcache_add (name));
 	  /* If there was an existing entry and it was a double-colon entry,
 	     enter_file will have returned a new one, making it the prev
