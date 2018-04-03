

// single global instance for access by other components.
Ip::Intercept Ip::Interceptor;

void
Ip::Intercept::StopTransparency(const char *str)
{
    if (transparent_active) {
        debugs(89, DBG_IMPORTANT, "Stopping full transparency: " << str);
