  status = Customs_Host (EXPORT_SAME, &permit);
  if (status != RPC_SUCCESS)
    {
      if (debug_flag)
	printf ("Customs won't export: %s\n", Rpc_ErrorMessage (status));
      return 0;
    }

