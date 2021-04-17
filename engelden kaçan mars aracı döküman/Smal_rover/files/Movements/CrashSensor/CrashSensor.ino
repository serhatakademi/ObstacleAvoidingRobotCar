void fCrash()
{
	Stoppage();
	delay(50);
	Serial.println("interrupt----fCrash--------->>>");
	if((lastCrash + 2000) > millis())
	{
		Backward(180);  
		delay(400);
		switch(EnviromentLengths())
		{
		case 0:
			TLeft(190);
			DefDist = GetDistanceFix(inputPin2, outputPin2);
			while(DefDist<120){
				delay(20);
				DefDist = GetDistanceFix(inputPin2, outputPin2);
			}
			Stoppage();
			break;
		case 1:
			Backward(180);  
			delay(400);
			break;
		case 2:
			TRight(190);
			DefDist = GetDistanceFix(inputPin2, outputPin2);
			while(DefDist<120){
				delay(20);
				DefDist = GetDistanceFix(inputPin2, outputPin2);
			}
			Stoppage();
			break;
		}
       lastCrash=millis();
	}
	else
	{
		Backward(180);
		delay(random(rndMin, rndMax));
		Stoppage();
		delay(10);
		//frontCrashSensor = false;
	}
	Serial.println("interrupt----fCrash---------<<<");
}














