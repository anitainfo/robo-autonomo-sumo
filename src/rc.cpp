// #include <motors.hpp>

// void canal_setup(){
//     pinMode(PIN_CANAL1, INPUT); 
//     pinMode(PIN_CANAL2, INPUT); 
//     Serial.begin(9600); 
// }

// void run_remote_control(){

//     Serial.println("Remote control selected");
    
//     int canal1 = pulseIn(PIN_CANAL1, HIGH, 30000); 
//     int canal2 = pulseIn(PIN_CANAL2, HIGH, 30000); 
    
//     if(canal1 == 0 || canal2 == 0){ 
//     motor_control(LEFT, 0); 
//     motor_control(RIGHT, 0); 
//     Serial.println("Desconectado"); 
//     return; 
//     } 
    
//     if(canal1<REFERENCIA+DEADZONE && canal1>REFERENCIA-DEADZONE){ 
//     canal1 = REFERENCIA; 
//     } 
    
//     if(canal2<REFERENCIA+DEADZONE && canal2>REFERENCIA-DEADZONE){ 
//     canal2 = REFERENCIA; 
//     } 
    
//     int map_canal1 = map(canal1, 1000, 2000, -MAX_PWR, MAX_PWR); 
//     int map_canal2 = map(canal2, 1000, 2000, -MAX_PWR, MAX_PWR); 
    
//     int motor_left = map_canal2 - map_canal1; 
//     int motor_right = map_canal2 + map_canal1; 
    
//     motor_control(LEFT, motor_left); 
//     motor_control(RIGHT, motor_right); 
    
//     Serial.print(motor_left); 
//     Serial.print("\t"); 
//     Serial.println(motor_right); 
// }