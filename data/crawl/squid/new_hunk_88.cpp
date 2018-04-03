        digest_request->user()->credentials(Auth::Failed);
        digest_request->flags.invalid_password = true;

        SBuf msgNote;
        if (reply.notes.find(msgNote, "message")) {
            digest_request->setDenyMessage(msgNote.c_str());
        } else if (reply.other().hasContent()) {
            // old helpers did send ERR result but a bare message string instead of message= key name.
            digest_request->setDenyMessage(reply.other().content());
