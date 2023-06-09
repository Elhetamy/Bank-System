/**
 * @author Abdelrahman Mohamed Elhetamy
 * @file BankingSystem.h
 * @project Bank System
 * @date 07 June 2023
 */

#ifndef BANKINGSYSTEM_H_
#define BANKINGSYSTEM_H_

#define ADMIN_SIZE		2		//Macro to define the array of struct admins size
/**
 * A nested structs had been implemented to contain the client data and have a pointer to itself to link it with other nodes in our database
 */
typedef struct client
{
	struct details
	{
		char client_ID;
		char client_password;
		char client_name[20];
		int client_budget;
	}details;
	struct client * Link;
}Client_t;
/**
 * A struct which hold the admins data 
 */
typedef struct
{
	short unsigned int Admin_ID;
	short unsigned int Admin_Password;
}Admin_t;

	/***********************************FUNCTIONS PROTOTYPE************************/
/*Clien Functions*/
Client_t* CreateClientList(void);
char ValidateClient(Client_t* Start,char ClientID,char ClientPassword);
void PrintClientDetails(Client_t* Start,char ClientID,char ClientPassword);

/*Admin Functions*/
char ValidateAdmin(short unsigned int AdminID,short unsigned int AdminPassword);
void PrintClientDetailsAdmin(Client_t* Start,char cn[]);
Client_t* EditClientDetailsAdmin(Client_t* Start,char cn[],char NewID,char NewPassword);
Client_t* AddClient(Client_t *Start);
Client_t* DeleteClient(Client_t* Start,char cn[],char ClientID);

#endif