                 res == test_array[i].result
                 && (res == false 
                     || 0 == strcmp (test_array[i].filename, filename)));
    }

  return NULL;
