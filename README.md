# Quiz Game LCD

Welcome to the Quiz Game LCD project! This interactive quiz game utilizes an LCD display, a buzzer, and a NeoPixel LED to create an engaging experience for users. The game presents a series of questions, and players can select their answers using a slider.

## Features
- LCD display for questions and answers
- Slider input for answer selection
- Buzzer feedback for correct/incorrect answers
- NeoPixel LED for visual feedback

## Getting Started

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/spageektti/quiz-game-lcd.git
   ```
2. Open the `sketch.ino` file in the Arduino IDE.
3. Upload the code to your Arduino/Pico/other board.

### Wokwi Simulation
You can also try the project online using Wokwi:
[Run the Quiz Game on Wokwi](https://wokwi.com/projects/406226650622143489)

## Code Overview
The main logic of the game is implemented in `sketch.ino`. It initializes the LCD, NeoPixel, and input pins, then enters a loop to display questions and handle user input.

### Questions and Answers
The game includes a set of predefined questions and multiple-choice answers. The correct answers are stored in an array for validation.

## Contributing
Feel free to fork the repository and submit pull requests for any improvements or features you'd like to add!

## License
This project is licensed under the MIT License. See the LICENSE file for more details.

Enjoy the quiz game!
