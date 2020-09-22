#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
void instone()
{
	int i;
	time_t t;
	 time(&t);
	printf("\n\n\t\t\t\t\t\t\t\t\t\t***INSTRUCTIONS FOR LEVEL 1***\n\t\t\t\t\t\t\t\t\t\t\n\n");
	for(i=0;i<70;i++)
		printf("===");
	printf("\nCurrent date and time : %s",ctime(&t));
	printf("\n\nTotal Marks:24                          \t\t\t\t\t\t\t\t\t\t\t\t\tNO. OF QUESTIONS:8\n");
	for(i=0;i<70;i++)
		printf("===");
	printf("\n\nREAD the following INSTRUCTIONS carefully.");
	printf("\n\nINSTRUCTIONS:\n");
	printf("-------------\n\n");
	printf("\t\t1. The given quiz consists of questions on different topics covered in c programming language.\n\n");
	printf("\t\t2. Each question in given quiz is of multiple choice format.\n\n");
	printf("\t\t3. If the response is correct candidate will be given 3 marks and for wrong response one mark will be reduced from total score.");
	printf("\n\n\t\t4. Read each question carefully and type the option.ALL QUESTIONS ARE COMPULSORY.  Please tap 'ENTER' key for next question. \n");
	printf("\n\t\t5. After responding to 8th question click on SUBMIT to end LEVEL 1.\n");
	printf("\n\t\t6. You have only one attempt so give your response wisely.\n\n\t\t7. The total score is based on your \"CORRECT\" responses to given questions as well as \"TIME\" taken by you to solve the problem.\n");
	printf("\n\t\t8. If your score for LEVEL 1 is greater than 10 then only you will be eligible for next level.\n");
	printf("\n\t\t9. You are not be alloted for LEVEL 2 if you 'QUIT' LEVEL 1 even though your score is more than 10.");

	printf("\n\n\t\t10. only registered ,enrolled users can give the test.   ");
	printf("\n\n\n\t\t\t\t                              BEST OF LUCK FOR QUIZ\n");
	printf("\n\t\t\t\t\t\tTo start exam click on START.(Press 'ENTER')");
	return;
}
void insttwo()
{
	int i;
	time_t t;
	 time(&t);
	printf("\n\n\t\t\t\t\t\t\t\t\t\t   ***INSTRUCTIONS FOR LEVEL 2***\n\t\t\t\t\t\t\t\t\t\t\n\n");
    for(i=0;i<70;i++)
		printf("===");
	printf("\nCurrent date and time : %s",ctime(&t));
	printf("\n\nTotal Marks:50                           \t\t\t\t\t\t\t\t\t\t\t\t\tNO. OF QUESTIONS:10\n");
	for(i=0;i<70;i++)
		printf("===");
	printf("\n\nREAD the following INSTRUCTIONS carefully.");
	printf("\n\nINSTRUCTIONS:\n");
	printf("-------------\n\n");
	printf("\t\t1. The given quiz consists of questions on different topics covered in c programming language.\n\n");
	printf("\t\t2. Each question in given quiz is of multiple choice format.\n\n");
	printf("\t\t3. If the response is correct candidate will be given 5 marks and for wrong response two mark will be reduced from total score.\n\n");
	printf("\t\t4. Read each question carefully and and type the option,if you want to skip that question press 'E' and go for next question.\n\n");
	printf("\t\t5. You have only one attempt so give your response wisely.\n\n\t\t6. The total score is based on your responses to given questions as well as 'TIME' taken by you to solve the problem.\n\n");
	printf("\t\t7. You can 'QUIT' the exam anytime and you will get marks upto which you will be solved.");
	printf("\n\t\t9.To start exam click on START.");
	printf("\n\n\t\t           Only Selected candidates are allowed for LEVEL 2.");
	printf("\n\n\n\t\t\t\t                               BEST OF LUCK FOR QUIZ");
	printf("\n\t\t\t\t\t\tTo start level click on START.(Press 'ENTER')");

}
void help1()
{
	int i;
	for(i=0;i<70;i++)
		printf("===");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t***STUDENT HELP SECTION***\t\t\t\t\t\t\t\t\t\t\n");
	printf("\t\t\t\t\t\t\t\t\t\t   =====================\n\n");
	for(i=0;i<70;i++)
		printf("---");
	printf("\n\n\t\t\t\t1. Every student must REGISTER their account and write your details for appering ofr the QUIZ.");
	printf("\n\n\t\t\t\t2. Student should remember their UNIQUE username and password.As it is very neccessary for starting the QUIZ.");
	printf("\n\n\t\t\t\t3. Do not share your password to anyone for your security purpose.");
	printf("\n\n\t\t\t\t4. Password should not be less than '8 character' and not be greater than '10 character'");
	printf("\n\n\t\t\t\t5. In case of for forget username or password please contact with Teacher/Administration. ");	
	printf("\n\n\n\n\t\t\t\tPress 'ENTER' for returnning to MAIN MENU");
	getch();
	
}
void help2()
{
	int i;
	for(i=0;i<70;i++)
		printf("===");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t***STUDENT HELP SECTION***\t\t\t\t\t\t\t\t\t\t\n");
	printf("\t\t\t\t\t\t\t\t\t\t   =====================\n\n");
	for(i=0;i<70;i++)
		printf("---");
	printf("\n\n\t\t\t\t1. LEADERBOARD is according to total score achieved in the QUIZ.");
	printf("\n\n\t\t\t\t2. This total score is calculated according to rules including time required to finish the QUIZ.");
	printf("\n\n\t\t\t\t3. You can not take objection on marking system and obtained marks as score is fairly calculated.");
	printf("\n\n\t\t\t\t5. All rights and decision are reserved to Organizers");
	
	printf("\n\n\n\n\t\t\t\tPress 'ENTER' for returnning to HOME");
	
	getch();
	
	
}

