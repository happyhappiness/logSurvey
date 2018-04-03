  while (val < end && ISSPACE (end[-1]))
    --end;
  if (val == end)
    goto err;

  if (!simple_atof (val, end, &number))
    goto err;

  *(long *)closure = (long)(number * mult);
  return 1;
}

