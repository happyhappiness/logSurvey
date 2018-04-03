
    if (preview.enabled()) {
        if (!preview.done())
            buf.Printf("P(%d)", preview.debt());
    }

    if (virginSendClaim.active())
