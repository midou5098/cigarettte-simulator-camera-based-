import mediapipe as mp
import cv2
def state(hands_landmark):
    fingered=0
    if hands_landmark.landmark[8].y<hands_landmark.landmark[6].y:
        fingered+=1
    if hands_landmark.landmark[12].y<hands_landmark.landmark[10].y:
        fingered+=1
    if hands_landmark.landmark[16].y<hands_landmark.landmark[14].y:
        fingered+=1
    if hands_landmark.landmark[20].y<hands_landmark.landmark[18].y:
        fingered+=1
    opne=hands_landmark.landmark[4].x>hands_landmark.landmark[3].x
    if fingered>=3 and opne:
        return 1
    else:
        return 0

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
    pito=""
        
   
    
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
    if result.multi_hand_landmarks is not None:
        for hands_landmark in result.multi_hand_landmarks:
                if state(hands_landmark)==0:
                    pito="closed"
                else:
                    pito="opened"
                
                mp.solutions.drawing_utils.draw_landmarks(frame,hands_landmark,mp_hnds.HAND_CONNECTIONS)
    print(f"dis nigga hands are ? {pito}")
    cv2.imshow("webcame",frame)
cap.release()
cv2.destroyAllWindows()

