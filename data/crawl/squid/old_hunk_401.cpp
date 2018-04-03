    AsyncJob::callException(e);
}

/// Whether Squid FTP Relay supports a named feature (e.g., a command).
static bool
Ftp::SupportedCommand(const SBuf &name)
