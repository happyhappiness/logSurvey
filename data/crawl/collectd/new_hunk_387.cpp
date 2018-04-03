   */
  native public static int RegisterShutdown (String name,
      CollectdShutdownInterface obj);

  /**
   * Java representation of collectd/src/plugin.h:plugin_dispatch_values
   */
  native public static int DispatchValues (ValueList vl);

  /**
   * Java representation of collectd/src/plugin.h:plugin_get_ds
   */
  native public static DataSet GetDS (String type);

  /**
   * Java representation of collectd/src/plugin.h:plugin_log
   */
  native private static void Log (int severity, String message);

  public static void LogError (String message)
  {
    Log (LOG_ERR, message);
  } /* void LogError */

  public static void LogWarning (String message)
  {
    Log (LOG_WARNING, message);
  } /* void LogWarning */

  public static void LogNotice (String message)
  {
    Log (LOG_NOTICE, message);
  } /* void LogNotice */

  public static void LogInfo (String message)
  {
    Log (LOG_INFO, message);
  } /* void LogInfo */

  public static void LogDebug (String message)
  {
    Log (LOG_DEBUG, message);
  } /* void LogDebug */

} /* class CollectdAPI */

/* vim: set sw=2 sts=2 et fdm=marker : */
