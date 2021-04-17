int motor1Pin1=3;
int motor1Pin2=4;

int motor2Pin1=5;
int motor2Pin2=6;

int motor3Pin1=7;
int motor3Pin2=8;

int motor4Pin1=9;
int motor4Pin2=10;

//US Sensor LEFT
int inputPin1=53;  //  ECHO/Rx Pin
int outputPin1=51; //  TRIG/TX Pin

//Fix US sensor FRONT
int inputPin2=47;  //  ECHO/Rx Pin 
int outputPin2=49; //  TRIG/TX Pin

//Fix US sensor RIGHT
int inputPin3=43;  //  ECHO/Rx Pin 
int outputPin3=45; //  TRIG/TX Pin


int rndMin = 100;
int rndMax = 500;
int DefDist;

unsigned long lastCrash;

//volatile bool frontCrashSensor = false;//, onInterrupt = false;

void setup() 
{ 
	Serial.begin(9600);
	pinMode(inputPin1, INPUT);
	pinMode(outputPin1, OUTPUT);

	pinMode(inputPin2, INPUT);
	pinMode(outputPin2, OUTPUT);

	pinMode(inputPin3, INPUT);
	pinMode(outputPin3, OUTPUT);

	pinMode(motor1Pin1, OUTPUT);
	pinMode(motor1Pin2, OUTPUT);

	pinMode(motor2Pin1, OUTPUT);
	pinMode(motor2Pin2, OUTPUT);

	pinMode(motor3Pin1, OUTPUT);
	pinMode(motor3Pin2, OUTPUT);

	pinMode(motor4Pin1, OUTPUT);
	pinMode(motor4Pin2, OUTPUT);

	pinMode(2, INPUT);
	//attachInterrupt(0, frontCrash, FALLING);

	//FrontUSEye.attach(11);
	//FrontUSEye.write(78); //K?z?p?ll?s; 18 BAL; 138 JOBB;

	delay(6000);
} 

void loop() 
{ 
	if(digitalRead(2) == LOW)
	{
		fCrash();
	}
	else
	{
		int ActDist= GetDistanceFix(inputPin2, outputPin2);
		if (ActDist > 180){
			if(digitalRead(2) == LOW)
			{
				fCrash();
			}
			Forward(230);
			delay(30);
		}
		else if (ActDist > 110 && ActDist <= 180){
			if(digitalRead(2) == LOW)
			{
				fCrash();
			}
			Forward(200);
			switch(EnviromentLengths())
			{
			case 0:
				if(digitalRead(2) == LOW)
				{
					fCrash();
				}
				DeflectionLeft(200);
				delay(random(rndMin, rndMax));
				break;
			case 1:
				if(digitalRead(2) == LOW)
				{
					fCrash();
				}
				delay(30);
				break;
			case 2:
				if(digitalRead(2) == LOW)
				{
					fCrash();
				}
				DeflectionRight(200);
				delay(random(rndMin, rndMax));
				break;
			}
		}
		else if (ActDist >60 && ActDist <= 110){
			if(digitalRead(2) == LOW)
			{
				fCrash();
			}
			Forward(180);
			switch(EnviromentLengths())
			{
			case 0:
				if(digitalRead(2) == LOW)
				{
					fCrash();
				}
				DeflectionLeft(200);
				delay(random(rndMin, rndMax));
				break;
			case 1:
				if(digitalRead(2) == LOW)
				{
					fCrash();
				}
				Forward(180);
				delay(30);
				break;
			case 2:
				if(digitalRead(2) == LOW)
				{
					fCrash();
				}
				DeflectionRight(200);
				delay(random(rndMin, rndMax));
				break;
			}
		} 
		else if (ActDist > 30 && ActDist <= 60){
			Stoppage();
			switch(EnviromentLengths())
			{
			case 0:
				if(digitalRead(2) == LOW)
				{
					fCrash();
				}
				TLeft(200);
				DefDist = GetDistanceFix(inputPin2, outputPin2);
				while(DefDist >30 && DefDist<160){
					delay(20);
					DefDist = GetDistanceFix(inputPin2, outputPin2);
				}
				Stoppage();
				break;
			case 1:
				if(digitalRead(2) == LOW)
				{
					fCrash();
				}
				Forward(180);
				delay(30);
				break;
			case 2:
				if(digitalRead(2) == LOW)
				{
					fCrash();
				}
				TRight(200);
				DefDist = GetDistanceFix(inputPin2, outputPin2);
				while(DefDist >30 && DefDist<160){
					delay(20);
					DefDist = GetDistanceFix(inputPin2, outputPin2);
				}
				Stoppage();
				break;
			}
		}
		else if (ActDist <= 30){
			Stoppage();
			delay(10);
			Backward(180);
			while(GetDistanceFix(inputPin2, outputPin2)<40){
				delay(50);
			}
			Stoppage();
			switch(EnviromentLengths())
			{
			case 0:
				if(digitalRead(2) == LOW)
				{
					fCrash();
				}
				TLeft(200);
				DefDist = GetDistanceFix(inputPin2, outputPin2);
				while(DefDist >30 && DefDist<160){
					delay(20);
					DefDist = GetDistanceFix(inputPin2, outputPin2);
				}
				Stoppage();
				break;
			case 1:
				if(digitalRead(2) == LOW)
				{
					fCrash();
				}
				Forward(180);
				delay(30);
				break;
			case 2:
				if(digitalRead(2) == LOW)
				{
					fCrash();
				}
				TRight(200);
				DefDist = GetDistanceFix(inputPin2, outputPin2);
				while(DefDist >30 && DefDist<160){
					delay(20);
					DefDist = GetDistanceFix(inputPin2, outputPin2);
				}
				Stoppage();
				break;
			}
		}
	}
}

















































































