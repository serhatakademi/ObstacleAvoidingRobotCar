int GetDistanceFix(int echo, int trig)
{
	/*Serial.print("inputPin1 ECHO: ");
	Serial.println(echo);
	Serial.print("outputPin1 TRIG: ");
	Serial.println(trig);*/
	int dist=0;
	digitalWrite(trig, LOW);  // send low pulse for 2?s
	delayMicroseconds(2);
	digitalWrite(trig, HIGH); // send high pulse for 10?s
	delayMicroseconds(10);
	digitalWrite(trig, LOW);  // back to low pulse
	int distance = pulseIn(echo, HIGH);  // read echo value
	dist = distance/29/2;  // in cm
	Serial.println(dist);

	return dist;
}

int EnviromentLengths()
{
	int lengths[3];

	lengths[0] = GetDistanceFix(inputPin1, outputPin1);
	lengths[1] = GetDistanceFix(inputPin2, outputPin2);
	lengths[2] = GetDistanceFix(inputPin3, outputPin3);

	if(lengths[1] > lengths[0] && lengths[1] > lengths[2])
	{
		return 1;
	}
	else if( lengths[0] >=  lengths[2])
	{
		return 0;
	}
	else
	{
		return 2;
	}
}




