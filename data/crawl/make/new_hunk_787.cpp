	file->update_status = 0;
      else
        {
          /* This is a dependency file we cannot remake.  Fail.  */
          if (!rebuilding_makefiles || !file->dontcare)
            complain (file);
          file->update_status = 2;
        }
    }
