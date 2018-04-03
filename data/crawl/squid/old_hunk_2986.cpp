        buf.Printf("Stopped, reason:");
        buf.Printf("%s",stopReason);
    }
    buf.Printf(" job%d]", id);
    buf.terminate();

    return buf.content();
