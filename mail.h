	#include<conio.h>
	FILE* locBit;
	FILE* locBit1;
	FILE* locBit2;
	FILE* locBit3;
	FILE* locBit4;
	FILE* MainCRET;
int Init(void)
{
	locBit = fopen("GmailUR.txt","w");
	locBit1 =fopen("Mail.txt","w");
	locBit2 =fopen("Message.txt","w");
	locBit3 =fopen("PassUR.txt","w");
	locBit4 =fopen("Subject.txt","w");
	MainCRET=fopen("Mail.aysoat","w");
	printf("\n\nInitiating please wait\n");
	fprintf(MainCRET,"import smtplib\nurm=open('GmailUR.txt','r')\nurp=open('PassUR.txt','r')\nsocmail = urm.read()\npassword = urp.read()\nsub = open('Subject.txt','r')\nsubject = sub.read()\nsandesh = open('Message.txt','r')\nsmessage = sandesh.read()\nmailid = open('Mail.txt','r')\nj = mailid.readline()\nEmail=j.split()\ns = smtplib.SMTP('smtp.gmail.com', 587)\ns.starttls()\ns.login(socmail, password)\nbody = ''\nding = 'Subject:{}{}'.format(subject, body)\nmessage = ding+smessage\n#print('Message Sent to',Email)\ns.sendmail(socmail, Email, smessage)\nprint('Done')\n\n");
	fclose(MainCRET);
	return 0;
}
void fillDat(void)
{
	Init();
	char GMAILID[2561], PASSWARD[256], SUBJECT[256], SENDMAIL[256], MESSAGE[256];
	printf("Hello, Here We'll Fill The Data!");
	printf("\n\nYour Gmail ID (Remember only Gmail is supported)\nGmail:> ");
	scanf("%s",&GMAILID);
	fprintf(locBit,"%s",GMAILID);
	printf("\n\nPassword For Provided Email ID (%s)\nPassowrd:> ",GMAILID);
	scanf("%s",&PASSWARD);
	fprintf(locBit3,"%s",PASSWARD);
	printf("\n\n\nOkay Step 1 is now completed!\nLet's Move Furthur\n\nPress Enter To Continue\n");
	getch();
	system("CLS");
	printf("Okay, now we are in step 2, Here we are filling information that can be changed many a times!!\n\n");
	system("COLOR 0c");
	printf("\n\n\aCAUTION: Here only one word input is accepted,\nIf you want a sentence then goto your project's folder\nand make changes in files.\n(Files that can be changed are: Subject.txt, Message.txt and Mail.txt)\n\nPress Enter To Continue\n\n");
	getch();
	system("CLS");
	printf("Please enter the sender's Mail-ID (Only one word is accepted, Else this will crash!)\nMail:> ");
	scanf("%s",&SENDMAIL);
	fprintf(locBit1,"%s",SENDMAIL);
	printf("Please enter the subject for mail (Only one word is accepted, Else this will crash!)\nSubject:> ");
	scanf("%s",&SUBJECT);
	fprintf(locBit4,"%s",SUBJECT);
	printf("Please enter the Message for mail (Only one word is accepted, Else this will crash!)\nMessage:> ");
	scanf("%s",&MESSAGE);
	fprintf(locBit2,"%s",MESSAGE);
	system("CLS");
	printf("Okay, we are all set!\nPress any key to close me.\n");
	getch();
	printf("\a");
	fclose(locBit);
	fclose(locBit1);
	fclose(locBit2);
	fclose(locBit3);
	fclose(locBit4);
	exit(0);
}
int SendMail(int returnVal)
{
system("python Mail.aysoat");
switch(returnVal)
{
case 0:
return 0;
break;
case -1:
return -1;
break;
default:
return 0;
break;
}
system("attrib -h -s Mail.aysoat");
}
