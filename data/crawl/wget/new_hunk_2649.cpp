  if (0 != strcmp (test_copy, expected_result))
    {
      printf ("Failed path_simplify(\"%s\"): expected \"%s\", got \"%s\".\n",
              test, expected_result, test_copy);
    }
  if (modified != expected_change)
    {
      if (expected_change)
        printf ("Expected modification with path_simplify(\"%s\").\n",
                test);
      else
        printf ("Expected no modification with path_simplify(\"%s\").\n",
                test);
    }
  xfree (test_copy);
}
