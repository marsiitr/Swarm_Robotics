# Swarm_Robotics
Srishti 2020

<p align="center">
  <img width="600" height="400" src="https://cdn.thenewstack.io/media/2017/10/f1235e26-mergeable-nervous-system-robots-1.jpeg">
</p>

## Abstract
*Swarm robotics is an approach to the coordination of the multiple robots as a system which consist of large numbers of mostly simple physical robots.  Only through their interactions a collective behavior emerges that is able to solve complex tasks. These characteristics lead to the main advantages of swarms: adaptability, robustness, and scalability. Under this excuse we made multiple bots which coordinate among themselves to form different shapes*

## Motivation
*As swarm of ants work in unison to achieve an intimidating task, similarly multiple bots can work in unison to achieve a seemingly difficult task. As the newbies, out of curiosity we choose to work on the same.*

## Mechanical Aspect of the Design
#### Components Used:

|       Component      |                         Size                        | Quantity |
|:--------------------:|:---------------------------------------------------:|:--------:|
| Nut and  Countersink |               6mm diameter 60mm length              |    16    |
|     Nut and Bolt     |                     3mm diameter                    |    16    |
|     L - Brackets     |                       Standard                      |     8    |
|     70mm Wheels      |               70mm diameter 20mm width              |     8    |
|     Castor Wheel     |                        Small                        |     4    |
|       Plywood 1      |                     150X150X50mm                    |     8    |
|       Plywood 2      | 70X60X13.6mm (depends on the  size of castor wheel) |     4    |

## Electronics Aspect of the Design
#### Contents
* 4 X ESP9266(NodeMCU)
* 4 X L298(Motor Driver)
* 8 X 60rpm DC motors
* 4 X MPU 92/65(Gyroscope)
* 1 X Overhead Camera
* 4 X 12V Li-polymer Batteries
* Jumpers

## Cost Structure

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
* Paritosh Sanadhya
* Prathmesh Bhaktan
* Samiksha Jain
* Sarthak Malik
* Vidhi Mittal

## Mentors
* Annu Shree
* Shubhanshu Agarwal

## References
* OpenCV Python Tutorial For Beginners - https://www.youtube.com/playlist?list=PLS1QulWo1RIa7D1O6skqDQ-JZ1GGHKK-K
* Stack Overflow - https://stackoverflow.com/
* Pyimagesearch - https://pyimagesearch.com/
* Arduino - https://www.arduino.cc/
