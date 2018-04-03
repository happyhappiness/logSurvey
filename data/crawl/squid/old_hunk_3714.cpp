        virginConsumed += size;
        Must(!isRetriable); // or we should not be consuming
        disableRepeats("consumed content");
        disableBypass("consumed content");
    }
}

