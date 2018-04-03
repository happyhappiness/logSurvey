void
Debug::finishDebug()
{
    std::cerr << "debugs: " << CurrentDebug->str() << std::endl;
    delete CurrentDebug;
    CurrentDebug = NULL;
}

void
Debug::xassert(const char *msg, const char *file, int line)
{
    getDebugOut() << "assertion failed: " << file << ":" << line <<
                    ": \"" << msg << "\"";
    abort();
}
