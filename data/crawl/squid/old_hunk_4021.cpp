

// single global instance for access by other components.
IPIntercept IPInterceptor;

void
IPIntercept::StopTransparency(const char *str)
{
    if (transparent_active) {
        debugs(89, DBG_IMPORTANT, "Stopping full transparency: " << str);
