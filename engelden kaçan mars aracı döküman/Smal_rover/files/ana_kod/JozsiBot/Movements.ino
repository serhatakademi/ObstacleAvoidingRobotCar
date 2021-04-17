/* analogWrite(motor1Pin1, duration); //bal elso elore OK
 analogWrite(motor2Pin2, duration); //bal hatso elore OK
 analogWrite(motor3Pin2, duration); //jobb hatso elore OK
 analogWrite(motor4Pin2, duration); //jobb elso elore OK
 */

void Forward(int duration){
	analogWrite(motor1Pin1, duration); //bal elso elore OK
	analogWrite(motor2Pin2, duration); //bal hatso elore OK
	analogWrite(motor3Pin2, duration); //jobb hatso elore OK
	analogWrite(motor4Pin2, duration); //jobb elso elore OK
}

void Backward(int duration){
	analogWrite(motor1Pin2, duration); //bal elso hatra OK
	analogWrite(motor2Pin1, duration); //bal hatso hatra OK
	analogWrite(motor3Pin1, duration); //jobb hatso hatra OK
	analogWrite(motor4Pin1, duration); //jobb elso hatra OK
}

void Stoppage(){
	digitalWrite(motor1Pin1, LOW); 
	digitalWrite(motor2Pin1, LOW); 
	digitalWrite(motor3Pin1, LOW); 
	digitalWrite(motor4Pin1, LOW);

	digitalWrite(motor1Pin2, LOW); 
	digitalWrite(motor2Pin2, LOW); 
	digitalWrite(motor3Pin2, LOW); 
	digitalWrite(motor4Pin2, LOW); 
}

void TLeft(int duration){
	analogWrite(motor3Pin2, duration); //jobb hatso elore OK
	analogWrite(motor4Pin2, duration*1.2); //jobb elso elore OK
	analogWrite(motor1Pin2, duration*1.2); //bal elso hatra OK
	analogWrite(motor2Pin1, duration); //bal hatso hatra OK
}

void TRight(int duration){
	analogWrite(motor3Pin1, duration); //jobb hatso elore OK
	analogWrite(motor4Pin1, duration*1.2); //jobb elso elore OK
	analogWrite(motor1Pin1, duration*1.2); //bal elso hatra OK
	analogWrite(motor2Pin2, duration); //bal hatso hatra OK
}

void DeflectionLeft(int duration){
	analogWrite(motor1Pin1, duration/4); //bal elso elore OK
	analogWrite(motor2Pin2, duration/4); //bal hatso elore OK
	analogWrite(motor3Pin2, duration); //jobb hatso elore OK
	analogWrite(motor4Pin2, duration); //jobb elso elore OK
}

void DeflectionRight(int duration){
	analogWrite(motor1Pin1, duration); //bal elso elore OK
	analogWrite(motor2Pin2, duration); //bal hatso elore OK
	analogWrite(motor3Pin2, duration/4); //jobb hatso elore OK
	analogWrite(motor4Pin2, duration/4); //jobb elso elore OK
}














