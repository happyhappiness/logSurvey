            parseApplicationDataMessage();
            continue;
        }
        skipMessage("unknown ContentType msg");
    }
}

void
Security::HandshakeParser::parseChangeCipherCpecMessage()
{
    Must(currentContentType == ContentType::ctChangeCipherSpec);
    // we are currently ignoring Change Cipher Spec Protocol messages
    // Everything after this message may be is encrypted
    // The continuing parsing is pointless, abort here and set parseDone
    skipMessage("ChangeCipherCpec msg");
    ressumingSession = true;
    parseDone = true;
}

void
Security::HandshakeParser::parseAlertMessage()
{
    Must(currentContentType == ContentType::ctAlert);
    const Alert alert(tkMessages);
    debugs(83, 3, "level " << alert.level << " description " << alert.description);
    // we are currently ignoring Alert Protocol messages
}

void
