
void gop_delay(float time_s) {
    struct timeval delay;
                   delay.tv_sec  = 0;
                   delay.tv_usec = time_s * 1000 * 1000;
    select(0, NULL, NULL, NULL, &delay);}
