//g++ ./seed.cpp -lpthread -lasound -std=c++0x -o gopi
//-------------------------------- BOX---------------------------------
#include "./box.cpp"
//----------------------------information------------------------------
#include "./info.cpp"
//--------------------------------mind---------------------------------
#include "./mind.cpp"
//--------------------------------sound--------------------------------
#define  ALSA_PATH "./sound-alsa.c"
#include ALSA_PATH
void* gop_sound(void*){
    sound_alsa();}
//-------------------------------connect-------------------------------
#include "./net.cpp"
void* gop_server(void*){
    gopi_server.build();
    gopi_server.start();}
void* gop_client(void*) {
    gopi_client.start();}
//-------------------------BODY----------------------------------------
int main (){
    pthread_create (&thread[0], NULL, gop_info  , NULL);  while (flag_info != true)     {sleep(1);}
    pthread_create (&thread[1], NULL, gop_sound , NULL);  while (flag_sound == true)    {sleep(1);}
    pthread_create (&thread[2], NULL, gop_server, NULL);  while (gopi_server.how == "") {sleep(1);}
    pthread_create (&thread[3], NULL, gop_client, NULL);  while (gopi_client.how == "") {sleep(1);}

    while(true) {
        sleep(1);}}
