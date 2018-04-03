    return NULL;
}

void
Auth::UserRequest::denyMessageFromHelper(const char *proto, const Helper::Reply &reply)
{
    static SBuf messageNote;
    if (!reply.notes.find(messageNote, "message")) {
        messageNote.append(proto);
        messageNote.append(" Authentication denied with no reason given");
    }
    setDenyMessage(messageNote.c_str());
}

