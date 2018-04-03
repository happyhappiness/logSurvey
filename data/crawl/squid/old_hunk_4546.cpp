        startWriting();
    } else {
        disableRetries();
        mustStop("ICAP service unusable");
    }

    ICAPXaction_Exit();
