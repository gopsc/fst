


int action_who_is_that(

                          int     that_site,
                          char* buffer_send

                      ) {





    if (

           strcmp ( gop_connection.how [ that_site ], "Connectting") == 0
    ||     strcmp ( gop_connection.how [ that_site ], "Sop"        ) == 0

       ) {



// this is a frendly hello

// and nothing happened







// so we could ask some thing

        if (

               strcmp ( gop_connection.command [ that_site ], "")

               != 0

           ) {



            strcat ( buffer_send, gop_connection.command [ that_site ] );

            strcat ( buffer_send, "." );

            strcpy ( gop_connection.command [ that_site ], "" );}




// if we don't have a message to send

// we send a normal recive

// we change it to hello soon

        else {

            strcat ( buffer_send, "Here." );}




        return 1;}



    else {


        return 0;}}




