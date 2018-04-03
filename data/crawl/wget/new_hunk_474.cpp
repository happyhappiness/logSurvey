  mu_run_test (test_append_uri_pathel);
  mu_run_test (test_are_urls_equal);
  mu_run_test (test_is_robots_txt_url);

  return NULL;
}

char *program_name; /* Needed by lib/error.c. */

int
main (int argc, char *argv[])
{
  const char *result;

  program_name = argv[0];

  result = all_tests();

  if (result != NULL)
    {
      puts (result);
    }
  else
    {
      printf ("ALL TESTS PASSED\n");
    }

  printf ("Tests run: %d\n", tests_run);

  return result != 0;
}

