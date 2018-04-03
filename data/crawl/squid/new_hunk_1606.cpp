
    if (ping && i) {
        ping_mean = ping_sum / i;
        std::cerr << i << " requests, round-trip (secs) min/avg/max = "
                  << (ping_min/1000) << "." << (ping_min%1000)
                  << "/" << (ping_mean/1000) << "." << (ping_mean%1000)
                  << "/" << (ping_max/1000) << "." << (ping_max%1000)
                  << std::endl;
    }
    return 0;
}
