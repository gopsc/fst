
string control_message(int site, string buffer_recv){












    string that;







    if (gop_connect.how[site] == "Connectting"     or      gop_connect.how[site] == "Sop"){

        that = "This is gop station.";
        that += '\n';






        if (buffer_recv.find("This is ") != 0      or      buffer_recv.find('\n') == -1) {

            that += "Who is that?";
            return that;}


        else {





            string that1 = buffer_recv.substr(0, buffer_recv.find('\n'));




            if (that1 != "This is gop station." ) {

                that += "Who is that now?";

                return that;}

            else {




                //This is gop station, send information




                that += information_get();


                for ( int i = 0; i <= 3; i++ ) {
                        that += gop_connect.information[i]; }












                int     that_num1 = buffer_recv.find('\n')+1;
                int     that_num2 = buffer_recv.find('\n', that_num1);
                int     that_num3 = that_num2+1;
                string  that2;
                string  that3;




                if ( that_num2 > -1 ) {
                    that2 = buffer_recv.substr( that_num1, that_num2-that_num1 );}
                else {
                    that2 = buffer_recv.substr( that_num1, buffer_recv.length() );}

                if ( that_num3 > 0 ) {
                    that3 = buffer_recv.substr( that_num3, buffer_recv.length());}










//---------------------------------------------------------

                if (that2 == "Sopi.") {

                    gop_connect.information[site] = "";
                    gop_connect.update[site]      = "";
                    gop_connect.step_update[site] = 0;
                    gop_connect.command[site]     = "";





                    if (gop_connect.how[site] == "Connectting") {

                        gop_connect.how[site] = "Sopi";

                        that += "Who is that now?";
                        return that;}





                    else if (gop_connect.how[site] == "Sop") {

                        gop_connect.how[site] = "Connectted";

                        that += "Who is that now?";
                        return that;}}

//---------------------------------------------------------

                else if ( that2 == "Who is that?"   or  that2 == "Who is that now?" ) {


                    if ( gop_connect.command[site] != "" ) {


                        that += gop_connect.command[site];

                        //cout << that.length() << endl;


                        gop_connect.command[site] = "";}


                    else {
                        that += "Here.";}}

//---------------------------------------------------------

                else if ( that2 == "Smile." ) {

                    cout << "Smile from " << gop_connect.address_ip[site] << endl;

                    gop_connect.address_ip[0] = that3;

                    that += "Recive.";}

//---------------------------------------------------------

                else if ( that2 == "Update." ) {







                    if ( that3 == "Done." ) {

                        update_mix(site);}

                    else {


                        // name,site,length
						// words

                        int    num_file_name    = that3.find(',');
                        int    num_file_site    = that3.find(',', num_file_name+1);
                        int    num_file_length  = that3.find('\n')-1;
						
                        string that_file_site   = that3.substr(num_file_name+1, num_file_site - num_file_name-1);
						
                        string that_file_name   = path_the;
                               that_file_name  += "/gop/downloads/";
                               that_file_name  += that3.substr(0, num_file_name);
                               that_file_name  += '.';
                               that_file_name  += that_file_site;
							   
                        string that_file_length = that3.substr(num_file_site+1, num_file_length-num_file_site-1);
                        string that_file_words  = that3.substr(num_file_length+2, that3.length());





                        if ( atoi(that_file_length.c_str()) == that_file_words.length() ) {

                            cout << that_file_name << endl;

                            file_save(that_file_name, that_file_words);

                            that +=  "Recive.";}



                        else {
                            cout << "file lost." << endl;
                            cout << "Send: " << atoi(that_file_length.c_str()) << endl;
                            cout << "Got : " << that_file_words.length()       << endl;
							
                            that += "Lost.";
                            that += '\n';
                            that += that_file_name;
                            that += '\n';}}}

//---------------------------------------------------------

                else if ( that2.find("Calculate:") == 0 ) {


                    for (int i = 0; i <= 3; i++) {

                        if ( (gop_connect.how[i] == "Connetted" or gop_connect.how[i] == "Sopi")
                          and gop_connect.command[i] == "" and gop_connect.information[i].find(":Free") != 0) {


                            gop_connect.command[i]  = buffer_recv.substr(that_num1, buffer_recv.length());


                            that += "Recive.";
                            return that;}}


							
							
							
							

                    //cout << "Get calculate date, calculate start." << endl;
                    //cout << "length:" << buffer_recv.length() << endl;

                    int that_step = 1;
                    int that_site = 0;


                    while ( that_site != -1 ) {

                        result_sound[that_step] = atoi(that3.substr(that_site+1, that3.find("\n", that_site+1)-that_site-1).c_str());

                        that_site = that3.find("\n", that_site+1);

                        that_step++;}


                    cout << "number: " << that_step << endl;


                    calculate_now = that2;

                    pthread_create(&thread_calculate, NULL, start_calculate, NULL);

                     that += "Start.";}

//---------------------------------------------------------

                else {
                    that =  "WHAT?";
                    cout << endl << that  << buffer_recv  << endl;
                    return that;}}}}










//========================================================

    if ( gop_connect.how[site] == "Connectted" or
         gop_connect.how[site] == "Sopi" ){

        that = "This is gop station.";
        that += '\n';}

//========================================================





    if ( gop_connect.how[site] == "Connectted" or
        gop_connect.how[site] == "Sopi" ){



// SHOW ITSELF


            if ( buffer_recv == "" ) {
                that += "Who is that?";}





            else if (    buffer_recv.find("This is ") != 0
                      or buffer_recv.find('\n') == -1 ) {




                cout << endl << "WHAT?" << endl;
                cout <<    buffer_recv  << endl;
                that += "Who is that now?";}




            else {





// WHO IT IS



                string that3 = buffer_recv.substr(0, buffer_recv.find('\n'));



                if (     that3 != "This is gop station."
                     and that3 != "This is a leaf.") {

                    cout << endl << "What?" << endl;
                    cout <<          that3  << endl;
                    that += "Who is that now?";}

                else {





// Get information

                     if ( buffer_recv.find("-----") != -1 ) {


                        string that4 = buffer_recv.substr( buffer_recv.find("-----"),
                                                           buffer_recv.rfind("-----")+6 -buffer_recv.find("-----"));



                        gop_connect.information[site] = that4;



//                        for (int i=1; i<=point_ip[1]; i++) {

//                            if ( gop_connect.address_ip[site] == info_ip[1][i][2] ) {

//                                gop_connect.information[site] = "";}}


// Get command

                        string that5;

                        try {
                            that5 = buffer_recv.substr( buffer_recv.rfind("-----")+6,
                                                        buffer_recv.length());}
                        catch (...) {}







//-------------------------------------------------------------------------------------

//It means client is ready

                        if ( that5 == "Here." or that5 == "Recive." ) {


                            string that_file;
                            string that_file_length;

//-------------------------------------------------------------------------------------

                            if (gop_connect.command[site].find("Smile") == 0) {

                               that += gop_connect.command[site];

                               gop_connect.command[site]="";}

//-------------------------------------------------------------------------------------



                            else if ( gop_connect.command[site] == "Update." ) {


							    // count_update means times between tow update message

                                if ( count_update < count_update_max ) {
								
                                    that += "Who is that now?";

                                    count_update++;}

                                else {

                                    count_update=0;

                                    that += "Update.";



                                    if ( gop_connect.update[site] == "" ) {

                                        if ( control_update(&(gop_connect.update[site])) == "Done.") {

                                            cout << "THERE IS NO GOP SOURCE." << endl;
											
                                            that += '\n';
                                            that += "Who is that now?";
											
                                            gop_connect.command[site] = "";
											
                                            return that;}}


                                    that_file        = file_get(gop_connect.update[site]);
                                    that_file_length = to_string(that_file.length());


                                    if ( gop_connect.step_update[site]*size_update > that_file.length() ) {

                                        if ( control_update(&(gop_connect.update[site])) == "Done.") {

                                            cout << "Done" << endl;

                                            gop_connect.step_update[site] = 0;
                                            gop_connect.command[site] = "";

                                            that += '\n';
                                            that += "Done.";

                                            return that;}

                                        else {
                                            gop_connect.step_update[site] = 0;}}


                                    that_file        = file_get(gop_connect.update[site]);
                                    that_file_length = to_string(that_file.length());

                                    // show file name if it have not begin
                                    if ( gop_connect.step_update[site] == 0) {
                                        cout << gop_connect.update[site] << endl;
                                        cout << "    send size : ";
                                        cout << that_file.length() << endl;}


                                    that += '\n';
                                    that += (gop_connect.update[site]).substr(gop_connect.update[site].find(name_the), (gop_connect.update[site]).length());
                                    that += ',';
                                    that += to_string(gop_connect.step_update[site]);
                                    that += ',';



                                    if ( (gop_connect.step_update[site]+1)*size_update > atoi(that_file_length.c_str()) ) {
                                        that += to_string(atoi(that_file_length.c_str())
                                             -  (gop_connect.step_update[site])*size_update);}

                                    else {

                                        that += to_string(size_update);}

                                    that += '.';
                                    that += '\n';

                                    that += that_file.substr((gop_connect.step_update[site])*size_update, size_update);
                                    (gop_connect.step_update[site])++;}}





//-------------------------------------------------------------------------------------

                            else if ( (gop_connect.information[site].find(":Free") != -1
                                and    gop_connect.information[site] != "") 
                                and    gop_connect.command[site] == "") {




                                string result_that = control_calculate_sound(gop_connect.information[site]);



                                if ( result_that == "Wait" ) {
                                    that += "Who is that now?";}
                                else {
                                    that += "Calculate:";
                                    that += result_that;
                                    //cout << that.length() << endl;
                                    }}

//-------------------------------------------------------------------------------------

                            else {
                                gop_connect.command[site] = "";
                                that += "Who is that now?";}}





//-------------------------------------------------------------------------------------






                        else if ( that5 == "Sopi." ) {


                            gop_connect.information[site] = "";
                            gop_connect.command[site] = "";
                            gop_connect.update[site] = "";
                            gop_connect.step_update[site] = 0;



                            for ( int i=0; i<=3; i++ ) {

                                if ( gop_connect.how[i] == "Connectting" or gop_connect.how[i] == "Sop" ) {
                                    gop_connect.command[i] = "Sopi.";}}



                            if (gop_connect.how[site] == "Connectted") {
                                gop_connect.how[site] = "Sop";}

                            else if (gop_connect.how[site] == "Sopi") {
                                gop_connect.how[site] = "Connectting";}



                            that += "Sopi.";}

//-------------------------------------------------------------------------------------

                        else if ( that5 == "Start." ) {

                            that += "Who is that now?";}

//-------------------------------------------------------------------------------------

                        else if ( that5.find("Calculate:") == 0 ) {

                            //cout << that5.substr(10, that5.find("\n")-10) << endl;
                            //cout << buffer_recv.length() << endl;

                            file_save(that5.substr(10, that5.find("\n")-10), that5.substr(that5.find("\n")+1, that5.length()));

                            int that_step = 1;
                            int that_site = that5.find("\n");


                            while ( that_site != -1 ) {

                                result_ft[that_step] = atoi(that5.substr(that_site+1, that5.find("\n", that_site+1)-that_site-1).c_str());

                                that_site = that5.find("\n", that_site+1);

                                that_step++;}

				ft_show();

                            that += "Who is that now?";}

//-------------------------------------------------------------------------------------

                        else {
                            that += "Who is that now?";}}

//-------------------------------------------------------------------------------------

                    else {
                        that += "Who is that now?";}}}}

    return that;}
