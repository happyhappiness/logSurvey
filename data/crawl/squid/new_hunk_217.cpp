            parseApplicationDataMessage();
            continue;
        }
        skipMessage("unknown ContentType msg [fragment]");
    }
}

void
Security::HandshakeParser::parseChangeCipherCpecMessage()
{
    Must(currentContentType == ContentType::ctChangeCipherSpec);
    // We are currently ignoring Change Cipher Spec Protocol messages.
    skipMessage("ChangeCipherCpec msg [fragment]");

    // Everything after the ChangeCipherCpec message may be encrypted.
    // Continuing parsing is pointless. Stop here.
    resumingSession = true;
    done = "ChangeCipherCpec";
}

void
Security::HandshakeParser::parseAlertMessage()
{
    Must(currentContentType == ContentType::ctAlert);
    const Alert alert(tkMessages);
    debugs(83, (alert.fatal() ? 2:3),
           "level " << static_cast<int>(alert.level) <<
           " description " << static_cast<int>(alert.description));
    if (alert.fatal())
        done = "fatal Alert";
    // else ignore the warning (at least for now)
}

void
