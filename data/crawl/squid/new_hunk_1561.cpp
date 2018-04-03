    fprintf(debug_log, "\tTotal free:            %6d KB %d%%\n",
            (int) (ms.bytes_free >> 10),
            Math::intPercent(ms.bytes_free, ms.bytes_total));
#endif
}

void
