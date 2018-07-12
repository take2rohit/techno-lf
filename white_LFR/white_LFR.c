#include<avr/io.h>
#include<util/delay.h>

void hleft(void)
{
	PORTC=0b00000110;
}

void hright(void)
{
	PORTC=0b00001001;
}

void foreward(void)
{
	PORTC=0b00001010;
}

void left(void)
{
	PORTC=0b00000010;
}

void right(void)
{
	PORTC=0b00001000;
}

void backward(void)
{
	PORTC=0b00000101;
}

main()
{
	DDRB=0B00000000;	 // array--> i/p
	DDRD=0B00000000;	 // Sensor
	DDRC=0B11111111;	 // led--> o/p 
	char x,y,k=0; 
	int m=1;	// 1 is WLF

	while (1) 
	{
		
		y= PIND & 0b11000000;
		x= PINB & 0B00000111; //read i/p with masking unused bits 
		
		if (y==0)
			m=1;

		else if (y==0b11000000)
			m=0;

		if (m==1)	//WLF

		{
			if(x==0b00000010  ) 	
				foreward();
	
			else if(x==0b000000110)
				left();
	
			else if(x==0b00000100)
				left();
		
			else if(x==0b000000011)
				right();
	
			else if(x==0b00000001)
				right();
			
			if(y==0b10000000)	//acute check right
				k=1;

			else if(y==0b01000000)	//acute check left
				k=2;
			
			else if(x==0b00000000)
			{
				if (k==1)	
					hright();
				if (k==2)
					hleft();			
			}

			
		}

		
		if (m==0)	//BLF

		{
			if(x==0b00000101  ) 	
				foreward();
	
			else if(x==0b000000001)
				left();
	
			else if(x==0b00000011)
				left();
		
			else if(x==0b000000100)
				right();
	
			else if(x==0b00000110)
				right();	
		
			if(y==0b10000000)	//left sense black turn left
				k=2;

			else if(y==0b01000000)
				k=1;

			else if(x==0b00000111)
			{
				if (k==1)	
					hright();
				if (k==2)
					hleft();			
			}
			
		}

	}
  
}
