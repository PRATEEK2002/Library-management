//2017A7PS0171P
//PRATEEK SHARMA
#include<stdio.h>
#include <stdlib.h>
#include<string.h>            
#include<ctype.h>       
#include<time.h>
typedef struct books book;
typedef struct dates date;
struct dates{
	int day;
	int mon;
	int yr;
	
};

struct books   						//Structure to store book information
{
	char title[20];
	char author[20];
	int count;
	int rackno;

	char issuer[20];

	int iss_day;
	int iss_mon;
	int iss_yr;
	int reg_day;
	int reg_mon;
	int reg_yr;
	struct books *next;

};
/**
date getdates(){
	 time_t T= time(NULL);
    struct  tm tm = *localtime(&T);
	date dt;
	dt.day=tm.tm_mday;
		dt.mon=tm.tm_mon+1;
	dt.yr=tm.tm_year+1900;
	return dt;
	
}**/
int days_greator15(date d1,date d2,int lim) // function to check whether difference between two dates is greator than certain limit or not
{
	int ans=1;;
	int diff1=d2.day-d1.day;
		int diff2=d2.mon-d1.mon;

	int diff3=d2.yr-d1.yr;
	if(diff2>1 && diff3>1)
		ans=0;

	if(diff1>=lim && diff2==0 && diff3==0)
		ans=0;
	if(diff2==1)
	{
		int diff4=d2.day+(30-d1.day);
		if(diff4>=lim)
			ans=0;
	}
	if(diff3==1)
	{
		if(d2.mon!=1 || d1.mon!=12 )
			ans=0;
		else{
		int diff5=d2.day+(30-d1.day);
		if(diff5=lim)
			ans=0;	
		}
	}
	return ans;
}
int exists(const char *fname)    // function to check certain file exist or not
{
    FILE *file;
    if ((file = fopen(fname, "r")))
    {
        fclose(file);
        return 1;
    }
    return 0;
}




int main()
{
	char ast[]="       ***************";
	char ast2[]="***************      ";	
	
	char spc[]="                      ";
	char spc2[]="             ";


while(1){
system("clear");

printf("%sWELCOME TO LIBRARY MANAGEMENT SYSTEM%s\n\n",ast,ast2); // interface to ask person to login as a admin or a user
printf("\n%sPRESS 0 TO EXIT%s\n",spc,spc);

printf("\n%sFOR USER LOGIN PRESS 1%s\n",spc,spc);
printf("\n%sFOR ADMIN LOGIN PRESS 2%s\n",spc,spc);
int uad;
printf("\n%senter your choice ",spc);

//scanf("%d",&uad);

while(scanf("%d",&uad) != 1)   {
	printf("%sPlease enter an integer: ",spc);
    while(getchar() != '\n');
 }
    //printf("You entered: %d\n",n);
if(uad!=1 && uad!=2){
    printf("\n%sbye\n",spc);
            return 0;
}
//////////////////////////////////ADMIN SITE STARTED///////////////////////////////////////
if(uad==2)
{
	   system("clear");

    char aid[]="admin";     // admin's id is "admin"
    char apass[]="pass";	// admin's password is "pass"
    char ID[20];	// temporary id, password
    char pass[20];
	printf("\n%sADMIN LOGIN PAGE%s\n",ast,ast2);
	printf("%s(you can use ID= admin, password=pass)\n",spc);

    printf("\n%sENTER YOUR ID_ ",spc);
    scanf("%s",ID);
    printf("\n%sENTER ADMIN PASSWORD_ ",spc);
    scanf("%s",pass);
    if(strcmp(aid,ID)==0 && strcmp(apass,pass)==0){
		/////////////////////////////////////////////////////INTERFACE FOR ADMIN'S FUNCTION////////////////////////
		while(1){
			system("clear");
			printf("\n%shello admin%s\n",ast,ast2);
			int op1;
			printf("\n%s>FOR ADDING USERS PRESS 1%s\n",spc,spc);
			printf("\n%s>FOR DELETING USERS PRESS 2%s\n",spc,spc);

			printf("\n%s>FOR ADDING BOOKS PRESS 3%s\n",spc,spc);

			printf("\n%s>VENDOR MANAGEMENT PRESS 4%s\n",spc,spc);
			printf("\n%s>FOR ALL BOOK DETAILS PRESS 5%s\n",spc,spc);
			printf("\n%s>INVENTORY MANAGEMENT PRESS 6%s\n",spc,spc);
			printf("\n%s>FOR ALL USERS DETAILS PRESS 7%s\n",spc,spc);


			printf("\n%s>FOR LOG OUT PRESS 8%s\n",spc,spc);

			printf("\n%s>ENTER YOUR CHOICE",spc);

			//scanf("%d",&op1);
			while(scanf("%d",&op1) != 1)   {
				printf("%sPlease enter an integer: ",spc);
				while(getchar() != '\n');
			}
			if(op1==8){									///TO EXIT ADMIN SITE/////////
				system("clear");

			break;}

			
			if(op1==1){									///OPTION 1 IS FOR REGISTERING USER TO THE LIBRARY MANAGEMENT SYSTEM//////
				system("clear");

				printf("ADD NEW USER: \n");

				char uid[20],upass[20];
				printf("\nADD USERID OF USER: ");
				scanf("%s",uid);
				printf("\nADD PASSWORD FOR USER: ");
				scanf("%s",upass);
				//// checking if user is already present or not i.e username is unique
				char usid[20],uspass[20];
				int ch4=exists("users.txt");
				int flag=0;

				if(ch4==1){
					FILE *tp=fopen("users.txt","r");
					if(tp==NULL)
						printf("tp\n");
				
					//printf("USERIDs and PASSWORDs\n\n");
					while(1){
						int k1=fscanf(tp,"%s",usid);
						if(k1==EOF)
							break;
						fscanf(tp,"%s",uspass);
						if(strcmp(usid,uid)==0)
							flag=1;
					}
					fclose(tp);
				}	
				//////////////////////end check///
				if(flag==0){
					FILE *fp;
					fp=fopen("users.txt","a");								////USERS.TXT IS THE FILE TO STORE USERS///
					fputs(uid, fp);
					fputs(" ", fp);
					fputs(upass, fp);
					fputs("\n", fp);
					fclose(fp);
				
					printf("user entered...\n");
				}
				else{
					printf("user name is already taken try something else...\n");

				}
				while(1){
					int dx;
					printf("\nto exit press 1\n");
					scanf("%d",&dx);
					if(dx==1)
						break;
				}
		
		    }
		
		
			if(op1==2){								////OPTION 2 FOR DELETNG USERS////////
				system("clear");
				printf("Delete USER: \n");
				char did[20];
				printf("\nUSERID OF USER: ");
				scanf("%s",did);
				//printf("did %s\n",did);
				char uid[20],upass[20];
				int ch6=exists("users.txt");
				if(ch6==1){
				FILE *fp=fopen("users.txt","r");
				if(fp==NULL)
					printf("fp\n");
					
				FILE *cp=fopen("tmp.txt","w");
				if(cp==NULL)
					printf("cp\n");
				int flag=0;
				while(1){
				
					int k1=fscanf(fp,"%s",uid);
					if(k1==EOF)
						break;
					fscanf(fp,"%s",upass);
					if(strcmp(uid,did)!=0){
						fprintf(cp,"%s ",uid);
						fprintf(cp,"%s",upass);
						fprintf(cp,"%s","\n");
						}
					else{
						flag=1;
						}	
					}
					fclose(fp);
					fclose(cp);
					remove("users.txt");
					rename("tmp.txt","users.txt");
					if(flag==0){
						printf("user not registered\n");
					}
					if(flag==1){
						printf("user deleted\n");
					}
					while(1){
						int dx;
						printf("\nto exit press 1\n");
						scanf("%d",&dx);
						if(dx==1)
							break;
						
					}
				}	

									
			
		    }
			
			if(op1==3){								///////OPTION 3 FOR REGISTERING BOOKS IN THE SYSTEM//////
				system("clear");
				book bk;
				
				////// TAKING TIME FROM SYSTEM.////
				bk.iss_day=-1;
				bk.iss_mon=-1;
				bk.iss_yr=-1;
				time_t T= time(NULL);
				struct  tm tm = *localtime(&T);
				
				bk.reg_day=tm.tm_mday;
				bk.reg_mon=tm.tm_mon+1;
				bk.reg_yr=tm.tm_year+1900;
				///////////END/////
				
				system("clear");
				printf("\n***important** ENTER BOOK TITLE or AUHTOR IN ONE WORD ONLY(example -for book name ART is allowed but FINE ART is not allowed ): \n");

				printf("\nADD BOOK TITLE: ");
				scanf("%s",bk.title);
				printf("\nADD AUTHOR NAME: ");
				scanf("%s",bk.author);
				printf("\nADD RACK NUMBER(integer): ");
				//scanf("%d",&bk.rackno);
				while(scanf("%d",&bk.rackno) != 1)   {
					printf("Please enter an integer: ");
					while(getchar() != '\n');
				}
				bk.count=1;
				
				FILE *gp;
				gp=fopen("booksss.txt","a");
				fprintf(gp,"%s ",bk.title);

				fprintf(gp,"%s ",bk.author);
				fprintf(gp,"%d ",bk.count);
				fprintf(gp,"%d ",bk.rackno);
				fprintf(gp,"%d ",bk.reg_day);
				fprintf(gp,"%d ",bk.reg_mon);

				fprintf(gp,"%d ",bk.reg_yr);
					fprintf(gp,"%s ","NA");
					fprintf(gp,"%d ",bk.iss_day);
				fprintf(gp,"%d ",bk.iss_mon);

				fprintf(gp,"%d",bk.iss_yr);
				

				fputs("\n", gp);
				fclose(gp);
				
				
			//display all books/////////
			
				system("clear");
				int ch1=exists("booksss.txt");
				if(ch1==1)
				{	printf("\n\n AVAILABLE BOOKS IN LIBARAY\n\n");
					printf("\nNAME        AUTHOR      RACKNO    REG-DATE    ISSUEDBY        ISSUINGDATE\n");


					book bik;
					FILE *fp=fopen("booksss.txt","r");
					while(1){				
						int k1=fscanf(fp,"%s",bik.title);
						if(k1==EOF)
							break;
						fscanf(fp,"%s",bik.author);
						fscanf(fp,"%d",&bik.count);
						fscanf(fp,"%d",&bik.rackno);
						fscanf(fp,"%d",&bik.reg_day);
						fscanf(fp,"%d",&bik.reg_mon);
						fscanf(fp,"%d",&bik.reg_yr);
						fscanf(fp,"%s",bik.issuer);
						fscanf(fp,"%d",&bik.iss_day);
						fscanf(fp,"%d",&bik.iss_mon);
						fscanf(fp,"%d",&bik.iss_yr);

						printf("%-12s  %-12s %d       %d-%d-%d      %-12s  %d-%d-%d\n",bik.title,bik.author,bik.rackno,bik.reg_day,bik.reg_mon,bik.reg_yr,bik.issuer,bik.iss_day,bik.iss_mon,bik.iss_yr);
											
					}
					fclose(fp);	
					while(1){
						int dx;
						printf("\nto exit press 1\n");
						scanf("%d",&dx);
						if(dx==1)
							break;
						
					}
				}
				// DISPLAY END;
				
				
				
		    }
			if(op1==4){								///// OPTION 4 FOR VENDOR MANAGEMENT///////////////
				char title[20],author[20],vendor[20];

				system("clear");
				printf("\n***important** ENTER BOOK TITLE or AUHTOR IN ONE WORD ONLY(example -for book name ART is allowed but FINE ART is not allowed ): \n");
				printf("\nADD BOOk AND VENDOR NAME DETAILS TO ORDER THE BOOK: \n\n");

				printf("\nADD BOOK TITLE: ");
				scanf("%s",title);
				printf("\nADD AUTHOR NAME: ");			///// STORING BOOK NAME,AUTHOR,VENDOR IN A FILE TO PREPARE A LIST///
				scanf("%s",author);
				//printf("\nADD RACK NUMBER: ");
				//scanf("%d",&bk.count);
				printf("\nADD VENDOR NAME: ");
				scanf("%s",vendor);
				FILE *fp;
				fp=fopen("vendor_management.txt","a");
				fputs(title, fp);
				fputs(" ", fp);
				fputs(author, fp);
				fputs(" ", fp);
				fputs(vendor, fp);

				fputs("\n", fp);
				fclose(fp);
				system("clear");
				//displaying vendor file///
				FILE *fp1;
				fp1=fopen("vendor_management.txt","r");
				printf("\nNAME        AUTHOR      VENDOR\n");

				while(1){
				
					int k1=fscanf(fp1,"%s",title);
					if(k1==EOF)
						break;
					fscanf(fp1,"%s",author);
					fscanf(fp1,"%s",vendor);
					printf("%-12s",title);
					printf("%-12s ",author);
					printf("%-12s\n",vendor);
				}
				while(1){
					int nn;
					printf("To exit press 1.....\n" );
					scanf("%d",&nn);
					if(nn==1)
						break;
				}	
				fclose(fp1);	
				/// end of displaying
				
			}
			if(op1==5)									///////OPTION 5 FOR PRINTING DETAILS OF ALL BOOKS/////////
			{	
				system("clear");
				int ch1=exists("booksss.txt");
				if(ch1==1)
				{	printf("\n\n AVAILABLE BOOKS IN LIBARAY\n\n");
					printf("\nNAME        AUTHOR      RACKNO    REG-DATE    ISSUEDBY        ISSUINGDATE\n");


					book bik;
					FILE *fp=fopen("booksss.txt","r");
					while(1){				
						int k1=fscanf(fp,"%s",bik.title);
						if(k1==EOF)
							break;
						fscanf(fp,"%s",bik.author);
						fscanf(fp,"%d",&bik.count);
						fscanf(fp,"%d",&bik.rackno);
						fscanf(fp,"%d",&bik.reg_day);
						fscanf(fp,"%d",&bik.reg_mon);
						fscanf(fp,"%d",&bik.reg_yr);
						fscanf(fp,"%s",bik.issuer);
						fscanf(fp,"%d",&bik.iss_day);
						fscanf(fp,"%d",&bik.iss_mon);
						fscanf(fp,"%d",&bik.iss_yr);

						printf("%-12s  %-12s %d       %d-%d-%d      %-12s  %d-%d-%d\n",bik.title,bik.author,bik.rackno,bik.reg_day,bik.reg_mon,bik.reg_yr,bik.issuer,bik.iss_day,bik.iss_mon,bik.iss_yr);
											
					}
					fclose(fp);	
					while(1){
						int dx;
						printf("\nto exit press 1\n");
						scanf("%d",&dx);
						if(dx==1)
							break;
						
					}
				}
			
			}
			if(op1==6)                   	///////OPTION FOR INVENTORY MANAGEMENT OF ALL BOOKS/////////
			{
				system("clear");
				book bak;
				FILE *fp1;
				fp1=fopen("booksss.txt","r");
				printf("BOOK           AUTHOR         COUNT\n\n");
				int cnt1=0;
				while(1){
				
					int k1=fscanf(fp1,"%s",bak.title);
					if(k1==EOF)
						break;
					cnt1++;
					int flg=0;
					int cnt2=0;
					int cnt=0;

					fscanf(fp1,"%s",bak.author);
					fscanf(fp1,"%d",&bak.count);
					fscanf(fp1,"%d",&bak.rackno);
					fscanf(fp1,"%d",&bak.reg_day);
					fscanf(fp1,"%d",&bak.reg_mon);
					fscanf(fp1,"%d",&bak.reg_yr);
					fscanf(fp1,"%s",bak.issuer);
					fscanf(fp1,"%d",&bak.iss_day);
					fscanf(fp1,"%d",&bak.iss_mon);
					fscanf(fp1,"%d",&bak.iss_yr);
						

					book ck;
					FILE *fp2;
					fp2=fopen("booksss.txt","r");
					while(1){
				
						int k2=fscanf(fp2,"%s",ck.title);
						if(k2==EOF)
							break;
						cnt2++;
				
						fscanf(fp2,"%s",ck.author);
						fscanf(fp2,"%d",&ck.count);
						fscanf(fp2,"%d",&ck.rackno);
							fscanf(fp2,"%d",&ck.reg_day);
						fscanf(fp2,"%d",&ck.reg_mon);
						fscanf(fp2,"%d",&ck.reg_yr);
						fscanf(fp2,"%s",ck.issuer);
						fscanf(fp2,"%d",&ck.iss_day);
						fscanf(fp2,"%d",&ck.iss_mon);
													
						fscanf(fp2,"%d",&ck.iss_yr);
						if(strcmp(bak.author,ck.author)==0 && strcmp(bak.title,ck.title)==0 ){
							cnt++;
							if(cnt1>cnt2)
								flg=1;
						}
					
					}
					fclose(fp2);	

					if(flg==0){
						printf("%-15s",bak.title);
						printf("%-15s",bak.author);
						printf("%d ",cnt);
				
						printf("\n");
					}
				}
				
				while(1){
					int nn;
					printf("\n\nTo exit press 1\n" );
					scanf("%d",&nn);
					if(nn==1)
						break;
				}
				
				
			}
			if(op1==7){								////OPTION 7 for printing users detail////////
				system("clear");
				printf("PRINT ALL USERS INFO: \n");
				
				char usid[20],upass[20];
				int ch4=exists("users.txt");
				if(ch4==1){
					FILE *fp=fopen("users.txt","r");
					if(fp==NULL)
						printf("fp\n");
				
				//int flag=0;
					printf("USERIDs and PASSWORDs\n\n");
					while(1){
						int k1=fscanf(fp,"%s",usid);
						if(k1==EOF)
							break;
						fscanf(fp,"%s",upass);
	
						printf("USERID-> %s \n",usid);
						printf("PASSWORD-> %s\n",upass);
						printf("%s","\n");
				
					
					}
					fclose(fp);
					while(1){
						int dx;
						printf("\nto exit press 1\n");
						scanf("%d",&dx);
						if(dx==1)
							break;
						
					}
				}
		    }
			
			
		}	
	}

    
    else{
		system("clear");
		printf("\nwrong ID or password\n");
		while(1){	
		int ch;
		printf("\nFor going back press 1\n");
		scanf("%d",&ch);
		if(ch==1)
			break;
		}
    }

}
//////////////////// END OF ADMIN SITE/////////////////////////////



///////////////////  USER SITE ///////////////////////////////////////////////////////////////////////////

if(uad==1)
{
	system("clear");
	printf("\n%sUSER SIDE%s\n",ast,ast2);
	/////   DISPLAYING NEWLY ENTERED BOOKS (LIMIT 5 DAYS)
	
			date curr_dt;
			 time_t T= time(NULL);
				struct  tm tm = *localtime(&T);
				
				curr_dt.day=tm.tm_mday;
				curr_dt.mon=tm.tm_mon+1;
				curr_dt.yr=tm.tm_year+1900;
			int ch1=exists("booksss.txt");
			if(ch1==1)
			{						///printf("\n NOTIFICATIONS1\n");

				book bik;
				FILE *fp=fopen("booksss.txt","r");
				printf("\n%s!RECENT BOOKS (WHICH ARE ADDED WITHIN 5 DAYS)\n",spc);
				printf("\n%sNAME        AUTHOR      RACKNO   REG-DATE\n",spc);

				while(1){				
					int k1=fscanf(fp,"%s",bik.title);
					if(k1==EOF)
						break;
					fscanf(fp,"%s",bik.author);
					fscanf(fp,"%d",&bik.count);
					fscanf(fp,"%d",&bik.rackno);
					fscanf(fp,"%d",&bik.reg_day);
					fscanf(fp,"%d",&bik.reg_mon);
					fscanf(fp,"%d",&bik.reg_yr);
					fscanf(fp,"%s",bik.issuer);
					fscanf(fp,"%d",&bik.iss_day);
					fscanf(fp,"%d",&bik.iss_mon);
					fscanf(fp,"%d",&bik.iss_yr);

						date isdt;
						isdt.day=bik.reg_day;
						isdt.mon=bik.reg_mon;
						isdt.yr=bik.reg_yr;

						int ch2=days_greator15(isdt,curr_dt,5);
						if(ch2==1)
						{
						printf("%s",spc);
						printf("%-12s %-12s %d       %d-%d-%d \n",bik.title,bik.author,bik.rackno,bik.reg_day,bik.reg_mon,bik.reg_yr);	
						
						}
						
					
				}
					fclose(fp);	
			}
			
			
	////////////////// END OF BOOK SECTION///// 
	char uid[20],upass[20];
	printf("\n%s#IF YOU ARE NOT REGSITERED ASK ADMIN TO ENROLL YOU (for trial purpose you can use ID= ankit, password=1234 i.e one of the many user)\n",spc);

	 printf("\n%sENTER YOUR USER ID_ ",spc);
    scanf("%s",uid);
    printf("\n%sENTER PASSWORD_ ",spc);
    scanf("%s",upass);
	
	///////////////// FROM THE "LIST OF USERS" REGISTERED BY ADMIN, MATCHING THE ID, PASSWORD OF THE CURRENT USER/////////
	
	char tempid[20],temppass[20];
	FILE *fp=fopen("users.txt","r");
	int flag=0;
	while(1){				
		int k1=fscanf(fp,"%s",tempid);
		if(k1==EOF)
			break;
		fscanf(fp,"%s",temppass);
		if(strcmp(uid,tempid)==0 && strcmp(upass,temppass)==0){
			flag=1;
			break;
		}
	}	
	//// END OF ID,PASSWORD MATCHING
	/**if(flag==0)
	{
		system("clear");
		printf("\nINCORRECT ID OR PASSWORD\n\n");
		while(1){	
			int inf;
			printf("\nfor going back press 1...");
			scanf("%d",&inf);
			if(inf==1)
				break;
		}	
	}***/
	if(flag==1){
		while(1)
		{		
				system("clear");
				printf("%swelcome %s%s\n\n",ast,uid,ast2);

			/////  NOTIFICATION TO USER (FOR THE DEADLINE OF BOOKS (WHICH IS 15 DAYS))////////////////////////////////////
			date curr_dt;
			 time_t T= time(NULL);
				struct  tm tm = *localtime(&T);
				
				curr_dt.day=tm.tm_mday;
				curr_dt.mon=tm.tm_mon+1;
				curr_dt.yr=tm.tm_year+1900;
			int ch1=exists("booksss.txt");
			if(ch1==1)
			{						///printf("\n NOTIFICATIONS1\n");

				book bik;
				FILE *fp=fopen("booksss.txt","r");
				while(1){				
					int k1=fscanf(fp,"%s",bik.title);
					if(k1==EOF)
						break;
					fscanf(fp,"%s",bik.author);
					fscanf(fp,"%d",&bik.count);
					fscanf(fp,"%d",&bik.rackno);
					fscanf(fp,"%d",&bik.reg_day);
					fscanf(fp,"%d",&bik.reg_mon);
					fscanf(fp,"%d",&bik.reg_yr);
					fscanf(fp,"%s",bik.issuer);
					fscanf(fp,"%d",&bik.iss_day);
					fscanf(fp,"%d",&bik.iss_mon);
					fscanf(fp,"%d",&bik.iss_yr);
			

					if(strcmp(uid,bik.issuer)==0){
						//curr_dt
						date isdt;
						isdt.day=bik.iss_day;
						isdt.mon=bik.iss_mon;
						isdt.yr=bik.iss_yr;

						int ch2=days_greator15(isdt,curr_dt,15);
						if(ch2==0)
						{
						printf("%s!!NOTIFICATIONS::",spc);
						printf("%s, your 15 days are over for %s book, please return it\n",uid,bik.title);	
						
						}
						
					}
				}
					fclose(fp);	
			}
			
			//////////////END OF NOTIFIACTION/////////////////////////////////////////
			///////////////////////////ALERT//////////////////////////////////////
				char b_nm[20],b_auth[20],b_res[20];
				int ch2=exists("reservation.txt");
				if(ch2==1){
				FILE *gp=fopen("reservation.txt","r");
				if(gp==NULL)
					printf("gp\n");
				
				int flag=0;
				while(1){
				
					int k1=fscanf(gp,"%s",b_nm);
					if(k1==EOF)
						break;
					fscanf(gp,"%s",b_auth);
					fscanf(gp,"%s",b_res);
					if(strcmp(b_res,uid)==0)
					{
						int ch1=exists("booksss.txt");
						if(ch1==1)
						{	
							book bik;
							FILE *fp=fopen("booksss.txt","r");
							while(1){				
								int k1=fscanf(fp,"%s",bik.title);
								if(k1==EOF)
									break;
								fscanf(fp,"%s",bik.author);
								fscanf(fp,"%d",&bik.count);
								fscanf(fp,"%d",&bik.rackno);
								fscanf(fp,"%d",&bik.reg_day);
								fscanf(fp,"%d",&bik.reg_mon);
								fscanf(fp,"%d",&bik.reg_yr);
								fscanf(fp,"%s",bik.issuer);
								fscanf(fp,"%d",&bik.iss_day);
								fscanf(fp,"%d",&bik.iss_mon);
								fscanf(fp,"%d",&bik.iss_yr);
								if(strcmp(b_nm,bik.title)==0 && strcmp(b_auth,bik.author)==0 && strcmp(bik.issuer,"NA")==0)
								{
									printf("%s!!ALERT::",spc);
									printf("%s, %s book is availabe now, you can issue it now\n",uid,bik.title);	
						
								}
				
							}
							fclose(fp);	
					
						}
					}
					
					
				}	
				fclose(gp);

				}
			///////////////////////////END OR ALERT//////////////////////////////////////
			///////////////////////  AVAILABLE OPTIONS FOR USER //////////////////////////////////////
			//printf("%s////////////////////////////",spc);
			printf("\n\n%s>FOR BOOK SEARCH PRESS 1\n",spc);
			printf("\n%s>FOR BOOK TRANSACTION/ISSUE or BOOK RESERVATION(IF BOOK IS ISSUED BY SOMEONE ELSE): 2\n",spc);
			printf("\n%s>FOR BOOK RETURN PRESS 3\n",spc);

			printf("\n%s>FOR CANCELLATION OF RESERVATION OF BOOK 4\n",spc);
			printf("\n%s>FOR LOG OUT 5\n",spc);

			int op2;
			printf("\n%s>ENTER YOUR CHOICE HERE_ : ",spc);
			//scanf("%d",&op2);
			while(scanf("%d",&op2) != 1)   {
				printf("%sPlease enter an integer: ",spc);
				while(getchar() != '\n');
			}
    
			
			if(op2==5)
				break;
			if(op2==1) ////////////////////////// OPTION 1 FOR SERACHING BOOKS ///////////////////////////////////
			{
				system("clear");
				printf("\n***important** ENTER BOOK TITLE or AUHTOR IN ONE WORD ONLY(example -for book name ART is allowed but FINE ART is not allowed ): \n");

				int search_sel;
				printf("\n(FOR A CERTAIN BOOK)FOR SERACH BY BOOK NAME AND AUTHOR NAME BOTH, PRESS 1: \n");
				printf("\n(ALL BOOKS BY SAME NAME)FOR SERACH BY BOOK NAME, PRESS 2: \n");
				printf("\n(ALL BOOKS BY AUTHOR NAME)FOR SERACH BY AUTHOR NAME, PRESS 3: \n");
				printf("\nENTER YOUR CHOICE HERE_");
				//scanf("%d",&search_sel);
				while(scanf("%d",&search_sel) != 1)   {
					printf("Please enter an integer: ");
					while(getchar() != '\n');
				}
    
				system("clear");

				char btitle[20],bauthor[20];
				if(search_sel==1 || search_sel==2){
					printf("\nENTER BOOK NAME: ");
					scanf("%s",btitle);
				}
				if(search_sel==1 || search_sel==3){
					printf("\nENTER AUTHOR NAME : ");
					scanf("%s",bauthor);
				}
				FILE* fp=fopen("booksss.txt","r");
				book bk;
				int f=0;
				system("clear");

				while(1){				
					int k1=fscanf(fp,"%s",bk.title);
					if(k1==EOF)
						break;
					fscanf(fp,"%s",bk.author);
					fscanf(fp,"%d",&bk.count);
					fscanf(fp,"%d",&bk.rackno);
					fscanf(fp,"%d",&bk.reg_day);
					fscanf(fp,"%d",&bk.reg_mon);
					fscanf(fp,"%d",&bk.reg_yr);
					fscanf(fp,"%s",bk.issuer);
					fscanf(fp,"%d",&bk.iss_day);
					fscanf(fp,"%d",&bk.iss_mon);
					fscanf(fp,"%d",&bk.iss_yr);
					
					if(search_sel==1){
					if(strcmp(btitle,bk.title)==0 && strcmp(bauthor,bk.author)==0){
						f=1;
					}
					}
					if(search_sel==2){
					if(strcmp(btitle,bk.title)==0){
						f=1;
					}
					}
					if(search_sel==3){
					if(strcmp(bauthor,bk.author)==0){
						f=1;
					}
					}
					
					if(f==1){
						printf("\nBOOK INFO\n");
						printf("\nBOOK NAME %s",bk.title);
						printf("\nBOOK AUTHOR %s",bk.author);
						//printf("\nBOOK COUNT %d",bk.count);
						printf("\nBOOK RACK NUMBERs %d",bk.rackno);
						printf("\nBOOK ENTERED ON %d-%d-%d",bk.reg_day,bk.reg_mon,bk.reg_yr);
						printf("\n\n");
						f=0;
						
						//break;
					}
				}
				if(f==0){
					printf("\n\nTHIS BOOK ARE PRESENT/EMPTY\n");
					
				}
				while(1)
				{
					int nn;
					printf("\nfor going back to previous page press 1\n");
					scanf("%d",&nn);
						if(nn==1)
							break;	
				}

			}
			if(op2==2)     //////////////// OPTION 2 FOR ISSUING BOOK, IF AVAILABLE or RESERVING BOOK///////
			{
				system("clear");
				printf("\nBOOK TRANSACTION: \n");
				printf("\n***important** ENTER BOOK TITLE or AUHTOR IN ONE WORD ONLY(example -for book name ART is allowed but FINE ART is not allowed ): \n");

				printf("\nDETAILS OF BOOKS WITH ISSUER CAN BE CHECK BY OPTION 5 ON ADMIN SITE(LOGIN AS ADMIN): \n");

				
				char btitle[20],bauthor[20];
				printf("\nENTER BOOK NAME  FOR CHECK OUT: ");
				scanf("%s",btitle);
				printf("\nENTER AUTHOR NAME : ");
				scanf("%s",bauthor);
				FILE* fp=fopen("booksss.txt","r");
				book buk;
				int f=0,f2=0;
				while(1){				
					int k1=fscanf(fp,"%s",buk.title);
					if(k1==EOF)
						break;
					fscanf(fp,"%s",buk.author);
					fscanf(fp,"%d",&buk.count);
					fscanf(fp,"%d",&buk.rackno);
					fscanf(fp,"%d",&buk.reg_day);
					fscanf(fp,"%d",&buk.reg_mon);
					fscanf(fp,"%d",&buk.reg_yr);
					fscanf(fp,"%s",buk.issuer);
					fscanf(fp,"%d",&buk.iss_day);
					fscanf(fp,"%d",&buk.iss_mon);
					fscanf(fp,"%d",&buk.iss_yr);
					

					if(strcmp(btitle,buk.title)==0 && strcmp(bauthor,buk.author)==0){
						f2=1;
					if(strcmp("NA",buk.issuer)==0){
						f=1;
					break;}
				
					}
				}
				if(f2==1 && f==0)
				{
					printf("\nTHIS BOOK IS ISSUED BY SOMEONE ELSE\n");
					printf("\nPress 1 for Reservation..\n");
					printf("\nPress 0 to exist..\n");
					int sel;
					scanf("%d",&sel);
					if(sel==1)
					{
						FILE *np;
						np=fopen("reservation.txt","a");
						fprintf(np,"%s ",btitle);
						fprintf(np,"%s ",bauthor);
						fprintf(np,"%s",uid);
						fprintf(np,"%s","\n");

//						fputs("\n", np);


						fclose(np);
						system("clear");
						printf("BOOK IS RESERVED, ALERT WILL COME\n");

						while(1){
							int ch;
							printf("\nFor going back press 1\n");
							scanf("%d",&ch);
							if(ch==1)
							break;
						}
						
					}
						


					/**while(1)
					{
						int ch;
						printf("For going back press 1\n");
						scanf("%d",&ch);
					if(ch==1)
						break;
					}*/
				}
				if(f==1)
				{
					
					/**entering the issuer name in the books file**/
				char title1[20],author1[20];
				 date rg,is,iss; 
				 time_t T= time(NULL);
				struct  tm tm = *localtime(&T);
				
				is.day=tm.tm_mday;
				is.mon=tm.tm_mon+1;
				is.yr=tm.tm_year+1900;
				//char issue_r[]=uid;
				char issue_r1[20];
				int rack;
				
				FILE *bp=fopen("booksss.txt","r");
				book* bk;
				book* head;
				bk=(book *)malloc(sizeof(book));
				head=(book *)malloc(sizeof(book));

				head=bk;

				int cnt=0;
				while(1){
					book* tmp;
					tmp=(book *)malloc(sizeof(book));	
					int k=fscanf(bp,"%s",tmp->title);
					if(k==EOF)
						break;
					fscanf(bp,"%s",tmp->author);
					fscanf(bp,"%d",&tmp->count);
					fscanf(bp,"%d ",&tmp->rackno);
					fscanf(bp,"%d ",&tmp->reg_day);
					fscanf(bp,"%d ",&tmp->reg_mon);
					fscanf(bp,"%d ",&tmp->reg_yr);

					fscanf(bp,"%s ",tmp->issuer);
					fscanf(bp,"%d ",&tmp->iss_day);
					fscanf(bp,"%d ",&tmp->iss_mon);
					fscanf(bp,"%d ",&tmp->iss_yr);


					bk->next=tmp;
					bk=tmp;					

				}
				fclose(bp);
				FILE *gp=fopen("booksss.txt","w");
				head=head->next;
				int flag=0;
				while(head!=NULL){
					if(strcmp(btitle,head->title)==0 && strcmp(bauthor,head->author)==0 && strcmp("NA",head->issuer)==0 && cnt==0){	
						fprintf(gp,"%s ",head->title);
//&& strcmp("NA",head->issuer)==0 && cnt==0
						fprintf(gp,"%s ",head->author);
						fprintf(gp,"%d ",head->count);
						fprintf(gp,"%d ",head->rackno);
						fprintf(gp,"%d ",head->reg_day);
						fprintf(gp,"%d ",head->reg_mon);
						fprintf(gp,"%d ",head->reg_yr);
						fprintf(gp,"%s ",uid);
						fprintf(gp,"%d ",is.day);
						fprintf(gp,"%d ",is.mon);
						fprintf(gp,"%d",is.yr);

						fprintf(gp,"%s","\n");
						cnt++;
						
					}
					else{
						fprintf(gp,"%s ",head->title);

						fprintf(gp,"%s ",head->author);
						fprintf(gp,"%d ",head->count);
						fprintf(gp,"%d ",head->rackno);
						fprintf(gp,"%d ",head->reg_day);
						fprintf(gp,"%d ",head->reg_mon);
						fprintf(gp,"%d ",head->reg_yr);
						fprintf(gp,"%s ",head->issuer);
						fprintf(gp,"%d ",head->iss_day);
						fprintf(gp,"%d ",head->iss_mon);
						fprintf(gp,"%d",head->iss_yr);

						fprintf(gp,"%s","\n");
					}
					head=head->next;

				}	
				
						fclose(gp);
					
					//end
					
					system("clear");
					printf("\nBOOK INFO\n");
					printf("\nBOOK NAME_ %s",buk.title);
					printf("\nBOOK AUTHOR_ %s",buk.author);
					//printf("\nBOOK COUNT %d",bk.count);
					printf("\nBOOK RACK NUMBER_ %d",buk.rackno);
					printf("\nBOOK ENTERED ON_ %d-%d-%d",buk.reg_day,buk.reg_mon,buk.reg_yr);

					printf("\n\n");
					int c=0;
					while(1)
					{
						
					int nn=0;
					printf("\nfor going back to previous page press 1\n");
						if(c==0){
						printf("\nfor ISSUING BOOK PRESS 2 \n");}
										scanf("%d",&nn);
		
						if(nn==1)
							break;
						if(nn==2){
							system("clear");
							printf("\nRECIEPT\n");
							printf("\nBOOK NAME_ %s",buk.title);
							printf("\nBOOK AUTHOR_ %s",buk.author);
							printf("\nBOOK ISSUED by_ %s",uid);
							//printf("\nBOOK RACK NUMBERs %d",bk.rackno);
							printf("\nBOOK ENTERED ON_ %d-%d-%d",is.day,is.mon,is.yr);

									c++;	
							
							
						}
							
							
					}

					
				}
				if(f==0 && f2==0){
					printf("THIS BOOK IS NOT PRESENT\n");
					while(1)
					{
						int ch;
						printf("For going back press 1\n");
						scanf("%d",&ch);
					if(ch==1)
						break;
					}
					
				}
			}	
			if(op2==3)     //////////////// OPTION 2 FOR RETURNING BOOK, IF ISSUED///////
			{
				system("clear");
				printf("\nBOOK TRANSACTION/RETURN: \n");
				printf("\n***important** ENTER BOOK TITLE or AUHTOR IN ONE WORD ONLY(example -for book name ART is allowed but FINE ART is not allowed ): \n");

				//int sel;
				//printf("\nFOR ISSUING BOOK PRESS 1: \n");
				//printf("\nFOR RETURNING BOOK PRESS 2: \n");
				//printf("\nENTER YOUR CHOICE HERE_ ");
				//scanf("%d",&sel);
				char ret1[]="NA";
				
				date rt;
				rt.day=-1;
				rt.mon=-1;
				rt.yr=-1;

				char btitle[20],bauthor[20];
				printf("\nENTER BOOK NAME : ");
				scanf("%s",btitle);
				printf("\nENTER AUTHOR NAME : ");
				scanf("%s",bauthor);
				FILE* fp=fopen("booksss.txt","r");
				book buk;
				int f=0,f2=0;
				while(1){				
					int k1=fscanf(fp,"%s",buk.title);
					if(k1==EOF)
						break;
					fscanf(fp,"%s",buk.author);
					fscanf(fp,"%d",&buk.count);
					fscanf(fp,"%d",&buk.rackno);
					fscanf(fp,"%d",&buk.reg_day);
					fscanf(fp,"%d",&buk.reg_mon);
					fscanf(fp,"%d",&buk.reg_yr);
					fscanf(fp,"%s",buk.issuer);
					fscanf(fp,"%d",&buk.iss_day);
					fscanf(fp,"%d",&buk.iss_mon);
					fscanf(fp,"%d",&buk.iss_yr);
					

					if(strcmp(btitle,buk.title)==0 && strcmp(bauthor,buk.author)==0){
						f2=1;
					if(strcmp(uid,buk.issuer)==0){
						f=1;
					break;}
				
					}
				}
				if(f2==1 && f==0)
				{
					printf("THIS BOOK IS ISSUED BY SOMEONE ELSE\n");
					while(1)
					{
						int ch;
						printf("For going back press 1\n");
						scanf("%d",&ch);
					if(ch==1)
						break;
					}
				}
				if(f==1)
				{
					
					/**deleting the issuer name in the books file**/
				char title1[20],author1[20];
				 date rg,is,iss; 
				 time_t T= time(NULL);
				struct  tm tm = *localtime(&T);
				
				is.day=tm.tm_mday;
				is.mon=tm.tm_mon+1;
				is.yr=tm.tm_year+1900;
				//char issue_r[]=uid;
				char issue_r1[20];
				int rack;
				
				FILE *bp=fopen("booksss.txt","r");
				book* bk;
				book* head;
				bk=(book *)malloc(sizeof(book));
				head=(book *)malloc(sizeof(book));

				head=bk;

				int cnt=0;
				while(1){
					book* tmp;
					tmp=(book *)malloc(sizeof(book));	
					int k=fscanf(bp,"%s",tmp->title);
					if(k==EOF)
						break;
					fscanf(bp,"%s",tmp->author);
					fscanf(bp,"%d",&tmp->count);
					fscanf(bp,"%d ",&tmp->rackno);
					fscanf(bp,"%d ",&tmp->reg_day);
					fscanf(bp,"%d ",&tmp->reg_mon);
					fscanf(bp,"%d ",&tmp->reg_yr);

					fscanf(bp,"%s ",tmp->issuer);
					fscanf(bp,"%d ",&tmp->iss_day);
					fscanf(bp,"%d ",&tmp->iss_mon);
					fscanf(bp,"%d ",&tmp->iss_yr);


					bk->next=tmp;
					bk=tmp;					

				}
				fclose(bp);
				FILE *gp=fopen("booksss.txt","w");
				head=head->next;
				int flag=0;
				while(head!=NULL){
					if(strcmp(btitle,head->title)==0 && strcmp(bauthor,head->author)==0 && strcmp(uid,head->issuer)==0 && cnt==0){	
						fprintf(gp,"%s ",head->title);
//&& strcmp("NA",head->issuer)==0 && cnt==0
						fprintf(gp,"%s ",head->author);
						fprintf(gp,"%d ",head->count);
						fprintf(gp,"%d ",head->rackno);
						fprintf(gp,"%d ",head->reg_day);
						fprintf(gp,"%d ",head->reg_mon);
						fprintf(gp,"%d ",head->reg_yr);
						fprintf(gp,"%s ","NA");
						fprintf(gp,"%d ",rt.day);
						fprintf(gp,"%d ",rt.mon);
						fprintf(gp,"%d",rt.yr);

						fprintf(gp,"%s","\n");
						cnt++;
						
					}
					else{
						fprintf(gp,"%s ",head->title);

						fprintf(gp,"%s ",head->author);
						fprintf(gp,"%d ",head->count);
						fprintf(gp,"%d ",head->rackno);
						fprintf(gp,"%d ",head->reg_day);
						fprintf(gp,"%d ",head->reg_mon);
						fprintf(gp,"%d ",head->reg_yr);
						fprintf(gp,"%s ",head->issuer);
						fprintf(gp,"%d ",head->iss_day);
						fprintf(gp,"%d ",head->iss_mon);
						fprintf(gp,"%d",head->iss_yr);

						fprintf(gp,"%s","\n");
					}
					head=head->next;

				}	
				
						fclose(gp);
					
					//end
					
					system("clear");
					printf("\nBOOK INFO\n");
					printf("\nBOOK NAME_ %s",buk.title);
					printf("\nBOOK AUTHOR_ %s",buk.author);
					//printf("\nBOOK COUNT %d",bk.count);
					printf("\nBOOK RACK NUMBER_ %d",buk.rackno);
					printf("\nBOOK ENTERED ON_ %d-%d-%d",buk.reg_day,buk.reg_mon,buk.reg_yr);

					printf("\n\n");
					int c=0;
					while(1)
					{
						
					int nn=0;
					printf("\nfor going back to previous page press 1\n");
						if(c==0){
						printf("\nfor RETURNING BOOK PRESS 2 \n");}
										scanf("%d",&nn);
		
						if(nn==1)
							break;
						if(nn==2){
							system("clear");
							printf("\nRECIEPT\n");
							printf("\nBOOK NAME_ %s",buk.title);
							printf("\nBOOK AUTHOR_ %s",buk.author);
							printf("\nBOOK RETURNED by_ %s",uid);
							//printf("\nBOOK RACK NUMBERs %d",bk.rackno);
							//printf("\nBOOK ENTERED ON_ %d-%d-%d",is.day,is.mon,is.yr);

									c++;	
							
							
						}
							
							
					}

					
				}
				if(f==0 && f2==0){
					printf("THIS BOOK IS NOT PRESENT");
					while(1)
					{
						int ch;
						printf("For going back press 1\n");
						scanf("%d",&ch);
					if(ch==1)
						break;
					}
					
				}
			}
			if(op2==4)                         //// reservation of book is cancelled here
			{
				system("clear");
				printf("Delete book reservation: \n");
				printf("\n***important** ENTER BOOK TITLE,AUHTOR IN ONE WORD ONLY(example -for book name ART is allowed but FINE ART is not allowed ): \n");

				char b_name[20],b_author[20];
				printf("\nBook Name: ");
				scanf("%s",b_name);
				printf("\nAuthor's Name: ");
				scanf("%s",b_author);
				//printf("did %s\n",did);
				char bnm[20],bauth[20],bres[20];
				int ch1=exists("reservation.txt");
				if(ch1==1){
				FILE *fp=fopen("reservation.txt","r");
				if(fp==NULL)
					printf("fp\n");
				
				FILE *cp=fopen("tmp1.txt","w");
				if(cp==NULL)
					printf("cp\n");
				int flag=0;
				while(1){
				
					int k1=fscanf(fp,"%s",bnm);
					if(k1==EOF)
						break;
					fscanf(fp,"%s",bauth);
					fscanf(fp,"%s",bres);

					if(strcmp(bnm,b_name)==0 && strcmp(bauth,b_author)==0 && strcmp(bres,uid)==0){
								flag=1;
						}
					else{
						fprintf(cp,"%s ",bnm);
						fprintf(cp,"%s ",bauth);
						fprintf(cp,"%s ",bres);

						fprintf(cp,"%s","\n");
						}	
					}
					fclose(fp);
					fclose(cp);
					remove("reservation.txt");
					rename("tmp1.txt","reservation.txt");
					if(flag==0){
						printf("no reservation\n");
					}
					else{
						printf("reservation cancelled \n");

					}
					while(1)
					{
						int ch;
						printf("For going back press 1\n");
						scanf("%d",&ch);
					if(ch==1)
						break;
					}

				}	
				
			}
		}
		
	}
	else{
		system("clear");
		printf("wrong id/pass....\n");
		while(1)
		{	
			int ch;
			printf("\nFor going back press 1....\n");
			scanf("%d",&ch);
			if(ch==1)
				break;
		}
		
	}
					
		/////////////END OF USER SITE//////////////			

						
	
	
	
	
}




}
}
				