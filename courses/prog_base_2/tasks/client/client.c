#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>


char * convert(char * hostname){
    char *ip=malloc(sizeof(char)*100);
    struct hostent *he;
    struct in_addr **addr_list;
    
    he = gethostbyname(hostname);
    if (he == NULL) {
        printf("%s\n", "--- Get host by name failed.");
        return NULL;
    }
    
    addr_list = (struct in_addr**) he->h_addr_list;
    
    for (int i = 0; addr_list[i] != NULL; i++) {
        strcpy(ip, inet_ntoa(*addr_list[i]));
    }
    
    printf("%s resloved to %s\n", hostname, ip);
    
    return ip;
}

int init(){
    struct sockaddr_in server;
    // Create socket
    int socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    printf("%s\n", (socket_desc == -1) ? "Socket cannot be created." : "Socket created.");
    
    //server.sin_addr.s_addr = inet_addr("93.73.1.110");
    
    server.sin_addr.s_addr = inet_addr(convert("pb-homework.appspot.com")); // google.com
    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    
    // Connect to a remote server
    int connection_result = connect(socket_desc, (struct sockaddr *)&server, sizeof(server));
    printf("%s\n", (connection_result < 0) ? "Connection error." : "Connected.");
    return socket_desc;
}

void receive_message(char* server_reply, int socket_desc){              // Receive a reply from the server
    bzero(server_reply, 2000);
    long int reply_result = recv(socket_desc, server_reply, 2000, 0);
    printf("%s\n", (reply_result < 0) ? "Reply error." : "Data received.");
    printf("%s\r\n", server_reply);
}

void send_message(int socket_desc, char * message){                         // Send some data
    long int send_result = send(socket_desc, message, strlen(message), 0);
    printf("%s\n", (send_result < 0) ? "Send error." : "Data sent.");
}

int count_result(char* server_reply){
    int result=0;
    char *vowel = "euoaiyEYUOIA";
    char *res_str = strstr(server_reply, "\r\n\r\n");
    if (res_str == NULL) {
        printf("NULL\n");
    }
    for(int i=3; i<strlen(res_str); i++){
        if ( res_str[i]==' ' || res_str[i]=='\n'){
            if (strrchr(vowel, res_str[i+1]) == NULL)
                result++;
        }
    }
    return result;
}

int main () {
    int socket_desc = init();
    
    
    char *message = "GET /var/14 HTTP/1.1\r\nHost:pb-homework.appspot.com\r\n\r\n";
    send_message(socket_desc, message);
    
    
    char server_reply[2000];
    receive_message(server_reply, socket_desc);
   
    
    char *secret_ptr = strstr(server_reply, "secret=");
    char *message2=malloc(sizeof(char)*100);
    sprintf(message2, "GET /var/14?%s HTTP/1.1\r\nHost:pb-homework.appspot.com\r\n\r\n", secret_ptr);
    message=message2;
    
    send_message(socket_desc, message);
    receive_message(server_reply, socket_desc);
    
    
    int result = count_result(server_reply);
    
    char *message3=malloc(sizeof(char)*100);
    sprintf(message3, "POST /var/14 HTTP/1.1\r\nHost:pb-homework.appspot.com\r\nContent-length: 8\r\n\r\nresult=%d", result);
    message=message3;
    
    
    send_message(socket_desc, message);
    receive_message(server_reply, socket_desc);
    
    close(socket_desc);
}
