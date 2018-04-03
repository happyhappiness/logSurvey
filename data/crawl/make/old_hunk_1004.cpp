{
  char * s = argv[0];
  int result = 0;
  while (isspace (*s))
    s++;
  result = ! (*s);
  o = variable_buffer_output (o,  result ? "1" : "", result);
