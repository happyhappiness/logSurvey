static void
_db_print_stderr(const char *format, va_list args)
{
    if (1 < Debug::level)
        return;

    vfprintf(stderr, format, args);
}

Debug::OutStream *Debug::CurrentDebug(NULL);

std::ostream &
Debug::getDebugOut()
{
    if (!CurrentDebug) {
        CurrentDebug = new Debug::OutStream;
        CurrentDebug->setf(std::ios::fixed);
        CurrentDebug->precision(2);
    }
    return *CurrentDebug;
}

void
Debug::parseOptions(char const *)
{}

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

const char*
SkipBuildPrefix(const char* path)
{
    return path;
}

std::ostream &
