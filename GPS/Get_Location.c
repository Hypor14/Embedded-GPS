#include "GPS.h"
#include "../LANDMARKS.h"
#include "../LCD/LCD.h"

void Display_Location(double currLat, double currLon) {

    // find nearest landmark to my current location
    double bestDist = 1e9;
    uint8_t choice = -1;

    for (uint8_t i = 0; i < NUM_LANDMARKS; i++) {
        double d = haversine(currLat, currLon,landmarks[i].lat, landmarks[i].lon);

        if (d < bestDist) {
            bestDist = d;
            choice  = i;
        }
    }

    // display if in close proximity
    if (choice >= 0 && bestDist <= Proximity) {
				Lcd_string(landmarks[choice].name);
    } else {
        printf("------------------");  
    }
}