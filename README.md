 Railway Reservation System





Description: This application has two modes- Admin and User.  It allows admin to generate user ids , set Train info and see all Reservations, users and cancellations. It also allows user can Reserve, Enquire and Cancel Ticket. After reservation and cancellation there is updation of seats.
Ticket fare is calculated based upon concession category. All data entered would be stored in files in binary form using file Handling. 




## Classes used in the application:

### Train: 

This class contains train Details like Trainname, number, class type and their fares, date, boarding and destination stations. It has function for inputting these details and printing them.

### Reserve: 

This class contains passenger details like name of person, age and the corresponding booked train details along with PNR number, concession, reserved seats. It has function for inputting these details and printing them.

### Cancel: 

Similar elements as of Reserve class given above.

### User:
This class contains id and password of user. It has function for inputting these details and printing them.

## Functions used in the application

### Admin:

It has subfunctions to Add Train, Display all trains and following functions

#### User Management: 

It can be used to add new Users and display existing users with their ID and password.

#### Display Reservations:

It reads records from Reservation file and display them.

#### Display Cancellations:

It reads records from Cancelled file and display them.

### User: 

A particular user can login using his/her credentials. It has following subfunctions

#### Reserve:

It takes ticket details from user as input. Calculates concession and updates seats in Train file and then generates PNR Number using random number generator.

#### Cancel:

It takes PNR number as input and finds the reserved ticket and deletes it from Reservation file and Updates Cancellation file.

#### Enquiry:

Display all Trains Details from Train file.

## Files

### id.txt: 
Binary file. Contains User Records.

### trains.txt:
Binary file. Contains Train Records.

### reservations.txt:
Binary file. Contains Reservation Records.

### cancel.txt:
Binary file. Contains Cancellation Records.

### temp.txt:
Binary file. Holds Reservation Records except Cancellation Records.

