// Hack: replaces global ::xassert() to debug debugging assertions
// Relies on assert macro calling xassert() without a specific scope.
void
Debug::xassert(const char *msg, const char *file, int line) {

    if (CurrentDebug) {
        *CurrentDebug << "assertion failed: " << file << ":" << line <<
