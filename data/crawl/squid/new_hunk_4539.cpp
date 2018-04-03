        newReserve = x;
    }

    if (Squid_MaxFD - newReserve < XMIN(256, Squid_MaxFD / 2))
	fatalf("Too few filedescriptors available in the system (%d usable of %d).\n", Squid_MaxFD - newReserve, Squid_MaxFD);

    debugs(51, 0, "Reserved FD adjusted from " << RESERVED_FD << " to " << newReserve << " due to failures");
    RESERVED_FD = newReserve;
}