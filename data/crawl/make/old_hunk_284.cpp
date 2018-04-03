                                  PARSEFS_NOAR);
          free (p);

          /* Load each file and add it to the list "to be rebuilt".  */
          while (files != 0)
            {
              struct nameseq *next = files->next;
              const char *name = files->name;
              struct dep *deps;

              free_ns (files);
              files = next;

              if (! load_file (&ebuf->floc, &name, noerror) && ! noerror)
                fatal (&ebuf->floc, _("%s: failed to load"), name);

              deps = alloc_dep ();
              deps->next = read_files;
              read_files = deps;
