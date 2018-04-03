
void
IPIntercept::StopTransparency(const char *str) {
    debugs(89, DBG_IMPORTANT, "Stopping full transparency: " << str);
    transparent_active = 0;
}

void
IPIntercept::StopInterception(const char *str) {
    debugs(89, DBG_IMPORTANT, "Stopping IP interception: " << str);
    intercept_active = 0;
}

int
