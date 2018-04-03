  status = Customs_Host (EXPORT_SAME, &permit);
  if (status != RPC_SUCCESS)
    {
      DB (DB_EXTRA, (_("Customs won't export: %s\n"),
                     Rpc_ErrorMessage (status)));
      return 0;
    }

