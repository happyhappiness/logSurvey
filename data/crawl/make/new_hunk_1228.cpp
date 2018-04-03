
  if (!env && (bad || print_usage_flag))
    {
      print_usage(bad);
      die (bad ? 2 : 0);
    }
}
