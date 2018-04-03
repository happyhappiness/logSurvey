  return metalink_check_safe_path (basename) ? basename : NULL;
}

/* Append the suffix ".badhash" to the file NAME, except without
   overwriting an existing file with that name and suffix.  */
void
