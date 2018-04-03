     debugs(29, DBG_IMPORTANT, "Reconfigure: NTLM authentication configuration cleared.");
 }
 
-bool
-Auth::Ntlm::Config::dump(StoreEntry * entry, const char *name, Auth::SchemeConfig * scheme) const
-{
-    if (!Auth::SchemeConfig::dump(entry, name, scheme))
-        return false;
-
-    storeAppendPrintf(entry, "%s ntlm keep_alive %s\n", name, keep_alive ? "on" : "off");
-    return true;
-}
-
-Auth::Ntlm::Config::Config() : keep_alive(1)
-{ }
-
-void
-Auth::Ntlm::Config::parse(Auth::SchemeConfig * scheme, int n_configured, char *param_str)
-{
-    if (strcmp(param_str, "keep_alive") == 0) {
-        parse_onoff(&keep_alive);
-    } else
-        Auth::SchemeConfig::parse(scheme, n_configured, param_str);
-}
-
 const char *
 Auth::Ntlm::Config::type() const
 {
