        bp.consume(size);
        virginConsumed += size;
        Must(!isRetriable); // or we should not be consuming
        disableBypass("consumed content");
    }
}

