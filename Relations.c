#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct PNB *PNBList;

struct PNB{
int playerId;
char Name[30];
char birthDate[12];
PNBList next;
};

typedef PNBList PNBHashTable[1009];

bool equal_PNB(PNBList pnb1, PNBList pnb2){
    if(strcmp(pnb1->Name,pnb2->Name)==0 && pnb1->playerId==pnb2->playerId && 
       strcmp(pnb1->birthDate,pnb2->birthDate)==0){
        return true;
    }
    return false;
}

PNBList new_PNB(int ID, char* Name, char* birthDate){
    PNBList PNB = (PNBList)malloc(sizeof(struct PNB));
    PNB->playerId = ID;
    strcpy(PNB->Name, Name);
    strcpy(PNB->birthDate, birthDate);
    PNB->next = NULL;
    return PNB;
}
void print_PNB(PNBList pnb){
    if (pnb != NULL){
        printf("(%d, %s, %s) ", pnb->playerId, pnb->Name, pnb->birthDate);
    }
}

void print_PNBTable(PNBHashTable* pnbt){
    // printf("PNB Table: \n");
    for(int i = 0; i < 1009; i++){
        PNBList* position = pnbt[i];
        while((*position) != NULL){
            print_PNB(*position);
            printf("\n");
            position = &(*position)->next;
        }
    }
    printf("\n");
}

typedef struct TPN *TPNList;
struct TPN {
    char Team[31];
    int playerId;
    int number;
    TPNList next;
};
typedef TPNList TPNHashTable[1009];

bool equal_TPN(TPNList tpn1, TPNList tpn2){
    if(strcmp(tpn1->Team,tpn2->Team)==0 && tpn1->playerId==tpn2->playerId 
    && tpn1->number==tpn2->number){
        return true;
    }
    return false;
}

TPNList new_TPN(char* team, int ID, int number){
    TPNList TPN = (TPNList)malloc(sizeof(struct TPN));
    strcpy(TPN->Team, team);
    TPN->playerId = ID;
    TPN->number = number;
    TPN->next = NULL;
    return TPN;
}

void print_TPN(TPNList tpn){
    if (tpn != NULL){
        printf("(%s, %d, %d) ", tpn->Team, tpn->playerId, tpn->number);
    }
}

void print_TPNTable(TPNHashTable* tpnt){
    // printf("TPN Table: \n");
    for(int i = 0; i < 1009; i++){
        TPNList* position = tpnt[i];
        while((*position) != NULL){
            print_TPN(*position);
            printf("\n");
            position = &(*position)->next;
        }
    }
    printf("\n");
}

typedef struct TC *TCList;
struct TC {
    char Team[40];
    char city[40];
    TCList next;
};
typedef TCList TCHashTable[1009];

bool equal_TC(TCList tc1, TCList tc2){
    if(strcmp(tc1->Team, tc2->Team)==0 && strcmp(tc1->city, tc2->city)==0){
        return true;
    }
    return false;
}

TCList new_TC(char* team, char* city){
    TCList TC = (TCList)malloc(sizeof(struct TC));
    strcpy(TC->Team, team);
    strcpy(TC->city, city);
    TC->next = NULL;
    return TC;
}

void print_TC(TCList tc){
    if (tc != NULL){
        printf("(%s, %s) ", tc->Team, tc->city);
    }
}

void print_TCTable(TCHashTable* tct){
    // printf("TC Table: \n");
    for(int i = 0; i < 1009; i++){
        TCList* position = tct[i];
        while((*position) != NULL){
            print_TC(*position);
            printf("\n");
            position = &(*position)->next;
        }
    }
    printf("\n");
}

typedef struct GHVD *GHVDList;
struct GHVD {
    int gameId;
    char homeTeam[31];
    char visitorTeam[31];
    char date[31];
    GHVDList next;
};
typedef GHVDList GHVDHashTable[1009];

bool equal_GHVD(GHVDList ghvd1, GHVDList ghvd2){
    if(ghvd1->gameId == ghvd2->gameId && strcmp(ghvd1->homeTeam,ghvd2->homeTeam)==0 
    && strcmp(ghvd1->visitorTeam,ghvd2->visitorTeam)==0 && strcmp(ghvd1->date,ghvd2->date)==0){
        return true;
    }
    return false;
}

GHVDList new_GHVD(int ID, char* hometeam, char* visitorteam, char* date){
    GHVDList GHVD = (GHVDList)malloc(sizeof(struct GHVD));
    GHVD->gameId = ID;
    strcpy(GHVD->homeTeam, hometeam);
    strcpy(GHVD->visitorTeam, visitorteam);
    strcpy(GHVD->date, date);
    GHVD->next = NULL;
    return GHVD;
}

void print_GHVD(GHVDList ghvd){
    if (ghvd != NULL){
        printf("(%d, %s, %s, %s) ", ghvd->gameId, ghvd->homeTeam, ghvd->visitorTeam, ghvd->date);
    }
}

void print_GHVDTable(GHVDHashTable* ghvdt){
    for(int i = 0; i < 1009; i++){
        GHVDList* position = ghvdt[i];
        while((*position) != NULL){
            print_GHVD(*position);
            printf("\n");
            position = &(*position)->next;
        }
    }
    printf("\n");
}

typedef struct GPG *GPGList;
struct GPG {
    int gameId;
    int playerId;
    int goals;
    GPGList next;
};
typedef GPGList GPGHashTable[1009];

bool equal_GPG(GPGList gpg1, GPGList gpg2){
    if(gpg1->gameId == gpg2->gameId && gpg1->playerId == gpg2->playerId && gpg1->goals == gpg2->goals){
        return true;
    }
    return false;
}

GPGList new_GPG(int gameid, int playerid, int goals){
    GPGList gpg = (GPGList)malloc(sizeof(struct GPG));
    gpg->gameId = gameid;
    gpg->playerId = playerid;
    gpg->goals = goals;
    gpg->next = NULL;
    return gpg;
}

void print_GPG(GPGList gpg){
    if (gpg != NULL){
        printf("(%d, %d, %d) ", gpg->gameId, gpg->playerId, gpg->goals);
    }
}

void print_GPGTable(GPGHashTable* gpgt){
    for(int i = 0; i < 1009; i++){
        GPGList* position = gpgt[i];
        while((*position) != NULL){
            print_GPG(*position);
            printf("\n");
            position = &(*position)->next;
        }
    }
    printf("\n");
}

int hashing_char(char* key) {
    int sum = 0;
    char* t;
    for (t = key; *t != '\0'; t++) {
        sum *= 10;
        sum += *t - '0';
    }
    int res = abs(sum % 1009);
    return res;
}

int hashing_num(int key){
    return key % 1009;
}

PNBHashTable* new_PNBTable(){
    PNBHashTable * table = (PNBHashTable*)malloc(sizeof(PNBHashTable));
    for(int i=0;i<1009;i++){
        PNBList * index = table[i];
        (*index)=NULL;
    }
    return table;
}

TPNHashTable* new_TPNTable(){
    TPNHashTable * table = (TPNHashTable*)malloc(sizeof(TPNHashTable));
    for(int i=0;i<1009;i++){
        TPNList * index = table[i];
        (*index)=NULL;
    }
    return table;
}

TCHashTable* new_TCTable(){
    TCHashTable * table = (TCHashTable*)malloc(sizeof(TCHashTable));
    for(int i=0;i<1009;i++){
        TCList * index = table[i];
        (*index)=NULL;
    }
    return table;
}

GHVDHashTable* new_GHVDTable(){
    GHVDHashTable * table = (GHVDHashTable*)malloc(sizeof(GHVDHashTable));
    for(int i=0;i<1009;i++){
        GHVDList * index = table[i];
        (*index)=NULL;
    }
    return table;
}

GPGHashTable* new_GPGTable(){
    GPGHashTable * table = (GPGHashTable*)malloc(sizeof(GPGHashTable));
    for(int i=0;i<1009;i++){
        GPGList * index = table[i];
        (*index)=NULL;
    }
    return table;
}

PNBHashTable* insert_PNB(PNBList pnb, PNBHashTable* PNBHashTable){
    int index = hashing_num(pnb->playerId);
    PNBList* position =PNBHashTable[index];
    while((*position) != NULL){
        if(equal_PNB(pnb, (*position))){
            printf("PNB tuple :");
            print_PNB(pnb);
            printf(" already exists\n");
            return PNBHashTable;
        }else{
            position=&(*position)->next;
        }
    }
    *position = pnb;
    return PNBHashTable;
}

TPNHashTable* insert_TPN(TPNList tpn, TPNHashTable* TPNHashTable){
    int index = hashing_num(tpn->playerId);
    TPNList* position =TPNHashTable[index];
    while((*position) != NULL){
        if(equal_TPN(tpn, (*position))){
            printf("TPN tuple :");
            print_TPN(tpn);
            printf(" already exists\n");
            return TPNHashTable;
        }else{
            position=&(*position)->next;
        }
    }
    *position = tpn;
    return TPNHashTable;
}

TCHashTable* insert_TC(TCList tc, TCHashTable* TCHashTable){
    int index = hashing_char(tc->city);
    TCList* position = TCHashTable[index];
    while((*position) != NULL){
        if(equal_TC(tc, (*position))){
            printf("TC tuple :");
            print_TC(tc);
            printf(" already exists\n");
            return TCHashTable;
        }else{
            position=&(*position)->next;
        }
    }
    *position = tc;
    return TCHashTable;
}

GHVDHashTable* insert_GHVD(GHVDList ghvd, GHVDHashTable* GHVDHashTable){
    int index = hashing_num(ghvd->gameId);
    GHVDList* position =GHVDHashTable[index];
    while((*position) != NULL){
        if(equal_GHVD(ghvd, (*position))){
            printf("GHVD tuple :");
            print_GHVD(ghvd);
            printf(" already exists\n");
            return GHVDHashTable;
        }else{
            position=&(*position)->next;
        }
    }
    *position = ghvd;
    return GHVDHashTable;
}

GPGHashTable* insert_GPG(GPGList gpg, GPGHashTable* GPGHashTable){
    int index = hashing_num(gpg->playerId);
    GPGList* position =GPGHashTable[index];
    while((*position) != NULL){
        if(equal_GPG(gpg, (*position))){
            printf("GPG tuple :");
            print_GPG(gpg);
            printf(" already exists\n");
            return GPGHashTable;
        }else{
            position=&(*position)->next;
        }
    }
    *position = gpg;
    return GPGHashTable;
}

PNBHashTable* delete_PNB(int playerid, char* name, char* birthdate, PNBHashTable* table){
    bool checkID=true;
    if(playerid==-1){checkID=false;}
    bool checkName=true;
    if(*name == '*'){checkName=false;}
    bool checkBirthDate=true;
    if(*birthdate == '*'){checkBirthDate=false;}
    if(checkID){
        int index = hashing_num(playerid);
        PNBList* position =table[index];
        while((*position) != NULL){
            if(playerid == (*position)->playerId && (checkName==false || strcmp(name, (*position)->Name)==0)
            &&(checkBirthDate==false || strcmp(birthdate, (*position)->birthDate)==0)){
                *position = (*position)->next;
            }else{
                position=&(*position)->next;
            }
        }
        return table;
    }else{
        for(int i=0; i< 1009; i++){
            PNBList* position =table[i];
            while((*position) != NULL){
                if((checkName==false || strcmp(name, (*position)->Name)==0)
                && (checkBirthDate==false || strcmp(birthdate, (*position)->birthDate)==0)){
                   *position = (*position)->next;
                }else{
                    position=&(*position)->next;
                }
            }
        }
        return table;
    }
}

TPNHashTable* delete_TPN(char* team, int playerid, int number, TPNHashTable* table){
    bool checkTeam=true;
    if(*team == '*'){checkTeam=false;}
    bool checkID=true;
    if(playerid==-1){checkID=false;}
    bool checkNumber=true;
    if(number==-1){checkNumber=false;}
    if(checkID){
        int index = hashing_num(playerid);
        TPNList* position =table[index];
        while((*position) != NULL){
            if(playerid == (*position)->playerId && (checkTeam==false || strcmp(team, (*position)->Team)==0)
            &&(checkNumber==false || number == (*position)->number)){
                *position = (*position)->next;
            }else{
                position=&(*position)->next;
            }
        }
        
        return table;
    }else{
        for(int i=0; i< 1009; i++){
            TPNList* position =table[i];
            while((*position) != NULL){
                if((checkTeam==false || strcmp(team, (*position)->Team)==0)
                && (checkNumber==false || number == (*position)->number)){
                   *position = (*position)->next;
                }else{
                    position=&(*position)->next;
                }
            }
        }
        return table;
    }
}

TCHashTable* delete_TC(char* team, char* city, TCHashTable* table){
    bool checkTeam=true;
    if(*team == '*'){checkTeam=false;}
    bool checkCity=true;
    if(*city== '*'){checkCity=false;}
    if(checkCity){
        int index = hashing_char(city);
        TCList* position =table[index];
        while((*position) != NULL){
            if(strcmp(city, (*position)->city) == 0 && (checkTeam==false || strcmp(team, (*position)->Team)==0)){
                *position = (*position)->next;
            }else{
                position=&(*position)->next;
            }
        }
        return table;
    }else{
        for(int i=0; i< 1009; i++){
            TCList* position =table[i];
            while((*position) != NULL){
                if((checkTeam==false || strcmp(team, (*position)->Team)==0)){
                   *position = (*position)->next;
                }else{
                    position=&(*position)->next;
                }
            }
        }
        return table;
    }
}

GHVDHashTable* delete_GHVD(int gameid, char* hometeam, char* visitorteam, char* date, GHVDHashTable* table){
    bool checkID = true;
    if(gameid == -1){checkID = false;}
    bool checkHome=true;
    if(*hometeam == '*'){checkHome=false;}
    bool checkVisitor=true;
    if(*visitorteam== '*'){checkVisitor=false;}
    bool checkDate = true;
    if(*date == '*'){checkDate = false;}
    if(checkID){
        int index = hashing_num(gameid);
        GHVDList* position =table[index];
        while((*position) != NULL){
            if(gameid == (*position)->gameId && (checkHome==false || strcmp(hometeam, (*position)->homeTeam)==0)&&
            (checkVisitor == false || strcmp(visitorteam, (*position)->visitorTeam) ==0) &&
            (checkDate == false || strcmp(date, (*position)->date) == 0)){
                *position = (*position)->next;
            }else{
                position=&(*position)->next;
            }
        }
        return table;
    }else{
        for(int i=0; i< 1009; i++){
            GHVDList* position =table[i];
            while((*position) != NULL){
                if((checkHome==false || strcmp(hometeam, (*position)->homeTeam)==0)&&
                  (checkVisitor == false || strcmp(visitorteam, (*position)->visitorTeam) ==0) &&
                  (checkDate == false || strcmp(date, (*position)->date) == 0)){
                   *position = (*position)->next;
                }else{
                    position=&(*position)->next;
                }
            }
        }
        return table;
    }
}

GPGHashTable* delete_GPG(int gameid, int playerid, int goals, GPGHashTable* table){
    bool checkGameID = true;
    if(gameid == -1){checkGameID = false;}
    bool checkPlayerID = true;
    if(playerid == -1){checkPlayerID = false;}
    bool checkGoals = true;
    if(goals == -1){checkGoals = false;}

    if(checkPlayerID){
        int index = hashing_num(playerid);
        GPGList* position =table[index];
        while((*position) != NULL){
            if(playerid == (*position)->playerId && (checkGameID==false || gameid == (*position)->gameId) &&
            (checkGoals == false || goals == (*position)->goals)){
                *position = (*position)->next;
            }else{
                position=&(*position)->next;
            }
        }
        return table;
    }else{
        for(int i=0; i< 1009; i++){
            GPGList* position =table[i];
            while((*position) != NULL){
                if((checkGameID==false || gameid == (*position)->gameId) &&
                   (checkGoals == false || goals == (*position)->goals)){
                   *position = (*position)->next;
                }else{
                    position=&(*position)->next;
                }
            }
        }
        return table;
    }
}

PNBHashTable* lookup_PNB(int playerid, char* name, char*birthdate, PNBHashTable* table){
    PNBHashTable* result = new_PNBTable();
    bool checkID=true;
    if(playerid==-1){checkID=false;}
    bool checkName=true;
    if(*name == '*'){checkName=false;}
    bool checkBirthDate=true;
    if(*birthdate == '*'){checkBirthDate=false;}

    if(checkID){
        int index = hashing_num(playerid);
        PNBList* position =table[index];
        while((*position) != NULL){
            //check if the current tuple is what we are looking for
            if(playerid == (*position)->playerId && (checkName==false || strcmp(name, (*position)->Name)==0)
            &&(checkBirthDate==false || strcmp(birthdate, (*position)->birthDate)==0)){
                PNBList temp= new_PNB((*position)->playerId, (*position)->Name, (*position)->birthDate);
                temp->next = NULL;
                insert_PNB(temp, result);
                position=&(*position)->next;
            }else{
                position=&(*position)->next;
            }
        }
        return result;
    }else{
        for(int i=0; i< 1009; i++){
            PNBList* position =table[i];
            while((*position) != NULL){
                if((checkName==false || strcmp(name, (*position)->Name)==0)
                  &&(checkBirthDate==false || strcmp(birthdate, (*position)->birthDate)==0)){
                PNBList temp= new_PNB((*position)->playerId, (*position)->Name, (*position)->birthDate);
                    temp->next=NULL;
                    insert_PNB(temp, result);
                    position=&(*position)->next;
                }else{
                    position=&(*position)->next;
                }
            }
        }
        return result;
    }
}

TPNHashTable* lookup_TPN(char* team, int playerid, int number, TPNHashTable* table){
    TPNHashTable* result = new_TPNTable();
    bool checkTeam=true;
    if(*team == '*'){checkTeam=false;}
    bool checkID=true;
    if(playerid==-1){checkID=false;}
    bool checkNumber=true;
    if(number == -1){checkNumber=false;}

    if(checkID){
        int index = hashing_num(playerid);
        TPNList* position =table[index];
        while((*position) != NULL){
            if(playerid == (*position)->playerId && (checkTeam==false || strcmp(team, (*position)->Team)==0)
            && (checkNumber==false || number == (*position)->number)){
                TPNList temp= new_TPN((*position)->Team, (*position)->playerId, (*position)->number);
                temp->next = NULL;
                insert_TPN(temp, result);
                position=&(*position)->next;
            }else{
                position=&(*position)->next;
            }
        }
        return result;
    }else{
        for(int i=0; i< 1009; i++){
            TPNList* position =table[i];
            while((*position) != NULL){
                if((checkTeam==false || strcmp(team, (*position)->Team)==0)
                  &&(checkNumber==false || number == (*position)->number)){
                TPNList temp= new_TPN((*position)->Team, (*position)->playerId, (*position)->number);
                    temp->next=NULL;
                    insert_TPN(temp, result);
                    position=&(*position)->next;
                }else{
                    position=&(*position)->next;
                }
            }
        }
        return result;
    }
}

TCHashTable* lookup_TC(char* team, char* city, TCHashTable* table){
    int test = 0;
    TCHashTable* result = new_TCTable();
    bool checkTeam=true;
    if(*team == '*'){checkTeam=false;}
    bool checkCity=true;
    if(*city== '*'){checkCity=false;}

    if(checkCity){
        int index = hashing_char(city);
        TCList* position =table[index];
        while((*position) != NULL){
            if(strcmp(city, (*position)->city) == 0 && (checkTeam==false || strcmp(team, (*position)->Team)==0)){
                TCList temp= new_TC((*position)->Team, (*position)->city);
                temp->next = NULL;
                insert_TC(temp, result);
                test += 1;
                position=&(*position)->next;
            }else{
                position=&(*position)->next;
            }
        }
        if(test == 0){
            printf("No match was found\n");
        }
        return result;
    }else{
        for(int i=0; i< 1009; i++){
            TCList* position =table[i];
            while((*position) != NULL){
                if((checkTeam==false || strcmp(team, (*position)->Team)==0)){
                TCList temp= new_TC((*position)->Team, (*position)->city);
                    temp->next=NULL;
                    insert_TC(temp, result);
                    test +=1;
                    position=&(*position)->next;
                }else{
                    position=&(*position)->next;
                }
            }
        }
        if(test == 0){
            printf("No match was found\n");
        }
        return result;
    }
}

GHVDHashTable* lookup_GHVD(int gameid, char* hometeam, char* visitorteam, char* date, GHVDHashTable* table){
    GHVDHashTable* result = new_GHVDTable();
    bool checkID = true;
    if(gameid == -1){checkID = false;}
    bool checkHome=true;
    if(*hometeam == '*'){checkHome=false;}
    bool checkVisitor=true;
    if(*visitorteam== '*'){checkVisitor=false;}
    bool checkDate = true;
    if(*date == '*'){checkDate = false;}

    if(checkID){
        int index = hashing_num(gameid);
        GHVDList* position =table[index];
        while((*position) != NULL){
            if(gameid == (*position)->gameId && (checkHome==false || strcmp(hometeam, (*position)->homeTeam)==0)&&
            (checkVisitor == false || strcmp(visitorteam, (*position)->visitorTeam) ==0) &&
            (checkDate == false || strcmp(date, (*position)->date) == 0)){
                GHVDList temp= new_GHVD((*position)->gameId, (*position)->homeTeam, (*position)->visitorTeam, (*position)->date);
                temp->next = NULL;
                insert_GHVD(temp, result);
                position=&(*position)->next;
            }else{
                position=&(*position)->next;
            }
        }
        return result;
    }else{
        for(int i=0; i< 1009; i++){
            GHVDList* position =table[i];
            while((*position) != NULL){
                if((checkHome==false || strcmp(hometeam, (*position)->homeTeam)==0)&&
                  (checkVisitor == false || strcmp(visitorteam, (*position)->visitorTeam) ==0) &&
                  (checkDate == false || strcmp(date, (*position)->date) == 0)){
                GHVDList temp= new_GHVD((*position)->gameId, (*position)->homeTeam, (*position)->visitorTeam, (*position)->date);
                    temp->next=NULL;
                    insert_GHVD(temp, result);
                    position=&(*position)->next;
                }else{
                    position=&(*position)->next;
                }
            }
        }
        return result;
    }
}

GPGHashTable* lookup_GPG(int gameid, int playerid, int goals, GPGHashTable* table){
    GPGHashTable* result = new_GPGTable();
    bool checkGameID = true;
    if(gameid == -1){checkGameID = false;}
    bool checkPlayerID = true;
    if(playerid == -1){checkPlayerID = false;}
    bool checkGoals = true;
    if(goals == -1){checkGoals = false;}

    if(checkPlayerID){
        int index = hashing_num(playerid);
        GPGList* position =table[index];
        while((*position) != NULL){
            if(playerid == (*position)->playerId && (checkGameID==false || gameid == (*position)->gameId) &&
            (checkGoals == false || goals == (*position)->goals)){
                GPGList temp= new_GPG((*position)->gameId, (*position)->playerId, (*position)->goals);
                temp->next = NULL;
                insert_GPG(temp, result);
                position=&(*position)->next;
            }else{
                position=&(*position)->next;
            }
        }
        return result;
    }else{
        for(int i=0; i< 1009; i++){
            GPGList* position =table[i];
            while((*position) != NULL){
                if((checkGameID==false || gameid == (*position)->gameId) &&
                   (checkGoals == false || goals == (*position)->goals)){
                    GPGList temp= new_GPG((*position)->gameId, (*position)->playerId, (*position)->goals);
                    temp->next=NULL;
                    insert_GPG(temp, result);
                    position=&(*position)->next;
                }else{
                    position=&(*position)->next;
                }
            }
        }
        return result;
    }
}

PNBHashTable* populate_PNB(){
    PNBHashTable* PNBTABLE = new_PNBTable();
    insert_PNB(new_PNB(75196, "A. Moore", "28 Aug 1985"), PNBTABLE);//
    insert_PNB(new_PNB(59797, "G. Jones", "26 Dec 1986"), PNBTABLE);//
    insert_PNB(new_PNB(87977, "U. Hughes", "13 Feb 1990"), PNBTABLE);//
    insert_PNB(new_PNB(20945, "Q. Morgan", "14 Feb 1998"), PNBTABLE);//
    insert_PNB(new_PNB(70513, "G. King", "13 Apr 1993"), PNBTABLE);//
    insert_PNB(new_PNB(51213, "T. Sullivan", "24 Jun 1995"), PNBTABLE); //
    insert_PNB(new_PNB(61367, "A. Moore", "18 Mar 2000"), PNBTABLE);//
    insert_PNB(new_PNB(55870, "D. Hernandez", "25 Jul 1997"), PNBTABLE);//
    insert_PNB(new_PNB(47087, "W. Stewart", "5 Jan 1994"), PNBTABLE);//
    insert_PNB(new_PNB(39468, "G. Jones", "25 Feb 1990"), PNBTABLE);//
    return PNBTABLE;
}

TPNHashTable* populate_TPN(){
    TPNHashTable* TPNTABLE = new_TPNTable();
    insert_TPN(new_TPN("Americans", 87977, 11), TPNTABLE);//
    insert_TPN(new_TPN("Americans", 75196, 7), TPNTABLE);//
    insert_TPN(new_TPN("Americans", 61367, 99), TPNTABLE);//
    insert_TPN(new_TPN("Maple Leafs", 75196, 7), TPNTABLE);
    insert_TPN(new_TPN("Maple Leafs", 20945, 24), TPNTABLE);//
    insert_TPN(new_TPN("Redwings", 70513, 10), TPNTABLE);//
    insert_TPN(new_TPN("Redwings", 20945, 10), TPNTABLE);//
    insert_TPN(new_TPN("Crunch", 51213, 1), TPNTABLE);//
    insert_TPN(new_TPN("Crunch", 51213, 9), TPNTABLE);//
    insert_TPN(new_TPN("Crunch", 55870, 13), TPNTABLE);//
    return TPNTABLE;
}

TCHashTable* populate_TC(){
    TCHashTable* TCTABLE = new_TCTable();
    insert_TC(new_TC("Americans", "Rochester"), TCTABLE);//
    insert_TC(new_TC("Maple Leafs", "Toronto"), TCTABLE);//
    insert_TC(new_TC("Redwings", "Detroit"), TCTABLE);//
    insert_TC(new_TC("Crunch", "Syracuse"), TCTABLE);//
    return TCTABLE;
}

GHVDHashTable* populate_GHVD(){
    GHVDHashTable* GHVDHASHTABLE = new_GHVDTable();
    insert_GHVD(new_GHVD(1, "Americans", "Maple Leafs", "3 Jan 2023"), GHVDHASHTABLE);
    insert_GHVD(new_GHVD(2, "Crunch", "Redwings", "3 Jan 2023"), GHVDHASHTABLE);
    insert_GHVD(new_GHVD(3, "Americans", "Crunch", "6 Jan 2023"), GHVDHASHTABLE);
    insert_GHVD(new_GHVD(4, "Redwings", "Maple Leafs", "6 Jan 2023"), GHVDHASHTABLE);
    insert_GHVD(new_GHVD(5, "Redwings", "Americans", "8 Jan 2023"), GHVDHASHTABLE);
    insert_GHVD(new_GHVD(6, "Maple Leafs", "Crunch", "8 Jan 2023"), GHVDHASHTABLE);
    insert_GHVD(new_GHVD(7, "Maple Leafs", "Crunch", "9 Jan 2023"), GHVDHASHTABLE);
    insert_GHVD(new_GHVD(8, "Americans", "Redwings", "10 Jan 2023"), GHVDHASHTABLE);
    insert_GHVD(new_GHVD(9, "Crunch", "Americans", "12 Jan 2023"), GHVDHASHTABLE);
    insert_GHVD(new_GHVD(10, "Redwings", "Maple Leafs", "12 Jan 2023"), GHVDHASHTABLE);
    return GHVDHASHTABLE;
}
GPGHashTable* populate_GPG(){
    GPGHashTable* GPGHASHTBALE = new_GPGTable();
    insert_GPG(new_GPG(2, 55870, 1), GPGHASHTBALE);
    insert_GPG(new_GPG(2, 70513, 2), GPGHASHTBALE);
    insert_GPG(new_GPG(3, 51213, 1), GPGHASHTBALE);
    insert_GPG(new_GPG(5, 20945, 4), GPGHASHTBALE);
    insert_GPG(new_GPG(6, 55870, 2), GPGHASHTBALE);
    insert_GPG(new_GPG(7, 75196, 1), GPGHASHTBALE);
    insert_GPG(new_GPG(8, 87977, 1), GPGHASHTBALE);
    insert_GPG(new_GPG(8, 75196, 2), GPGHASHTBALE);
    insert_GPG(new_GPG(9, 55870, 3), GPGHASHTBALE);
    insert_GPG(new_GPG(9, 61367, 2), GPGHASHTBALE);
    return GPGHASHTBALE;
}

/*
1- using the index on Name, find each tuple in the StudentId-Name-Address-Grade relation that has Name component “C. Brown”;
2- for each tuple t found in (1) do begin
3- let i be the StudentId component of tuple t;
4- using the index on Course and StudentId in the
   Course-StudentId-Grade relation, find the tuples with Course component “CS101” and StudentId component i;
5- print the Grade component of tuple s;
end
*/

//What number did Name wear when playing for Team?
void Q1(char* name, char* team){
    int test =0;
    PNBHashTable* result = lookup_PNB(-1, name, "*", populate_PNB());
    for(int i = 0; i < 1009; i++){
        PNBList* position = result[i];
        while((*position) != NULL){
            int id = (*position)->playerId;
            TPNHashTable* result2 = lookup_TPN(team, id, -1, populate_TPN());
            TPNList* position2 = result2[hashing_num(id)];
            while((*position2) != NULL){
                test += 1;
                printf("%d \n", (*position2)->number);
                position2 = &(*position2)->next;
            }
            position = &(*position)->next;
        }
    }   
    if (test == 0){
        printf("No match was found\n");
    }
}

//how many goals did name score on date?
void Q2(char* name, char* date){
    int test = 0;
    PNBHashTable* result = lookup_PNB(-1, name, "*", populate_PNB());
        for(int i = 0; i < 1009; i++){
        PNBList* position = result[i];
        while((*position) != NULL){
            int id = (*position)->playerId;
            GPGHashTable* result2 = lookup_GPG(-1,id,-1,populate_GPG());
            GPGList* position2 = result2[hashing_num(id)];
            while((*position2) != NULL){
                int goals = (*position2)->goals;
                GHVDHashTable* result3 = lookup_GHVD((*position2)->gameId, "*", "*", date, populate_GHVD());
                GHVDList* position3 = result3[hashing_num((*position2)->gameId)];
                while((*position3) != NULL){
                    test+=1;
                    printf("%d \n", goals);
                    position3 = &(*position3)->next;
                }
            position2 = &(*position2)->next;
            }
            position = &(*position)->next;
        }
    }
    if (test == 0){
        printf("No match was found\n");
    }
}

//What number did Name wear when playing for Team?
void Q1_REPL(){
    char inputName[30] = "";
    char inputTeam[30] = "";
    while(strcmp(inputName, "quit") !=0 && strcmp(inputTeam, "quit") !=0 ){
        printf(" Enter a name  (\"quit\" to quit): ");
        fgets(inputName, sizeof(inputName), stdin);
            inputName[strcspn(inputName, "\n")] = 0;
        if (strcmp(inputName, "quit") == 0) {
            break;
        }
        printf(" Enter a Team  (\"quit\" to quit): ");
        fgets(inputTeam, sizeof(inputTeam), stdin);
        inputTeam[strcspn(inputTeam, "\n")] = 0;
        if (strcmp(inputTeam, "quit") == 0) {
            break;
        }
        printf("Q: What number did %s wear when playing for %s? \n", inputName, inputTeam);
        printf("Ans: \n");
        Q1(inputName, inputTeam);
    }
}

//how many goals did name score on date?
void Q2_REPL(){
    char inputName[30] = "";
    char inputDate[35] = "";
    while(strcmp(inputName, "quit") !=0 && strcmp(inputDate, "quit") !=0 ){
        printf(" Enter a Name  (\"quit\" to quit): ");
        fgets(inputName, sizeof(inputName), stdin);
            inputName[strcspn(inputName, "\n")] = 0;
        if (strcmp(inputName, "quit") == 0) {
            break;
        }
        printf(" Enter a Date  (\"quit\" to quit): ");
        fgets(inputDate, sizeof(inputDate), stdin);
        inputDate[strcspn(inputDate, "\n")] = 0;
        if (strcmp(inputDate, "quit") == 0) {
            break;
        }
        printf("Q: How many goals did %s score on %s? \n", inputName, inputDate);
        printf("Ans: \n");
        Q2(inputName, inputDate);
    }
}
TPNHashTable* selection_TPN(int playerid){
    return lookup_TPN("*", playerid, -1, populate_TPN());
}

void projection_TPN(int playerid){
    TPNHashTable* tpnt = lookup_TPN("*", playerid, -1, populate_TPN());
    TPNList* position = tpnt[hashing_num(playerid)];
    while(*position != NULL){
        printf("%s \n", (*position)->Team);
            position = &(*position)->next;
    }
}
typedef struct GPGHVD *GPGHVDList;
struct GPGHVD {
    int gameid;
    int playerid;
    int goals;
    char homeTeam[31];
    char visitorTeam[31];
    char date[31];
    GPGHVDList next;
};
typedef GPGHVDList GPGHVDHashTable[1009];

bool GPGHVDTable_null(GPGHVDHashTable * table){
    for(int i=0; i< 1009; i++){
        GPGHVDList* position =table[i];
        if((*position) != NULL){
            return false;;
        }
    }
    return true;
}
bool equal_GPGHVD(GPGHVDList t1, GPGHVDList t2){
    if(t1->gameid == t2->gameid && t1->playerid == t2->playerid && t1->goals == t2->goals && strcmp(t1->homeTeam, t2->homeTeam)==0 &&
    strcmp(t1->visitorTeam, t2->visitorTeam)==0 &&strcmp(t1->date, t2->date) == 0){
        return true;
    }
    return false;
}

GPGHVDList new_GPGHVD(int gameid, int playerid, int goals, char* hometeam, char* visitorteam, char* date){
    GPGHVDList gpghvd = (GPGHVDList)malloc(sizeof(struct GPGHVD));
    gpghvd->gameid = gameid;
    gpghvd->playerid = playerid;
    gpghvd->goals = goals;
    strcpy(gpghvd->homeTeam,hometeam);
    strcpy(gpghvd->visitorTeam,visitorteam);
    strcpy(gpghvd->date,date);
    gpghvd->next= NULL;
    return gpghvd;
}

GPGHVDHashTable* new_GPGHVDHashTable(){
    GPGHVDHashTable * t = (GPGHVDHashTable*)malloc(sizeof(GPGHVDHashTable));
    for(int i=0;i<1009;i++){
        GPGHVDList * index = t[i];
        (*index) = NULL;
    }
    return t;
}

void print_GPGHVD(GPGHVDList gpghvd){
    if (gpghvd != NULL){
        printf("(%d, %d, %d, %s, %s, %s) ", gpghvd->gameid, gpghvd->playerid, gpghvd->goals, gpghvd->homeTeam, gpghvd->visitorTeam, gpghvd->date);
    }
}
GPGHVDHashTable* insert_GPGHVD(GPGHVDList t, GPGHVDHashTable* table){
    int index = hashing_num(t->playerid);
    GPGHVDList* position =table[index];
    while((*position) != NULL){
        if(equal_GPGHVD(t, (*position))){
            printf("GPGHVD tuple :");
            print_GPGHVD(t);
            printf(" already exists\n");
            return table;
        }else{
            position=&(*position)->next;
        }
    }
    *position = t;
    return table;
}

void print_GPGHVDTable(GPGHVDHashTable* table){
    for(int i = 0; i < 1009; i++){
        GPGHVDList* position = table[i];
        while((*position) != NULL){
            print_GPGHVD(*position);
            printf("\n");
            position = &(*position)->next;
            }
        }
    printf("\n");
}

GPGHVDHashTable* join_GHVD_GPG(){
    GPGHashTable* gpgt = populate_GPG();
    GHVDHashTable* ghvdt = populate_GHVD();
    GPGHVDHashTable* result = new_GPGHVDHashTable();
    for(int i=0; i<1009;i++){
        GPGList* position = gpgt[i];
        while((*position) != NULL){
            GHVDList* position2 = ghvdt[hashing_num((*position)->gameId)];
            while((*position2) != NULL){
                insert_GPGHVD(new_GPGHVD((*position)->gameId, (*position)->playerId, (*position)->goals,
                (*position2)->homeTeam, (*position2)->visitorTeam, (*position2)->date), result);
            position2 = &(*position2)->next;
            }
            position = &(*position)->next;
        }

    }
    return result;
}

void all_the_above(){
    GPGHVDHashTable* ghvdt1 = join_GHVD_GPG();
    for(int i=0; i<1009; i++){
        GPGHVDList* position = ghvdt1[i];
        while((*position) != NULL){
            if(strcmp((*position)->date, "8 Jan 2023") == 0){
                printf("(%d, %d)\n", (*position)->playerid, (*position)->goals);
            }
            position = &(*position)->next;
        }
    }
}
void test_part1(){
    //part1
    printf("PNB Table: \n");
    print_PNBTable(populate_PNB());

    printf("TPN Table: \n");
    print_TPNTable(populate_TPN());

    printf("TC Table: \n");
    print_TCTable(populate_TC());


    printf("GHVD Table: \n");
    print_GHVDTable(populate_GHVD());

    printf("GPG Table: \n");
    print_GPGTable(populate_GPG());

    printf("Performing lookup: \n");
    printf("Testing lookup(〈“Americans”, 61367, 99〉, Team-PlayerId-Number)  \n");
    print_TPNTable(lookup_TPN("Americans", 61367, 99, populate_TPN()));
    printf("\n");
    printf("Testing lookup(〈“Crunch”, 51213, ∗〉, Team-PlayerId-Number)\n");
    print_TPNTable(lookup_TPN("Crunch", 51213, -1,populate_TPN()));
    printf("\n");
    printf("Testing lookup(〈“Americans”, “Toronto”〉, Team-City) \n");
    print_TCTable(lookup_TC("Americans", "Toronto", populate_TC()));
    printf("\n");

    printf("Performing delete: \n");
    printf("Testing delete (〈4, “Redwings”, “Maple Leafs”, “6 Jan 2023”〉, GameId-HomeTeam-AwayTeam-Date) \n");
    print_GHVDTable(delete_GHVD(4, "Redwings", "Maple Leafs", "6 Jan 2023", populate_GHVD()));
    printf("\n");
    printf("Testing delete (〈∗, “Redwings”, “Crunch”, ∗〉, GameId-HomeTeam-AwayTeam-Date) \n");
    print_GHVDTable(delete_GHVD(-1, "Redwings", "Crunch", "*", populate_GHVD()));
    printf("Testing delete (〈∗, “Americans”, ∗, ∗〉, GameId-HomeTeam-AwayTeam-Date) \n");
    print_GHVDTable(delete_GHVD(-1, "Americans", "*", "*", populate_GHVD()));
    printf("\n");

    printf("Performing insert: \n");
    printf("Testing insert (〈“Ice Pilots”, “Pensacola”〉, Team-City) \n");
    print_TCTable(insert_TC(new_TC("Ice Pilots", "Pensacola"), populate_TC()));
    printf("Testing insert (〈“Crunch”, “Syracuse”〉, Team-City) \n");
    print_TCTable(insert_TC(new_TC("Crunch", "Syracuse"), populate_TC()));
}
void test_part3(){
    printf("Result for σPlayerId=51213(TPN)\n");
    TPNHashTable* test1 = selection_TPN(51213);
    print_TPNTable(test1);
    printf("Result for πTeam(σPlayerId=51213(TPN))\n");
    projection_TPN(51213);
    printf("\n");
    printf("Result for GHVD ▷◁ GPG\n");
    GPGHVDHashTable* test2 = join_GHVD_GPG();
    print_GPGHVDTable(test2);
    printf("Result for πPlayerId,Goals(σDate=“8 Jan 2023”(GHVD ▷◁ GPG))\n");
    all_the_above();
}
int main(){
    //part1
    test_part1();
    //part 2
    printf("Testing Q1: What number did NAME wear when playing for TEAM? \n");
    Q1_REPL();
    printf("Testing Q2: How many goals did NAME score on DATE? \n");
    Q2_REPL();
    //part 3
    test_part3();
}
