#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Variables:
typedef struct {
    char userName[20];
    char pass[20];
    char confirm[20];
    char checkUser [20];
    char checkPass [20];
} userInfo;

userInfo p;
int opt;
unsigned int key = 143; //Could change

//Functions:
void login();
void create();
void xorCrypt();

int main(){

    printf("WELCOME! \nInsert the option you want: \n\n");
    printf(" 1-Login \n 2-Create Account \n 3-Exit \n\n");

    do{
        printf("Option: ");
        scanf("%d", &opt);
        switch(opt){

            case 1: login(); break;
            case 2: create(); break;
            case 3: printf("Goodbye!"); break;

            default: printf("Invalid operation! Try again: \n");
        }
    } while (opt != 3);

    return 0;
}

void login(void){

    scanf("%*c"); //Cleans "\n" (ENTER) off the buffer
    printf("Username: \n");
    fgets(p.checkUser, 20, stdin);
    printf("Password: \n");
    fgets(p.checkPass, 20, stdin);
    xorCrypt(p.checkPass, key);

    if (strcmp(p.checkUser, p.userName)==0&&strcmp(p.checkPass, p.pass)==0){
        printf("Welcome back %s", p.userName);
    }
    else{
        printf("Account not found! Try again: \n");
    }
}

void create(void){

    scanf("%*c");
    printf("Create your new username: \n");
    fgets(p.userName, 20, stdin);
    printf("Now create your new password: \n");
    fgets(p.pass, 20, stdin);
    xorCrypt(p.pass, key);
    printf("Confirm your password: \n");
    fgets(p.confirm, 20, stdin);
    xorCrypt(p.confirm, key);

    if(strcmp(p.confirm, p.pass) == 0){
        printf("Your account has been created successfully! \n");
        printf("Try to log in now: \n");
    }

    else{
        printf("ERROR! Try again: \n");
    }
}

void xorCrypt(char *data, int key){

    int siz = strlen (data);

    for(int i=0; i<siz; i++){
        data[i] = data[i] ^ key;
    }
}
