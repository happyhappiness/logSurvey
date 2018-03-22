  return did_something;		/* tell them to retry if we made one */
}

/* Prepare to extract a file.
   Return zero if extraction should not proceed.  */

static int
prepare_to_extract (char const *file_name)
{
  if (to_stdout_option)
    return 0;

  if (old_files_option == UNLINK_FIRST_OLD_FILES
      && !remove_any_file (file_name, recursive_unlink_option)
      && errno != ENOENT)
    {
      unlink_error (file_name);
      return 0;
    }

