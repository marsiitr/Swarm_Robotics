# import all the required packages
from __future__ import print_function
import pyzbar.pyzbar as pyzbar
import numpy
import cv2
import time
from bs4 import BeautifulSoup
import urllib3.reque

def decode(im):
    # Find QR codes
    decodedObjects = pyzbar.decode(im)
    # Print results
    for obj in decodedObjects:
        print('Type : ', obj.type)
        print('Data : ', obj.data, '\n')
    return decodedObjects

# get the webcam:
cap = cv2.VideoCapture(cv2.CAP_DSHOW)
#set the length and breadth
cap.set(3, 720)
cap.set(4, 720)
print(cap.get(3))
print(cap.get(4))
time.sleep(2)
font = cv2.FONT_HERSHEY_SIMPLEX

while (cap.isOpened()):
    # set different urls for different bots
    e_url1 = "192.168.137.165/specificArgs?direction="
    e_url2 = "192.168.137.182/specificArgs?direction="

    # Capture frame-by-frame
    ret, frame = cap.read()
    # Our operations on the frame come here
    im = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    decodedObjects = decode(im)
    for decodedObject in decodedObjects:

        points = decodedObject.polygon
        print(points)
        #calculate the centre's coordinates
        a=(points[0][0]+points[1][0]+points[2][0]+points[3][0])/4
        b=(points[0][1]+points[1][1]+points[2][1]+points[3][1])/4
        print(a)
        print(b)

        # If the points do not form a quad, find convex hull
        if len(points) > 4:
            hull = cv2.convexHull(np.array([point for point in points], dtype=np.float32))
            hull = list(map(tuple, np.squeeze(hull)))
        else:
            hull = points;

        # Number of points in the convex hull
        n = len(hull)
        # Draw the convext hull
        for j in range(0, n):
            cv2.line(frame, hull[j], hull[(j + 1) % n], (255, 0, 0), 3)

        x = decodedObject.rect.left
        y = decodedObject.rect.top

        qrCode = str(decodedObject.data)
        cv2.putText(frame, barCode, (x, y), font, 1, (0, 255, 255), 2, cv2.LINE_AA)
        s = 'O' + str(0) + 'A' + str(a) + 'B' + str(b) + 'C' + str(0) + 'D'

        if(qrCode== str(b'QR Code' )):

            e_url1 = e_url1 + str(s)
            print(e_url1)
            http=urllib3.PoolManager()
            response=http.request('GET',e_url1)
            soup=BeautifulSoup(response.data)
        if (qrCode == str (b'http://qrly.me/bdft' )):

            e_url2 = e_url2 + str(s)
            print(e_url2)
            http = urllib3.PoolManager()
            response = http.request('GET', e_url2)
            soup = BeautifulSoup(response.data)

    # Display the resulting frame
    cv2.imshow('frame', frame)
    key = cv2.waitKey(1)
    if key & 0xFF == ord('q'):
        break

 # When everything done, release the capture
cap.release()
cv2.destroyAllWindows()