import mediapipe as mp
import cv2
mp_hnds=mp.solutions.hands
hands=mp_hnds.Hands()
cap=cv2.VideoCapture(0)
if not cap :
    print("couldnt open the camera twin")
    exit()
while True:
    ret,frame=cap.read()
    rgb=cv2.cvtColor(frame,cv2.COLOR_BGR2RGB)
    result=hands.process(rgb)
    print(f"dis nigga got hands? {result.multi_hand_landmarks is not None}")
    cv2.imshow("webcame",frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
cap.release()
cv2.destroyAllWindows()