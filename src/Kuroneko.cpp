#include "Kuroneko.hpp"

void print_introduction() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(2000); // waits for the serial to connect
    Serial.println(R"((  *   )                                         (                              )");
    Serial.println(R"((` )  /(   (     (                     )         )\ )     (    (     (          )");
    Serial.println(R"(( ( )(_))  )(    )\    (       (    ( /(   ___  (()/(    ))\   )(    )(     (   )");
    Serial.println(R"(((_(_())  (()\  ((_)   )\ )    )\   )(_)) |___|  /(_))  /((_) (()\  (()\    )\  )");
    Serial.println(R"((|_   _|   ((_)  (_)  _(_/(   ((_) ((_)_        (_) _| (_))    ((_)  ((_)  ((_) )");
    Serial.println(R"((  | |    | '_|  | | | ' \)) / _|  / _` |        |  _| / -_)  | '_| | '_| / _ \ )");
    Serial.println(R"((  |_|    |_|    |_| |_||_|  \__|  \__,_|        |_|   \___|  |_|   |_|   \___/ )");
    Serial.println("\n\n-- por Equipe Phoenix de Robótica\n");
    digitalWrite(LED_BUILTIN, LOW);
}
                                     
void debug_robot() {
    
}