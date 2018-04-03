    return PathedCommands.find(cmd) != PathedCommands.end();
}

/// Parses a single FTP request on the control connection.
/// Returns NULL on errors and incomplete requests.
ClientSocketContext *
Ftp::Server::parseOneRequest(Http::ProtocolVersion &ver)
{
    // OWS <command> [ RWS <parameter> ] OWS LF

    // InlineSpaceChars are isspace(3) or RFC 959 Section 3.1.1.5.2, except
