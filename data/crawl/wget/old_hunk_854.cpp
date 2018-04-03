    }
  return NULL;
}
/* Check for the existance of '$HOME/.wgetrc' and return it's path
   if it exists and is set.  */
char *
wgetrc_user_file_name (void) 
{
  char *home = home_dir();
  char *file = NULL;
  if (home)
    file = aprintf ("%s/.wgetrc", home);
