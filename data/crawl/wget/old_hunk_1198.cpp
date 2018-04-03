  path_simplify (copy);
  return copy;
}

static void
run_test (char *test, char *expected_result, bool expected_change)
{
  char *test_copy = xstrdup (test);
  bool modified = path_simplify (test_copy);

  if (0 != strcmp (test_copy, expected_result))
    {
      printf ("Failed path_simplify(\"%s\"): expected \"%s\", got \"%s\".\n",
              test, expected_result, test_copy);
    }
  if (modified != expected_change)
    {
