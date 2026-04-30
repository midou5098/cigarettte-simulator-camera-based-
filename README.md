🚬 Gesture Controlled Cigarette Simulation

An interactive desktop simulation built with Python, MediaPipe, OpenCV, and C++/SDL2 that uses real-time hand gesture recognition to control a virtual cigarette burning animation.

The application tracks whether the user's hand is open or closed through webcam input and maps that state to a smoking simulation rendered in SDL.

---

🚀 Features

- ✋ Real-Time Hand Gesture Detection
  
  - Webcam tracking using OpenCV
  - Hand landmark recognition via MediaPipe
  - Detects open vs closed palm states

- 🔄 Python ↔ C++ Communication
  
  - Python writes hand state ("1" or "0") into a shared text file
  - C++ SDL engine continuously reads this state
  - Creates a lightweight IPC bridge between both runtimes

- 🚬 Interactive Cigarette Burn System
  
  - Multiple cigarette brand selections
  - Animated flame sprite sheet
  - Burn progression controlled by hand opening gesture

- 🎨 SDL2 Visual Interface
  
  - Custom textured assets
  - Dynamic clipping for ash/burn reveal
  - Menu system and interaction logic

---

🧠 How It Works

1. Hand Tracking Layer (Python)

Using MediaPipe Hands, the webcam feed is analyzed frame by frame:

- Finger landmarks are checked
- Thumb openness is verified
- If at least 3 fingers + thumb are extended → hand = "opened"
- Otherwise → hand = "closed"

The resulting state is written to:

state.txt

where:

- "1" = open hand
- "0" = closed hand

To reduce unnecessary disk writes, updates are throttled every "0.1s".

---

2. Simulation Layer (C++ / SDL2)

The SDL application polls "state.txt" continuously:

- If hand state = "1"
- and cigarette is currently burning

the cigarette ash advances downward frame by frame.

This creates the illusion that the cigarette is being "pulled" or consumed in response to the user's gesture.

---

3. Burn Animation

The cigarette consists of:

- static cigarette texture
- smoked overlay texture
- clipping rectangle to reveal consumed section
- animated fire sprite

Burn progression variable:

fy

controls:

- flame Y position
- ash reveal clipping
- completion state

---

🛠️ Tech Stack

Python Side

- OpenCV
- MediaPipe
- time

C++ Side

- SDL2
- SDL2_ttf
- SDL2_image
- SDL2_gfx

---

📦 Build & Run

Step 1 — Run gesture detector

python detector.py

This starts webcam tracking and updates "state.txt".

---

Step 2 — Build SDL simulation

g++ main.cpp -o smoke \
-lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_gfx

---

Step 3 — Launch simulation

./smoke

---

🎮 Controls

Input| Action
Mouse Click| Select cigarette type
Smoke Button| Start simulation
Open Hand| Progress burn
ESC| Return to menu

---

🧩 Project Structure

detector.py      -> MediaPipe hand tracker
main.cpp         -> SDL application entry
headers.h        -> UI / animation / logic
state.txt        -> runtime communication bridge
assets/          -> textures and sprite sheets

---

⚙️ Technical Highlights

- Cross-language runtime synchronization
- Basic interprocess communication without sockets/pipes
- Hand landmark boolean gesture classification
- Sprite animation management
- Texture clipping for progressive burn illusion

---

⚠️ Known Limitations

- Uses file polling for communication (not optimal but simple)
- Webcam gesture recognition can fluctuate under poor lighting
- Single gesture type only (open/closed)

---

🔮 Future Improvements

- Replace text-file bridge with sockets/shared memory
- Add inhale/exhale smoke particles
- Add multiple gesture commands
- Improve burn realism
- Add sound effects / ember glow

---

📌 Purpose

This project was built as an experiment in combining:

- computer vision
- gesture recognition
- SDL animation
- cross-language interaction

into one responsive real-time desktop simulation.

---

📜 License

Free to use and modify.
