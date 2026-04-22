from mediapipe import *
import cv2

cap=cv2.VideoCapture(0)
if not cap :
    print("couldnt open the camera twin")
    exit()
while True:
    ret,frame=cap.read()
    cv2.imshow("webcame",frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
cap.release()
cv2.destroyAllWindows()