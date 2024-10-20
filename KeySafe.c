#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

//Variables:
struct {
    char userName[20];
    char pass[20];
    char confirm[20];
    char checkUser [20];
    char checkPass [20];
} userInfo[MAX];

int opt;
unsigned int key = 143; //Could change

//Functions:
void login();
void create();
void xorCrypt();
int check_list();
void init_list();

int main(){
    printf("WELCOME! \nInsert the option you want: \n\n");
    printf(" 1-Login \n 2-Create Account \n 3-Exit \n\n");

    init_list();    //Initializes the list

    do{
        printf("Option: ");
        scanf("%d", &opt);
        switch(opt){
            case 1:
                login();
                break;
            case 2:
                create();
                break;
            case 3:
                printf("Goodbye!");
                break;
            default:
                printf("Invalid operation! Try again: \n");
        }
    } while (opt != 3);

    return 0;
}

void init_list(void){   //Initializes the next blank list
    register int t;

    for(t=0; t<MAX; ++t){
        userInfo[t].userName[0] = '\0';
    }
}

int check_list(){   //Checks if there's space for a new list
    register int t;

    for(t=0; userInfo[t].userName[0] && t<MAX; ++t);

    if(t==MAX) return -1;

    return t;
}

void login(void){
    int i;
    //Checks which account it is (by number)
    scanf("%*c"); //Cleans "\n" (ENTER) off the buffer
    printf("Which user are you? ");
    scanf("%d", &i);
    //Shows user info
    scanf("%*c");
    printf("Username: \n");
    fgets(userInfo[i].checkUser, 20, stdin);
    printf("Password: \n");
    fgets(userInfo[i].checkPass, 20, stdin);
    xorCrypt(userInfo[i].checkPass, key);

    if (strcmp(userInfo[i].checkUser, userInfo[i].userName)==0&&strcmp(userInfo[i].checkPass, userInfo[i].pass)==0){
        printf("Welcome back user %d: %s", i, userInfo[i].userName);
    }
    else{
        printf("Account not found! Try again: \n");
    }
}

void create(void){
    int slot;
    //Checks if there's space for a new list
    slot = check_list();
    if(slot==-1){
        printf("\nList of users is full! Delete an account to create another one!");
        return;
    }
    //New Username
    scanf("%*c");
    printf("Create your new username: \n");
    fgets(userInfo[slot].userName, 20, stdin);
    //New passord
    printf("Now create your new password: \n");
    fgets(userInfo[slot].pass, 20, stdin);
    xorCrypt(userInfo[slot].pass, key); //Encrypts the password
    //Password confitmation
    printf("Confirm your password: \n");
    fgets(userInfo[slot].confirm, 20, stdin);
    xorCrypt(userInfo[slot].confirm, key);  //Encrypts the confirmation

    if(strcmp(userInfo[slot].confirm, userInfo[slot].pass) == 0){ //Checks password
        printf("Your account has been created successfully! \n");
        printf("You are the user: %d\n", slot);
        printf("Try to log in now: \n");
    }

    else{
        printf("ERROR! Try again: \n");
    }
}

void xorCrypt(char *data, int key){ //Simple encryption system

    int siz = strlen (data);

    for(int i=0; i<siz; i++){
        data[i] = data[i] ^ key;
    }
}
