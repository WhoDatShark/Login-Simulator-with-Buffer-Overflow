#include<bits/stdc++.h>
#include "mail.h"
#include<conio.h>
using namespace std;

class MAPS {
private:
    map<string ,string> credentials;
public:
    MAPS(){
        string current;
        string key;
        string value;
        int pos;
        ifstream showf("creds.txt");
        while(getline(showf, current)) {
            pos = current.find("\t");
            key = current.substr(0,pos);
            value = current.substr(pos+1);
            credentials.insert({key, value});
        }
        showf.close();
    }
    ~MAPS(){
        fstream file;
        file.open("creds.txt");
        map <string, string>::iterator it = credentials.begin();
        while (it != credentials.end ()) {
            file<<it->first<<"\t"<<it->second<<endl;
            it++;
        }
        file.close();
    }
    void newReg (string id, string pass)
    {
        if(pass.length()<8){
            cout<<"\nPassword too short!!"<<endl<<"Generating password...\n";
            getch();
            pass=passGen();
        }
        bool lower = false;
        bool upper = false;
        bool digit = false;
        bool spchar = false;
        int length = pass.length();
        while(length--){
            if(islower(pass[length]))
                lower = true;
            if(isupper(pass[length]))
                upper = true;
            if(isdigit(pass[length]))
                digit = true;
            if(!isdigit(pass[length])&&!islower(pass[length])&&!isupper(pass[length]))
                spchar = true;
        }
        if(lower&&upper&&digit&&spchar)
            credentials[id] = pass;
        else {
            cout<<"Password is not strong enough!!\n Generating new password... \n";
            getch();
            pass=passGen();
            newReg(id,pass);
        }
    }
    void show ()
    {
        map <string, string>::iterator it = credentials.begin ();
        while (it != credentials.end ())
        {
            cout << "Email-Id: " << it->first << "\tPassword: " << it->second << endl;
            it++;
        }
    }
    bool passVerify(string id, string pass){
        auto search = credentials.find(id);
        if(search!=credentials.end()){
            if(search->second == pass){
                cout<<"\nCredentials Matched!!\nAccess Granted!"<<endl;
                getch();
                return true;
            }
            else
                cout<<"\nIncorrect Password!!"<<endl;
                getch();
            return false;
        }
        else {
            cout << "\nEmail ID not found!\nPlease Register before proceeding!!" << endl;
            getch();
            return false;
        }
    }
    bool changePassword(string id){
        auto search = credentials.find(id);
        string pass;
        if(search!=credentials.end()){
            cout<<"\nEnter new password: "<<endl;
            fflush(stdin);
            getline(cin, pass);
            if(pass==search->second)
            {
                cout<<"New password cannot be the same as old password!!\n Generating new password...\n";
                pass=passGen();
            }
            else {
                if(pass.length()<8){
                cout<<"\nPassword too short!!"<<endl<<"Generating password...\n";
                getch();
                pass=passGen();
                }
        bool lower = false;
        bool upper = false;
        bool digit = false;
        bool spchar = false;
        int length = pass.length();
        while(length--){
            if(islower(pass[length]))
                lower = true;
            if(isupper(pass[length]))
                upper = true;
            if(isdigit(pass[length]))
                digit = true;
            if(!isdigit(pass[length])&&!islower(pass[length])&&!isupper(pass[length]))
                spchar = true;
        }
        if(lower&&upper&&digit&&spchar){
            search->second = pass;
            return true;
            }
        else {
            cout<<"Password is not strong enough!!\n Generating new password... \n";
            getch();
            pass=passGen();
            search->second = pass;
            return true;
            }

        }
    }
        else{
            cout<<"\nEmail-ID doesn't Exist!!\nPlease Sign-up First!!"<<endl;
            return false;
        }
    }
    string passGen(){
        string special = "!#$%&*?@";
        string newp="";
        srand(time(NULL));
        for(int i=1;i<=2;i++) {
            newp+= special[rand() % 8];
            newp+= char((97+(rand() % 26)));
            newp+= char((65+(rand() % 26)));
            newp+= to_string(rand() % 10);
        }
        cout<<"\nPassword generated successfully!\n Password: "<<newp<<endl;
        getch();
        return newp;
    }
};

class RSA{
	private:
		long long int n,p=0,q=0,phi_n,e,d,t,t1=0,t2=1,r1,r2,r,qu;

		// email of user who logged in

	public:
		string registered_email;
		void values();
		void eea();

};

int digit=4;  // no of digit in otp
int otp[4]={0};  // generated otp
int given_input=0;  // no of digit user entered
int value[4];  // otp user will enter
int otpResend=0;  //  1 --> resend otp, 0 --> otp valid no need to resend
char alphabet[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int numbers[10]={0,1,2,3,4,5,6,7,8,9};

void initializeGlobalVariable(){  // initialize otp, value, given_input to 0.
	for(int i=0;i<digit;i++){
		otp[i]=value[i]=0;
	}
	given_input=0;
}

void otpVerify(){

	// for(int i=0;i<digit;i++){
	// 	printf("%d ",otp[i]);
	// }

	for(int i=0;i<digit;i++){
		printf("Enter digit %d: ",i+1);
		scanf("%d",&value[i]);
		given_input++;
	}
	int check=1;
	for(int i=0;i<digit;i++){
		if(value[i]!=otp[i]){
			printf("%d--%d\n",value[i],otp[i]);
			check=0;
			break;
		}
	}
	if(check==1){
		printf("OTP verified!!\n");
		otpResend=0;
	}
	else{
		printf("Invalid OTP!!\n");
		int val=-1;
		do{
			printf("Resend OTP? (0/1): ");
			scanf("%d",&val);
			if(val==1 || val==0){
				otpResend=val;
			}
			else{
				printf("Invalid input!!\n");
				val=-1;
			}
		}while(val==-1);
	}
}

void otpSend(string registered_email){
	int min=5;
	do{

		// otp creation
		srand(time(0));
		for(int i=0;i<digit;i++){
			otp[i]=rand()%9+1;
		}

		// otp prints
		// for(int i=0;i<digit;i++){
		// 	printf("%d ",number[i]);
		// }

		// message creation
		ofstream file;
		file.open("Message.txt");
		file << "OTP-";
		for(int i=0;i<digit;i++){
			file << otp[i];
		}
		file.close();

		// email setting
		file.open("Mail.txt");
		file << registered_email;
		file.close();

		SendMail(0);
		// otpVerify();
		std::cout << "OTP is valid for 5 min only!!" << std::endl;
		auto result = std::async(std::launch::async, otpVerify);
		auto start = std::chrono::steady_clock::now();
		while (std::chrono::duration_cast<std::chrono::minutes>(std::chrono::steady_clock::now() - start).count() < min) {
			// Check for user input every 1 second
			std::this_thread::sleep_for(std::chrono::seconds(1));
			// std::string input;
			// std::cin >> input;
			if (given_input == 4) {
				break; // Break out of the loop and skip the remaining time
			}
		}
		initializeGlobalVariable();
		result.get(); // Wait for the code to finish executing
		std::cout << "Time Ends\n" << std::endl;


	}while(otpResend);
}

// Features will be implemented

void symmetricKeyGen(string registered_email){
	printf("Symmetric key will be mailed on the registered email address\n");

	// key generation
	int symmetricKey;
	srand(time(0));
	symmetricKey=rand()%100+1;

	// writing key in Message.txt file
	ofstream file;
	file.open("Message.txt");
	file << "Symmetric key --> " << symmetricKey;
	file.close();

	// writing registered email
	file.open("Mail.txt");
	file << registered_email;
	file.close();

	// sending mail
	SendMail(0);
}

int searchFactors(long long int e, long long int factors[],long long int a){
	for(long long int i=0;i<=a;i++){
		if(e==factors[i]){
			return 1;
		}
	}
	if(e==0){
		return 1;
	}
	return 0;
}

void generateTwoPrimeNumber(long long int* p,long long int *q){
	int n,run=1,p_prime=1,q_prime=1;
	srand(time(0));
	while(run){
		n=rand()%10+1;
		*p=(6*n)-1;
		// cout<<"np="<<n<<"\n";

		for(int i=2;i<(*p-1);i++){
			if(*p%i==0){
				p_prime=0;
				break;
			}
			else{
				p_prime=1;
			}
		}

		if(p_prime==0){
			*p=(6*n)+1;
			for(int i=2;i<(*p-1);i++){
				if(*p%i==0){
					p_prime=0;
					// cout<<"p\n";
					break;
				}
				else{
					p_prime=1;
				}
			}
		}

		n=rand()%10+1;
		// cout<<"nq="<<n<<"\n";
		*q=(6*n)+1;
		for(int i=2;i<(*q-1);i++){
			if(*q%i==0){
				q_prime=0;
				break;
			}
		}

		if(q_prime==0){
			*q=(6*n)-1;
			for(int i=2;i<(*q-1);i++){
				if(*q%i==0){
					q_prime=0;
					break;
				}
				else{
					q_prime=1;
				}
			}
		}

		if(p_prime==1&&q_prime==1){
			run=0;
		}
	}
	// cout<<"p="<<*p<<",q="<<*q;
}

void generateE(long long int* e,long long int* phi_n){
	long long int factors[*phi_n];
	long long int a=0;
	for(long long int i=1;i<=*phi_n;i++){
		if(*phi_n%i==0){
			factors[a]=i;
			a++;
		}
	}
	// printf("\na");
	a--;
	// for(long long int i=0;i<=a;i++){
	// 	printf("%d,",factors[i]);
	// }
	srand(time(0));
	*e=rand()%*phi_n;
	while(searchFactors(*e,factors,a)){
		*e=rand()%*phi_n;
	}
	// cout<<"\neonly="<<*e;
}

void RSA::values()
{
	// cout<<"\nEnter Values of P & Q: ";
	// cin>>p>>q;
	generateTwoPrimeNumber(&p,&q);
	// cout<<"p="<<p<<",q="<<q;
	n=p*q;
	phi_n=(p-1)*(q-1);
	// cout<<"\nn="<<n<<",phi_n="<<phi_n;
T1:	generateE(&e,&phi_n);
	if(e<0&&e>phi_n)
		goto T1;
	for(long long int i=2;i<e;i++)
	{
		if(e%i==0)
			goto T1;
	}
}
void RSA::eea()
{
	r1=phi_n;
	r2=e;
	while(r2>0)
	{
		qu=r1/r2;
		r=r1%r2;
		r1=r2;
		r2=r;
		t=t1-(qu*t2);
		t1=t2;
		t2=t;
	}
    if(r1==1&&t1>0)
    {
        // cout<<"\nP = "<<p<<"\nQ = "<<q<<"\nE = "<<e<<"\nN = "<<"\nPhi(N) = "<<phi_n<<"\nD = "<<t1;
		d=t1;
    }
    if(r1==1&&t1<0)
    {
        // cout<<"\nP = "<<p<<"\nQ = "<<q<<"\nE = "<<e<<"\nN = "<<n<<"\nPhi(N) = "<<phi_n<<"\nD = "<<t1+t2;
		d=t1+t2;
    }
	// cout<<"\ne="<<e<<",d="<<d;
	cout<<"Asymmetric key will be mailed on the registered email address\n";

	ofstream file;
	file.open("Message.txt");
	file<<"public key--> "<<e<<", Private key--> "<<d<<"\nPublic Pair (e,n)--> ("<<e<<","<<n<<")"<<"\nPrivate Pair (d,n)--> ("<<d<<","<<n<<")";
	file.close();

	file.open("Mail.txt");
	file<<registered_email;
	file.close();

	SendMail(0);
}

int indexOf(char ch){
    for(int i=0;i<26;i++){
        if(ch==alphabet[i]){
            return i;
        }
    }
    return -1;
}

int encipher(int pt,int key){
    return (pt+key)%26;
}

int decipher(int ct,int key){
    int pt=(ct-key)%26;
    if(pt<0){
        return pt+26;
    }
    return pt;
}

int encipher_digit(int pd,int key){
	return (pd+key)%10;
}

int decipher_digit(int cd,int key){
	int pd=(cd-key)%10;
	if(pd<0){
		return pd+10;
	}
	return pd;
}

int indexOf_digit(int digit){
	for(int i=0;i<10;i++){
        if(digit==numbers[i]){
            return i;
        }
    }
    return -1;
}

void encryption(string registered_email){
	int size;
	int index=0;
	int index_messgae;
	int index_cipher;

	printf("\nEnter approximate size of message\n*Note: size can be greater than message but not smaller than it.\n-->");
	scanf("%d",&size);
	fflush(stdin);
	printf("\nEnter message\n-->");
	char message[size];
	gets(message);
	size=strlen(message);
	int key[size];
	size++;
	char cipher[size];
	size--;

	srand(time(0));
	for(int i=0;i<size;i++){
		if(' '==message[i]){
			continue;
		}
		key[index]=rand()%10;
		message[i]=toupper(message[i]);
		index_messgae=indexOf(message[i]);
		index_cipher=encipher(index_messgae,key[index]);
		cipher[index]=alphabet[index_cipher];
		index++;
	}
	cipher[index]='\0';

	string receiver_email;
	cout<<"\nEnter email-id of receiver\n*Note: only you and the receiver will able to decrypt the text\n-->";
	cin>>receiver_email;

	int sender=registered_email.length();
	int receiver=receiver_email.length();
	int ind=0;
    int modulo=(sender+receiver)/2;

	int secretKeyArr[sender+receiver];
	for(int i=0;i<sender;i++){
        secretKeyArr[ind]=registered_email[i];
        ind++;
    }
	for(int i=0;i<receiver;i++){
        secretKeyArr[ind]=receiver_email[i];
        ind++;
    }

	int secretKey=0;
    for(int i=0;i<(sender+receiver);i++){
        secretKey+=secretKeyArr[i];
    }

	secretKey=secretKey%modulo;

	int index_Cdigit;
	int index_Pdigit;
	for(int i=0;i<index;i++){
		index_Pdigit=indexOf_digit(key[i]);
		index_Cdigit=encipher_digit(index_Pdigit,secretKey);
		key[i]=numbers[index_Cdigit];
	}

	cout<<"\nEncrypted text will be mailed on the registered email address\n";

	ofstream file;
	file.open("Message.txt");
	file<<"Encrypted Text--> "<<cipher<<", key Stream--> ";
	for(int i=0;i<(index);i++){
		file<<key[i];
	}
	file.close();

	file.open("Mail.txt");
	file<<registered_email;              //receiver_email;      //
	file.close();

	SendMail(0);
}

void decryption(string registered_email){
	int size_text;
	int size_key;
	int index=0;
	int index_cipher;
	int index_messgae;

	printf("\nEnter approximate size of ciphertext\n*note: size can be greater than ciphertext but not less than it.\n-->");
	scanf("%d",&size_text);
	fflush(stdin);

	printf("\nEnter ciphertext\n-->");
	char cipher[size_text];
	gets(cipher);
	size_text=strlen(cipher);

	size_text++;
	char message[size_text];
	size_text--;

	printf("\nEnter key stream\n-->");
	string key;
	cin>>key;
	size_key=key.length();

	int keyStream[size_key];
	for(int i=0;i<size_key;i++) {
      keyStream[i]=key[i]-48;
    }

	string sender_email;
	cout<<"\nEnter email-id of the sender\n*Note: only you and the sender will be able to decrypt the text\n-->";
	cin>>sender_email;

	// int receiver=registered_email.length();
	// int sender=sender_email.length();
	// int secretKey=(sender+receiver)/2;

	int receiver=registered_email.length();
	int sender=sender_email.length();
	int ind=0;
	int modulo=(sender+receiver)/2;
	int secretKeyArr[sender+receiver];

	for(int i=0;i<sender;i++){
        secretKeyArr[ind]=sender_email[i];
        ind++;
    }
	for(int i=0;i<receiver;i++){
        secretKeyArr[ind]=registered_email[i];
        ind++;
    }


	int secretKey=0;
    for(int i=0;i<(sender+receiver);i++){
        secretKey+=secretKeyArr[i];
    }

	secretKey=secretKey%modulo;

	int index_Cdigit;
	int index_Pdigit;
	for(int i=0;i<size_key;i++){
		index_Cdigit=indexOf_digit(keyStream[i]);
		index_Pdigit=decipher_digit(index_Cdigit,secretKey);
		keyStream[i]=numbers[index_Pdigit];
	}

	for(int i=0;i<size_text;i++){
		cipher[i]=toupper(cipher[i]);
		index_cipher=indexOf(cipher[i]);
		index_messgae=decipher(index_cipher,keyStream[i]);
		message[i]=alphabet[index_messgae];
	}
	cout<<"\nDecrypted text will be mailed on the registered email address\n";

	ofstream file;
	file.open("Message.txt");
	file<<"Decrypted Text--> "<<message;
	file.close();

	file.open("Mail.txt");
	file<<registered_email;
	file.close();

	SendMail(0);
}

int main(){
	RSA ASkey;
    MAPS m;
    string email, pass;
    int choice;
    int cho;
    home:   while(true){
    system("cls");
    cout<<"*****WELCOME TO OUR SAFETY APP*****"<<endl;
    cout<<"1. Log-in"<<endl;
    cout<<"2. Sign-up"<<endl;
    cout<<"3. Forgot Password?"<<endl;
    cout<<"4. Exit"<<endl;
    cin>>choice;
    switch (choice) {
        case 1:
            system("cls");
            cout<<"\nEnter your Email: ";
            fflush(stdin);
            getline(cin, email);
            cout<<"\nEnter your Password: ";
            fflush(stdin);
            getline(cin, pass);
			otpSend(email);
			if(!otpResend){
				if(m.passVerify(email, pass)){
					//goto features;  //giving the access to the features
					int run=1;
					while(run){
						system("cls");
						cout<<"***WELCOME TO THE DASHBOARD***"<<endl;
						cout<<"1. Password Generator"<<endl;
						cout<<"2. Symmetric Key Generator"<<endl;
						cout<<"3. Asymmetric Key Generator"<<endl;
						cout<<"4. Message Encryption"<<endl;
						cout<<"5. Message Decryption"<<endl;
						cout<<"6. Log-out"<<endl;
						cin>>cho;
						switch(cho){
							case 1:
								cout<<"\nGenerating Password"<<m.passGen();
								getch();
								break;
							case 2:
								symmetricKeyGen(email);
								getch();
								break;
							case 3:
								ASkey.registered_email=email;
								ASkey.values();
								ASkey.eea();
								getch();
								break;
							case 4:
								system("cls");
								encryption(email);
								getch();
								break;
							case 5:
								system("cls");
								decryption(email);
								getch();
								break;
							case 6:
								run=0;
						}

					}
				}
			}
			else{
				cout<<"\nTwo-Factor Authentication failed!!\nPlease try again!"<<endl;
				getch();
				goto home;
			}
            break;
        case 2:
            system("cls");
            cout<<"\nEnter your Email: ";
            fflush(stdin);
            getline(cin, email);
            cout<<"\nEnter your Password: ";
            fflush(stdin);
            getline(cin, pass);
			otpSend(email);
			if(!otpResend){
            	m.newReg(email, pass);
            	cout<<"\nPlease Log-in to continue"<<endl;

			}
			else{
				cout<<"\nTwo-Factor Authentication failed";
				getch();
			}
            break;
		case 3:
			system("cls");
			fflush(stdin);
			cout<<"\nEnter your email:";
			getline(cin, email);
			otpSend(email);
			if(!otpResend){
				if(m.changePassword(email)){
					cout<<"\nPassword changed successfully!!";
					getch();
				}
			}
			else{
				cout<<"\nTwo-Factor Authentication failed";
				getch();
			}
			break;
        case 4:
            system("cls");
            cout<<"Thank you!"<<endl;
            getch();
            return 0;
        default:
            cout<<"Incorrect choice!"<<endl<<"Please try again";
        }
    }
}
