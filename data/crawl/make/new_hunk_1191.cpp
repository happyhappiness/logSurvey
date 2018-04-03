void
print_variable_data_base ()
{
  puts (_("\n# Variables\n"));

  print_variable_set (&global_variable_set, "");
}
