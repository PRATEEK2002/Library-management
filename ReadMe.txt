#############################################################
ReadMe for assignment submitted by 2017A7PS0171P
Practical section number: P8
Asignment question attempted: 2(Library management system)
#############################################################
Team:
1. 2017A7PS0171P PRATEEK SHARMA
#############################################################
Description of how to run the code and observe the output: 
1. The only .c file is 2017A7PS0171P_P8.c 

2. First ".txt" files is booksss.txt(both input and output file), Information will be stored even after exiting the program, since storage is not 
dynamic, it stores the information in files for static use.
for storing books information, fields of this file are
		a)book name b) auhtor's name c)book count d) rack_number e)book arrival date in library f)book issuer(can be "NA", if not issued) g)issuing date(is -1 -1 -1 if not issued) 

3. Second .txt file is users.txt to save the userid and password of all user to verify during login of user, fields of this file are,
		a)userid b)password

4) Third .txt file is vendor_management.txt for ordering books from other libraries, fields are
		a) book name b) author's name c) vendor's name
5) Fourth .txt file is reservation.txt for reserving books, in case, book is not available at the time of issuing, fields of this file are
		a) book name b) author's name c) name of person(reserving)		

6) Put all the files in one folder, compile the 2017A7PS0171P_P8.c file and run it
	FUNCTIONALITY AND USE OF INTERFACE
	Program is divided into two section "admin's site" and "user's site"
		a) On first page, it will ask for your login choice as admin or user, press the number according to it.
			
			ADMIN'S SITE(after pressing 2)-
				if you choose admin login it will ask for ID and password	
**IMPORTANT**	(id is "admin" and password is "pass" (without quotes))

				after verification... following options will appear on screen.
				>FOR ADDING USERS PRESS 1
						after pressing 1, it will ask for userid and then password for user one by one, and new user is added in the system.
						(** userid is unique, there cant be two users with same userid)
				>FOR DELETING USERS PRESS 2
						after pressing 2, it will ask for userid only enter the ID, and user is removed from system/ users.txt.
				>FOR ADDING BOOKS PRESS 3(** check limitaions at the end of this file)
						after pressing 3, it will ask for book name, author's name and rack number(**integer(dont input char)) (arrival date is automaticaly taken from the system).
				>VENDOR MANAGEMENT PRESS 4
						after pressing 4, it will ask for book name, author's name and vendor's name and update the vendor management file and display all the entries of file on console.
				>FOR ALL BOOKs DETAILS PRESS 5
						after pressing 5, admin can see detail of every book such as, name, author, rackno,arrival date, issuer's name, issuing date etc.
						if book is not issued, issuer's name is "NA", and issuing date is "-1-1-1"
				>INVENTORY MANAGEMENT PRESS 6
						after pressing 6, admin can see books and their count.
				>FOR ALL USERs DETAILS PRESS 7
						after pressing 7, admin can see users and their passwords.
				>FOR LOG OUT PRESS 8
											
						
			USER's SITE(after pressing 1)-
				if you choose the user login, it will show the recently added books in the library(within 5 days) and
				it will ask for ID and password. (There can be multiple users)
**IMPORTANT**( while login, we can use any one of the ID,password registered in users.txt, one set is ID='ankit', password='1234' (without quotes))				
				after verification... following options will appear on screen.
				
				*NOTIFICATIONS: for notifying users about the deadline of returning book(after 15 days)(Current date-issuing date>15)
				
				*ALERTS: for notifying users that the book, that was reserved is available now and can be issued(someone has returned the book back). 

				>FOR BOOK SEARCH PRESS 1
						after pressing 1, it will ask for three options
							(FOR A CERTAIN BOOK)FOR SERACH BY BOOK NAME AND AUTHOR NAME BOTH, PRESS 1
									it will ask for book name and author name and print all unique books (i.e book name and author name as a pair are for uniqueness)
							(ALL BOOKS BY SAME NAME)FOR SERACH BY BOOK NAME, PRESS 2
									it will ask for book name only and print all the books with the given name
							(ALL BOOKS BY AUTHOR NAME)FOR SERACH BY AUTHOR NAME, PRESS 
									it will ask for Auhtor's name only and print all the books with the given name

				>FOR BOOK TRANSACTION/ISSUE PRESS 2
						it will ask for book name and author name, if book is available it will issue the book and if book is issued by
						someone else it will reserve that book for you, alert message will come, after book is returned to the library. 
		
				>FOR BOOK RETURN PRESS 3
						it will ask for book name and author name and return the book to libaray.
						
				>FOR CANCELLATION OF RESERVATION OF BOOKS 4
						if you have reserved any book, by this option you can cancel your reservation.
				>FOR LOG OUT PRESS 5
	
				
		
############################################################
Known limitations of the code (if you have not been able to completely/fully implement certain features that were asked):
1. one limitation is for taking input such as for userid, password, book name, author name or any other string input program expect
 one word only, not two word with spaces or multiple words(example- for book name "science" is allowed but "science work" is not allowed)
 i.e give input in word only
2. (BASIC CONSTRAINT) Don't put string in place of integer input(example for racknumber or any option choice)
	for selecting options also do not enter any string(integer check is added at most of the palces) but still it might start a infinte loop, exist the program in some case . 
#############################################################
Contributions of the team members:
prateek sharma -all code modules, as given in the problem statement are implemented and running nicely as expected. 
#############################################################