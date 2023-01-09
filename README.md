# Safety_App
#This project was developed for the 5-day learning program by CyberPeace Corps between 5th and 9th January, 2023
The Safety App is actually a Password Generator, Manager, Symmetric & Asymmetric Key Generator and last Message Encryption & Decryption 

## Before using saftey_app.exe do following steps to send email
### Step 1
Enter gmail id in "GmailUR.txt" for receiving mails from that id.
### Step 2
Enable 2 factor authentication in gmail id which you have entered in "GmailUR.txt".
### Step 3
below 2 factor authentication you can see an option name app passwords click on that.
i. In select app, select mail.
ii. select device, custom name, enter "SMTP".

### Following are the features of the application 
 1. User registration: A user can register on the app using their email ID and password. 
 2. Password Manager: The passwords of registered users are saved in a file. 
 3. Password Verification: Each time a user logs in, their password is verified with the one stored in the file. After this, 2FA occurs.
 4. Password Generator: In case the password given by user during registration or while changing is short or weak, a password is automatically generated for them.
 5. Changing Password: After logging in, user can change their password. Verification is still done, and then 2FA as well. 
 6. Recovery in case password is forgotten: In this case an OTP is sent to the registered email ID and user can reset their password.
 7. 2-Factor Authentication: At each log in, first the user's password is matched with stored one, and if successful, a OTP is sent to their email ID. OTP is only valid for 5 mins. 
 8. User-Key Generation: To communicate securely after logging in, user can generate a symmetric or asymmetric keys which will be sent on their mail. 
 9. Encryption: A message can be mailed to a user securely after it is encrypted with some keystream! User receives the ciphertext with a keystream which can be forwarded to the receiver.
 10. Decryption: The receiver is the only person who can decrypt that same message after logging in as the program verifies the sender and receiver while decrypting.
