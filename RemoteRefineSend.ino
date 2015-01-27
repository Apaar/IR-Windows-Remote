#include <IRremote.h>		// Must be located in sketchbook
					//  libraries folder

int RECV_PIN = 8;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); 
    // Start the receiver
}
long prev=0;
void loop() 
{
  
  
  
  if (irrecv.decode(&results)) 
  {
   
    int flag=0;
    
    if(prev == results.value)
       { flag = 1; }
    
    if(results.value == 2218066430 && flag==0) //the values are the specific IR signals being recieved by the IR sensor
    {Serial.println(11);}
    
    else if(results.value == 2218066685 && flag==0)
    {Serial.println(12);}   
    
    else if(results.value == 2218066940 && flag==0)
    {Serial.println(13);}
    
    else if(results.value == 2218067195 && flag==0)
    {Serial.println(14);}
    
    else if(results.value == 2218067450 && flag==0)
    {Serial.println(21);}
    
    else if(results.value == 2218067705 && flag==0)
    {Serial.println(22);}
    
    else if(results.value == 2218067960 && flag==0)
    {Serial.println(23);}
    
    else if(results.value == 2218068215 && flag==0)
    {Serial.println(24);}
    
    else if(results.value == 2218068470 && flag==0)
    {Serial.println(31);}
    
    else if(results.value == 2218068725 && flag==0)
    {Serial.println(32);}
    
    else if(results.value == 2218068980 && flag==0)
    {Serial.println(33);}
    
    else if(results.value == 2218069235 && flag==0)
    {Serial.println(34);}
    
    else if(results.value == 2218069490 && flag==0)
    {Serial.println(41);}
    
    else if(results.value == 2218069745 && flag==0)
    {Serial.println(42);}
    
    else if(results.value == 2218070000 && flag==0)
    {Serial.println(43);}
    
    else if(results.value == 2218070255 )   //in case of volume multiple hits beneficial so no elimination
    {Serial.println(44);}
    
    else if(results.value == 2218070510 )
    {Serial.println(51);}
   
    else if(results.value == 2218070765 && flag==0)
    {Serial.println(52);}
   
    else if(results.value == 2218071020 && flag==0)
    {Serial.println(53);}
   
    else if(results.value == 2218071275 && flag==0)
    {Serial.println(54);}
   
    else if(results.value == 2218071530 && flag==0)
    {Serial.println(61);}
   
    else if(results.value == 2218071785 && flag==0)
    {Serial.println(62);}
   
    else if(results.value == 2218072040 && flag==0)
    {Serial.println(63);}
   
    else if(results.value == 2218072295 && flag==0)
    {Serial.println(64);}
    
    prev = results.value;
   
    irrecv.resume();          // Receive the next value
  }
}

