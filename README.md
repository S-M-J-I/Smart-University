# Smart University

*This project was submitted as an evaluation metric for the course Microprocessor, Microcontroller and Interfacing Laboratory in United Internation University.*

This project is a hardware-software fusion. Find the software(web-app) part [here](https://github.com/S-M-J-I/Smart-University-Attendance).

## Problem Statement & Solution

Universities have many "background" processes that are done physically such as turning of room lights, attendance systems, and so on. Thus, we made a multidisciplinary electronics system that would automate these "background" tasks and save time and resources.

## Features

Our system provides:
- Automated online attendance system through biometric (fingerprint) validation. [Find the seperate repo here](https://github.com/S-M-J-I/Smart-University-Attendance)
- Automatic toggling of room lights
- Automated roof-top system for monsoon.
- Automated plant-watering system for the university's green environment.
- Electricity generation on pressure (and storage).

## Processes


- ### Automated online attendance system through biometric:
  1. The student puts his finger on the fingerprint sensor.
  2. The sensor then finds the fingerprint pattern in its embedded memory.
  3. Once found, the sensor uses the Node-MCU to send the details of the fingerprint to the online web-app which can be found [here](https://github.com/S-M-J-I/Smart-University-Attendance).
  4. The online web-app finds the details and updates the attendance for the student on that day and course.

- ### Automated toggling of room lights:
  1. Two IR sensors are placed side-by-side, one on the outside of the room and one on the inside of the room.
  2. When a person enters, the outside sensor gets triggered and temporarily disables the inside sensor for a specific delay.
  3. When a person exits, the inside sensors gets triggered and temporarily disables the outside sensor for a specific delay.
  4. These sensors keep track of the count of people in the room. If the count is >0, then an LED is turned on. Else off
  5. Extensive testing of this system revealed that this mechanism can handle the challenge of multiple people entering in a short period of time.

- ### Automated roof-top system for monsoon:
  1. A water sensor is placeed on the outside of the building, close to the roof.
  2. When it detects water above a certain threshold(heavy/moderate rain rain), it uses microservo motor to close the open roof of the university. ***Please check out the [architecture](https://fastly.4sqi.net/img/general/600x600/596420105_qk4NT9Gfls3xSQSctlZ8t6v6_9w_Saf2Z8poQh8IE4U.jpg) of our university to see relevance***
  3. When the threshold falls below the threshold(slight rain/fog), then the roof opens.
  4. While closed, the roof is fitted with a pipe that collects rainwater and flows it directly to a storage tank which is later used for watering the university's green environment.
  
- ### Automated plant-watering system:
  1. A moisture sensor detects the moisture of the soil, and our system checks if it is below a certain threshold(dry).
  2. If yes, the submersible motor in the water storage unit is turned on forcing the water to flow into the environment.
  3. The system keeps watering the environment until it the moisture threshold reaches above the certain threshold(moist).
  4. The motor is then turned off.

- ### Electricity generation on pressure:
  1. A piezo electric sensor is fitted underneath the busy pathways of the university grounds. To force uneccessary triggering, we keep the force received by the piezo at a certain threshold.
  2. When people walk on the pathways, a pressure is applied to the piezo sensor which reaches above a certain threshold. It then generates electricity which we then store it.
  3. This is a green alternative to power the university's electrical systems.

## Components Used

- Arduino Uno (x2)
- Node MCU Wifi Module
- Fingerprint sensor
- Microservo motor
- IR Sensor (x2)
- Piezo Elecric Sensor
- Submersible motor
- Water sensor
- Moisture sensor

<hr>


***This project was made by [S M Jishanul Islam](https://github.com/S-M-J-I/), [Hridoy Das](https://github.com/hridoy1000), [Nur Islam Shourav](https://github.com/NI-Shourav), and [Sahid Hossain Mustakim](https://github.com/sratul35). This project is not accepting outside contributions.***
