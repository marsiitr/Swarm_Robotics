# Swarm_Robotics
## Srishti 2020

<div style="text-align: justify">
<p align="center">
  <img width="600" height="400" src="/Images and Videos/Images/Shapes/Square.png">
</p>

## Abstract
Swarm robotics is an approach to the coordination of the multiple robots as a system which consist of large numbers of mostly simple physical robots.  Only through their interactions a collective behavior emerges that is able to solve complex tasks. These characteristics lead to the main advantages of swarms: adaptability, robustness, and scalability. Under this excuse we made multiple bots which coordinate among themselves to form different shapes.

## Motivation
As swarm of ants work in unison to achieve an intimidating task, similarly multiple bots can work in unison to achieve a seemingly difficult task. As the newbies, out of curiosity we choose to work on the same.

## Mechanical Aspect of the Design
This project consists of four mechanically identical bots which move in unison to form the shape specified by the user. But each of the bot has a unique identity because of the unique QR code pasted on its roof. Each bot has 2 sheets of ply one over the other with electrical components between them. A single bot consists of 2 normal wheels at the back, 1 castor wheel at the front and 2 L-brackets for holding motors in them.
<p align="center">
  <img width="600" height="400" src="/Mechanical Design/Solidworks_design/CAD_and_circuit_images/Img3.jpeg">
</p>

## Electronics Aspect of the Design
In each of the bot, the microcontroller used is ESP8266(NodeMCU). For angle detection fron the initial position for a particular bot, a gyroscope sensor(particularly
MPU-92/65 is used. For controlling the motors, a motor driver(particularly L298) is used in each bot.
<p align="center">
  <img width="600" height="400" src="/Mechanical Design/Solidworks_design/CAD_and_circuit_images/Img5.png">
</p>
Initially each bot is set to a particular same direction, but when the user calls for a shape using a user friendy interface, each bot is assigned its final coordinates in the field of view of the overhead camera. Thus each bot reaches to its final position one by one. And the final shape is achieved.

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

## Working
Open cv facilitates the process of reading QR codes, including loading images from disk, grabbing a new frame from a video stream, and processing it. Important libraries we imported are pyzbar, argparse and cv2.
    The ZBar library will decode the barcode or QR code. OpenCV can come back in to perform any further processing and display the result. For Python, we use pyzbar, which has a simple decode function to locate and decode all symbols in the image. The decode function simply wraps pyzbar’s decode function and loops over the located barcodes and QR codes and prints the data. The decoded symbols from the previous step are passed on to the display function . If the points form a quad ( e.g. in a QR code ), we simply draw the quad. If the location is not a quad, we draw the outer boundary of all the points ( also called the convex hull ) of all the points. This is done using an OpenCV function called cv2.convexHull. Finally, the main function simply reads an image, decodes it and displays the results.
<p align="center">
  <img width="600" height="400" src="/Mechanical Design/Solidworks_design/CAD_and_circuit_images/Img6.jpeg">
</p>
Firstly ,a function handleSpecificArg() is defined that receives data that is sent by the python code that is doing image recognition. Python returns the data in the form of string which is then sent to the NodeMCU. All of the NodeMCUs are connected to the hotspot of the same laptop so it directly sends the data to each NodeMCU.
  Then several functions such that backward(), forward(), etc are defined that helps the bots to move. Then a function get_gyro() is defined that gives the angle turned by bot. Then setup of different pins takes place. Then the function data() gets all the coordinates and the current angle from x-axis and which shape is to be made.
Then the real loop function starts. First we get data from the camera . Then the bot starts to rotate until it is turned in the direction of target position . Then it starts to move forward until it reaches the target position on reaching the target position it starts rotating until it reaches the required orientation. All the bots do the same to make the required shape .

## Applications
Potential applications of swarms are many. To list the few:
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
1. [Paritosh Sanadhya](https://github.com/Pasa1912)
2. [Prathmesh Bhaktan](https://github.com/prathamb)
3. [Samiksha Jain](https://github.com/samiksha-jain003)
4. [Sarthak Malik](https://github.com/ganzagun)
5. [Vidhi Mittal](https://github.com/Vidhi-mittal01)

## Mentors
1. [Annu Shree](https://github.com/annushree21)
2. [Shubhanshu Agarwal](https://github.com/Shubhanshu07)

## References
* [OpenCV Python Tutorial For Beginners](https://www.youtube.com/playlist?list=PLS1QulWo1RIa7D1O6skqDQ-JZ1GGHKK-K)
* [Stack Overflow](https://stackoverflow.com/)
* [Pyimagesearch](https://pyimagesearch.com/)
* [Arduino](https://www.arduino.cc/)
</div>
