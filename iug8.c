#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[]){

        int a;
        int conecta;

        int porta;
        int inicio = 78;
        int final = 65535;
        char *destino;
        destino = argv[1];
        
        struct sockaddr_in alvo;

       for(porta=inicio;porta<final;porta++){

        a = socket(AF_INET,SOCK_STREAM,0);
        alvo.sin_family = AF_INET;
        alvo.sin_port = htons(21);
        alvo.sin_addr.s_addr = inet_addr(destino);

        conecta = connect(a, (struct sockaddr *)&alvo, sizeof alvo);
        
        if(conecta == 0){
                printf("fucking server, requesting... \n",porta);
               // close(a);
               // close(conecta);
        } else {
                //printf("fechada %d",porta);
                close(a);
                close(conecta);
        }
        }
}
