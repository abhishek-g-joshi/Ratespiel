			#include<stdio.h>
			#include<string.h>
			#include<conio.h>
			#include<time.h>
			#include <windows.h>
			#include"instructions.h"
			void displayscore(int);
			void que(char *);
			void mainmenu();
			typedef struct user
			{
			    char unm[10];
			    char up[10];
			    char name[20];
			    char mail[30];
			    char mno[10];
			}USR;
			typedef struct mrk
			{
				char usernm[20];
				float sc;
				float t;
				int pc;
				int nc;
			}MRK;
			MRK m;
			FILE *fs,*f;
			USR u;
			int search(char *id)
			{
				char nm[10];
			    int pos;
			    rewind(fs);
			    while(1)
			    {
			        fread(&u,sizeof(USR),1,fs);
			        if(feof(fs))
			        {
			            pos=-1;
			            break;
			        }
			        if(strcmp(u.unm,id)==0)
			        	break;
			        pos=ftell(fs);

			    }
			    return pos;
			}
			int searchloginid(char *id,char *p)
			{
				char nm[10];
			    int pos;
			    rewind(fs);
			    while(1)
			    {
			        fread(&u,sizeof(USR),1,fs);
			        if(feof(fs))
			        {
			            pos=-1;
			            break;
			        }
			        if(strcmp(u.unm,id)==0 && strcmp(u.up,p)==0)
			        	break;
			        pos=ftell(fs);

			    }
			    return pos;
			}
			void signup()
			{
			    char nm[10],p[15];
			    char pn[10],gm[30],name[20];;
			    int pos,i=0,j=0,k,cnt=0;
			    while(1)
			{
				printf("\n");
					for(k=0;k<70;k++)
			    	printf("***");
			    	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t** SIGN UP SECTION **");
			    	printf("\n\t\t\t\t\t\t\t\t\t\t\t  =================");
			    printf("\n\n");
			    while(1)
				{
					printf("\n\t* Enter Student Name:\n\t  ");
					fflush(stdin);
					scanf("%[^\n]s",name);
					printf("\n");
					for(k=0;k<70;k++)
			    	printf("---");
			    	j=0;
			    	while(j<=strlen(name))
			    	{
			    		if((name[j]>=65 &&name[j]<=90)||(name[j]>=97 &&name[j]<=122)||name[j]==32)
			    			j++;
			    		else
			    			break;
					}
					if(j!=strlen(name))
					{
						printf("\n\tInvalid Student Name.....Please try again\n");
					}
					else
						break;
				}
			    while(1)
				{
				
					printf("\n\t* Enter your Email address:\n\t  ");
					fflush(stdin);
					scanf("%s",gm);
					printf("\n");
					for(k=0;k<70;k++)
			    	printf("---");
			    	if((gm[0]<65 || gm[0]>90)&&(gm[0]<97|| gm[0]>122))
			    	{
			    		printf("\n\tInvalid E-Mail.....Please try again\n");
			    		continue;
					}
					j=0;
					while(j<=strlen(gm))
					{
						if(gm[j]=='@')
						{
						break;
						}
						j++;
					}
					if(j<=strlen(gm))
					{
						break;
					}
					else
						printf("\n\tInvalid E-Mail.....Please try again\n");
				}
				while(1)
				{
					printf("\n\t* Enter your mobile no:\n\t  ");
					fflush(stdin);
					scanf("%s",pn);
					printf("\n");
					for(k=0;k<70;k++)
			    	printf("---");
			    	if(pn[0]<'7')
			    	{
			    		printf("\n\tInvalid Mobile number...Please try again");
						continue;
			    		
					}
			    	j=0;
					if(strlen(pn)>10 || strlen(pn)<10)
					{
						printf("\n\tInvalid Mobile number...Please try again");
						continue;
					}
					else
					{
						while(j<10)
						{
							if(pn[j]>=48 && pn[j]<=57)
								j++;
							else
								break;
						}
					}
					if(j==10)
						break;
					else
						printf("\n\tInvalid Mobile number...Please try again");
				}
					
			    printf("\n\t* Enter Student's User Name\n\t  ");
			    fflush(stdin);
			  	scanf("%s",nm);
			  	printf("\n");
					for(k=0;k<70;k++)
			    	printf("---");
			    pos=search(nm);
			    if(pos>=0)
			    {
			        printf("\n\tThis account is already registered");
			        printf("\n\tPlease log in  to start your exam\n\n");
			        break;
			    }
			    //fflush(stdin);
			    while(1)
			    {
					fflush(stdin);
					i=0;
					cnt=0;
					printf("\n\t* Student's Password:\n\t  ");
					do{
			        	p[i]=getch();
			        	if(p[i]!='\r')
						{
								if(p[i]==8)
								{
									i--;
									printf("\b \b");
									continue;
								}
			            	printf("*");
			       		}
			        	i++;
			        	cnt++;
			   		 }while(p[i-1]!='\r');
			   		 p[i-1]='\0';
			   		if(cnt<6)
			   		 {
						printf("\n\tToo short Password.....Please try again\n");
			   		 }
			   		 else
			   		 {
						
			   		 	if(cnt>10)
			   		 	{
			   				printf("\n\tToo long Password.....Please try again\n");
						}
						else
			   		 		break;
			   		 }
			   	}
					
			    
			    printf("\n");
					for(k=0;k<70;k++)
			    	printf("---");
			    strcpy(u.unm,nm);
				strcpy(u.up,p);
				
				strcpy(u.name,name);
				strcpy(u.mail,gm);
				strcpy(u.mno,pn);
			    fwrite(&u,sizeof(USR),1,fs);
				printf("\n\n\t\t\tSuccessfully Registration of Student");
				printf("\n\n\t\t\tPlease \"Log In\" for Entering QUIZ");
				printf("\n\n\t\t\t\tPress \"ENTER\" to continue...");
				break;
				}
			}
			void home()
			{
				int cnt,i;
				char opt;
				system("cls");
			     for(i=0;i<70;i++)
			    	printf("===");
			    printf("\n\n\t\t\t\t\t\t\t\t\t***Welcome To RATESPIEL:A Programming Quiz***\n\n");
			    for(i=0;i<70;i++)
			    	printf("===");
			     puts("\n\n\t\t\t\t * Enter 'V' to view LEADERBOARD   ");
			     puts("\n\n\t\t\t\t * Enter 'H' for HELP            ");
			     puts("\n\n\t\t\t\t * Enter 'Q' to QUIT             ");
			     for(i=0;i<70;i++)
			    	printf("---");
			    printf("\n\n\t\t\t\tOption:");
			     opt=(toupper(getch()));
			    {
			     while(1)
			     {
				 	switch(opt)
				 	{

					case 'V':
					{
			     		system("cls");
			     		cnt=getcount();
			     		displayscore(cnt);
			     		getch();
			     		home();
			     		break;
			     	}
			     	case 'H':
			            {
			                system("cls");
			                help2();
			                home();
			                break;
			            }
			        case 'Q':
			        {
			             mainmenu();
			             break;
			        }
					}
				}
			     }
			}
			void login()
			{
			    char nm[10],p[10],opt;
			    int pos,i=0,k;
			    while(1)

			{
				printf("\n");
					for(k=0;k<70;k++)
			    	printf("***");
			    	printf("\n\n\t\t\t\t\t\t\t\t\t\t\tLOG IN SECTION");
			    	printf("\n\t\t\t\t\t\t\t\t\t\t\t===============");
			    printf("\n\n\n\t* Enter student's user name:\n\t ");
			  	scanf("%s",nm);
			  		for(k=0;k<70;k++)
			    	printf("---");
				printf("\n\n\n\t* Student's Password:\n\t");
				do{
			        p[i]=getch();
			        if(p[i]!='\r')
					{
			        		if(p[i]==8)
								{
									i--;
									printf("\b \b");
									continue;
								}
			            printf("*");
			        }
			        i++;
			    }while(p[i-1]!='\r');
			    p[i-1]='\0';
			    pos=searchloginid(nm,p);
			    printf("\n");
				for(k=0;k<70;k++)
			    printf("---");
			    if(pos<0)
			    {
			        printf("\n\n\t\t\t Incorrect Username or Password or This Student is not registered for Exam\n");
			        printf("\n\t\t\tPlease enter correct Username or Password or Please Singup to register for Exam.\n\n");
			        break;
			    }
				printf("\n\n\t\t\tThank you..!!\n\n\t\t\tYou have been Successfully login\n\n");
				printf("\n\n\n\t\t\t\t\t\t\t\t\tPlease press 'ENTER' to continue...!");
				getch();
				system("cls");
				instone();
				getch();
			    system("cls");
			     printf("\n\t\t\t\t\t\t\t\t\t     **** WELCOME TO RATESPIEL THE PROGRAMMING TEST****\n");
			     printf("\t\t\t\t\t\t\t\t\t         -------------------------------------------");
                 printf("\n\n");
					for(k=0;k<70;k++)
			    	printf("===");
                 puts("\n\n\n\t\t\t\t\t\t\t\t\t\t\t    Enter 'S' to START TEST");
				opt=(toupper(getch()));
				 if(opt=='S')
			     {
			         que(u.unm);
			         getch();
			         home();
			     }
				break;

				}
			}
			void display()
			{
				int i,j=0;
			    rewind(fs);
			    for(i=0;i<70;i++)
			    	printf("===");
			    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t***STUDENTS DETAILS***\n\t\t\t\t\t\t\t\t\t\t\n\n");
			    for(j=0;j<70;j++)
			    	printf("---");
			    printf("\n\t\t\tSr.No\t\tUSER ID\t\t\t\tPASSWORD\t\t\tNAME\t\t\t\tMAIL ID\t\t\t\tMOBILE NO\n");
			    for(j=0;j<70;j++)
			    	printf("---");
			    i=1;
			    while(1)
			    {
			    	fread(&u,sizeof(USR),1,fs);
			    	if(feof(fs))
			    		break;
			    	printf("\n\t\t\t %d.\t\t %-30s  %-30s%-30s%-30s\t%-30s\n",i,u.unm,u.up,u.name,u.mail,u.mno);
			    	i++;	
				}
				for(j=0;j<70;j++)
			    	printf("===");
			}
			void writescore(char *nm,float score,int pcnt,int ncnt,float treq)
			{
				float sc;
			 	char n[20];
			 	int i=0,j=0;
			 	FILE *f;
			 	f=fopen("myscore.dat","a+b");
			 	if(f==NULL)
			 	{
			 		f=fopen("myscore.dat","wb");
			 		fclose(f);
			 		f=fopen("myscore.dat","a+b");
				 }
			 		strcpy(m.usernm,nm);
				    sc=score;
				    m.sc=sc;
				    m.pc=pcnt;
				    m.nc=ncnt;
				    m.t=treq;
			     	fwrite(&m,sizeof(MRK),1,f);
			     	fclose(f);
			     	return;
			}
				int getcount()
				{
					int i=0,j=0,pos=0,tmp=0,d=0,cnt=0;
				    rewind(f);
				    f=fopen("myscore.dat","rb");
				    while(1)
				    {
				    	fread(&m,sizeof(MRK),1,f);
				    	if(feof(f))
				    		break;
				    	cnt++;
					}
					return cnt;
				}
				void displayscore(int cnt)
				{
				    int no;
				    int i=0,d=0,pos=0,tmp=0,j=0,k=0,apc[cnt],anc[cnt],tmp1=0,tmp2=0,tmp3=0;
				    float ac[cnt],atc[cnt];
				    char uname[cnt][15];
				    f=fopen("myscore.dat","rb");
				    if(f==NULL)
				    {
				    	printf("\n\n\n\n\t\t\tNo records found");
				    	getch();
				    	return;
					}
				    while(1)
				    {
				        fread(&m,sizeof(m),1,f);
				        if(feof(f))
				        {
				            break;
				        }
				        ac[i]=m.sc;
				        strcpy(uname[i],m.usernm);
				        apc[i]=m.pc;
				        anc[i]=m.nc;
				        atc[i]=m.t;
				        if(i==cnt)
				            break;
				        else
				            i++;
				    }
				    char tmpStr[15];
				        d=cnt;
				        for(i=0;i<d-1;i++)
				        {
				            pos=i;
				            for(j=i+1;j<d;j++)
				            {
				                if(ac[j]>ac[pos])
				                    pos=j;
				            }
				            if(i!=pos)
				            {
				               tmp=ac[i];
				                strcpy(tmpStr,uname[i]);
				                tmp1=apc[i];
				                tmp2=anc[i];
				                tmp3=atc[i];
				                ac[i]=ac[pos];
				                strcpy(uname[i],uname[pos]);
				                apc[i]=apc[pos];
				                anc[i]=anc[pos];
				                atc[i]=atc[pos];
				                ac[pos]=tmp;
				                strcpy(uname[pos],tmpStr);
				                apc[pos]=tmp1;
				                anc[pos]=tmp2;
				                atc[pos]=tmp3;
				            }
				        }
				    for(k=0;k<70;k++)
			    	printf("===");
			    	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t  ***STUDENT'S LEADERBOARD***\n\t\t\t\t\t\t\t\t\t\t\n\n");
			    	for(k=0;k<70;k++)
			    	printf("---");
			    	printf("\n\t\tUSER ID\t\t\t\tPOSITIVE QUESTIONS\t\t\tNEGATIVE QUESTIONS\t\t\tSCORE\t\t\tTIME REQUIRED\t\t\tRANK\n");
			    	for(k=0;k<70;k++)
			    	printf("---");
				    for( i=0;i<cnt;i++)
					{
				        printf("\n\t\t %-10s\t\t\t\t%-5d \t\t\t\t\t %-5d\t\t\t\t%-5.3f\t\t\t  %-5.3f\t\t\t  %-5d\n",uname[i],apc[i],anc[i],ac[i],atc[i],i+1);
				    }
				    for(k=0;k<70;k++)
			    	printf("===");
				    fclose(f);
				    return;
				}
			void que(char *nm)
			{
				int i,j,pcnt=0,ncnt=0,r1,r2,cnt=0,pcnt1=0,ncnt1=0;
				float score=0,marks=0,totmrk=0,treq=0,treq1=0;
				char opt,snm[20],ans;
				strcpy(snm,nm);
				time_t time1,time2,time3,time4;
				time(&time1);
				for(i=0;i<=8;i++)
				{
					system("cls");
					r1=i;
					switch(r1)
					{
					case 1:
					    printf("\n\n\n\n");
					    for(j=0;j<70;j++)
			    				printf("===");
						printf("\n\n\n\n\t\t1.who is the founder of C language ?");
						printf("\n\n\t\ta.Charls Babge          b.Denis Richie");
						printf("\n\t\tc.Steve Jobs          d.Bill Gets");
						printf("\n\n\t\tRight Your ans Here:");
							printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tPress 'Q' for QUIT the exam");
						ans=toupper(getch());
						if(ans=='Q')
						{
							system("cls");
							time(&time2);
							treq=difftime(time2, time1);
							marks=(float)pcnt*3-1*ncnt-difftime(time2, time1)/180;
							totmrk=(float)score+marks;
							printf("\n\n\n\n\n");
							 for(j=0;j<70;j++)
			    				printf("===");
			    			printf("\n\n\n\n\t\t\t\tGreat Job Mr/Miss: \"%s\"",nm);
							printf("\n\n\n\t\t\t\t\t\t\tYour score in Level 1 is %5.3f",score);
							printf("\n\n\n\t\t\t\t\t\t\tYour TOTAL score  is %5.3f",totmrk);
							printf("\n\n\n\n\t\t\t\t\t\t\tPlease press 'ENTER' to continue....\n\n\n\n\n\n\n\n\n");
							for(j=0;j<70;j++)
			    				printf("===");
							writescore(snm,totmrk,pcnt,ncnt,treq);
							return;
						}
						if(ans=='B')
							{
								printf("\n\n\t\tRight Answer\n\n");
								pcnt++;
								for(j=0;j<70;j++)
			    					printf("---");
								getch();
								break;
							}
						else
							{
								printf("\n\n\t\tWrong Answer:\n\t\tCorrect Ans is option b.Denis Richie\n\n");ncnt++;
								for(j=0;j<70;j++)
			    					printf("---");
								getch();break;
							}
							
					case 2:
						printf("\n\n\n\n");
						for(j=0;j<70;j++)
			    				printf("===");
						printf("\n\n\n\n\t\t2.What will be the output of following program?");
						printf("\n\t\t#include<stdio.h>\n\t\tvoid main()\n\t\t{\n\t\t\tint i = 10;\n\t\t\tstatic int x = i;\n\t\t\tif (x == i)\n\t\t\t\tprintf(\"equal\");\n\t\t\telse if (x < i)))\n\t\t\t\tprintf(\"less than\");\n\t\t\telse\n\t\t\t\tprintf(\"greater than\");\n\t\t}");
						printf("\n\t\tOptions:\n\t\ta.equal\n\t\tb.greater than\n\t\tc.less than\n\t\td.compiler error\n\t\te.none of the above");
						printf("\n\n\t\tRight Your ans Here:");
						printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tPress 'Q' for QUIT the exam");
						ans=toupper(getch());
						if(ans=='Q')
						{
							system("cls");
							time(&time2);
							treq=difftime(time2, time1);
							marks=(float)pcnt*3-1*ncnt-difftime(time2, time1)/180;
							totmrk=(float)score+marks;
							printf("\n\n\n\n\n");
							 for(j=0;j<70;j++)
			    				printf("===");
			    			printf("\n\n\n\n\t\t\t\tGreat Job Mr/Miss: \"%s\"",nm);
							printf("\n\n\n\t\t\t\t\t\t\tYour score in Level 1 is %5.3f",score);
							printf("\n\n\n\t\t\t\t\t\t\tYour TOTAL score  is %5.3f",totmrk);
							printf("\n\n\n\n\t\t\t\t\t\t\tPlease press 'ENTER' to continue....\n\n\n\n\n\n\n\n\n");
							for(j=0;j<70;j++)
			    				printf("===");
							writescore(snm,totmrk,pcnt,ncnt,treq);
							return;
						}
						if(ans=='D')
							{
								printf("\n\n\t\tRight Answer\n\n");
								pcnt++;
								for(j=0;j<70;j++)
			    					printf("---");	
								getch();break;

							}
						else
							{
								printf("\n\n\t\tWrong Answer:\n\t\tCorrect Ans is option d.compiler error\n\n");ncnt++;
								for(j=0;j<70;j++)
			    					printf("---");
								getch();break;
							}
						
					case 3:
						printf("\n\n\n\n");
						for(j=0;j<70;j++)
			    				printf("===");
						printf("\n\n\n\n\t\t3.What will be output if you will compile and execute the following c code?");
						printf("\n\t\t#include <stdio.h>\n\t\tint main()\n\t\t{\n\t\t\tint a = 5;\n\t\t\tfloat b;\n\t\t\tprintf(\"%%d \", sizeof(++a + b));\n\t\t\tprintf(\"%%d \", a);\n\t\t\treturn 0;\n\t\t} ");
						printf("\n\t\tOptions:\n\t\ta. 2 6\n\t\tb. 4 6\n\t\tc. 2 5\n\t\td. 4 5");
						printf("\n\n\t\tRight Your ans Here:");
						printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tPress 'Q' for QUIT the exam");
						ans=toupper(getch());
						if(ans=='Q')
						{
							system("cls");
							time(&time2);
							treq=difftime(time2, time1);
							marks=(float)pcnt*3-1*ncnt-difftime(time2, time1)/180;
							totmrk=(float)score+marks;
							printf("\n\n\n\n\n");
							 for(j=0;j<70;j++)
			    				printf("===");
			    			printf("\n\n\n\n\t\t\t\tGreat Job Mr/Miss: \"%s\"",nm);
							printf("\n\n\n\t\t\t\t\t\t\tYour score in Level 1 is %5.3f",score);
							printf("\n\n\n\t\t\t\t\t\t\tYour TOTAL score  is %5.3f",totmrk);
							printf("\n\n\n\n\t\t\t\t\t\t\tPlease press 'ENTER' to continue....\n\n\n\n\n\n\n\n\n");
							for(j=0;j<70;j++)
			    				printf("===");
							writescore(snm,totmrk,pcnt,ncnt,treq);
							return;
						}
						if(ans=='D')
							{
								printf("\n\n\t\tRight Answer\n\n");
								pcnt++;
								for(j=0;j<70;j++)
			    					printf("---");
								getch();break;

							}
						else
							{
								printf("\n\n\t\tWrong Answer:\n\t\tCorrect Ans is option d. 4 5\n\n");ncnt++;
								for(j=0;j<70;j++)
			    					printf("---");
								getch();break;
							}
							
					case 4:
						printf("\n\n\n\n");
						for(j=0;j<70;j++)
			    				printf("===");
						printf("\n\n\n\n\t\t4.What will be the output of following program?");
						printf("\n\t\t#include<stdio.h>\n\t\tvoid main()\n\t\t{\n\t\t\tprintf(\"\%%s\", \"i\"\n\t\t\t\t\"am\"\n\t\t\t\t\"good\");\n\t\t}");
						printf("\n\t\tOptions:\n\t\ta. i am good\n\t\tb. i\n\t\tc. good\n\t\td. iamgood\n\t\te. Compiler error");
						printf("\n\n\t\tRight Your ans Here:");
						printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tPress 'Q' for QUIT the exam");
						ans=toupper(getch());
						if(ans=='Q')
						{
							system("cls");
							time(&time2);
							treq=difftime(time2, time1);
							marks=(float)pcnt*3-1*ncnt-difftime(time2, time1)/180;
							totmrk=(float)score+marks;
							printf("\n\n\n\n\n");
							 for(j=0;j<70;j++)
			    				printf("===");
			    			printf("\n\n\n\n\t\t\t\tGreat Job Mr/Miss: \"%s\"",nm);
							printf("\n\n\n\t\t\t\t\t\t\tYour score in Level 1 is %5.3f",score);
							printf("\n\n\n\t\t\t\t\t\t\tYour TOTAL score  is %5.3f",totmrk);
							printf("\n\n\n\n\t\t\t\t\t\t\tPlease press 'ENTER' to continue....\n\n\n\n\n\n\n\n\n");
							for(j=0;j<70;j++)
			    				printf("===");
							writescore(snm,totmrk,pcnt,ncnt,treq);
							return;
						}
						if(ans=='D')
							{
								printf("\n\n\t\tRight Answer\n\n");
								pcnt++;
								for(j=0;j<70;j++)
			    					printf("---");
								getch();break;

							}
						else
							{
								printf("\n\n\t\tWrong Answer:\n\t\tCorrect Ans is option d.iamgood\n\n");ncnt++;
								for(j=0;j<70;j++)
			    					printf("---");
								getch();
								break;
							}
							
					case 5:
						printf("\n\n\n\n");
						for(j=0;j<70;j++)
			    				printf("===");
						printf("\n\n\n\n\t\t5.What is the output of following program?");
						printf("\n\t\t#include <stdio.h>\n\t\tint main()\n\t\t{\n\t\t\tif (0)\n\t\t\t;\n\t\t\tprintf(\"Hello\");\n\t\t\tprintf(\"Hi\");\n\t\t\treturn 0;\n\t\t} ");
						printf("\n\t\tOptions:\n\t\ta. Hi\n\t\tb. HelloHi\n\t\tc. run time error\n\t\td. None of the mentioned");
						printf("\n\n\t\tRight Your ans Here:");
						printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tPress 'Q' for QUIT the exam");
						ans=toupper(getch());
						if(ans=='Q')
						{
							system("cls");
							time(&time2);
							treq=difftime(time2, time1);
							marks=(float)pcnt*3-1*ncnt-difftime(time2, time1)/180;
							totmrk=(float)score+marks;
							printf("\n\n\n\n\n");
							 for(j=0;j<70;j++)
			    				printf("===");
			    			printf("\n\n\n\n\t\t\t\tGreat Job Mr/Miss: \"%s\"",nm);
							printf("\n\n\n\t\t\t\t\t\t\tYour score in Level 1 is %5.3f",score);
							printf("\n\n\n\t\t\t\t\t\t\tYour TOTAL score  is %5.3f",totmrk);
							printf("\n\n\n\n\t\t\t\t\t\t\tPlease press 'ENTER' to continue....\n\n\n\n\n\n\n\n\n");
							for(j=0;j<70;j++)
			    				printf("===");
							writescore(snm,totmrk,pcnt,ncnt,treq);
							return;
						}
						if(ans=='B')
							{
								printf("\n\n\t\tRight Answer\n\n");
								pcnt++;
								for(j=0;j<70;j++)
			    					printf("---");
								getch();break;

							}
						else
							{
								printf("\n\n\t\tWrong Answer:\n\t\tCorrect Ans is option b. HelloHi\n\n");ncnt++;
								for(j=0;j<70;j++)
			    					printf("---");
								getch();break;
							}
							
					case 6:
						printf("\n\n\n\n");
						for(j=0;j<70;j++)
			    				printf("===");
						printf("\n\n\n\n\t\t6.Which of the following true about FILE *fp ?");
						printf("\n\t\tOptions:\n\t\ta. FILE is a keyword in C for representing files and fp is a variable of FILE type.");
						printf("\n\t\tb. FILE is a structure and fp is a pointer to the structure of FILE type.");
				 		printf("\n\t\tc. FILE is a stream");
			     		printf("\n\t\td. FILE is a buffered stream.");
			     		printf("\n\n\t\tRight Your ans Here:");
			     		printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tPress 'Q' for QUIT the exam");
			     		ans=toupper(getch());
			     		if(ans=='Q')
						{
							system("cls");
							time(&time2);
							treq=difftime(time2, time1);
							marks=(float)pcnt*3-1*ncnt-difftime(time2, time1)/180;
							totmrk=(float)score+marks;
							printf("\n\n\n\n\n");
							 for(j=0;j<70;j++)
			    				printf("===");
			    			printf("\n\n\n\n\t\t\t\tGreat Job Mr/Miss: \"%s\"",nm);
							printf("\n\n\n\t\t\t\t\t\t\tYour score in Level 1 is %5.3f",score);
							printf("\n\n\n\t\t\t\t\t\t\tYour TOTAL score  is %5.3f",totmrk);
							printf("\n\n\n\n\t\t\t\t\t\t\tPlease press 'ENTER' to continue....\n\n\n\n\n\n\n\n\n");
							for(j=0;j<70;j++)
			    				printf("===");
							writescore(snm,totmrk,pcnt,ncnt,treq);
							return;
						}
			     		if(ans=='B')
							{
								printf("\n\n\t\tRight Answer\n\n");
								pcnt++;
								for(j=0;j<70;j++)
			    					printf("---");
								getch();break;

							}
						else
							{
								printf("\n\n\t\tWrong Answer:\n\t\tCorrect Ans is option b.FILE is a structure and fp is a pointer to the structure of FILE type.\n\n");ncnt++;
								for(j=0;j<70;j++)
			    					printf("---");
								getch();break;
							}
							
					case 7:
						printf("\n\n\n\n");
						for(j=0;j<70;j++)
			    				printf("===");
						printf("\n\n\n\n\t\t7.In fopen(), the open mode \"wx\" is sometimes preferred \"w\" because.");
						printf("\n\n\t\t1) Use of wx is more efficient.\n\t\t2) If w is used, old contents of file are erased and a new empty file is created. When wx is used, fopen() returns NULL if file already exists.");
						printf("\n\t\tOptions:\n\t\t a.Only 1\n\t\tb. Only 2\n\t\tc. Both 1 and 2\n\t\td. Neither 1 nor 2");
						printf("\n\n\t\tRight Your ans Here:");
						printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tPress 'Q' for QUIT the exam");
						ans=toupper(getch());
						if(ans=='Q')
						{
							system("cls");
							time(&time2);
							treq=difftime(time2, time1);
							marks=(float)pcnt*3-1*ncnt-difftime(time2, time1)/180;
							totmrk=(float)score+marks;
							printf("\n\n\n\n\n");
							 for(j=0;j<70;j++)
			    				printf("===");
			    			printf("\n\n\n\n\t\t\t\tGreat Job Mr/Miss: \"%s\"",nm);
							printf("\n\n\n\t\t\t\t\t\t\tYour score in Level 1 is %5.3f",score);
							printf("\n\n\n\t\t\t\t\t\t\tYour TOTAL score  is %5.3f",totmrk);
							printf("\n\n\n\n\t\t\t\t\t\t\tPlease press 'ENTER' to continue....\n\n\n\n\n\n\n\n\n");
							for(j=0;j<70;j++)
			    				printf("===");
							writescore(snm,totmrk,pcnt,ncnt,treq);
							return;
						}
						if(ans=='B')
							{
								printf("\n\n\t\tRight Answer\n\n");
								pcnt++;
								for(j=0;j<70;j++)
			    					printf("---");
								getch();break;

							}
						else
							{
								printf("\n\n\t\tWrong Answer:\n\t\tCorrect Ans is option b.Only 2\n\n");ncnt++;
								for(j=0;j<70;j++)
			    					printf("---");
								getch();break;
							}
							
					case 8:
						printf("\n\n\n\n");
						for(j=0;j<70;j++)
			    				printf("===");
						printf("\n\n\n\n\t\t8.Which of the following functions from \"stdio.h\" can be used in place of printf()?");
						printf("\n\t\tOptions:\n\t\ta. fputs() with FILE stream as stdout.\n\t\tb. fprintf() with FILE stream as stdout.\n\t\tc. fwrite() with FILE stream as stdout.\n\t\td. All of the above three – a, b and c.\n\t\te. In \"stdio.h\", there's no other equivalent function of printf().");
						printf("\n\n\t\tRight Your ans Here:");
						printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tPress 'Q' for QUIT the exam");
						ans=toupper(getch());
						if(ans=='Q')
						{
							system("cls");
							time(&time2);
							treq=difftime(time2, time1);
							marks=(float)pcnt*3-1*ncnt-difftime(time2, time1)/180;
							totmrk=(float)score+marks;
							printf("\n\n\n\n\n");
							 for(j=0;j<70;j++)
			    				printf("===");
			    			printf("\n\n\n\n\t\t\t\tGreat Job Mr/Miss: \"%s\"",nm);
							printf("\n\n\n\t\t\t\t\t\t\tYour score in Level 1 is %5.3f",score);
							printf("\n\n\n\t\t\t\t\t\t\tYour TOTAL score  is %5.3f",totmrk);
							printf("\n\n\n\n\t\t\t\t\t\t\tPlease press 'ENTER' to continue....\n\n\n\n\n\n\n\n\n");
							for(j=0;j<70;j++)
			    				printf("===");
							writescore(snm,totmrk,pcnt,ncnt,treq);
							return;
						}
						if(ans=='B')
							{
								printf("\n\n\t\tRight Answer\n\n");
								pcnt++;
								for(j=0;j<70;j++)
			    					printf("---");
								getch();break;

							}
						else
							{
								printf("\n\n\t\tWrong Answer:\n\t\tCorrect Ans is option b.fprintf() with FILE stream as stdout\n\n");ncnt++;
								for(j=0;j<70;j++)
			    					printf("---");
								getch();break;
							}
							
					}

				}
				system("cls");
				time(&time2); 
				treq=difftime(time2, time1);
				pcnt1=pcnt;
				ncnt1=ncnt; 
				score=(float)3*pcnt-ncnt-difftime(time2, time1)/180;
				printf("\n\n\n\n\n");
				 for(i=0;i<70;i++)
			    	printf("===");
			    	printf("\n\n\n\n\t\t\t\tGreat Job Mr/Miss: \"%s\"",nm);
				printf("\n\n\n\t\t\t\t\t\t\tYour score in Level 1 is %5.3f",score);
				printf("\n\n\n\n\t\t\t\t\t\t\tPlease press 'ENTER' to continue....\n\n\n\n\n\n\n\n\n");
				for(i=0;i<70;i++)
			    	printf("===");
				
				getch();
				if(score>=10)
				{
					system("cls");
					printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tCongratulation Mr/Miss \"%s\" are done with LEVEL 1..!!! And you are selected for LEVEL 2\n\n\n\t\t\t\t\t\t\t\t\tPress any key for LEVEL 2 or press 'S' for submit test",nm);
					if(toupper(getch())=='S')
					{
						totmrk=(float)score+marks;
						writescore(snm,totmrk,pcnt,ncnt,treq);
						getch();
						return home();
					}
					else
					{
				pcnt=0,ncnt=0;
				system("cls");
				printf("\n");
				for(i=0;i<70;i++)
					printf("===");
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t****Welcome to Level 2****");
				insttwo();
				getch();
				time(&time3);
				for(i=0;i<=10;i++)
				{
					system("cls");
					r2=i;
					switch(r2)
					{
					case 1:
						printf("\n\n\n\n");
						for(j=0;j<70;j++)
			    				printf("===");
						printf("\n\n\n\n\t\t1.What is the output of following program?");
						printf("\n\t\tinclude‹stdio.h›\n\t\tint main()\n\t\t{\n\t\t\tstruct site\n\t\t\t{\n\t\t\t\tchar name[] = \"GeeksQuiz\";\n\t\t\t\tint no_of_pages = 200;\n\t\t\t};\n\t\t\tstruct site *ptr;\n\t\t\tprintf(\"%%d \", ptr->no_of_pages);\n\t\t\tprintf(\"%%s\", ptr->name);\n\t\t\tgetchar();\n\t\t\treturn 0;\n\t\t} ");
						printf("\n\t\tOptions:\n\t\ta. 200 GeeksQuiz\n\t\tb. 200\n\t\tc. Runtime Error\n\t\td. Compiler Error");
						printf("\n\n\t\t\t\t* Enter 'E' to skip this question\t\t\t\t\t\t\t\t\t* Press 'Q' for QUIT the exam\n\n");
						printf("\n\n\t\tRight Your ans Here:");
						ans=toupper(getch());
						if(ans=='E')
						{
							break;
						}
						if(ans=='Q')
						{
							system("cls");
							time(&time4);
							treq1=difftime(time4, time3);
							marks=(float)pcnt*5-2*ncnt-difftime(time4, time3)/300;
							totmrk=(float)score+marks;
							printf("\n\n\n\n\n");
				 			for(j=0;j<70;j++)
			    				printf("===");
			    			printf("\n\n\n\n\t\t\t\tGreat Job Mr/Miss: \"%s\"",nm);
							printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tYour score in Level 2 is %5.3f",score);
							printf("\n\n\t\t\t\t\t\t\t\t\t\t\tYour Total Score is %5.3f",totmrk);
							printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\tPlease press 'ENTER' to continue\n\n\n\n\n\n\n\n\n");
							for(j=0;j<70;j++)
			    				printf("===");
							pcnt=pcnt1+pcnt;
							ncnt=ncnt1+ncnt;
							treq=treq1+treq;
							writescore(snm,totmrk,pcnt,ncnt,treq);
							return;
						}
						if(ans=='D')
							{
								printf("\n\n\t\tRight Answer\n\n");
								pcnt++;
								for(j=0;j<70;j++)
			    					printf("---");
								getch();break;

							}
						else
							{
								printf("\n\n\t\tWrong Answer:\n\t\tCorrect Ans is option d.Compiler Error\n\n");ncnt++;
								for(j=0;j<70;j++)
			    					printf("---");
								getch();break;
							}
							
					case 2:
						printf("\n\n\n\n");
						for(j=0;j<70;j++)
			    				printf("===");
						printf("\n\n\n\n\t\t2.What is the output of following program?");
						printf("\n\t\t#include<stdio.h>\n\t\tstruct Point\n\t\t{\n\t\t\tint x, y, z;\n\t\t};\n\t\tint main()\n\t\t{\n\t\t\tstruct Point p1 = {.y = 0, .z = 1, .x = 2};\n\t\t\tprintf(\"%%d %%d %%d\", p1.x, p1.y, p1.z);\n\t\t\treturn 0;\n\t\t}");
						printf("\n\t\tOptions:\n\t\ta. Compiler Error\n\t\tb. 2 0 1\n\t\tc. 0 1 2\n\t\td. 2 1 0");
						printf("\n\n\t\t\t\t* Enter 'E' to skip this question\t\t\t\t\t\t\t\t\t*Press 'Q' for QUIT the exam\n\n");
						printf("\n\n\t\tRight Your ans Here:");
						ans=toupper(getch());
						if(ans=='E')
						{
							break;
						}
						if(ans=='Q')
						{
							system("cls");
							time(&time4);
							treq1=difftime(time4, time3);
							marks=(float)pcnt*5-2*ncnt-difftime(time4, time3)/300;
							totmrk=(float)score+marks;
							printf("\n\n\n\n\n");
				 			for(j=0;j<70;j++)
			    				printf("===");
			    			printf("\n\n\n\n\t\t\t\tGreat Job Mr/Miss: \"%s\"",nm);
							printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tYour score in Level 2 is %5.3f",score);
							printf("\n\n\t\t\t\t\t\t\t\t\t\t\tYour Total Score is %5.3f",totmrk);
							printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\tPlease press 'ENTER' to continue\n\n\n\n\n\n\n\n\n");
							for(j=0;j<70;j++)
			    				printf("===");
							pcnt=pcnt1+pcnt;
							ncnt=ncnt1+ncnt;
							treq=treq1+treq;
							writescore(snm,totmrk,pcnt,ncnt,treq);
							return;
						}
						if(ans=='B')
							{
								printf("\n\n\t\tRight Answer\n\n");
								pcnt++;
								for(j=0;j<70;j++)
			    					printf("---");
								getch();break;

							}
						else
							{
								printf("\n\n\t\tWrong Answer:\n\t\tCorrect Ans is option b.2 0 1\n\n");ncnt++;
								for(j=0;j<70;j++)
			    					printf("---");
								getch();break;
							}
					case 3:
						printf("\n\n\n\n");
						for(j=0;j<70;j++)
			    				printf("===");
						printf("\n\n\n\n\t\t3.What is the output of following program?");
						printf("\n\t\t#include <stdio.h>\n\t\tint main()\n\t\t{\n\t\t\tint i;\n\t\t\tfor (i = 1; i != 10; i += 2)\n\t\t\t\tprintf(\" GeeksQuiz \");\n\t\t\treturn 0;\n\t\t}");
						printf("\n\t\tOptions:\n\t\ta. GeeksQuiz GeeksQuiz GeeksQuiz GeeksQuiz GeeksQuiz\n\t\tb. GeeksQuiz GeeksQuiz GeeksQuiz …. infinite times\n\t\tc. GeeksQuiz GeeksQuiz GeeksQuiz GeeksQuiz\n\t\td.GeeksQuiz GeeksQuiz GeeksQuiz GeeksQuiz GeeksQuiz GeeksQuiz");
			 			printf("\n\n\t\t\t\t*Enter 'E' to skip this question\t\t\t\t\t\t\t\t\t*Press 'Q' for QUIT the exam\n\n");
			 			printf("\n\n\t\tRight Your ans Here:");
			 			ans=toupper(getch());
						if(ans=='E')
						{
							break;
						}
						if(ans=='Q')
						{
							system("cls");
							time(&time4);
							treq1=difftime(time4, time3);
							marks=(float)pcnt*5-2*ncnt-difftime(time4, time3)/300;
							totmrk=(float)score+marks;
							printf("\n\n\n\n\n");
				 			for(j=0;j<70;j++)
			    				printf("===");
			    			printf("\n\n\n\n\t\t\t\tGreat Job Mr/Miss: \"%s\"",nm);
							printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tYour score in Level 2 is %5.3f",score);
							printf("\n\n\t\t\t\t\t\t\t\t\t\t\tYour Total Score is %5.3f",totmrk);
							printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\tPlease press 'ENTER' to continue\n\n\n\n\n\n\n\n\n");
							for(j=0;j<70;j++)
			    				printf("===");
							pcnt=pcnt1+pcnt;
							ncnt=ncnt1+ncnt;
							treq=treq1+treq;
							writescore(snm,totmrk,pcnt,ncnt,treq);
							return;
						}
						if(ans=='B')
							{
								printf("\n\n\t\tRight Answer\n\n");
								pcnt++;
								for(j=0;j<70;j++)
			    					printf("---");
								getch();break;

							}
						else
							{
								printf("\n\n\t\tWrong Answer:\n\t\tCorrect Ans is option b.GeeksQuiz GeeksQuiz GeeksQuiz …. infinite times\n\n");ncnt++;
								for(j=0;j<70;j++)
			    					printf("---");
								getch();break;
							}
					case 4:
						printf("\n\n\n\n");
						for(j=0;j<70;j++)
			    				printf("===");
						printf("\n\n\n\n\t\t4.What is the output of following program?");
						printf("\n\t\t#include <iostream>\n\t\t#include <string.h>\n\t\tusing namespace std;\n\n\t\tstruct Test\n\t\t{\n\t\t\tchar str[20];\n\t\t};\n\t\tint main()\n\t\t{\n\t\t\tstruct Test st1, st2;\n\t\t\tstrcpy(st1.str, \"GeeksQuiz\");\n\t\t\tst2 = st1;st1.str[0] = 'S';\n\t\t\tcout << st2.str;\n\t\t\treturn 0;\t\t}");
						printf("\n\t\tOptions:\n\t\ta. Segmentation Fault\n\t\tb. SeeksQuiz\n\t\tc. GeeksQuiz\n\t\td. Compiler Error");
							printf("\n\n\t\t\t\t*Enter 'E' to skip this question\t\t\t\t\t\t\t*Press 'Q' for QUIT the exam\n\n");
						printf("\n\n\t\tRight Your ans Here:");
						ans=toupper(getch());
						if(ans=='E')
						{
							break;
						}
						if(ans=='Q')
						{
							system("cls");
							time(&time4);
							treq1=difftime(time4, time3);
							marks=(float)pcnt*5-2*ncnt-difftime(time4, time3)/300;
							totmrk=(float)score+marks;
							printf("\n\n\n\n\n");
				 			for(j=0;j<70;j++)
			    				printf("===");
			    			printf("\n\n\n\n\t\t\t\tGreat Job Mr/Miss: \"%s\"",nm);
							printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tYour score in Level 2 is %5.3f",score);
							printf("\n\n\t\t\t\t\t\t\t\t\t\t\tYour Total Score is %5.3f",totmrk);
							printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\tPlease press 'ENTER' to continue\n\n\n\n\n\n\n\n\n");
							for(j=0;j<70;j++)
			    				printf("===");
							pcnt=pcnt1+pcnt;
							ncnt=ncnt1+ncnt;
							treq=treq1+treq;
							writescore(snm,totmrk,pcnt,ncnt,treq);
							return;
						}
						if(ans=='C')
							{
								printf("\n\n\t\tRight Answer\n\n");
								pcnt++;
								for(j=0;j<70;j++)
			    					printf("---");
								getch();break;

							}
						else
							{
								printf("\n\n\t\tWrong Answer:\n\t\tCorrect Ans is option c.GeeksQuiz\n\n");ncnt++;
								for(j=0;j<70;j++)
			    					printf("---");
								getch();break;
							}
					case 5:
						printf("\n\n\n\n");
						for(j=0;j<70;j++)
			    				printf("===");
						printf("\n\n\t\t5.\n\t\tint var1;\n\t\textern int var2;\n\t\tWhich of the following statements is correct ?");
						printf("\n\t\tOptions:\n\t\ta. Both statements only declare variables, don’t define them.\n\t\tb. First statement declares and defines var1, but second statement only declares var2\n\t\tc. Both statements declare define variables var1 and var2");
						printf("\n\n\t\t\t\t*Enter 'E' to skip this question\t\t\t\t\t\t\t\t\t*Press 'Q' for QUIT the exam\n\n");
						printf("\n\n\t\tRight Your ans Here:");
						ans=toupper(getch());
						if(ans=='E')
						{
							break;
						}
						if(ans=='Q')
						{
							system("cls");
							time(&time4);
							treq1=difftime(time4, time3);
							marks=(float)pcnt*5-2*ncnt-difftime(time4, time3)/300;
							totmrk=(float)score+marks;
							printf("\n\n\n\n\n");
				 			for(j=0;j<70;j++)
			    				printf("===");
			    			printf("\n\n\n\n\t\t\t\tGreat Job Mr/Miss: \"%s\"",nm);
							printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tYour score in Level 2 is %5.3f",score);
							printf("\n\n\t\t\t\t\t\t\t\t\t\t\tYour Total Score is %5.3f",totmrk);
							printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\tPlease press 'ENTER' to continue\n\n\n\n\n\n\n\n\n");
							for(j=0;j<70;j++)
			    				printf("===");
							pcnt=pcnt1+pcnt;
							ncnt=ncnt1+ncnt;
							treq=treq1+treq;
							writescore(snm,totmrk,pcnt,ncnt,treq);
							return;
						}
						if(ans=='B')
							{
								printf("\n\n\t\tRight Answer\n\n");
								pcnt++;
								for(j=0;j<70;j++)
			    					printf("---");
								getch();break;

							}
						else
							{
								printf("\n\n\t\tWrong Answer:\n\t\tCorrect Ans is option b.First statement declares and defines var1, but second statement only declares var2\n\n");ncnt++;
								for(j=0;j<70;j++)
			    					printf("---");
								getch();break;
							}
			        case 6:
			        	printf("\n\n\n\n");
			        	for(j=0;j<70;j++)
			    				printf("===");
			        	printf("\n\n\n\n\t\t6.#include\"stdio.h\"\n\t\t#include\"stdlib.h\"\n\t\tvoid reverse(int i)\n\t\t{\n\t\t\tif (i > 5)\n\t\t\t\texit(0);\n\t\t\tprintf(\"%%d\", i);\n\t\t\treturn reverse(i++);\n\t\t}\n\n\t\tint main()\n\t\t{\n\t\t\treverse(1);\n\t\t}") ;
			        	printf("\n\t\tOptions:\n\t\ta. Segmenation fault\n\t\tb. Compilation errorc\n\t\tc. Print 1 Infinite time\n\t\td. Both a & c");
			        	printf("\n\n\t\t\t\t*Enter 'E' to skip this question\t\t\t\t\t\t\t\t\t*Press 'Q' for QUIT the exam\n\n");
						printf("\n\n\t\tRight Your ans Here:");
						ans=toupper(getch());
						if(ans=='E')
						{
							break;
						}
						if(ans=='Q')
						{
							system("cls");
							time(&time4);
							treq1=difftime(time4, time3);
							marks=(float)pcnt*5-2*ncnt-difftime(time4, time3)/300;
							totmrk=(float)score+marks;
							printf("\n\n\n\n\n");
				 			for(j=0;j<70;j++)
			    				printf("===");
			    			printf("\n\n\n\n\t\t\t\tGreat Job Mr/Miss: \"%s\"",nm);
							printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tYour score in Level 2 is %5.3f",score);
							printf("\n\n\t\t\t\t\t\t\t\t\t\t\tYour Total Score is %5.3f",totmrk);
							printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\tPlease press 'ENTER' to continue\n\n\n\n\n\n\n\n\n");
							for(j=0;j<70;j++)
			    				printf("===");
							pcnt=pcnt1+pcnt;
							ncnt=ncnt1+ncnt;
							treq=treq1+treq;
							writescore(snm,totmrk,pcnt,ncnt,treq);
							return;
						}
						if(ans=='D')
							{
								printf("\n\n\t\tRight Answer\n\n");
								pcnt++;
								for(j=0;j<70;j++)
			    					printf("---");
								getch();break;

							}
						else
							{
								printf("\n\n\t\tWrong Answer:\n\t\tCorrect Ans is option d.Both a & c\n\n");ncnt++;
								for(j=0;j<70;j++)
			    					printf("---");
								getch();break;
							}
			        case 7:
			        	printf("\n\n\n\n");
			        	for(j=0;j<70;j++)
			    				printf("===");
			        	printf("\n\n\n\n\t\t7.int main()\n\t\t{\n\t\t\tfloat a=0.7d; \n\t\t\tif(a<0.7)\n\t\t\t\tprintf(\"C\");\n\t\t\telse\n\t\t\t\tprintf(\"C++\");\n\t\t\treturn 0;\t\t\n}");
			        	printf("\n\t\tOptions:\n\t\ta. Compilation error\n\t\tb. C++\n\t\tc. C\n\t\td. None of the Above");
			        		printf("\n\n\t\t\t\t*Enter 'E' to skip this question\t\t\t\t\t\t\t\t\t*Press 'Q' for QUIT the exam\n\n");
						printf("\n\n\t\tRight Your ans Here:");
						ans=toupper(getch());
			        	if(ans=='E')
						{
							break;
						}
						if(ans=='Q')
						{
							system("cls");
							time(&time4);
							treq1=difftime(time4, time3);
							marks=(float)pcnt*5-2*ncnt-difftime(time4, time3)/300;
							totmrk=(float)score+marks;
							printf("\n\n\n\n\n");
				 			for(j=0;j<70;j++)
			    				printf("===");
			    			printf("\n\n\n\n\t\t\t\tGreat Job Mr/Miss: \"%s\"",nm);
							printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tYour score in Level 2 is %5.3f",score);
							printf("\n\n\t\t\t\t\t\t\t\t\t\t\tYour Total Score is %5.3f",totmrk);
							printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\tPlease press 'ENTER' to continue\n\n\n\n\n\n\n\n\n");
							for(j=0;j<70;j++)
			    				printf("===");
							pcnt=pcnt1+pcnt;
							ncnt=ncnt1+ncnt;
							treq=treq1+treq;
							writescore(snm,totmrk,pcnt,ncnt,treq);
							return;
						}
						if(ans=='C')
							{
								printf("\n\n\t\tRight Answer\n\n");
								pcnt++;
								for(j=0;j<70;j++)
			    					printf("---");
								getch();break;

							}
						else
							{
								printf("\n\n\t\tWrong Answer:\n\t\tCorrect Ans is option c.C\n\n");ncnt++;
								for(j=0;j<70;j++)
			    					printf("---");
								getch();break;
							}
			        case 8:
			        	printf("\n\n\n\n");
			        	for(j=0;j<70;j++)
			    				printf("===");
			        	printf("\n\n\n\n\t\t8.nclude <iostream>\n\t\tusing namespace std;\n\t\tint main() \n\t\t{\n\t\t\tchar i = 0;\n\t\t\tfor(; i++; printf(\"%%d\", i))\n\t\t\t\t;\n\t\t\tprintf(\"%%d\", i);\n\t\t\treturn 0;\n\t\t}");
			        	printf("\n\t\tOptions:\n\t\ta. 0 1 2 … infinite times\n\t\tb. 0 1 2 … 127\n\t\tc. 0\n\t\td. 1");
			        	printf("\n\n\t\t\t\t*Enter 'E' to skip this question\t\t\t\t\t\t\t\t\t*Press 'Q' for QUIT the exam\n\n");
						printf("\n\n\t\tRight Your ans Here:");
						ans=toupper(getch());
			        	if(ans=='E')
						{
							break;
						}
						if(ans=='Q')
						{
							system("cls");
							time(&time4);
							treq1=difftime(time4, time3);
							marks=(float)pcnt*5-2*ncnt-difftime(time4, time3)/300;
							totmrk=(float)score+marks;
							printf("\n\n\n\n\n");
				 			for(j=0;j<70;j++)
			    				printf("===");
			    			printf("\n\n\n\n\t\t\t\tGreat Job Mr/Miss: \"%s\"",nm);
							printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tYour score in Level 2 is %5.3f",score);
							printf("\n\n\t\t\t\t\t\t\t\t\t\t\tYour Total Score is %5.3f",totmrk);
							printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\tPlease press 'ENTER' to continue\n\n\n\n\n\n\n\n\n");
							for(j=0;j<70;j++)
			    				printf("===");
							pcnt=pcnt1+pcnt;
							ncnt=ncnt1+ncnt;
							treq=treq1+treq;
							writescore(snm,totmrk,pcnt,ncnt,treq);
							
							return;
						}
						if(ans=='D')
							{
								printf("\n\n\t\tRight Answer\n\n");
								pcnt++;
								for(j=0;j<70;j++)
			    					printf("---");
								getch();break;

							}
						else
							{
								printf("\n\n\t\tWrong Answer:\n\t\tCorrect Ans is option d.1\n\n");ncnt++;
								for(j=0;j<70;j++)
			    					printf("---");
								getch();break;
							}
			        case 9:
			        	printf("\n\n\n\n");
			        	for(j=0;j<70;j++)
			    				printf("===");
			        	printf("\n\n\n\n\t\t9.#include <iostream>\n\t\tusing namespace std;\n\t\tint main()\n\t\t{\n\t\t\tunsigned int x = 3;\n\t\t\twhile (x-- >= 0) {\n\t\t\t\tprintf(\"%%d  \", x);\n\t\t\t}\n\t\t\treturn 0;\n\t\t}");
						printf("\n\t\tOptions:\n\t\ta. 3 2 1 0\n\t\tb. 2 1 0 -1\n\t\tc. infinite loop\n\t\td. -65535");
						printf("\n\n\\t\tt\t*Enter 'E' to skip this question\t\t\t\t\t\t\t\t\t*Press 'Q' for QUIT the exam\n\n");
						printf("\n\n\t\tRight Your ans Here:");
						ans=toupper(getch());
						if(ans=='E')
						{
							break;
						}
						if(ans=='Q')
						{
							system("cls");
							time(&time4);
							treq1=difftime(time4, time3);
							marks=(float)pcnt*5-2*ncnt-difftime(time4, time3)/300;
							totmrk=(float)score+marks;
							printf("\n\n\n\n\n");
				 			for(j=0;j<70;j++)
			    				printf("===");
			    			printf("\n\n\n\n\t\t\t\tGreat Job Mr/Miss: \"%s\"",nm);
							printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tYour score in Level 2 is %5.3f",score);
							printf("\n\n\t\t\t\t\t\t\t\t\t\t\tYour Total Score is %5.3f",totmrk);
							printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\tPlease press 'ENTER' to continue\n\n\n\n\n\n\n\n\n");
							for(j=0;j<70;j++)
			    				printf("===");
							pcnt=pcnt1+pcnt;
							ncnt=ncnt1+ncnt;
							treq=treq1+treq;
							writescore(snm,totmrk,pcnt,ncnt,treq);
							return;
						}
						if(ans=='C')
							{
								printf("\n\n\t\tRight Answer\n\n");
								pcnt++;
								for(j=0;j<70;j++)
			    					printf("---");
								getch();break;

							}
						else
							{
								printf("\n\n\t\tWrong Answer:\n\t\tCorrect Ans is option c.infinite loop");ncnt++;
								getch();break;
							}
			        case 10:
			        	printf("\n\n\n\n");
			        	for(j=0;j<70;j++)
			    				printf("===");
			        	printf("\n\n\n\n\t\tWhat is the problem with following code?\n\n\t\t#include<stdio.h>\n\t\tint main()\n\t\t{\n\t\t\tint *p = (int *)malloc(sizeof(int));\n\t\t\tp = NULL;\n\t\t\tfree(p);\n}");
			        	printf("\n\t\tOptions:\n\t\ta. Compiler Error: free can’t be applied on NULL pointer\n\t\tb. Memory Leak\n\t\tc. Dangling Pointer\n\t\td. The program may crash as free() is called for NULL pointer.");
			            printf("\n\n\t\t\t\t*Enter 'E' to skip this question\t\t\t\t\t\t\t\t\t*Press 'Q' for QUIT the exam\n\n");
						printf("\n\n\t\tRight Your ans Here:");
						ans=toupper(getch());
						if(ans=='E')
						{
							break;
						}
						if(ans=='Q')
						{
							system("cls");
							time(&time4);
							treq1=difftime(time4, time3);
							marks=(float)pcnt*5-2*ncnt-difftime(time4, time3)/300;
							totmrk=(float)score+marks;
							printf("\n\n\n\n\n");
				 			for(j=0;j<70;j++)
			    				printf("===");
			    			printf("\n\n\n\n\t\t\t\tGreat Job Mr/Miss: \"%s\"",nm);
							printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tYour score in Level 2 is %5.3f",score);
							printf("\n\n\t\t\t\t\t\t\t\t\t\t\tYour Total Score is %5.3f",totmrk);
							printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\tPlease press 'ENTER' to continue\n\n\n\n\n\n\n\n\n");
							for(j=0;j<70;j++)
			    				printf("===");
							pcnt=pcnt1+pcnt;
							ncnt=ncnt1+ncnt;
							treq=treq1+treq;
							writescore(snm,totmrk,pcnt,ncnt,treq);
							return;
						}
						if(ans=='B')
							{
								printf("\n\n\t\tRight Answer\n\n");
								pcnt++;
								for(j=0;j<70;j++)
			    					printf("---");
								getch();break;

							}
						else
							{
								printf("\n\n\t\tWrong Answer:\n\t\tCorrect Ans is option b.Memory Leak\n\n");ncnt++;
								for(j=0;j<70;j++)
			    					printf("---");
								getch();break;
							}
					}
					}
					system("cls");
					time(&time4);
					treq1=difftime(time4, time3);
					marks=(float)pcnt*5-2*ncnt-difftime(time4, time3)/300;
					totmrk=(float)score+marks;
					printf("\n\n\n\n\n");
				 	for(i=0;i<70;i++)
			    		printf("===");
			    	printf("\n\n\n\n\t\t\t\tGreat Job Mr/Miss: \"%s\"",nm);
					printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tYour score in Level 2 is %5.3f",marks);
					printf("\n\n\t\t\t\t\t\t\t\t\t\t\tYour Total Score is %5.3f",totmrk);
					printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\tPlease press 'ENTER' to continue\n\n\n\n\n\n\n\n\n");
					for(i=0;i<70;i++)
			    	printf("===");
					pcnt=pcnt1+pcnt;
					ncnt=ncnt1+ncnt;
					treq=treq1+treq;
					writescore(snm,totmrk,pcnt,ncnt,treq);
					
			    }
				}
			    else
				{
					system("cls");
					printf("\n\n\n");
					for(i=0;i<70;i++)
			    	printf("===");
				    totmrk=(float)score+marks;
				    writescore(snm,totmrk,pcnt,ncnt,treq);
					printf("\n\n\n\n\n\t\t\t\t\t\t\t\tSorry your performance is not satifactionary.So your are not selected for Level 2");
					printf("\n\n\n\t\t\t\t\t\t\t\tPlease try next time.\n\n\t\t\t\t\t\t\t\t\t\tAll the Best...!!!!\n\n");
						for(i=0;i<70;i++)
			    	printf("---");
					return;
				}
				return;
			}
			void main()
			{
				int i;
			    float d;
			    printf("\n\n\n");
			    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t");
			    for(i=0;i<10;i++)
                    	printf("===");
                printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|\t\t  RATESPIEL\t     |");
                printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|        ------------        |");
                printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|  The 'C' Programming Quiz  |");
                printf("\n\t\t\t\t\t\t\t\t\t\t\t\t");
                for(i=0;i<10;i++)
                    	printf("===");
                printf("\n\n\n");
                getch();
                //system("cls");
                for(d=0;d<=100;d+=7.28)
                {
                	system("cls");
                	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tLoading... %.2f%%",d);
                	Sleep(10);
                	
				}
				mainmenu();
				return;
			}
			void mainmenu()   
			{
			 	int opt,cnt,i,opt1;
			    
			    char code[10];
			    time_t t;
	 			time(&t);
			    fs=fopen("user.dat","a+b");
			    if(fs==NULL)
			    {
			        fs=fopen("user.dat","wb");
			        fclose(fs);
			        fs=fopen("user.dat","a+b");
			    }
			    while(1)
			    {
			    	system("cls");
			    	printf("\n\n");
			    	for(i=0;i<31;i++)
                    	printf("***");
			        printf(" WELCOME TO RATESPIEL ");
			        for(i=0;i<31;i++)
                    	printf("***");
                    printf("\nCurrent date and time : %s",ctime(&t));
                    printf("\n\n\t\t1.Student Sign Up\n\n");
                    printf("\t\t2.Student Log In\n\n\t\t3.Teacher Log In\n\n\t\t4.Help\n\n\t\t5.Exit\n\n\n");
                    for(i=0;i<70;i++)
                    	printf("===");
                    printf("\n\t\tOption: ");
			         scanf("%d",&opt);
			         if(opt>5)
			         {
			         	printf("\n\t\tInvalid Option..Please 'ENTER' valid option");
			         	getch();
			         	continue;
					 }
			            
			        switch(opt)
			        {
			        case 1:
			        	system("cls");
			            signup();getch();
						break;
			        case 2:
			        	system("cls");
			        	login();getch();break;
			        case 3:
			        	while(1)
			        	{
			        	system("cls");
			        	printf("\n\n");
			        	for(i=0;i<70;i++)
			        		printf("=#=");
			        	i=0;
			        	printf("\n\n\t\t\t\t\t\t\t\t\t\t**TEACHER SECTION**");
			        	printf("\n\nHello Sir/Mam....!!!\n");
			        	printf("\tPlease enter your \"UNIQUE CODE\" \n\t\t");
			        	do
						{
			        		code[i]=getch();
			        		if(code[i]!='\r')
							{
								if(code[i]==8)
								{
									i--;
									printf("\b \b");
									continue;
								}
			            		printf("*");
			        		}
			        		i++;
			    		}while(code[i-1]!='\r');
			    		code[i-1]='\0';
			        	if(strcmp(code,"Admin@123")==0)
			        	{
			        		while(1)
			        		{
							system("cls");
							printf("\n\n\t\t\t\t\t\t\t\t\t\t\t**TEACHER SECTION**\n\n");
							for(i=0;i<70;i++)
								printf("===");
							printf("\n\n\t\t\t\t\t\t1.Student's Details\n\n\t\t\t\t\t\t2.Student's Record\n\n\t\t\t\t\t\t3.Exit to Home Page\n");
							for(i=0;i<70;i++)
								printf("---");
							printf("\n\n\t\t\t\t\t\tOption: ");
							opt1=getch();
							if(opt1=='1')
							{
								system("cls");
								display();getch();
								continue;
							}
			        		if(opt1=='2')
			        		{
			        			system("cls");
			        			cnt=getcount();
							displayscore(cnt);getch();
							continue;
							}
			        		if(opt1=='3')
			        		{
			        			return mainmenu();
							}
							break;
							}
						}
						else
						{
							if(strcmp(code,"EXIT")==0)
								return main();
							printf("\n\n\tOpss....!! SORRY\n\tPLEASE ENTER \"CORRECT\" CODE FOR CHECK IN.... OR \"EXIT\" for return the MAIN MENU");
							printf("\n\n\tPlease press 'ENTER' to continue");
							getch();
							continue;
						}	
					}
						getch();break;
					case 4:
						{
							system("cls");
							help1();
							break;
						}
					case 5:
						return;
			    	}
				}
				fclose(fs);
				return;
			}

