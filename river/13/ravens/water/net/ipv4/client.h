void socket_client::start(){
    file_append("/opt/gop/note/connect.note", info_time);
    file_append("/opt/gop/note/connect.note", "Client start");
    file_append("/opt/gop/note/connect.note", "\n");

    this->fd = socket(AF_INET, SOCK_STREAM, 0);
    this->address_ip = address_to;
    this->port = port_to;

    struct sockaddr_in address;

    char buffer_recv[10240];
    char buffer_send[10240];
    int ptr;

    string msg;

    this->how = "Wait";

    while (flag_client) {
        address.sin_family = AF_INET;
        address.sin_port = htons(this->port);
        address.sin_addr.s_addr = inet_addr(this->address_ip);

        if (connect(this->fd, (struct sockaddr *)&address, sizeof(address)) < 0) {}
        else {
            this->point_time = time(NULL);
            this->information = "";
            if ( this->how == "Wait" ) {
                cout << "Connectting to " << this->address_ip << endl;
                file_append("/opt/gop/note/note/connect.note", info_time);
                file_append("/opt/gop/note/connect.note", "Connectting to ");
                file_append("/opt/gop/note/connect.note", this->address_ip);
                file_append("/opt/gop/note/connect.note", "\n");;

                this->how = "Connectting";}
            recv(this->fd, buffer_recv, sizeof(buffer_recv), 0);

            msg = control_message(&(this->how),         &(gop_server.how),
                                  &(this->information), &(gop_server.information),
                                  &(this->command),     &(gop_server.command),
                                  &(this->update),      &(this->step_update),
                                    buffer_recv);
            if (this->how == "Turn") {
                for ( ptr=0; ptr<msg.length(); ptr++ ) {
                    this->address_ip[ptr] = msg[ptr];}
                this->address_ip[ptr] = '\0';
                this->how = "Wait";}
            else {
                for ( ptr=0; ptr<msg.length(); ptr++ ) {
                    buffer_send[ptr] = msg[ptr];}
                buffer_send[ptr] = '\0';
                send(this->fd, buffer_send, sizeof(buffer_send), 0);}

            close(this->fd);
            this->fd = socket(AF_INET, SOCK_STREAM, 0);}
        sleep(0.1);}
    file_append("/opt/gop/note/connect.note", info_time);
    file_append("/opt/gop/note/connect.note", "Client close");
    file_append("/opt/gop/note/connect.note", "\n");}




