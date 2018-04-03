 
 
 // single global instance for access by other components.
-IpIntercept IpInterceptor;
+Ip::Intercept Ip::Interceptor;
 
 void
-IpIntercept::StopTransparency(const char *str)
+Ip::Intercept::StopTransparency(const char *str)
 {
     if (transparent_active) {
         debugs(89, DBG_IMPORTANT, "Stopping full transparency: " << str);
