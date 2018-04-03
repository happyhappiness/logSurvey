        digest_request->user()->credentials(Auth::Failed);
        digest_request->flags.invalid_password = 1;

        Note::Pointer msgNote = reply.responseKeys.findByName("message");
        if (msgNote != NULL) {
            digest_request->setDenyMessage(msgNote->values[0]->value.termedBuf());
        } else if (reply.other().hasContent()) {
            // old helpers did send ERR result but a bare message string instead of message= key name.
            digest_request->setDenyMessage(reply.other().content());
