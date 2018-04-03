    cookie_jar_delete (wget_cookie_jar);
}


#ifdef TESTING

char *
test_parse_content_disposition()
{
  int i;
  struct {
    char *hdrval;    
    char *filename;
    bool result;
  } test_array[] = {
    { "filename=\"file.ext\"", "file.ext", true },
    { "attachment; filename=\"file.ext\"", "file.ext", true },
    { "attachment; filename=\"file.ext\"; dummy", "file.ext", true },
    { "attachment", NULL, false },    
  };
  
  for (i = 0; i < sizeof(test_array)/sizeof(test_array[0]); ++i) 
    {
      char *filename;
      bool res = parse_content_disposition (test_array[i].hdrval, &filename);

      mu_assert ("test_parse_content_disposition: wrong result", 
                 res == test_array[i].result
                 && (res == false 
                     || 0 == strcmp (test_array[i].filename, filename)));

      /* printf ("test %d: %s\n", i, res == false ? "false" : filename); */
    }

  return NULL;
}

#endif /* TESTING */

/*
 * vim: et ts=2 sw=2
 */
