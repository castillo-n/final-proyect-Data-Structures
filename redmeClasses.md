The classes are going to be (tentative)
Flight
=> flight No
=> flight Airline
=> flight Seats => this will be a array of pointers to seat objects
=> flight First to => row# column# //number of columns and row could vary from seat class to seat class
=> flight Economy Plus to => row# column# //number of columns and row could vary from seat class to seat class
=> flight Economy to => row# column# //number of columns and row could vary from seat class to seat class
=> flight departure date //utc time
=> flight departure time //utc time
=> flight departure city //utc time
=> flight departure state //utc time
=> flight departure country //utc time
=> flight arrival date //utc time
=> flight arrival time //utc time
=> flight arrival city //utc time
=> flight arrival state //utc time
=> flight arrival country //utc time


Passenger
=>First Name
=>Last Name
=>id
=>dob
=>array of future destinations holding in [0] a pointer to the flight and in [1] a pointer to the seat.
// so if the destinations are flight NK2389 and the seat 1b, and next flight is flight NK356 and seat 32a 
// the array would be destinations  [0][0]=>pointer to flight NK2389
//                                  [0][1]=>pointer to seat 1b
// the array would be destinations  [1][0]=>pointer to flight NK356
//                                  [1][1]=>pointer to seat 32a
// and so on with each flight


Seats
=> you said you got it but I would like to add a
=> seat passenger => pointer to passenger object