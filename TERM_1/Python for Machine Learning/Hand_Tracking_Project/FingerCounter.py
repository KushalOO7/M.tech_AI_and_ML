import cv2
import time
import os
import HandTrackingModule as htm

wCam, hCam = 640, 480

cap = cv2.VideoCapture(0)
cap.set(3, wCam)
cap.set(4, hCam)

folder_path = "FingerImages"
myList = os.listdir(folder_path)
#print(myList)

overlayList = []
for imPath in myList:
    image = cv2.imread(f'{folder_path}/{imPath}')
    #print(f'{folder_path}/{imPath}')
    overlayList.append(image)

detector = htm.handDetector(detectionCon=0.75)

pTime = 0
tipIds = [8, 12, 16, 20]

while True:
    success, img = cap.read()
    img = detector.findHands(img)
    lmList = detector.findPosition(img, draw = False)

    if len(lmList) != 0:
        fingers = []

        # For Thumb Finger
        if lmList[4][1] > lmList[3][1]:
            fingers.append(1)
        else:
            fingers.append(0)

        # For other Four Fingers
        for id in range(0,4):
            if lmList[tipIds[id]][2] < lmList[tipIds[id]-2][2]:
                fingers.append(1)
            else:
                fingers.append(0)

        # print(fingers)
        total_fingers = fingers.count(1)
        # print(total_fingers)
        img[2:162 , 2:162] = overlayList[total_fingers-1]

        cv2.rectangle(img, (2,225), (170,425), (0,255,0), cv2.FILLED)
        cv2.putText(img, str(total_fingers), (35,375), cv2.FONT_HERSHEY_PLAIN, 10, (0,0,0), 15)


    cTime = time.time()
    fps = 1 / (cTime - pTime)
    pTime = cTime

    cv2.putText(img, f'FPS: {int(fps)}', (470, 40), cv2.FONT_HERSHEY_PLAIN, 2, (0, 255, 255), 3)

    cv2.imshow("Image Panel", img)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break