             name exists, we just remove it and create the directory
             anyway.  */
          DEBUGP (("Removing %s because of directory danger!\n", t));
          unlink (t);
        }
    }
  res = make_directory (t);
