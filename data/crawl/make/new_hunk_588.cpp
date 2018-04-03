          f->stem = strcache_add_len (buffer, o - buffer);
          if (this)
            {
              if (! this->need_2nd_expansion)
                this = enter_prereqs (this, f->stem);
              else
                this->stem = f->stem;
            }
        }

      /* Add the dependencies to this file entry.  */
      if (this != 0)
        {
          /* Add the file's old deps and the new ones in THIS together.  */
          if (f->deps == 0)
            f->deps = this;
          else if (cmds != 0)
            {
              struct dep *d = this;

              /* If this rule has commands, put these deps first.  */
              while (d->next != 0)
                d = d->next;

              d->next = f->deps;
              f->deps = this;
            }
          else
            {
              struct dep *d = f->deps;

              /* A rule without commands: put its prereqs at the end.  */
              while (d->next != 0)
                d = d->next;

              d->next = this;
            }
        }

      name = f->name;

      /* All done!  Set up for the next one.  */
      if (nextf == 0)
        break;

      filenames = nextf;

      /* Reduce escaped percents.  If there are any unescaped it's an error  */
      name = filenames->name;
      if (find_percent_cached (&name))
        fatal (flocp, _("mixed implicit and normal rules"));
    }
}

