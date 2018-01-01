
void fft() {


//    double what[1000000];
    double mo;
    double t;

    double buffer_fft[65][65][3];

    for ( double round=1; round<=64; round++ ) {

        for ( double w=1; w<=64; w++ ) {

            buffer_fft[(int)round][(int)w][1] = 0;
            buffer_fft[(int)round][(int)w][2] = 0;

            for ( double n=round; n<=N; n=n+64 ) {

                t = (n-round)/N;
                buffer_fft[(int)round][(int)w][1] += (result_sound[(int)n]*cos(2*M_PI*(double)w*t));
                buffer_fft[(int)round][(int)w][2] -= (result_sound[(int)n]*sin(2*M_PI*(double)w*t));}}}






   //       result_sound[(int)n] * cos(2*M_PI*w/N * (n-round+round))

   //     = result_sound[(int)n] * cos(2*M_PI*w/N*(n-round)) * cos(2*M_PI*(double)w/N*round)
   //     - result_sound[(int)n] * sin(2*M_PI*w/N*(n-round)) * sin(2*M_PI*(double)w/N*round)



    double bin_fft[N/2][2];

    for ( double w=1; w<=N/2; w++ ) {

        bin_fft[(int)w][1] = 0;
        bin_fft[(int)w][2] = 0;
        for ( double round=1; round<=64; round++ ){



            bin_fft[(int)w][1]

        += (buffer_fft[(int)round][(int)w%64][1] * cos(2*M_PI*w*round/N)
           +buffer_fft[(int)round][(int)w%64][2] * sin(2*M_PI*w*round/N));



            bin_fft[(int)w][2]

        -= (buffer_fft[(int)round][(int)w%64][2] * cos(2*M_PI*w*round/N)
           -buffer_fft[(int)round][(int)w%64][1] * sin(2*M_PI*w*round/N));}




        mo = sqrt(bin_fft[(int)w][1]*bin_fft[(int)w][1] + bin_fft[(int)w][2]*bin_fft[(int)w][2]);
        mo = mo/(N/2);

        if (mo >= 1) {
            cout << w << ":" << mo << endl;}}}
