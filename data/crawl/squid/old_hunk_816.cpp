        HttpReply *reply = dynamic_cast<HttpReply*>(virgin.header);

        if (const char *value = (*i)->match(r, reply, alMaster)) {
            buf.Printf("%s: %s\r\n", (*i)->key.termedBuf(), value);
            Adaptation::History::Pointer ah = request->adaptHistory(false);
            if (ah != NULL) {
                if (ah->metaHeaders == NULL)
