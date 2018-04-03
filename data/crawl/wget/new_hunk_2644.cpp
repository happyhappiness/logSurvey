    {
      /* Rename <file> to <file>.orig before former gets written over. */
      if (rename (file, filename_plus_orig_suffix) != 0)
        logprintf (LOG_NOTQUIET, _("Cannot back up %s as %s: %s\n"),
                   file, filename_plus_orig_suffix, strerror (errno));

      /* Remember that we've already written a .orig backup for this file.
         Note that we never free this memory since we need it till the
         convert_all_links() call, which is one of the last things the
         program does before terminating.  BTW, I'm not sure if it would be
         safe to just set 'converted_file_ptr->string' to 'file' below,
         rather than making a copy of the string...  Another note is that I
         thought I could just add a field to the urlpos structure saying
         that we'd written a .orig file for this URL, but that didn't work,
         so I had to make this separate list.
         -- Dan Harkless <wget@harkless.org>

         This [adding a field to the urlpos structure] didn't work
         because convert_file() is called from convert_all_links at
         the end of the retrieval with a freshly built new urlpos
         list.
         -- Hrvoje Niksic <hniksic@xemacs.org>
      */
      string_set_add (converted_files, file);
    }
