# Swarm_Robotics
## Srishti 2020

<div style="text-align: justify"> your-text-here
<p align="center">
  <img width="600" height="400" src="https://cdn.thenewstack.io/media/2017/10/f1235e26-mergeable-nervous-system-robots-1.jpeg">
</p>

## Abstract
*Swarm robotics is an approach to the coordination of the multiple robots as a system which consist of large numbers of mostly simple physical robots.  Only through their interactions a collective behavior emerges that is able to solve complex tasks. These characteristics lead to the main advantages of swarms: adaptability, robustness, and scalability. Under this excuse we made multiple bots which coordinate among themselves to form different shapes*

## Motivation
*As swarm of ants work in unison to achieve an intimidating task, similarly multiple bots can work in unison to achieve a seemingly difficult task. As the newbies, out of curiosity we choose to work on the same.*

## Mechanical Aspect of the Design
*This project consists of four mechanically identical bots which move in unison to form the shape specified by the user. But each of the bot has a unique identity because of the unique QR code pasted on its roof. Each bot has 2 sheets of ply one over the other with electrical components between them. A single bot consists of 2 normal wheels at the back, 1 castor wheel at the front and 2 L-brackets for holding motors in them*

## Electronics Aspect of the Design
*In each of the bot, the microcontroller used is ESP8266(NodeMCU). For angle detection fron the initial position for a particular bot, a gyroscope sensor(particularly
MPU-92/65 is used. For controlling the motors, a motor driver(particularly L298) is used in each bot.*
      *Initially each bot is set to a particular same direction, but when the user calls for a shape using a user friendy interface, each bot is assigned its final coordinates in the field of view of the overhead camera. Thus each bot reaches to its final position one by one. And the final shape is achieved.*

## Cost Structure of the Components Used

| Part                     | Quantity | Cost per unit | Total cost |
|--------------------------|:--------:|:-------------:|-----------:|
| ESP9266 (NodeMCU)        |      4   |        330    |       1320 |
| L298  (Motor Driver)     |      4   |        250    |       1000 |
| 60rpm DC Motor           |      8   |        200    |       1600 |
| MPU 92/65 (Gyroscope)    |      4   |        300    |       1200 |
| Overhead Camera (WebCam) |      1   |       3000    |       3000 |
| 12V Li-polymer Battery   |      4   |       2000    |       8000 |
| Jumpers                  |     60   |          5    |        300 |
| Nut & Bolt (Medium)      |     16   |          5    |         80 |
| Nut & Bolt (Long)        |     16   |         10    |        160 |
| L - Brackets             |      8   |         15    |        120 |
| Normal Wheels            |      8   |         30    |        240 |
| Castor Wheels            |      4   |         25    |        100 |
| PlyWood                  |      1   |        280    |        280 |
| Miscellaneous            |      -   |          -    |        600 |
| Total                    |          |               | Rs.18000/- |

## Applications
*Potential applications of swarms are many. To list the few:*
* Tasks that demand miniaturization, like distributed sensing tasks in micromachinery or the human body.
* One of the promising use of the swarms is in disaster rescue missions.
* Swarms can be used in traffic handling.
* Swarms can form different shapes and designs so they can reach forbidden area.

## Limitations
* Formation of limited number of shapes.
* Initial relative distance  of the bots depends on the field of view of the camera use.
* Dependency on QR code recognition.
* Gyroscope must be used with intense care, as a slight slip of gyro in any of the direction, may give a large error in angle calculation.

## Future Improvement
* Many more shapes can be added to the list.
* Providing the sensors to prevent collision.
* Use of PID, to improve the movement of the bots.
* Assembling(to form the shape), independent of their initial positions.
* Use of GPS instead, to reach their destination.    

## Team Members
* [Paritosh Sanadhya](https://github.com/Pasa1912)
* [Prathmesh Bhaktan](https://github.com/prathamb)
* [Samiksha Jain](https://github.com/samiksha-jain003)
* [Sarthak Malik](https://github.com/ganzagun)
* [Vidhi Mittal](https://github.com/Vidhi-mittal01)

## Mentors
* [Annu Shree](https://github.com/annushree21)
* [Shubhanshu Agarwal](https://github.com/Shubhanshu07)

## References
* OpenCV Python Tutorial For Beginners - https://www.youtube.com/playlist?list=PLS1QulWo1RIa7D1O6skqDQ-JZ1GGHKK-K
* Stack Overflow - https://stackoverflow.com/
* Pyimagesearch - https://pyimagesearch.com/
* Arduino - https://www.arduino.cc/
</div>
