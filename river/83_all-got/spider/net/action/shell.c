



 int action_shell (

                    char * that_command

                  )

  {




 char buffer_command [ 64 ];




 if  (
       strstr ( that_command, "Shell " )  !=  NULL
     )

  {




 strcpy ( buffer_command, "bash " );

 strcat ( buffer_command, gop_hope . path_the );

 strcat ( buffer_command, "/" );

 strcat ( buffer_command, gop_hope . name_the );

 strcat ( buffer_command, "/things/shell/" );

 strcat (
          buffer_command,
          strstr ( that_command, "Shell " ) + 6
        );



  }





/*

 mabe i should use command get

*/


 if (
      0 != strcmp ( buffer_command, "" )
    )


  {


 system ( buffer_command );


 return 0;


  }





 else


  {

 return -1;

  }
