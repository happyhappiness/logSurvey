        newReserve = x;
    }

    debugs(51, 0, "Reserved FD adjusted from " << RESERVED_FD << " to " << newReserve << " due to failures");
    RESERVED_FD = newReserve;
}